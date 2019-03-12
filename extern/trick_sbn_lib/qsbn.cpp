#include <iostream>
#include <cstring>
#include <exception>

#include <QtEndian>

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

#include <QDateTime>

#include "qsbn.h"

#include "ccsds_header_lib.h"

/*******************************************************************************************************************************
 *
 *  QCcsdsPacket
 *
 * *****************************************************************************************************************************/

QCcsdsPacket::QCcsdsPacket(const uint32_t messageId, const uint16_t payloadLength, const char *payload)
{
    memset(this->data, 0, QSBN_MAX_CCSDS_PACKET_SIZE);

    CFE_SB_InitMsg(this->data, messageId, QSBN_MAX_CCSDS_PACKET_SIZE, FALSE);

    this->SetPayloadData(payload, payloadLength);
}

QCcsdsPacket::QCcsdsPacket(const QCcsdsPacket &other)
{
    memcpy(this->data, other.data, QSBN_MAX_CCSDS_PACKET_SIZE);
}

QCcsdsPacket QCcsdsPacket::operator=(const QCcsdsPacket &other)
{
    if (this != &other)
    {
        memcpy(this->data, other.data, QSBN_MAX_CCSDS_PACKET_SIZE);
    }

    return *this;
}

QCcsdsPacket::~QCcsdsPacket()
{
}

uint32_t QCcsdsPacket::GetMessageId() const
{
    return CFE_SB_GetMsgId((CFE_SB_MsgPtr_t) this->data);
}

uint16_t QCcsdsPacket::GetCommandCode() const
{
    return CFE_SB_GetCmdCode((CFE_SB_MsgPtr_t) this->data);
}

uint16_t QCcsdsPacket::GetPacketLength() const
{
    return CFE_SB_GetTotalMsgLength((CFE_SB_MsgPtr_t) this->data);
}

uint16_t QCcsdsPacket::GetHeaderLength() const
{
    return CFE_SB_GetTotalMsgLength((CFE_SB_MsgPtr_t) this->data) - CFE_SB_GetUserDataLength((CFE_SB_MsgPtr_t) this->data);
}

uint16_t QCcsdsPacket::GetPayloadLength() const
{
    return CFE_SB_GetUserDataLength((CFE_SB_MsgPtr_t) this->data);
}

const char * QCcsdsPacket::GetPacketData() const
{
    return this->data;
}

const char * QCcsdsPacket::GetPayloadData() const
{
    return this->data + this->GetHeaderLength();
}

QCcsdsPacket::PacketType QCcsdsPacket::GetPacketType() const
{
    CFE_SB_MsgPtr_t msg = (CFE_SB_MsgPtr_t) this->data;

    return (CCSDS_RD_TYPE(msg->Hdr) == CCSDS_TLM) ? PacketType::Telemetry : PacketType::Command;
}

void QCcsdsPacket::SetMessageId(const uint32_t messageId)
{
    char buffer[QSBN_MAX_CCSDS_PACKET_SIZE];
    int payloadLength = this->GetPayloadLength();

    if (payloadLength > 0)
    {
        memcpy(buffer, this->GetPayloadData(), payloadLength);
    }

    CFE_SB_SetMsgId((CFE_SB_MsgPtr_t) this->data, messageId);

    if (payloadLength > 0)
    {
        memcpy(this->data + this->GetHeaderLength(), buffer, payloadLength);
    }
}

void QCcsdsPacket::SetCommandCode(const uint16_t cmdCode)
{
    CFE_SB_SetCmdCode((CFE_SB_MsgPtr_t) this->data, cmdCode);
}

void QCcsdsPacket::SetPacketData(const char *data, const uint16_t packetLength)
{
    memcpy(this->data, data, packetLength);
}

void QCcsdsPacket::SetPayloadData(const char *data, const uint16_t length)
{
    CFE_SB_SetUserDataLength((CFE_SB_MsgPtr_t) this->data, length);

    if (length > 0)
    {
        memcpy(CFE_SB_GetUserData((CFE_SB_MsgPtr_t) this->data), data, length);
    }
}

