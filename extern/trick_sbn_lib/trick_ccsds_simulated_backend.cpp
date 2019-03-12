#include <stdexcept>
#include <iostream>

#include "trick_ccsds_simulated_backend.h"

namespace {

    void SimulateTimeStep(Protobetter::DynamicObject::Ptr data,
                          Protobetter::ProtobetterFieldType fieldType,
                          QString fieldName)
    {
        if (fieldType == Protobetter::UInt8)
        {
            uint8_t value = data->GetUInt8(fieldName);

            data->SetUInt8(fieldName, ++value);
        }
        else if (fieldType == Protobetter::UInt16)
        {
            uint16_t value = data->GetUInt16(fieldName);

            data->SetUInt16(fieldName, ++value);
        }
        else if (fieldType == Protobetter::UInt32)
        {
            uint32_t value = data->GetUInt32(fieldName);

            data->SetUInt32(fieldName, ++value);
        }
        else if (fieldType == Protobetter::UInt64)
        {
            uint16_t value = data->GetUInt64(fieldName);

            data->SetUInt64(fieldName, ++value);
        }
        else if (fieldType == Protobetter::Int8)
        {
            int8_t value = data->GetInt8(fieldName);

            data->SetInt8(fieldName, ++value);
        }
        else if (fieldType == Protobetter::Int16)
        {
            int16_t value = data->GetInt16(fieldName);

            data->SetInt16(fieldName, ++value);
        }
        else if (fieldType == Protobetter::Int32)
        {
            int32_t value = data->GetInt32(fieldName);

            data->SetInt32(fieldName, ++value);
        }
        else if (fieldType == Protobetter::Int64)
        {
            int16_t value = data->GetInt64(fieldName);

            data->SetInt64(fieldName, ++value);
        }
        else if (fieldType == Protobetter::Float)
        {
            float value = data->GetFloat(fieldName) + 1.1f;

            data->SetFloat(fieldName, value);
        }
        else if (fieldType == Protobetter::Double)
        {
            double value = data->GetDouble(fieldName) + 1.1;

            data->SetDouble(fieldName, value);
        }
        else if (fieldType == Protobetter::UnsignedBitfield)
        {
            uint64_t value = data->GetUnsignedBitfield(fieldName);

            data->SetUnsignedBitfield(fieldName, ++value); 
        }
        else if (fieldType == Protobetter::SignedBitfield)
        {
            int64_t value = data->GetSignedBitfield(fieldName);

            data->SetSignedBitfield(fieldName, ++value);
        }
    }

    void PrintProtobetterData(TrickVariableMapping &mapping)
    {
        for (int i = 0; i < mapping.ccsdsFieldNames.size(); ++i)
        {
            if (mapping.ccsdsFieldTypes[i] == Protobetter::Float)
            {
                float value = mapping.data->GetFloat(mapping.ccsdsFieldNames[i]);

                std::cout << " - " << mapping.ccsdsFieldNames[i].toStdString() << " = " << value << std::endl;
            }
            else if (mapping.ccsdsFieldTypes[i] == Protobetter::Double)
            {
                double value = mapping.data->GetDouble(mapping.ccsdsFieldNames[i]);

                std::cout << " - " << mapping.ccsdsFieldNames[i].toStdString() << " = " << value << std::endl;
            }
            else if (mapping.ccsdsFieldTypes[i] == Protobetter::Int8)
            {
                int8_t value = mapping.data->GetInt8(mapping.ccsdsFieldNames[i]);

                std::cout << " - " << mapping.ccsdsFieldNames[i].toStdString() << " = " << value << std::endl;
            }
            else if (mapping.ccsdsFieldTypes[i] == Protobetter::Int16)
            {
                int16_t value = mapping.data->GetInt16(mapping.ccsdsFieldNames[i]);

                std::cout << " - " << mapping.ccsdsFieldNames[i].toStdString() << " = " << value << std::endl;
            }
            else if (mapping.ccsdsFieldTypes[i] == Protobetter::Int32)
            {
                int32_t value = mapping.data->GetInt32(mapping.ccsdsFieldNames[i]);

                std::cout << " - " << mapping.ccsdsFieldNames[i].toStdString() << " = " << value << std::endl;
            }
            else if (mapping.ccsdsFieldTypes[i] == Protobetter::Int64)
            {
                int64_t value = mapping.data->GetInt64(mapping.ccsdsFieldNames[i]);

                std::cout << " - " << mapping.ccsdsFieldNames[i].toStdString() << " = " << value << std::endl;
            }
            else if (mapping.ccsdsFieldTypes[i] == Protobetter::UInt8)
            {
                uint8_t value = mapping.data->GetUInt8(mapping.ccsdsFieldNames[i]);

                std::cout << " - " << mapping.ccsdsFieldNames[i].toStdString() << " = " << value << std::endl;
            }
            else if (mapping.ccsdsFieldTypes[i] == Protobetter::UInt16)
            {
                uint16_t value = mapping.data->GetUInt16(mapping.ccsdsFieldNames[i]);

                std::cout << " - " << mapping.ccsdsFieldNames[i].toStdString() << " = " << value << std::endl;
            }
            else if (mapping.ccsdsFieldTypes[i] == Protobetter::UInt32)
            {
                uint32_t value = mapping.data->GetUInt32(mapping.ccsdsFieldNames[i]);

                std::cout << " - " << mapping.ccsdsFieldNames[i].toStdString() << " = " << value << std::endl;
            }
            else if (mapping.ccsdsFieldTypes[i] == Protobetter::UInt64)
            {
                uint64_t value = mapping.data->GetUInt64(mapping.ccsdsFieldNames[i]);

                std::cout << " - " << mapping.ccsdsFieldNames[i].toStdString() << " = " << value << std::endl;
            }
            
        }

        std::cout << std::endl;
    }

}

