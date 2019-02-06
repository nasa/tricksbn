#include "trick_ccsds_memory_manager.h"

#ifdef TRICK_VER 

    #pragma message("BUILDING WITH TRICK APIs.")
    
    #include "trick/MemoryManager.hh"

    extern Trick::MemoryManager *trick_MM;

#else

    #pragma message("BUILDING STANDALONE WITHOUT TRICK APIs.")

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

    for (int i = 0 ; i < this->mappings.size(); ++i)
    {
        uint32_t mid = this->mappings[i].messageId;

        QVector<TrickFieldAccessor> accessors;

        for (int j = 0; j < this->mappings[i].trickFieldNames.size(); ++j)
        {
            REF2 *refAttributes = 
                trick_MM->ref_attributes(
                    this->mappings[i].trickFieldNames[j].toStdString().c_str());

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
        }

        this->fieldAccessors[mid] = accessors;
    }

#endif

    return 1;
}

namespace
{
    void SetTrickInt(void *address, uint64_t size, int64_t value)
    {
        if (size == 1)
        {
            int8_t data = value;

            memcpy(address, &data, 1);
        }
        else if (size == 2)
        {
            int16_t data = value;

            memcpy(address, &data, 2);
        }
        else if (size == 4)
        {
            int16_t data = value;

            memcpy(address, &data, 4);

        }
        else if (size == 8)
        {
            int64_t data = value;

            memcpy(address, &data, 8);
        }
    }

    void SetTrickUInt(void *address, uint64_t size, uint64_t value)
    {
        if (size == 1)
        {
            uint8_t data = value;

            memcpy(address, &data, 1);
        }
        else if (size == 2)
        {
            uint16_t data = value;

            memcpy(address, &data, 2);
        }
        else if (size == 4)
        {
            uint16_t data = value;

            memcpy(address, &data, 4);

        }
        else if (size == 8)
        {
            uint64_t data = value;

            memcpy(address, &data, 8);
        }
    }

    int64_t GetTrickInt(void *address, uint64_t size)
    {
        int64_t value = -9999;

        if (size == 1)
        {
            int8_t data;

            memcpy(&data, address, 1);

            value = data;
        }
        else if (size == 2)
        {
            int16_t data;

            memcpy(&data, address, 2);

            value = data;
        }
        else if (size == 4)
        {
            int32_t data;

            memcpy(&data, address, 4);

            value = data;
        }
        else if (size == 8)
        {
            int64_t data;

            memcpy(&data, address, 8);

            value = data;
        }

        return value;
    }

    uint64_t GetTrickUInt(void *address, uint64_t size)
    {
        uint64_t value = 9999;

        if (size == 1)
        {
            uint8_t data;

            memcpy(&data, address, 1);

            value = data;
        }
        else if (size == 2)
        {
            uint16_t data;

            memcpy(&data, address, 2);

            value = data;
        }
        else if (size == 4)
        {
            uint32_t data;

            memcpy(&data, address, 4);

            value = data;
        }
        else if (size == 8)
        {
            uint64_t data;

            memcpy(&data, address, 8);

            value = data;
        }

        return value;
    }
}

QVariant TrickMemoryManagerClient::GetData(TrickFieldAccessor &accessor)
{
    QVariant value;

    if (accessor.type == TrickFieldAccessor::Float)
    {
        float data;
        memcpy(&data, accessor.address, 4);

        value = data;
    }
    else if (accessor.type == TrickFieldAccessor::Double)
    {
        double data;
        memcpy(&data, accessor.address, 8);

        value = data;
    }
    else if (accessor.type == TrickFieldAccessor::Int)
    {
        int64_t data = GetTrickInt(accessor.address, accessor.size);

        value.setValue(data);
    }
    else if (accessor.type == TrickFieldAccessor::UInt)
    {
        uint64_t data = GetTrickUInt(accessor.address, accessor.size);

        value.setValue(data);
    }

    return value;
}

void TrickMemoryManagerClient::SetData(TrickFieldAccessor &accessor, QVariant value)
{
    if (accessor.type == TrickFieldAccessor::Float)
    {
        float data = value.toFloat();

        memcpy(accessor.address, &data, 4);
    }
    else if (accessor.type == TrickFieldAccessor::Double)
    {
        double data = value.toDouble();

        memcpy(accessor.address, &data, 8);
    }
    else if (accessor.type == TrickFieldAccessor::Int)
    {
        SetTrickInt(accessor.address, accessor.size, value.toLongLong());
    }
    else if (accessor.type == TrickFieldAccessor::UInt)
    {
        SetTrickUInt(accessor.address, accessor.size, value.toULongLong());
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
        }
    }

    return messageCount;
}

int TrickMemoryManagerClient::WriteData(QCcsdsPacket &packet)
{
    uint32_t packetId = packet.GetMessageId();

    for (int i = 0; i < this->mappings.size(); ++i)
    {
        if (this->mappings[i].flowDirection == 2)
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

                return 1;
            }

        }
    }

    return -1;
}