/*******************************************************************************************************************************
 *
 *  QSbnPacket
 *
 * *****************************************************************************************************************************/

QSbnPacket::QSbnPacket(const QSbnPacket::PacketType type)
{
    memset(this->data, 0, QSBN_MAX_SBN_PACKET_SIZE);

    this->data[2] = type;
}

QSbnPacket::QSbnPacket(const uint32_t cpuId, const QSbnPacket::PacketType type, const uint16_t payloadLength)
{
    memset(this->data, 0, QSBN_MAX_SBN_PACKET_SIZE);

    qToBigEndian<quint16>(payloadLength, this->data);
    this->data[2] = type;
    qToBigEndian<quint32>(cpuId, &this->data[3]);
}

QSbnPacket::QSbnPacket(const QSbnPacket &other)
{
    memcpy(this->data, other.data, QSBN_MAX_SBN_PACKET_SIZE);
}

QSbnPacket::~QSbnPacket()
{
}

QSbnPacket QSbnPacket::operator=(const QSbnPacket &other)
{
    if (this != &other)
    {
        memcpy(this->data, other.data, QSBN_MAX_SBN_PACKET_SIZE);
    }

    return *this;
}

uint16_t QSbnPacket::GetPacketLength() const
{
    return this->GetHeaderLength() + this->GetPayloadLength();
}

uint16_t QSbnPacket::GetHeaderLength() const
{
    return 7;
}

uint16_t QSbnPacket::GetPayloadLength() const
{
    return qFromBigEndian<quint16>(this->data);
}

QSbnPacket::PacketType QSbnPacket::GetPacketType() const
{
    return static_cast<QSbnPacket::PacketType>(this->data[2]);
}

uint32_t QSbnPacket::GetCpuId() const
{
    return qFromBigEndian<quint32>(&this->data[3]);
}

const char * QSbnPacket::GetPacketData() const
{
    return this->data;
}

const char * QSbnPacket::GetPayloadData() const
{
    return this->data + 7;
}

void QSbnPacket::SetPacketType(const QSbnPacket::PacketType type)
{
    this->data[2] = type;
}

void QSbnPacket::SetCpuId(const uint32_t cpuId)
{
    qToBigEndian<quint32>(cpuId, &this->data[3]);
}

void QSbnPacket::SetPacketData(const char *data, const uint16_t packetLength)
{
    memcpy(this->data, data, packetLength);
}

void QSbnPacket::SetPayloadData(const char *data, const uint16_t payloadLength)
{
    memcpy(this->data+7, data, payloadLength);
    qToBigEndian<quint16>(payloadLength, this->data);
}

/*******************************************************************************************************************************
 *
 *  QSbnSubscription
 *
 * *****************************************************************************************************************************/

QSbnSubscriptionPacket::QSbnSubscriptionPacket()
{
    memset(this->data, 0, QSBN_MAX_SBN_PACKET_SIZE - 7);
}

QSbnSubscriptionPacket::QSbnSubscriptionPacket(const char *versionInfo, int length)
{
    memset(this->data, 0, QSBN_MAX_SBN_PACKET_SIZE - 7);
    memcpy(this->data, versionInfo, length);
}

QSbnSubscriptionPacket::QSbnSubscriptionPacket(const QSbnSubscriptionPacket &other)
{
    memcpy(this->data, other.data, QSBN_MAX_SBN_PACKET_SIZE - 7);
}

QSbnSubscriptionPacket QSbnSubscriptionPacket::operator =(const QSbnSubscriptionPacket &other)
{
    if (this != &other)
    {
        memcpy(this->data, other.data, QSBN_MAX_CCSDS_PACKET_SIZE - 7);
    }

    return *this;
}

QSbnSubscriptionPacket::~QSbnSubscriptionPacket()
{

}

const char * QSbnSubscriptionPacket::GetVersionInfo() const
{
    return this->data;
}

uint16_t QSbnSubscriptionPacket::GetSubscriptionCount() const
{
    return qFromBigEndian<quint16>(&this->data[48]);
}

void QSbnSubscriptionPacket::SetVersionInfo(const char *versionInfo)
{
    memcpy(this->data, versionInfo, 48);
}

