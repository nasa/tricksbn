#ifndef TRICK_CCSDS_MAPPING_H
#define TRICK_CCSDS_MAPPING_H

#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

#include <QString>
#include <QVector>

#include "protobetterdynamic.h"

#include "qsbn.h"

class TRICK_SBN_LIBSHARED_EXPORT TrickVariableMapping
{
public:

    QVariant GetProtobetterField(int memberIndex);
    void SetProtobetterField(int memberIndex, QVariant &value);

    static TrickVariableMapping FromJson(Protobetter::DynamicType::Ptr dynamicType, QJsonObject &data);

    QString cfsStructureType;
    uint32_t messageId;
    int32_t commandCode;
    uint8_t flowDirection; // 1 = trick->CFS, 2 = CFS->Trick, 3 = bi-directional

    // structure of arrays (SOA) pattern - so each mapping element is associated w/ an index into the following arrays...

    // TODO: also keep a list of QVector<Protobetter::FieldAccessor> here...
    // you can build this up during initialization and use it for > 40% faster
    // protobetter-encoded field access at runtime...
    QVector<QString> ccsdsFieldNames;
    QVector<Protobetter::ProtobetterFieldType> ccsdsFieldTypes;
    QVector<QString> trickFieldNames;
    QVector<QString> trickFieldTypes;

    Protobetter::DynamicObject::Ptr data;
};

class TRICK_SBN_LIBSHARED_EXPORT TrickCcsdsMappingClient
{
public:

    TrickCcsdsMappingClient();
    virtual ~TrickCcsdsMappingClient();

    virtual int Initialize(Protobetter::DynamicTypeCollection &prototypes, QJsonArray &trickVariableMappings);

    virtual int ReadData(QCcsdsPacket *packetArray, int maxMessages) = 0;
    virtual int WriteData(QCcsdsPacket &packet) = 0;

    QVector<uint32_t> GetInboundMids();

protected:

    QVector<TrickVariableMapping> mappings;
};
/*
class TRICK_SBN_LIBSHARED_EXPORT SimulatedTrickBackend : public TrickCcsdsMappingClient
{
public:

    SimulatedTrickBackend();
    ~SimulatedTrickBackend();

    int Initialize(Protobetter::DynamicTypeCollection &prototypes, QJsonArray &trickVariableMappings) override;

    int ReadData(QCcsdsPacket *packetArray, int maxMessages) override;
    int WriteData(QCcsdsPacket &packet) override;
};
*/
#endif // TRICK_CCSDS_MAPPING_H
