#include <QString>
#include <QtTest>

#include <QJSEngine>

#include <QFile>

#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

#include "qsbn.h"
#include "trick_ccsds_mapping.h"
#include "trick_ccsds_memory_manager.h"

#include "protobetterdynamic.h"

class TrickSbnTest : public QObject
{
    Q_OBJECT

public:
    TrickSbnTest();

private Q_SLOTS:

    void QVariantTest();

    void ConfigTest1();
    void ConfigTest2();
    void ConfigTest3();

    void QCcsdsPacketTest();
    void QSbnPacketTest();
    void QSbnSubscriptionPacketTest();

    void TrickVariableMappingTest();

    void TrickCcsdsMappingClientTest();
    void TrickCcsdsMemoryManagerClientTest();
};

TrickSbnTest::TrickSbnTest()
{
}

void TrickSbnTest::QVariantTest()
{
    // purpose of this test is to verify that this version of Qt's QVariant behavior is as expected
    typedef struct
    {
        int bitsA : 5;

    } QVariantTestData;

    // check float to double conversion
    QVariant floatVariant;
    float floatData = 12.3456f;

    floatVariant = floatData;

    double doubleData = -99.0;

    QVERIFY(qFuzzyCompare(doubleData, -99.0));

    doubleData = floatVariant.toDouble();

    QVERIFY(qFabs(doubleData - 12.3456) < 1e-06);

    // check float to int conversion
    int8_t int8Data = floatVariant.toInt();

    QCOMPARE(int8Data, 12);

    // test 8-byte integer to bitfield conversion
    int64_t int64Data = 11;
    QVariant int64Variant(int64Data);

    QVariantTestData testData;

    testData.bitsA = 7;
    QCOMPARE(testData.bitsA, 7);

    testData.bitsA = int64Variant.toInt();
    QCOMPARE(testData.bitsA, 11);
}

void TrickSbnTest::ConfigTest1()
{
    // load up default 'streaming' protocol config and verify it's valid
    QString configFilePath(":/data/test_json_data.tricksbn");

    QString configJsonData;
    QFile configFile(configFilePath);

    if (!configFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QFAIL("Failed to open default config file.");
    }

    configJsonData = configFile.readAll();

    QJsonDocument testConfigJsonDoc = QJsonDocument::fromJson(configJsonData.toUtf8());

    if (!testConfigJsonDoc.isObject())
    {
        QFAIL("Test config is not a valid JSON Object!");
    }

    auto testConfig = testConfigJsonDoc.object();

    QVERIFY(testConfig.contains("qsbnConfig"));
    QVERIFY(testConfig["qsbnConfig"].isObject());

    auto qsbnConfig = testConfig["qsbnConfig"].toObject();

    QSbn mySbn(qsbnConfig);

    QSbnPeer peerInfoContainer;

    QCOMPARE(mySbn.GetPeerInfo(8675309, peerInfoContainer), -1);

    QCOMPARE(mySbn.GetPeerInfo(2, peerInfoContainer), 1);
    QCOMPARE(peerInfoContainer.port, 15821);
}

