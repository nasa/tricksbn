#ifndef TRICK_CCSDS_VS_MAPPING_H
#define TRICK_CCSDS_VS_MAPPING_H

#include "trick_ccsds_mapping.h"

class TRICK_SBN_LIBSHARED_EXPORT TrickVariableServerClient : public TrickCcsdsMappingClient
{
public:

    TrickVariableServerClient(QString variableServerIp, uint16_t variableServerPort);
    ~TrickVariableServerClient();

    int Initialize(Protobetter::DynamicTypeCollection &prototypes, QJsonArray &trickVariableMappings) override;

    int ReadData(QCcsdsPacket *packetArray, int maxMessages) override;
    int WriteData(QCcsdsPacket &packet) override;

private:

    QString variableServerIp;
    uint16_t variableServerPort;

    uint16_t numberOfVariables;
};

#endif // TRICK_CCSDS_VS_MAPPING_H