uint16_t QSbnSubscriptionPacket::GetPacketLength() const
{
    return (50 + this->GetSubscriptionCount() * 6);
}

const char * QSbnSubscriptionPacket::GetPacketData() const
{
    return this->data;
}

uint32_t QSbnSubscriptionPacket::GetSubscriptionAt(int index)
{
    uint16_t subscriptionOffset = 50 + index * 6;

    return qFromBigEndian<quint32>(this->data + subscriptionOffset);
}

int QSbnSubscriptionPacket::AddSubscription(uint32_t messageId, uint16_t qos)
{
    uint16_t subCount = this->GetSubscriptionCount();

    uint16_t subscriptionOffset = 50 + subCount * 6;

    qToBigEndian<quint32>(messageId, &this->data[subscriptionOffset]);
    qToBigEndian<quint16>(qos, &this->data[subscriptionOffset+4]);

    qToBigEndian<quint16>(subCount+1, &this->data[48]);

    return 1;
}

int QSbnSubscriptionPacket::RemoveSubscription(uint32_t messageId)
{
    char buffer[QSBN_MAX_SBN_PACKET_SIZE - 7];

    uint16_t subCount = this->GetSubscriptionCount();

    int subscriptionIndex = -1;

    for (int i = 0; i < subCount; ++i)
    {
        uint32_t currentMid = qFromBigEndian<quint32>(&this->data[50+i*6]);

        if (currentMid == messageId)
        {
            subscriptionIndex = i;
            break;
        }
    }

    if (subscriptionIndex >= 0)
    {
        if (subCount > subscriptionIndex + 1)
        {
            uint16_t subsToCopy = subCount - (subscriptionIndex + 1);

            memcpy(buffer, &this->data[50+(subscriptionIndex+1)*6], subsToCopy*6);
            memcpy(&this->data[50+(subscriptionIndex)*6], buffer, subsToCopy*6);
        }

        qToBigEndian<quint16>(subCount-1, &this->data[48]);

        return 1;
    }

    return -1;
}

int QSbnSubscriptionPacket::SetPacketData(const char *data, const uint16_t length)
{
    memcpy(this->data, data, length);

    return 1;
}

/*******************************************************************************************************************************
 *
 *  QSbnPeer
 *
 * *****************************************************************************************************************************/

QSbnPeer::QSbnPeer()
    : cpuId(0), ipAddress(), port(), subscriptionMids()
{
}

QSbnPeer::QSbnPeer(const uint32_t cpuId, const QString &ipAddress, const uint16_t port)
    : cpuId(cpuId), ipAddress(ipAddress), port(port), subscriptionMids()
{
}

bool QSbnPeer::IsSubscribedToMessageId(uint32_t mid)
{
    for (int i = 0; i < subscriptionMids.size(); ++i)
    {
        if (subscriptionMids[i] == mid)
        {
            return true;
        }
    }

    return false;
}

QSharedPointer<QSbnSubscriptionPacket> QSbnPeer::ToSubscriptionPacket()
{
    auto packet = QSharedPointer<QSbnSubscriptionPacket>(
                new QSbnSubscriptionPacket(QSBN_VERSION_INFO, strlen(QSBN_VERSION_INFO) + 1));

    for (int i = 0; i < this->subscriptionMids.size(); ++i)
    {
        packet->AddSubscription(this->subscriptionMids[i]);
    }

    return packet;
}

/*******************************************************************************************************************************
 *
 *  QSbn Main Library Interface Class - instances of QSbn are represented by instances of this class
 *
 * *****************************************************************************************************************************/

QSbn::QSbn()
    : currentState(QSbn::Uninitialized), lastHeartbeat(0)
{
    this->currentState = QSbn::Uninitialized;
}

QSbn::QSbn(QString jsonConfigurationData)
    : currentState(QSbn::Uninitialized), lastHeartbeat(0)
{
    this->Initialize(jsonConfigurationData);
}

QSbn::QSbn(QJsonObject jsonConfiguration)
    : currentState(QSbn::Uninitialized), lastHeartbeat(0)
{
    this->Initialize(jsonConfiguration);
}

