#include <stdexcept>
#include <iostream>

#include "trick_ccsds_mapping.h"

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
            else if (mapping.ccsdsFieldTypes[i] == Protobetter::Int16)
            {
                uint16_t value = mapping.data->GetUInt16(mapping.ccsdsFieldNames[i]);

                std::cout << " - " << mapping.ccsdsFieldNames[i].toStdString() << " = " << value << std::endl;
            }
        }

        std::cout << std::endl;
    }

}

QVariant TrickVariableMapping::GetProtobetterField(int memberIndex)
{
    if (this->ccsdsFieldTypes[memberIndex] == Protobetter::UInt8)
    {
        return QVariant(this->data->GetUInt8(this->ccsdsFieldNames[memberIndex]));
    }
    else if (this->ccsdsFieldTypes[memberIndex] == Protobetter::UInt16)
    {
        return QVariant(this->data->GetUInt16(this->ccsdsFieldNames[memberIndex]));
    }
    else if (this->ccsdsFieldTypes[memberIndex] == Protobetter::UInt32)
    {
        return QVariant(this->data->GetUInt32(this->ccsdsFieldNames[memberIndex]));
    }
    else if (this->ccsdsFieldTypes[memberIndex] == Protobetter::UInt64)
    {
        return QVariant::fromValue(this->data->GetUInt64(this->ccsdsFieldNames[memberIndex]));
    }
    else if (this->ccsdsFieldTypes[memberIndex] == Protobetter::Int8)
    {
        return QVariant(this->data->GetInt8(this->ccsdsFieldNames[memberIndex]));
    }
    else if (this->ccsdsFieldTypes[memberIndex] == Protobetter::Int16)
    {
        return QVariant(this->data->GetInt16(this->ccsdsFieldNames[memberIndex]));
    }
    else if (this->ccsdsFieldTypes[memberIndex] == Protobetter::Int32)
    {
        return QVariant(this->data->GetInt32(this->ccsdsFieldNames[memberIndex]));
    }
    else if (this->ccsdsFieldTypes[memberIndex] == Protobetter::Int64)
    {
        return QVariant::fromValue(this->data->GetInt64(this->ccsdsFieldNames[memberIndex]));
    }
    else if (this->ccsdsFieldTypes[memberIndex] == Protobetter::UnsignedBitfield)
    {
        return QVariant::fromValue(this->data->GetUnsignedBitfield(this->ccsdsFieldNames[memberIndex]));
    }
    else if (this->ccsdsFieldTypes[memberIndex] == Protobetter::SignedBitfield)
    {
        return QVariant::fromValue(this->data->GetSignedBitfield(this->ccsdsFieldNames[memberIndex]));
    }
    else if (this->ccsdsFieldTypes[memberIndex] == Protobetter::Float)
    {
        return QVariant(this->data->GetFloat(this->ccsdsFieldNames[memberIndex]));
    }
    else if (this->ccsdsFieldTypes[memberIndex] == Protobetter::Double)
    {
        return QVariant(this->data->GetDouble(this->ccsdsFieldNames[memberIndex]));
    }
    // TODO: byte arrays...

    return QVariant();
}

