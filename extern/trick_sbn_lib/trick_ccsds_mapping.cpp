#include <stdexcept>
#include <iostream>

#include "trick_ccsds_mapping.h"

QVariant TrickVariableMapping::GetProtobetterField(int memberIndex)
{
    QVariant qv;

    switch (this->ccsdsFieldTypes[memberIndex])
    {
        case Protobetter::UInt8:
            qv = QVariant(this->data->GetUInt8(this->ccsdsFieldNames[memberIndex]));
            break;

        case Protobetter::UInt16:
            qv = QVariant(this->data->GetUInt16(this->ccsdsFieldNames[memberIndex]));
            break;

        case Protobetter::UInt32:
            qv = QVariant(this->data->GetUInt32(this->ccsdsFieldNames[memberIndex]));
            break;

        case Protobetter::UInt64:
            qv = QVariant::fromValue(this->data->GetUInt64(this->ccsdsFieldNames[memberIndex]));
            break;

        case Protobetter::Int8:
            qv = QVariant(this->data->GetInt8(this->ccsdsFieldNames[memberIndex]));
            break;

        case Protobetter::Int16:
            qv = QVariant(this->data->GetInt16(this->ccsdsFieldNames[memberIndex]));
            break;

        case Protobetter::Int32:
            qv = QVariant(this->data->GetInt32(this->ccsdsFieldNames[memberIndex]));
            break;

        case Protobetter::Int64:
            qv = QVariant::fromValue(this->data->GetInt64(this->ccsdsFieldNames[memberIndex]));
            break;

        case Protobetter::UnsignedBitfield:
            qv = QVariant::fromValue(this->data->GetUnsignedBitfield(this->ccsdsFieldNames[memberIndex]));
            break;

        case Protobetter::SignedBitfield:
            qv = QVariant::fromValue(this->data->GetSignedBitfield(this->ccsdsFieldNames[memberIndex]));
            break;

        case Protobetter::Float:
            qv = QVariant(this->data->GetFloat(this->ccsdsFieldNames[memberIndex]));
            break;

        case Protobetter::Double:
            qv = QVariant(this->data->GetDouble(this->ccsdsFieldNames[memberIndex]));
            break;

        default:
            // TODO: byte arrays...
            break;
    }

    return qv;
}

void TrickVariableMapping::SetProtobetterField(int memberIndex, QVariant &value)
{
    switch (this->ccsdsFieldTypes[memberIndex]) 
    {
        case Protobetter::UInt8:
            this->data->SetUInt8(this->ccsdsFieldNames[memberIndex], value.toUInt());
            break;

        case Protobetter::UInt16:
            this->data->SetUInt16(this->ccsdsFieldNames[memberIndex], value.toUInt());
            break;

        case Protobetter::UInt32:
            this->data->SetUInt32(this->ccsdsFieldNames[memberIndex], value.toUInt());
            break;

        case Protobetter::UInt64:
            this->data->SetUInt64(this->ccsdsFieldNames[memberIndex], value.toULongLong());
            break;

        case Protobetter::Int8:
            this->data->SetInt8(this->ccsdsFieldNames[memberIndex], value.toInt());
            break;

        case Protobetter::Int16:
            this->data->SetInt16(this->ccsdsFieldNames[memberIndex], value.toInt());
            break;

        case Protobetter::Int32:
            this->data->SetInt32(this->ccsdsFieldNames[memberIndex], value.toInt());
            break;

        case Protobetter::Int64:
            this->data->SetInt64(this->ccsdsFieldNames[memberIndex], value.toLongLong());
            break;

        case Protobetter::UnsignedBitfield:
            this->data->SetUnsignedBitfield(this->ccsdsFieldNames[memberIndex], value.toUInt());
            break;

        case Protobetter::SignedBitfield:
            this->data->SetSignedBitfield(this->ccsdsFieldNames[memberIndex], value.toInt());
            break;

        case Protobetter::Float:
            this->data->SetFloat(this->ccsdsFieldNames[memberIndex], value.toFloat());
            break;

        case Protobetter::Double:
            this->data->SetDouble(this->ccsdsFieldNames[memberIndex], value.toDouble());
            break;

        default:
            break;
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
    :debug(false)
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