void TrickSbnTest::ConfigTest2()
{
    /*
     * Load up default config and verify it's valid JSON
     *
     * */

    QString configFilePath(":/data/test_json_data.tricksbn");

    QString configJsonData;
    QFile configFile(configFilePath);

    if (!configFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QFAIL("Failed to open default config file.");
    }

    configJsonData = configFile.readAll();

    QJsonDocument testConfigJsonDoc = QJsonDocument::fromJson(configJsonData.toUtf8());

    if (!testConfigJsonDoc.isObject())
    {
        QFAIL("Test config is not a valid JSON Object!");
    }

    /*
     *  Verify that you can find the QSbnPeer config, QSbn config, the message instance list.
     *
     * */

    QJsonObject appConfig = testConfigJsonDoc.object();

    QVERIFY(appConfig.contains("qsbnConfig"));

    QVERIFY(appConfig.contains("qsbnJsonMessages"));
    QVERIFY(appConfig["qsbnJsonMessages"].isArray());

    /*
     *  Process the protobetter messages the user defined
     *
     * */

    // TODO: validation bruh?
    QJsonDocument prototypeDefs = QJsonDocument(appConfig["prototypes"].toArray());

    Protobetter::PrototypeCollection prototypes;

    prototypes.LoadPrototypesFromPType(prototypeDefs);

    QVERIFY(!prototypes.HasType("bob"));
    QVERIFY(prototypes.HasType("Vector_c"));
    QVERIFY(prototypes.HasType("LilBity_c"));
    QVERIFY(prototypes.HasType("Bittylicious_c"));

    /*
     *  Process the json messages the user defined
     *
     * */

    QJsonArray jsonMessages = appConfig["qsbnJsonMessages"].toArray();

    QJSEngine myEngine;
    myEngine.installExtensions(QJSEngine::AllExtensions);

    QJSValue deserializeJson = myEngine.evaluate("function(jsonData) { return JSON.parse(jsonData) }");
    QJSValue serializeJson = myEngine.evaluate("function(jsObj) { return JSON.stringify(jsObj) }");

    /*
     * Verify the first message contents and the transform logic works...
     *
     * */

    QString jsonMessageData = QString(QJsonDocument(jsonMessages.at(0).toObject()).toJson());

    QJSValue jsonMessage = deserializeJson.call(QJSValueList() << jsonMessageData);

    QVERIFY(jsonMessage.hasProperty("op"));
    QVERIFY(jsonMessage.hasProperty("messageId"));
    QVERIFY(jsonMessage.hasProperty("payloadObject"));
    QVERIFY(jsonMessage.hasProperty("processMessage"));

    QString jsonMessageTransformBody = jsonMessage.property("processMessage").toString();

    QJSValue processMessageFunction = myEngine.evaluate("function(payloadObject) { " + jsonMessageTransformBody + " }");

    if (processMessageFunction.isError())
    {
        QFAIL("Error interpreting user-supplied process message function!");
    }

    QJSValue messagePayload = jsonMessage.property("payloadObject");

    // check payload contents before the transform
    QCOMPARE(messagePayload.property("name").toString(), "bob");
    QCOMPARE(messagePayload.property("age").toInt(), 42);

    QJSValue transformResult = processMessageFunction.call(QJSValueList() << messagePayload);

    if (transformResult.isError())
    {
        QFAIL("Error calling user-supplied process message function!");
    }

    // check payload contents after the transform
    QCOMPARE(messagePayload.property("name").toString(), "chris");
    QCOMPARE(messagePayload.property("age").toInt(), 43);

    /*
     * Verify the second message contents and the transform logic works...
     *
     * */

    jsonMessageData = QString(QJsonDocument(jsonMessages.at(1).toObject()).toJson());

    jsonMessage = deserializeJson.call(QJSValueList() << jsonMessageData);

    QVERIFY(jsonMessage.hasProperty("op"));
    QVERIFY(jsonMessage.hasProperty("messageId"));
    QVERIFY(jsonMessage.hasProperty("payloadObject"));
    QVERIFY(jsonMessage.hasProperty("processMessage"));

    jsonMessageTransformBody = jsonMessage.property("processMessage").toString();

    processMessageFunction = myEngine.evaluate("function(payloadObject) { " + jsonMessageTransformBody + " }");

    if (processMessageFunction.isError())
    {
        QFAIL("Error interpreting transform function for message!");
    }

    messagePayload = jsonMessage.property("payloadObject");

    // check payload contents before the transform
    QCOMPARE(messagePayload.property("animal").toString(), "dog");
    QCOMPARE(messagePayload.property("age").toInt(), 6);
    QVERIFY(qFuzzyCompare(messagePayload.property("weight").toNumber(), 34.2));

    transformResult = processMessageFunction.call(QJSValueList() << messagePayload);

    if (transformResult.isError())
    {
        QFAIL("Error calling user-supplied process message function!");
    }

    // check payload contents after the transform
    QCOMPARE(messagePayload.property("animal").toString(), "cat");
    QCOMPARE(messagePayload.property("age").toInt(), 7);
    QVERIFY(qFuzzyCompare(messagePayload.property("weight").toNumber(), 41.2));
}

