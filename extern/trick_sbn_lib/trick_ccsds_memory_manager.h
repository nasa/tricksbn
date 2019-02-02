#ifndef TRICK_CCSDSD_MEMORY_MANAGER_H
#define TRICK_CCSDSD_MEMORY_MANAGER_H

#include "trick_ccsds_mapping.h"

struct TRICK_SBN_LIBSHARED_EXPORT TrickFieldAccessor
{
    enum TrickType
    {
        Float,
        Double,
        Int,
        UInt

        // TODO: add bytearrays down the road *if* the user specifically requests it...
        // should be pretty simple using QByteArray & QVariant, but need to spend a day
        // doing some testing to make sure you fully understand the conversion behavior...
    };

    void* address;
    uint64_t size;

    TrickFieldAccessor::TrickType type;

    // the following should be '0' if this field is a non-bitfield member
    uint16_t bitOffset;
    uint16_t bitfieldSize;
};

class TRICK_SBN_LIBSHARED_EXPORT TrickMemoryManagerClient : public TrickCcsdsMappingClient
{
public:

    TrickMemoryManagerClient();
    ~TrickMemoryManagerClient();

    int Initialize(Protobetter::DynamicTypeCollection &prototypes, QJsonArray &trickVariableMappings);

    int ReadData(QCcsdsPacket *packetArray, int maxMessages) override;
    int WriteData(QCcsdsPacket &packet) override;

    QVariant GetData(TrickFieldAccessor &accessor);
    void SetData(TrickFieldAccessor &accessor, QVariant value);

private:

    // hash of <message ID, vector of TrickFieldAccessors>
    QHash<uint32_t, QVector<TrickFieldAccessor> > fieldAccessors;
};

#endif /* TRICK_CCSDSD_MEMORY_MANAGER_H */