void TrickVariableMapping::SetProtobetterField(int memberIndex, QVariant &value)
{
    if (this->ccsdsFieldTypes[memberIndex] == Protobetter::UInt8)
    {
        this->data->SetUInt8(this->ccsdsFieldNames[memberIndex], value.toUInt());
    }
    else if (this->ccsdsFieldTypes[memberIndex] == Protobetter::UInt16)
    {
        this->data->SetUInt16(this->ccsdsFieldNames[memberIndex], value.toUInt());
    }
    else if (this->ccsdsFieldTypes[memberIndex] == Protobetter::UInt32)
    {
        this->data->SetUInt32(this->ccsdsFieldNames[memberIndex], value.toUInt());
    }
    else if (this->ccsdsFieldTypes[memberIndex] == Protobetter::UInt64)
    {
        this->data->SetUInt64(this->ccsdsFieldNames[memberIndex], value.toULongLong());
    }
    else if (this->ccsdsFieldTypes[memberIndex] == Protobetter::Int8)
    {
        this->data->SetInt8(this->ccsdsFieldNames[memberIndex], value.toInt());
    }
    else if (this->ccsdsFieldTypes[memberIndex] == Protobetter::Int16)
    {
        this->data->SetInt16(this->ccsdsFieldNames[memberIndex], value.toInt());
    }
    else if (this->ccsdsFieldTypes[memberIndex] == Protobetter::Int32)
    {
        this->data->SetInt32(this->ccsdsFieldNames[memberIndex], value.toInt());
    }
    else if (this->ccsdsFieldTypes[memberIndex] == Protobetter::Int64)
    {
        this->data->SetInt64(this->ccsdsFieldNames[memberIndex], value.toLongLong());
    }
    else if (this->ccsdsFieldTypes[memberIndex] == Protobetter::UnsignedBitfield)
    {
        this->data->SetUnsignedBitfield(this->ccsdsFieldNames[memberIndex], value.toUInt());
    }
    else if (this->ccsdsFieldTypes[memberIndex] == Protobetter::SignedBitfield)
    {
        this->data->SetSignedBitfield(this->ccsdsFieldNames[memberIndex], value.toInt());
    }
    else if (this->ccsdsFieldTypes[memberIndex] == Protobetter::Float)
    {
        this->data->SetFloat(this->ccsdsFieldNames[memberIndex], value.toFloat());
    }
    else if (this->ccsdsFieldTypes[memberIndex] == Protobetter::Double)
    {
        this->data->SetDouble(this->ccsdsFieldNames[memberIndex], value.toDouble());
    }
}

TrickVariableMapping TrickVariableMapping::FromJson(Protobetter::DynamicType::Ptr dynamicType, QJsonObject &data)
{
    TrickVariableMapping newMapping;
    newMapping.cfsStructureType = data["cfsStructureType"].toString();
    newMapping.messageId = data["messageId"].toString().toUInt(nullptr, 16);
    newMapping.flowDirection = data["flowDirection"].toInt();

    auto fieldCollection = dynamicType.staticCast<Protobetter::FieldCollection>();

    newMapping.data.reset(new Protobetter::DynamicObject(dynamicType));

    auto membersData = data["members"].toArray();

    for (int j = 0; j < membersData.size(); ++j)
    {
        auto currentMemberData = membersData.at(j);

        QString cfsFieldName = currentMemberData["cfsVar"].toString();

        newMapping.ccsdsFieldNames.push_back(cfsFieldName);
        newMapping.ccsdsFieldTypes.push_back(fieldCollection->GetFieldType(cfsFieldName));

        newMapping.trickFieldNames.push_back(currentMemberData["trickVar"].toString());
        newMapping.trickFieldTypes.push_back(currentMemberData["trickType"].toString());
    }

    return newMapping;
}

TrickCcsdsMappingClient::TrickCcsdsMappingClient()
{

}

TrickCcsdsMappingClient::~TrickCcsdsMappingClient()
{

}

int TrickCcsdsMappingClient::Initialize(Protobetter::DynamicTypeCollection &prototypes, QJsonArray &trickVariableMappings)
{
    for (int i = 0; i < trickVariableMappings.size(); ++i)
    {
        auto currentMappingData = trickVariableMappings.at(i).toObject();
        auto dynamicType = prototypes.GetType(currentMappingData["cfsStructureType"].toString());

        this->mappings.push_back(TrickVariableMapping::FromJson(dynamicType, currentMappingData));
    }

    return -1;
}

QVector<uint32_t> TrickCcsdsMappingClient::GetInboundMids()
{
    QVector<uint32_t> mids;

    for (int i = 0; i < this->mappings.size(); ++i)
    {
        if (this->mappings[i].flowDirection == 2 || this->mappings[i].flowDirection == 3)
        {
            mids.push_back(this->mappings[i].messageId);
        }
    }

    return mids;
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