QSbn::QSbn(const QSbn &)
{
    throw std::runtime_error("can't copy sbn instances!");
}

QSbn QSbn::operator =(const QSbn &)
{
    throw std::runtime_error("can't copy sbn instances!");
}

int QSbn::Initialize(QString jsonConfigurationData)
{
    QJsonDocument configurationDoc = QJsonDocument::fromJson(jsonConfigurationData.toUtf8());

    if (configurationDoc.isObject())
    {
        int ret = this->Initialize(configurationDoc.object());

        if (ret > 0)
        {
            this->currentState = QSbn::Initialized;
            return 1;
        }
    }

    std::cout << "ERROR: Invalid json string passed to QSbn constructor..." << std::endl;

    this->currentState = QSbn::InvalidConfiguration;
    return -1;
}

int QSbn::Initialize(QJsonObject jsonConfiguration)
{
    if (this->currentState >= 0)
    {
        return -1;
    }

    // TODO: help the user out, pal - split these checks up and give more helpful feedback to caller...
    if (!jsonConfiguration.contains("protocol") ||
            !jsonConfiguration.contains("sbnHostConfig") ||
            !jsonConfiguration.contains("sbnPeerConfig") ||
            !(jsonConfiguration["protocol"].isString()) ||
            !(jsonConfiguration["sbnHostConfig"].isObject()) ||
            !(jsonConfiguration["sbnPeerConfig"].isArray()))
    {
        this->currentState = QSbn::InvalidConfiguration;
        return -1;
    }

    // process protocol data
    if (jsonConfiguration["protocol"].toString() == "stream")
    {
        this->protocol = QSbn::CCSDS_STREAMING;
    }
    else
    {
        this->protocol = QSbn::SBN_UDP;
    }

    // process connection timeout data
    // TODO: this should really be an optional field
    this->connectionTimeout = jsonConfiguration["timeout"].toInt();

    // process host config data
    auto sbnHostConfig = jsonConfiguration["sbnHostConfig"].toObject();

    if (this->InitializePeerFromJsonConfig(sbnHostConfig, this->hostConfig) < 0)
    {
        this->currentState = QSbn::InvalidConfiguration;
        return -1;
    }

    // process peer config data
    auto sbnPeerConfig = jsonConfiguration["sbnPeerConfig"].toArray();

    for (int i = 0; i < sbnPeerConfig.count(); ++i)
    {
        if (sbnPeerConfig.at(i).isObject())
        {
            auto peerConfig = sbnPeerConfig.at(i).toObject();

            QSbnPeer newPeer;

            if (this->InitializePeerFromJsonConfig(peerConfig, newPeer) < 0)
            {
                this->currentState = QSbn::InvalidConfiguration;
                return -1;
            }

            this->peers.push_back(newPeer);
        }
        else
        {
            this->currentState = QSbn::InvalidConfiguration;
            return -1;
        }
    }

    this->currentState = QSbn::Initialized;
    return 1;
}

int QSbn::AddSubscriptions(QVector<uint32_t> &messageIds)
{
    if (this->protocol != QSbn::SBN_UDP)
    {
        return -1;
    }

    for (int i = 0; i < messageIds.size(); ++i)
    {
        if (!(this->hostConfig.subscriptionMids.contains(messageIds[i])))
        {
            this->hostConfig.subscriptionMids.push_back(messageIds[i]);
        }
    }

    return 1;
}