void TrickSbnTest::ConfigTest3()
{

}

void TrickSbnTest::QCcsdsPacketTest()
{
    // cmd mids: 0xfe44-0xfe4e
    // tlm mids: 0x7e6a-0x7e6d

    QCcsdsPacket *packets = new QCcsdsPacket[4];

    QString payload("The quick brown fox jumps over the lazy dog");

    // save off the initial header length
    int16_t telemetryHeaderLength = packets[0].GetHeaderLength();

    for (int i = 0; i < 3; ++i)
    {
        QCOMPARE(packets[i].GetMessageId(), 0x7e6a);
        QCOMPARE(packets[i].GetPayloadLength(), 0);
        QCOMPARE(packets[i].GetPacketType(), QCcsdsPacket::Telemetry);

        packets[i].SetMessageId(0x0F1A);

        // save off the initial start address of payload
        const char *oldPayloadAddress = packets[i].GetPayloadData();

        // set the payload
        packets[i].SetPayloadData(payload.toStdString().c_str(), payload.size() + 1);
        QCOMPARE(packets[i].GetPayloadData(), payload.toStdString().c_str());

        // change to a cmd packet and verify contents get moved correctly
        packets[i].SetMessageId(0xfe44);

        int16_t commandHeaderLength = packets[i].GetHeaderLength();

        QVERIFY(commandHeaderLength < telemetryHeaderLength);

        // verify that the payload was moved by the difference of tlm/cmd header lengths
        QCOMPARE(oldPayloadAddress - packets[i].GetPayloadData(), telemetryHeaderLength - commandHeaderLength);

        // verify the contents are not corrupted
        QCOMPARE(packets[i].GetPayloadData(), payload.toStdString().c_str());

        packets[i].SetMessageId(0x7e6b);

        QCOMPARE(packets[i].GetPayloadData(), payload.toStdString().c_str());
        QCOMPARE(oldPayloadAddress, packets[i].GetPayloadData());
    }

    for (int i = 0; i < 3; ++i)
    {
        packets[i] = packets[3];

        for (int j = 0; j < QSBN_MAX_CCSDS_PACKET_SIZE; ++j)
        {
            QCOMPARE(packets[i].GetPacketData()[j], packets[3].GetPacketData()[j]);
        }
    }
}

void TrickSbnTest::QSbnPacketTest()
{
    QSbnPacket *packets = new QSbnPacket[4];

    QString payload("The quick brown fox buddy");

    for (int i = 0; i < 3; ++i)
    {
        QCOMPARE(packets[i].GetPacketType(), QSbnPacket::SBN_NO_MSG);
        QCOMPARE(packets[i].GetCpuId(), 0);
        QCOMPARE(packets[i].GetHeaderLength(), 7);
        QCOMPARE(packets[i].GetPayloadLength(), 0);
        QCOMPARE(packets[i].GetPacketLength(), 7);

        packets[i].SetCpuId(i);
        packets[i].SetPacketType(QSbnPacket::SBN_APP_MSG);
        packets[i].SetPayloadData(payload.toStdString().c_str(), payload.length()+1);

        QCOMPARE(packets[i].GetPacketType(), QSbnPacket::SBN_APP_MSG);
        QCOMPARE(packets[i].GetCpuId(), i);
        QCOMPARE(packets[i].GetHeaderLength(), 7);
        QCOMPARE(packets[i].GetPayloadLength(), payload.length() + 1);
        QCOMPARE(packets[i].GetPacketLength(), payload.length() + 1 + 7);
    }

    for (int i = 0; i < 4; ++i)
    {
        packets[i] = packets[3];

        for (int j = 0; j < QSBN_MAX_SBN_PACKET_SIZE; ++j)
        {
            QCOMPARE(packets[i].GetPacketType(), QSbnPacket::SBN_NO_MSG);
            QCOMPARE(packets[i].GetCpuId(), 0);
            QCOMPARE(packets[i].GetHeaderLength(), 7);
            QCOMPARE(packets[i].GetPayloadLength(), 0);
            QCOMPARE(packets[i].GetPacketLength(), 7);
        }
    }
}

