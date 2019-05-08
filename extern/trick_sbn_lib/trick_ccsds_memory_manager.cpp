#include <stdexcept>
#include <iostream>

#include "trick_ccsds_memory_manager.h"
#include "trick_ccsds_utils.h"

#ifdef TRICK_VER 
#include "trick/MemoryManager.hh"
extern Trick::MemoryManager *trick_MM;
#endif

TrickMemoryManagerClient::TrickMemoryManagerClient()
{

}

TrickMemoryManagerClient::~TrickMemoryManagerClient()
{

}

int TrickMemoryManagerClient::Initialize(Protobetter::DynamicTypeCollection &prototypes, QJsonArray &trickVariableMappings)
{
    TrickCcsdsMappingClient::Initialize(prototypes, trickVariableMappings);

#ifdef TRICK_VER

    std::cout << "Initializing Trick CCSDS Memory Manager Client..." << std::endl;

    for (int i = 0 ; i < this->mappings.size(); ++i)
    {
        uint32_t mid = this->mappings[i].messageId;

        QVector<TrickFieldAccessor> accessors;

        for (int j = 0; j < this->mappings[i].trickFieldNames.size(); ++j)
        {
            REF2 *refAttributes = 
                trick_MM->ref_attributes(
                    this->mappings[i].trickFieldNames[j].toStdString().c_str());

            if (!refAttributes)
            {
                std::cout << "\n\nTrick CCSDS Memory Manager Client ERROR: no variable exists named "
                    << this->mappings[i].trickFieldNames[j].toStdString() << "\n\n";

                throw std::runtime_error("Invalid TVM file found...");
            }

            TrickFieldAccessor accessor;

            accessor.address = refAttributes->address;
            accessor.size = refAttributes->attr->size;

            if (this->mappings[i].trickFieldTypes[j] == "float")
            {
                accessor.type = TrickFieldAccessor::Float;
            }
            else if (this->mappings[i].trickFieldTypes[j] == "double")
            {
                accessor.type = TrickFieldAccessor::Double;
            }
            else if (this->mappings[i].trickFieldTypes[j] == "int")
            {
                accessor.type = TrickFieldAccessor::Int;
            }
            else if (this->mappings[i].trickFieldTypes[j] == "uint")
            {
                accessor.type = TrickFieldAccessor::UInt;
            }

            // TODO: you *may* need bitfield support at some point
            
            accessors.push_back(accessor);

            delete refAttributes;
        }

        this->fieldAccessors[mid] = accessors;
    }

#endif

    return 1;
}

QVariant TrickMemoryManagerClient::GetData(TrickFieldAccessor &accessor)
{
    QVariant value;

    switch (accessor.type)
    {
        case TrickFieldAccessor::Float:
        {
            float data = TrickCcsdsUtils::GetFloat(accessor.address);
            value.setValue(data);
            break;
        }
        case TrickFieldAccessor::Double:
        {
            double data = TrickCcsdsUtils::GetDouble(accessor.address);
            value.setValue(data);
            break;
        }
        case TrickFieldAccessor::Int:
        {
            int64_t data = TrickCcsdsUtils::GetInt(accessor.address, accessor.size);
            value.setValue(data);
            break;
        }
        case TrickFieldAccessor::UInt:
        {
            uint64_t data = TrickCcsdsUtils::GetUInt(accessor.address, accessor.size);
            value.setValue(data);
            break;
        }
    }

    return value;
}

void TrickMemoryManagerClient::SetData(TrickFieldAccessor &accessor, QVariant value)
{
    switch (accessor.type)
    {
        case TrickFieldAccessor::Float:
            TrickCcsdsUtils::SetFloat(accessor.address, value.toFloat());
            break;

        case TrickFieldAccessor::Double:
            TrickCcsdsUtils::SetDouble(accessor.address, value.toDouble());
            break;

        case TrickFieldAccessor::Int:
            TrickCcsdsUtils::SetInt(accessor.address, accessor.size, value.toLongLong());
            break;

        case TrickFieldAccessor::UInt:
            TrickCcsdsUtils::SetUInt(accessor.address, accessor.size, value.toULongLong());
            break;
    }
}

int TrickMemoryManagerClient::ReadData(QCcsdsPacket *packetArray, int maxMessages)
{
    int messageCount = 0;

    for (int i = 0; i < this->mappings.size(); ++i)
    {
        if (this->mappings[i].flowDirection == 1 || this->mappings[i].flowDirection == 3)
        {
            int memberCount = this->mappings[i].ccsdsFieldNames.size();
            uint32_t messageId = this->mappings[i].messageId;

            for (int j = 0; j < memberCount; ++j)
            {
                QVariant data = this->GetData(this->fieldAccessors[messageId][j]);

                this->mappings[i].SetProtobetterField(j, data);
            }

            if (debug)
            {
                // TODO: read back the data from the protobetter CCSDS packet
                // and dump it to stdout for debugging purposes
            }

            messageCount++;
        }
    }

    return messageCount;
}

int TrickMemoryManagerClient::WriteData(QCcsdsPacket &packet)
{
    uint32_t packetId = packet.GetMessageId();

    for (int i = 0; i < this->mappings.size(); ++i)
    {
        if (this->mappings[i].flowDirection == 2 || this->mappings[i].flowDirection == 3)
        {
            uint32_t messageId = this->mappings[i].messageId;

            if (messageId == packetId)
            {
                int memberCount = this->mappings[i].ccsdsFieldNames.size();

                this->mappings[i].data->SetData(packet.GetPayloadData());

                for (int j = 0; j < memberCount; ++j)
                {
                    QVariant data = this->mappings[i].GetProtobetterField(j);

                    this->SetData(this->fieldAccessors[messageId][j], data);
                }

                std::cout << "*** New CCSDS Data Processed Trick Mapping MID 0x" 
                    << QString::number(this->mappings[i].messageId, 16).toStdString()
                    << " ***\n" << std::endl;

                if (debug)
                {
                    for (int j = 0; j < memberCount; ++j)
                    {
                        QVariant data = this->GetData(this->fieldAccessors[messageId][j]);
                        QVariant protobetterData = this->mappings[i].GetProtobetterField(j);

                        std::cout << this->mappings[i].ccsdsFieldNames[j].toStdString()
                            << " = " << protobetterData.toString().toStdString() << ", ";

                        std::cout << this->mappings[i].trickFieldNames[j].toStdString()
                            << " = " << data.toString().toStdString() << std::endl;
                    }

                    std::cout << std::endl;
                }

                return 1;
            }

        }
    }

    std::cout << "ERROR TrickMemoryManagerClient::WriteData() called w/ no mappings for message ID = " 
        << QString::number(packetId, 16).toStdString() << std::endl;

    return -1;
}