int QSbn::SendSubscriptionsToPeers()
{
    if (this->protocol == QSbn::SBN_UDP && this->currentState == QSbn::Ready)
    {
        uint16_t hostSubCount = this->hostConfig.subscriptionMids.size();

        if (hostSubCount == 0)
        {
            return 1;
        }

        QSbnSubscriptionPacket subMessage(QSBN_VERSION_INFO, strlen(QSBN_VERSION_INFO) + 1);

        for (int i = 0; i < this->hostConfig.subscriptionMids.size(); ++i)
        {
            subMessage.AddSubscription(this->hostConfig.subscriptionMids[i]);
        }

        if (subMessage.GetSubscriptionCount() != hostSubCount)
        {
            std::cout << "ERROR building QSbn Subscription Message... failed to add subs to sub message..." << std::endl;
            return -1;
        }

        std::cout << "QSbn about to send " << subMessage.GetSubscriptionCount()
            << " subscriptions to peers: ";

        for (int i = 0; i < hostSubCount; ++i)
        {
            if (i != 0)
            {
                std::cout << ", ";
            }

            std::cout << QString::number(subMessage.GetSubscriptionAt(i), 16).toStdString();
        }

        std::cout << std::endl;

        QSbnPacket packet(this->hostConfig.cpuId,
                          QSbnPacket::SBN_SUB_MSG,
                          subMessage.GetPacketLength());

        packet.SetPayloadData(subMessage.GetPacketData(), subMessage.GetPacketLength());

        const char *packetData = packet.GetPacketData();
        int packetLength = packet.GetPacketLength();

        for (size_t i = 0; i < this->peers.size(); ++i)
        {
            int bytesSent = this->socket.writeDatagram(
                        packetData, packetLength,
                        this->peers[i].ipAddress, this->peers[i].port);

            if (bytesSent != packetLength)
            {
                return -1;
            }
        }

        return 1;
    }

    return -1;
}

int QSbn::Heartbeat()
{
    if (this->currentState == QSbn::Ready)
    {
        if (this->protocol == QSbn::SBN_UDP)
        {
            QSbnPacket heartbeatMsg(
                        this->hostConfig.cpuId,
                        QSbnPacket::SBN_HEARTBEAT_MSG,
                        0);

            int length = heartbeatMsg.GetPacketLength();

            for (size_t i = 0; i < this->peers.size(); ++i)
            {
                int bytesSent = this->socket.writeDatagram(
                            heartbeatMsg.GetPacketData(),
                            heartbeatMsg.GetPacketLength(),
                            this->peers[i].ipAddress,
                            this->peers[i].port);

                if (bytesSent != length)
                {
                    return -1;
                }
            }
        }

        return 1;
    }

    return -1;
}

int QSbn::StartQSbn()
{
    // bind udp port for receiving data
    if (!(this->socket.bind(this->hostConfig.ipAddress, this->hostConfig.port)))
    {
        this->currentState = QSbn::UdpPortBindFailed;
        return -1;
    }

    if (this->socket.state() == QAbstractSocket::BoundState)
    {
        this->currentState = QSbn::Ready;
    }
    else
    {
        this->currentState = QSbn::UnkownError;
        return -1;
    }

    int result = this->Heartbeat();

    if (result < 0)
    {
        return -1;
    }

    this->lastHeartbeat = QDateTime::currentMSecsSinceEpoch();

    std::cout << "Successfully started QSbn on <IP:port> = <"
              << this->hostConfig.ipAddress.toString().toStdString() << ":"
              << this->hostConfig.port << ">" << std::endl;

    if (this->protocol == QSbn::SBN_UDP && this->hostConfig.subscriptionMids.size() > 0)
    {
        result = this->SendSubscriptionsToPeers();

        if (result < 0)
        {
            return -1;
        }

        std::cout << "Successfully sent the following subs to peers: " << std::endl;

        for (int i = 0; i < this->hostConfig.subscriptionMids.size(); ++i)
        {
            std::cout << "0x" << QString::number(this->hostConfig.subscriptionMids[i], 16).toStdString() << std::endl;
        }

        std::cout << std::endl;
    }

//    std::cout

    return 1;
}

int QSbn::InitializePeerFromJsonConfig(QJsonObject peerConfig, QSbnPeer &peer)
{
    if (!peerConfig.contains("cpuId") ||
            !peerConfig.contains("ip") ||
            !peerConfig.contains("port") ||
            !(peerConfig["cpuId"].isDouble()) ||
            !(peerConfig["ip"].isString()) ||
            !(peerConfig["port"].isDouble()))
    {
        return -1;
    }

    peer.cpuId = peerConfig["cpuId"].toInt();
    peer.ipAddress = QHostAddress(peerConfig["ip"].toString());
    peer.port = peerConfig["port"].toInt();

    peer.lastSeen = 0;
    peer.isConnected = false;

    return 1;
}

