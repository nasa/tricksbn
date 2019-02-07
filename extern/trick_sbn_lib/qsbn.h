#ifndef QSBNLIB_H
#define QSBNLIB_H

#include <vector>
#include <cstring>

#include <QHostAddress>
#include <QUdpSocket>

#include <QSharedPointer>

#include "trick_sbn_lib_global.h"

#define QSBN_VERSION_INFO "$123TODO:putsomethinghere456789"

/*
 *  Configurable params here can be overriden in calling application's code
 *
 * */

#ifndef QSBN_MAX_CCSDS_PACKET_SIZE
    #define QSBN_MAX_CCSDS_PACKET_SIZE 32768
#endif

#ifndef QSBN_MAX_SBN_PACKET_SIZE
#define QSBN_MAX_SBN_PACKET_SIZE (QSBN_MAX_CCSDS_PACKET_SIZE + 7)
#endif

/*
 * CCSDS Packet Type
 *
 * */

class TRICK_SBN_LIBSHARED_EXPORT QCcsdsPacket
{
public:

    enum PacketType
    {
        Telemetry,
        Command
    };

    QCcsdsPacket(const uint32_t messageId = 0x7e6a,
                  const uint16_t payloadLength = 0, const char *payload = nullptr);
    QCcsdsPacket(const QCcsdsPacket &other);

    ~QCcsdsPacket();

    QCcsdsPacket operator=(const QCcsdsPacket &other);

    uint32_t GetMessageId() const;
    uint16_t GetCommandCode() const;

    uint16_t GetPacketLength() const;
    uint16_t GetHeaderLength() const;
    uint16_t GetPayloadLength() const;

    const char * GetPacketData() const;
    const char * GetPayloadData() const;

    QCcsdsPacket::PacketType GetPacketType() const;

    void SetMessageId(const uint32_t messageId);
    void SetCommandCode(const uint16_t cmdCode);

    void SetPacketData(const char *data, const uint16_t packetLength);
    void SetPayloadData(const char *data, const uint16_t payloadLength);

private:

    char data[QSBN_MAX_CCSDS_PACKET_SIZE];
};


/*
 *  SBN Subscription Packet
 *
 * */

class TRICK_SBN_LIBSHARED_EXPORT QSbnSubscriptionPacket
{
public:

    QSbnSubscriptionPacket();
    QSbnSubscriptionPacket(const char *versionInfo, int length);
    QSbnSubscriptionPacket(const QSbnSubscriptionPacket &other);

    ~QSbnSubscriptionPacket();

    QSbnSubscriptionPacket operator=(const QSbnSubscriptionPacket &other);

    const char * GetVersionInfo() const;
    uint16_t GetSubscriptionCount() const;

    void SetVersionInfo(const char *versionInfo);

    uint32_t GetSubscriptionAt(int index);

    int AddSubscription(uint32_t messageId, uint16_t qos = 0);
    int RemoveSubscription(uint32_t messageId);

    uint16_t GetPacketLength() const;
    const char * GetPacketData() const;

    int SetPacketData(const char *data, const uint16_t length);

private:

    char data[QSBN_MAX_SBN_PACKET_SIZE - 7];
};

/*
 *  SBN Packet Type
 *
 * */

class TRICK_SBN_LIBSHARED_EXPORT QSbnPacket
{
public:

    enum PacketType
    {
        SBN_NO_MSG = 0x0,
        SBN_SUB_MSG = 0x1,
        SBN_APP_MSG = 0x3,

        SBN_HEARTBEAT_MSG = 0xA0
    };

    QSbnPacket(const QSbnPacket::PacketType type = QSbnPacket::SBN_NO_MSG);
    QSbnPacket(const uint32_t cpuId, const QSbnPacket::PacketType type,
               const uint16_t payloadLength);
    QSbnPacket(const QSbnPacket &other);

    ~QSbnPacket();

    QSbnPacket operator=(const QSbnPacket &other);

    uint16_t GetPacketLength() const;
    uint16_t GetHeaderLength() const;
    uint16_t GetPayloadLength() const;
    QSbnPacket::PacketType GetPacketType() const;
    uint32_t GetCpuId() const;

    const char * GetPacketData() const;
    const char * GetPayloadData() const;

    void SetPacketType(const QSbnPacket::PacketType type);
    void SetCpuId(const uint32_t cpuId);

    void SetPacketData(const char *data, const uint16_t packetLength);
    void SetPayloadData(const char *data, const uint16_t payloadLength);

private:

    char data[QSBN_MAX_SBN_PACKET_SIZE];
};

/*
 *  SBN Peer Data
 *
 * */

class TRICK_SBN_LIBSHARED_EXPORT QSbnPeer
{
public:

    QSbnPeer();

    QSbnPeer(const uint32_t cpuId,
             const QString &ipAddress,
             const uint16_t port);

    bool IsSubscribedToMessageId(uint32_t mid);

    QSharedPointer<QSbnSubscriptionPacket> ToSubscriptionPacket();

    uint32_t cpuId;

    QHostAddress ipAddress;
    uint16_t port;

    QVector<uint32_t> subscriptionMids;

    bool isConnected;
    int64_t lastSeen;
};

/*
 *  QSbn Main Library Interface Class - instances of QSbn are represented by instances of this class
 *
 *  *** NOTE: this class is designed for a single thread handling communication - it is
 *              (by design) NOT thread-safe!
 *
 * */

class TRICK_SBN_LIBSHARED_EXPORT QSbn
{
public:

    enum Protocol
    {
        CCSDS_STREAMING,
        SBN_UDP
    };

    enum State
    {
        Ready = 1,
        Initialized = 0,
        Uninitialized = -1,
        InvalidConfiguration = -2,
        UdpPortBindFailed = -3,
        UnkownError = -99
    };

    QSbn();

    QSbn(QString jsonConfigurationData);
    QSbn(QJsonObject jsonConfiguration);

    // methods for processing QSbn configuration & initializing QSbn state
    int Initialize(QString jsonConfigurationData);
    int Initialize(QJsonObject jsonConfiguration);

    int AddSubscriptions(QVector<uint32_t> &messageIds);

    // This must be called to actually acquire network resources (bind UDP socket)
    // necessary for sending/receiving data
    int StartQSbn();

    QSbn::State GetCurrentState() const;
    QSbn::Protocol GetCurrentProtocol() const;

    int GetPeerInfo(uint32_t cpuId, QSbnPeer &peerInfo);

    /*
     *  synchronous send()/receive() methods.
     *
     *  ProcessNetMessages() needs to be called at an interval
     *  greater than the minimum connection timeout for all peers on SBN.
     *
     * */

    int ProcessIncomingMessages(QCcsdsPacket *msgQueue, int queueSize);
    int Send(QCcsdsPacket *msgQueue, int count);

private:

    // for simplicity & robustness (issues w/ timing & packet-loss, etc),
    // we just send heartbeats to all configured peers regardless of connection state.
    int Heartbeat();

    int SendSubscriptionsToPeers();

    int GetPeerIndexFromCpuId(uint32_t cpuId);

    QSbn::Protocol protocol;
    QSbn::State currentState;

    QSbnPeer hostConfig;
    int64_t lastHeartbeat;

    QUdpSocket socket;

    // timeout only used for connection-oriented protocols, e.g. sbn_udp
    uint32_t connectionTimeout;

    std::vector<QSbnPeer> peers;

    int InitializePeerFromJsonConfig(QJsonObject peerConfig, QSbnPeer &peer);

    QSbn(const QSbn &other);
    QSbn operator=(const QSbn &other);
};

#endif // QSBNLIB_H