void TrickSbnTest::QSbnSubscriptionPacketTest()
{
    QSbnPeer a(42, "192.168.2.15", 15821);

    for (int i = 0; i < 10; ++i)
    {
        a.subscriptionMids.push_back(69 + i);
    }

    QSbnPeer b;

    b = a;
    a.subscriptionMids.clear();

    QCOMPARE(a.cpuId, b.cpuId);
    QCOMPARE(a.ipAddress, b.ipAddress);
    QCOMPARE(a.port, b.port);

    QCOMPARE(a.subscriptionMids.size(), 0);
    QCOMPARE(b.subscriptionMids.size(), 10);

    for (int i = 0; i < 10; ++i)
    {
        QCOMPARE(b.IsSubscribedToMessageId(69 + i), true);
        QCOMPARE(b.IsSubscribedToMessageId(49 + i), false);
    }

    auto subs = b.ToSubscriptionPacket();

    QCOMPARE(subs->GetSubscriptionCount(), b.subscriptionMids.size());

    for (int i = 0; i < 10; ++i)
    {
        QCOMPARE(subs->GetSubscriptionAt(i), 69+i);
    }

    subs->RemoveSubscription(70);
    subs->RemoveSubscription(71);

    QCOMPARE(subs->GetSubscriptionCount(), 8);

    QCOMPARE(subs->GetSubscriptionAt(0), 69);

    for (int i = 1; i < 8; ++i)
    {
        QCOMPARE(subs->GetSubscriptionAt(i), 71+i);
    }
}

void TrickSbnTest::TrickVariableMappingTest()
{
    // load up default 'streaming' protocol config and verify it's valid
    QString configFilePath(":/data/default_config.tricksbn");

    QString configJsonData;
    QFile configFile(configFilePath);

    if (!configFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QFAIL("Failed to open default config file.");
    }

    configJsonData = configFile.readAll();

    QJsonDocument testConfigJsonDoc = QJsonDocument::fromJson(configJsonData.toUtf8());

    if (!testConfigJsonDoc.isObject())
    {
        QFAIL("Test config is not a valid JSON Object!");
    }

    auto trickSbnConfig = testConfigJsonDoc.object();

    auto prototypeDefs = QJsonDocument(trickSbnConfig["prototypes"].toArray());

    Protobetter::PrototypeCollection prototypes;
    prototypes.LoadPrototypesFromPType(prototypeDefs);

    auto dynamicTypes = Protobetter::DynamicTypeCollection::FromPrototypeCollection(prototypes);

    auto trickVariableMappings = trickSbnConfig["trickVariableMappings"].toArray();

    QCOMPARE(trickVariableMappings.size(), 1);

    auto mappingData = trickVariableMappings.at(0).toObject();

    QString cfsStructureType = mappingData["cfsStructureType"].toString();

    auto dynamicType = dynamicTypes.GetType(cfsStructureType);

    TrickVariableMapping newMapping = TrickVariableMapping::FromJson(dynamicType, mappingData);

    QCOMPARE(newMapping.messageId, QString("0x7e6a").toUInt(nullptr, 16));

    QCOMPARE(newMapping.ccsdsFieldNames[0], "b[0].e[0].x");
    QCOMPARE(newMapping.ccsdsFieldTypes[0], Protobetter::Float);
    QCOMPARE(newMapping.trickFieldNames[0], "var1");
    QCOMPARE(newMapping.trickFieldTypes[0], "double");

    QCOMPARE(newMapping.ccsdsFieldNames[1], "c[1]");
    QCOMPARE(newMapping.ccsdsFieldTypes[1], Protobetter::Int16);
    QCOMPARE(newMapping.trickFieldNames[1], "var2");
    QCOMPARE(newMapping.trickFieldTypes[1], "int");

    QVERIFY(qFuzzyCompare(newMapping.GetProtobetterField(0).toFloat(), 0.0f));
    QCOMPARE(newMapping.GetProtobetterField(1).toUInt(), 0);

    QVariant floatVariant(12.3456f);
    QVariant uintVariant(69);

    newMapping.SetProtobetterField(0, floatVariant);
    newMapping.SetProtobetterField(1, uintVariant);

    QVERIFY(qFuzzyCompare(newMapping.GetProtobetterField(0).toFloat(), 12.3456f));
    QCOMPARE(newMapping.GetProtobetterField(1).toUInt(), 69);
}