int QSbn::GetPeerInfo(uint32_t cpuId, QSbnPeer &peerInfo)
{
    for (size_t i = 0; i < this->peers.size(); ++i)
    {
        if (this->peers[i].cpuId == cpuId)
        {
            peerInfo = this->peers[i];
            return 1;
        }
    }

    return -1;
}

int QSbn::GetPeerIndexFromCpuId(uint32_t cpuId)
{
    for (size_t i = 0; i < this->peers.size(); ++i)
    {
        if (this->peers[i].cpuId == cpuId)
        {
            return i;
        }
    }

    return -1;
}

int QSbn::ProcessIncomingMessages(QCcsdsPacket *msgQueue, int queueSize)
{
    if (this->currentState != QSbn::Ready)
    {
        return -1;
    }
    else if (this->protocol == QSbn::CCSDS_STREAMING)
    {
        char buffer[QSBN_MAX_CCSDS_PACKET_SIZE];
        int messagesRead = 0;

        while (this->socket.hasPendingDatagrams())
        {
            if (messagesRead >= queueSize)
            {
                return messagesRead;
            }

            // this is a hack here to make up for the fact that QUdpSocket::hasPendingDatagrams()
            // appears to be buggy in certain versions of Qt 5 and incorrectly returns true even
            // when there's nothing to read :|
            int expectedSize = this->socket.pendingDatagramSize();

            if (expectedSize > 0)
            {
                int size = this->socket.readDatagram(buffer, QSBN_MAX_CCSDS_PACKET_SIZE);

                if (size > 0)
                {
                    msgQueue[messagesRead].SetPacketData(buffer, size);
                    messagesRead++;
                }
                else
                {
                    return -1;
                }
            }
            else if (expectedSize == 0)
            {
                return 0;
            }
            else
            {
                return -1;
            }
        }

        return messagesRead;
    }
    else if (this->protocol == QSbn::SBN_UDP)
    {
        QSbnPacket packet;
        char buffer[QSBN_MAX_SBN_PACKET_SIZE];

        int messagesRead = 0;

        // check peers to see who has timed-out since last processing call

        int64_t currentTime = QDateTime::currentMSecsSinceEpoch();

        for (size_t i = 0; i < this->peers.size(); ++i)
        {
            if (this->peers[i].isConnected
                    && currentTime - this->peers[i].lastSeen > this->connectionTimeout)
            {
                this->peers[i].isConnected = false;
                std::cout << "QSbn Peer CPU " << this->peers[i].cpuId << " disconnected..." << std::endl;
            }
        }

        // send heartbeats buddy
        if (currentTime - this->lastHeartbeat > 900)
        {
            int result = this->Heartbeat();

            if (result < 0)
            {
                std::cout << "QSbn ERROR when heartbeating..." << std::endl;
            }

            this->lastHeartbeat = currentTime;
        }

        while (this->socket.hasPendingDatagrams())
        {
            /*
             *  pull sbn messages off socket one at a time and process them according to their type...
             *  as messages from peers come in, check if they are connected, and if not,
             *  you need to send them subs and put them in a connected state again...
             *
             * */

            if (messagesRead >= queueSize)
            {
                return messagesRead;
            }

            // this is a hack here to make up for the fact that QUdpSocket::hasPendingDatagrams()
            // appears to be buggy in certain versions of Qt 5 and incorrectly returns true even
            // when there's nothing to read :|
            int expectedSize = this->socket.pendingDatagramSize();

            if (expectedSize > 0)
            {
                int size = this->socket.readDatagram(buffer, QSBN_MAX_SBN_PACKET_SIZE);

                if (size < 0)
                {
                    return messagesRead;
                }

                packet.SetPacketData(buffer, size);

                int peerIndex = this->GetPeerIndexFromCpuId(packet.GetCpuId());

                if (peerIndex < 0)
                {
                    std::cout << "QSbn WARNING: received message from an unkown peer cpu ID = "
                        << packet.GetCpuId() << std::endl;

                    continue;
                }
                else if (!this->peers[peerIndex].isConnected)
                {
                    // if peer was disconnected, it's not anymore pal o/
                    this->peers[peerIndex].isConnected = true;
                    std::cout << "QSbn Peer CPU " << this->peers[peerIndex].cpuId << " connected!" << std::endl;

                    this->SendSubscriptionsToPeers();
                }

                this->peers[peerIndex].lastSeen = QDateTime::currentMSecsSinceEpoch();

                if (packet.GetPacketType() == QSbnPacket::SBN_APP_MSG)
                {
                    msgQueue[messagesRead].SetPacketData(packet.GetPayloadData(), packet.GetPayloadLength());
                    messagesRead++;
                }
                else if (packet.GetPacketType() == QSbnPacket::SBN_SUB_MSG)
                {
                    QSbnSubscriptionPacket subsMsg;

                    subsMsg.SetPacketData(packet.GetPayloadData(), packet.GetPayloadLength());

                    uint16_t subCount = subsMsg.GetSubscriptionCount();

                    std::cout << "QSbn: Received sub msg from peer cpuId = "
                        << packet.GetCpuId() << " w/ " << subCount << " subscriptions..." << std::endl;

                    for (int i = 0; i < subCount; ++i)
                    {
                        uint32_t mid = subsMsg.GetSubscriptionAt(i);

                        std::cout << "QSbn: Peer cpuId " << packet.GetCpuId()
                            << " subscribed to message ID = " << QString::number(mid, 16).toStdString() << std::endl;

                        if (!this->peers[peerIndex]
                                .IsSubscribedToMessageId(mid))
                        {
                            this->peers[peerIndex].subscriptionMids.push_back(mid);
                        }
                    }
                }
                else if (packet.GetPacketType() == QSbnPacket::SBN_HEARTBEAT_MSG)
                {
                    // do nothing - we have already updated the connection state by this point...
                    std::cout << "received a heartbeat from peer cpuId = " << packet.GetCpuId() << std::endl;
                }
            }
            else if (expectedSize == 0)
            {
                return messagesRead;
            }
            else
            {
                return -1;
            }
        }

        return messagesRead;
    }

    return -1;
}

