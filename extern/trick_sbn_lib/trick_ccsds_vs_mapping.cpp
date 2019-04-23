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

}

TrickVariableServerClient::TrickVariableServerClient(QString variableServerIp, uint16_t variableServerPort)
    : variableServerIp(variableServerIp), variableServerPort(variableServerPort), numberOfVariables(0)
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