void TrickSbnTest::TrickCcsdsMappingClientTest()
{
    // load up default 'streaming' protocol config and verify it's valid
    QString configFilePath(":/data/default_config.tricksbn");

    QString configJsonData;
    QFile configFile(configFilePath);

    if (!configFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QFAIL("Failed to open default config file.");
    }

    configJsonData = configFile.readAll();

    QJsonDocument testConfigJsonDoc = QJsonDocument::fromJson(configJsonData.toUtf8());

    if (!testConfigJsonDoc.isObject())
    {
        QFAIL("Test config is not a valid JSON Object!");
    }

    auto trickSbnConfig = testConfigJsonDoc.object();

    auto prototypeDefs = QJsonDocument(trickSbnConfig["prototypes"].toArray());

    Protobetter::PrototypeCollection prototypes;
    prototypes.LoadPrototypesFromPType(prototypeDefs);

    auto dynamicTypes = Protobetter::DynamicTypeCollection::FromPrototypeCollection(prototypes);

    auto trickVariableMappings = trickSbnConfig["trickVariableMappings"].toArray();

    QCOMPARE(trickVariableMappings.size(), 1);

    TrickCcsdsMappingClient *client = new SimulatedTrickBackend();
    client->Initialize(dynamicTypes, trickVariableMappings);

    QCcsdsPacket ccsdsPackets[10];

    auto bittyliciousType = dynamicTypes.GetType("Bittylicious_c");

    Protobetter::DynamicObject::Ptr bittyliciousInstance(new Protobetter::DynamicObject(bittyliciousType));

    bittyliciousInstance->SetData(ccsdsPackets[0].GetPacketData());

    QCOMPARE(bittyliciousInstance->GetInt16("c[1]"), 0);
    QVERIFY(qFuzzyCompare(bittyliciousInstance->GetFloat("b[0].e[0].x"), 0.0f));

    int messages = client->ReadData(ccsdsPackets, 10);

    QCOMPARE(messages, 1);

    QCOMPARE(ccsdsPackets[0].GetMessageId(), 0x7e6a);

    messages = client->WriteData(ccsdsPackets[0]);

    bittyliciousInstance->SetData(ccsdsPackets[0].GetPayloadData());

    QCOMPARE(bittyliciousInstance->GetInt16("c[1]"), 1);
    QVERIFY(qFuzzyCompare(bittyliciousInstance->GetFloat("b[0].e[0].x"), 1.1f));

    delete client;
}