int QSbn::Send(QCcsdsPacket *msgQueue, int count)
{
    if (this->currentState != QSbn::Ready)
    {
        return -1;
    }
    else if (this->protocol == QSbn::CCSDS_STREAMING)
    {
        for (int i = 0; i < count; ++i)
        {
            int messageSize = msgQueue[i].GetPacketLength();
            const char *message = msgQueue[i].GetPacketData();

            for (size_t j = 0; j < this->peers.size(); ++j)
            {
                int bytesSent = this->socket.writeDatagram(
                                    message, messageSize,
                                    this->peers[j].ipAddress,
                                    this->peers[j].port);

                if (bytesSent < messageSize)
                {
                    return -1;
                }
            }
        }

        return 1;
    }
    else if (this->protocol == QSbn::SBN_UDP)
    {
        for (int i = 0; i < count; ++i)
        {
            uint16_t payloadLength = msgQueue[i].GetPacketLength();
            uint32_t mid = msgQueue[i].GetMessageId();

            QSbnPacket packet(this->hostConfig.cpuId, QSbnPacket::SBN_APP_MSG, payloadLength);
            packet.SetPayloadData(msgQueue[i].GetPacketData(), payloadLength);

            for (size_t j = 0; j < this->peers.size(); ++j)
            {
                if (this->peers[j].isConnected && this->peers[j].IsSubscribedToMessageId(mid))
                {
                    int bytesSent = this->socket.writeDatagram(
                                packet.GetPacketData(), packet.GetPacketLength(),
                                this->peers[j].ipAddress,
                                this->peers[j].port);

                    if (bytesSent < packet.GetPacketLength())
                    {
                        return -1;
                    }
                }
            }
        }

        return 1;
    }

    return -1;
}

QSbn::State QSbn::GetCurrentState() const
{
    return this->currentState;
}

QSbn::Protocol QSbn::GetCurrentProtocol() const
{
    return this->protocol;
}
























