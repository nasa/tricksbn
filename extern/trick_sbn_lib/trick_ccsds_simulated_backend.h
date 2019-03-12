#ifndef TRICK_CCSDS_SIMULATED_BACKEND_H
#define TRICK_CCSDS_SIMULATED_BACKEND_H

#include "trick_ccsds_mapping.h"

class TRICK_SBN_LIBSHARED_EXPORT SimulatedTrickBackend : public TrickCcsdsMappingClient
{
public:

    SimulatedTrickBackend();
    ~SimulatedTrickBackend();

    int Initialize(Protobetter::DynamicTypeCollection &prototypes, QJsonArray &trickVariableMappings) override;

    int ReadData(QCcsdsPacket *packetArray, int maxMessages) override;
    int WriteData(QCcsdsPacket &packet) override;
};

#endif // TRICK_CCSDS_SIMULATED_BACKEND_H