void TrickSbnTest::TrickCcsdsMemoryManagerClientTest()
{
    // load up default 'streaming' protocol config and verify it's valid
    QString configFilePath(":/data/default_config.tricksbn");

    QString configJsonData;
    QFile configFile(configFilePath);

    if (!configFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QFAIL("Failed to open default config file.");
    }

    configJsonData = configFile.readAll();

    QJsonDocument testConfigJsonDoc = QJsonDocument::fromJson(configJsonData.toUtf8());

    if (!testConfigJsonDoc.isObject())
    {
        QFAIL("Test config is not a valid JSON Object!");
    }

    auto trickSbnConfig = testConfigJsonDoc.object();

    auto prototypeDefs = QJsonDocument(trickSbnConfig["prototypes"].toArray());

    Protobetter::PrototypeCollection prototypes;
    prototypes.LoadPrototypesFromPType(prototypeDefs);

    auto dynamicTypes = Protobetter::DynamicTypeCollection::FromPrototypeCollection(prototypes);

    auto trickVariableMappings = trickSbnConfig["trickVariableMappings"].toArray();

    QCOMPARE(trickVariableMappings.size(), 1);

    TrickMemoryManagerClient *client = new TrickMemoryManagerClient();
    client->Initialize(dynamicTypes, trickVariableMappings);

    QCcsdsPacket ccsdsPackets[10];

    auto bittyliciousType = dynamicTypes.GetType("Bittylicious_c");

    Protobetter::DynamicObject::Ptr bittyliciousInstance(new Protobetter::DynamicObject(bittyliciousType));

    bittyliciousInstance->SetData(ccsdsPackets[0].GetPacketData());

    QCOMPARE(bittyliciousInstance->GetInt16("c[1]"), 0);
    QVERIFY(qFuzzyCompare(bittyliciousInstance->GetFloat("b[0].e[0].x"), 0.0f));

    char *startAddress = (char*)bittyliciousInstance->Data();

    TrickFieldAccessor b0_e0_x_Accessor;
    Protobetter::FieldAccessor tmp = bittyliciousType->GetMemberMap()->value("b[0].e[0].x");

    b0_e0_x_Accessor.address = tmp.byteOffset + startAddress;
    b0_e0_x_Accessor.size = 4;
    b0_e0_x_Accessor.type = TrickFieldAccessor::Float;
    b0_e0_x_Accessor.bitfieldSize = b0_e0_x_Accessor.bitOffset = 0;

    TrickFieldAccessor c1_Accessor;
    tmp = bittyliciousType->GetMemberMap()->value("c[1]");

    c1_Accessor.address = tmp.byteOffset + startAddress;
    c1_Accessor.size = 2;
    c1_Accessor.type = TrickFieldAccessor::UInt;
    c1_Accessor.bitOffset = c1_Accessor.bitfieldSize = 0;

    float test_b0_e0_x_Data = 12.345f;
    uint16_t test_c1_Data = 42;

    float test_b0_e0_x_Data_BE;
    uint16_t test_c1_Data_BE = qToBigEndian<quint16>(test_c1_Data);

    uint32_t temp32;
    memcpy(&temp32, &test_b0_e0_x_Data, 4);
    temp32 = qToBigEndian<quint32>(temp32);
    memcpy(&test_b0_e0_x_Data_BE, &temp32, 4);

    client->SetData(b0_e0_x_Accessor, QVariant(test_b0_e0_x_Data_BE));
    client->SetData(c1_Accessor, QVariant(test_c1_Data_BE));

    QVERIFY(qFuzzyCompare(client->GetData(b0_e0_x_Accessor).toFloat(), test_b0_e0_x_Data_BE));
    QCOMPARE(client->GetData(c1_Accessor).toUInt(), test_c1_Data_BE);

    QVERIFY(qFuzzyCompare(bittyliciousInstance->GetFloat("b[0].e[0].x"), 12.345f));
    QCOMPARE(bittyliciousInstance->GetUInt16("c[1]"), 42);

    delete client;
}

QTEST_GUILESS_MAIN(TrickSbnTest)

#include "tst_tricksbntest.moc"