SimulatedTrickBackend::SimulatedTrickBackend()
{

}

SimulatedTrickBackend::~SimulatedTrickBackend()
{

}

int SimulatedTrickBackend::Initialize(Protobetter::DynamicTypeCollection &prototypes, QJsonArray &trickVariableMappings)
{
    TrickCcsdsMappingClient::Initialize(prototypes, trickVariableMappings);

    return 1;
}

int SimulatedTrickBackend::ReadData(QCcsdsPacket *packetArray, int maxMessages)
{
    int messageCount = 0;

    for (int i = 0; i < this->mappings.size(); ++i)
    {
        if (messageCount >= maxMessages)
        {
            return -1;
        }

        if (this->mappings[i].flowDirection == 1 || this->mappings[i].flowDirection == 3)
        {
            auto currentObject = this->mappings[i].data;

            for (int j = 0; j < this->mappings[i].ccsdsFieldNames.size(); ++j)
            {
                Protobetter::ProtobetterFieldType fieldType = this->mappings[i].ccsdsFieldTypes[j];
                QString fieldName = this->mappings[i].ccsdsFieldNames[j];

                SimulateTimeStep(currentObject, fieldType, fieldName);
            }

            packetArray[i].SetMessageId(this->mappings[i].messageId);

            if (packetArray[i].GetPacketType() == QCcsdsPacket::Command &&
                    this->mappings[i].commandCode >= 0)
            {
                packetArray[i].SetCommandCode(this->mappings[i].commandCode);
            }

            packetArray[i].SetPayloadData(currentObject->Data(), currentObject->Size());
            messageCount++;
        }
    }

    return messageCount;
}

int SimulatedTrickBackend::WriteData(QCcsdsPacket &packet)
{
    for (int i = 0; i < this->mappings.size(); ++i)
    {
        if (this->mappings[i].messageId == packet.GetMessageId())
        {
            if (packet.GetPacketType() == QCcsdsPacket::Command)
            {
                if (this->mappings[i].commandCode == packet.GetCommandCode())
                {
                    this->mappings[i].data->SetData(packet.GetPayloadData());
                }
                else
                {
                    continue;
                }
            }
            else // it's telemetry
            {
                this->mappings[i].data->SetData(packet.GetPayloadData());
            }

            std::cout << "\n*** Recieved msgId = "
                      << QString::number(this->mappings[i].messageId, 16).toStdString();

            if (this->mappings[i].commandCode >= 0)
            {
                std::cout << ", cmdCode = " << this->mappings[i].commandCode << " ***\n" << std::endl;
            }
            else
            {
                std::cout << " ***\n" << std::endl;
            }

            PrintProtobetterData(this->mappings[i]);

            return 1;
        }
    }

    return -1;
}

