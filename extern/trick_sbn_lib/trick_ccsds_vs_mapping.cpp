#include "trick_ccsds_vs_mapping.h"

namespace {

    QString SetVariableServerFieldMessage(QString trickFieldName, QString trickFieldType, QVariant value)
    {
        if (trickFieldType == "float" || trickFieldType == "double")
        {

        }
        else if (trickFieldType == "int")
        {

        }
        else if (trickFieldType == "uint")
        {

        }

        return QString("");
    }

    int64_t GetInt(char *buffer, uint16_t size)
    {
        int64_t value;

        if (size == 1)
        {
            int8_t tmp;

            memcpy(&tmp, buffer, 1);

            value = tmp;
        }
        else if (size == 2)
        {
            int16_t tmp;

            memcpy(&tmp, buffer, 2);

            value = tmp;
        }
        else if (size == 4)
        {
            int32_t tmp;

            memcpy(&tmp, buffer, 4);

            value = tmp;
        }
        else if (size == 8)
        {
            int64_t tmp;

            memcpy(&tmp, buffer, 8);

            value = tmp;
        }

        return value;
    }

    uint64_t GetUInt(char *buffer, uint16_t size)
    {
        uint64_t value;

        if (size == 1)
        {
            uint8_t tmp;

            memcpy(&tmp, buffer, 1);

            value = tmp;
        }
        else if (size == 2)
        {
            uint16_t tmp;

            memcpy(&tmp, buffer, 2);

            value = tmp;
        }
        else if (size == 4)
        {
            uint32_t tmp;

            memcpy(&tmp, buffer, 4);

            value = tmp;
        }
        else if (size == 8)
        {
            uint64_t tmp;

            memcpy(&tmp, buffer, 8);

            value = tmp;
        }

        return value;
    }

    float GetFloat(char *buffer)
    {
        float value;

        memcpy(&value, buffer, 4);

        return value;
    }

    double GetDouble(char *buffer)
    {
        double value;

        memcpy(&value, buffer, 8);

        return value;
    }

}

TrickVariableServerClient::TrickVariableServerClient(QString variableServerIp, uint16_t variableServerPort)
    : variableServerIp(variableServerIp), variableServerPort(variableServerPort)
{
}

TrickVariableServerClient::~TrickVariableServerClient()
{

}

int TrickVariableServerClient::Initialize(Protobetter::DynamicTypeCollection &prototypes, QJsonArray &trickVariableMappings)
{
    TrickCcsdsMappingClient::Initialize(prototypes, trickVariableMappings);

    /*
     *  TODO:
     *
     *      1) you need to compute the number of variables here...
     *      2) need to create variable server connection and setup the subscriptions
     *
     * */

    return -1;
}

int TrickVariableServerClient::ReadData(QCcsdsPacket *packetArray, int maxMessages)
{
    return -1;
}

int TrickVariableServerClient::WriteData(QCcsdsPacket &packet)
{
    return -1;
}

