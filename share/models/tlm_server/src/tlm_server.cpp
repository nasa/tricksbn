#include <iostream>

#include <QDir>
#include <QString>
#include <QStringList>

#include <QJsonObject>

#include "tlm_server/include/tlm_server.hh"

#include "protobetterdynamic.h"
#include "qsbn.h"
#include "trick_ccsds_mapping.h"
#include "trick_ccsds_sim_backend.h"
#include "trick_ccsds_memory_manager.h"


TelemetryServer::TelemetryServer()
    :debugEnabled(false),
    sbn(nullptr),
    mappingClient(nullptr),
    packetBuffer(nullptr)
{
}


void TelemetryServer::init(TelemetryServerConfig &config)
{
    std::cout << "Initializing Trick-SBN" << std::endl;

    // Process prototypes
    Protobetter::DynamicTypeCollection *dynamicTypes = new Protobetter::DynamicTypeCollection;
    int resPtype = processPtypeFiles(config.prototypeFileDir, *dynamicTypes);

    // Process tvm data
    std::vector<std::string> tvmStrings;
    int resTvm = processTvmFiles(config.tvmFileDir, tvmStrings);

    // Convert to QJsonArray
    QJsonArray tvmObjects;
    for (size_t i = 0; i < tvmStrings.size(); ++i)
    {
        QString qstr(tvmStrings.at(i).c_str());
        QJsonDocument doc = QJsonDocument::fromJson(qstr.toUtf8());
        tvmObjects.push_back(doc.object());
    }

    // Initialize mapping client
    if (config.useSimulatedTrickBackend)
    {
        mappingClient = new SimulatedTrickBackend();
        std::cout << "Trick-SBN using simulated trick backend..." << std::endl; 
    }
    else
    {
        mappingClient = new TrickMemoryManagerClient();
        std::cout << "Trick-SBN using Trick memory manager API..." << std::endl;
    }

    mappingClient->Initialize(*dynamicTypes, tvmObjects);
    mappingClient->SetDebug(debugEnabled);

    // Initialize and run qsbn
    int resQsbn = initQsbn(config.qsbnJsonConfig);

    if (resQsbn < 0 || resTvm < 0 || resPtype < 0) {
        std::cout << "ERROR initializing TelemetryServer" << std::endl;
    }
}


int TelemetryServer::processPtypeFiles(std::string &ptypeDir, Protobetter::DynamicTypeCollection &dynamicTypes)
{
    int result = 0;

    QDir prototypeFileDir(QString(ptypeDir.c_str()));
    QStringList prototypeFilePaths = prototypeFileDir.entryList(QStringList() << "*.ptype", QDir::Files);
    if (prototypeFilePaths.size() == 0)
    {
        std::cout << "TRICK_SBN ERROR: no ptype files found in ptype dir - " << prototypeFileDir.absolutePath().toStdString() << std::endl;
        result = -1;
    }

    // process prototype data & build dynamic types

    Protobetter::PrototypeCollection *prototypes = new Protobetter::PrototypeCollection;
    
    for (int i = 0; i < prototypeFilePaths.length(); ++i)
    {
        QFileInfo prototypeFile(prototypeFileDir, prototypeFilePaths.at(i));

        prototypes->LoadPrototypesFromPType(prototypeFile.absoluteFilePath());
    }

    dynamicTypes = Protobetter::DynamicTypeCollection::FromPrototypeCollection(*prototypes);

    if (dynamicTypes.Size() == 0)
    {
        std::cout << "TRICK_SBN ERROR - no valid prototype definitions available!" << std::endl;
        result = -1;
    }
    else
    {
        std::cout << "TRICK_SBN: " << dynamicTypes.Size() << " prototypes available!" << std::endl; 
    }

    return result;
}


int TelemetryServer::processTvmFiles(std::string &tvmDir, std::vector<std::string> &tvmStrings)
{
    int result = 0;

    QDir tvmFileDir(QString(tvmDir.c_str()));
    QStringList tvmFilePaths = tvmFileDir.entryList(QStringList() << "*.tvm", QDir::Files);
    if (tvmFilePaths.size() == 0)
    {
        std::cout << "TRICK_SBN ERROR: no tvm files found in tvm dir - " << tvmFileDir.absolutePath().toStdString() << std::endl;
        result = -1;
    }

    QJsonArray tvmObjects;

    for (int i = 0; i < tvmFilePaths.length(); ++i)
    {
        QFileInfo tvmFileInfo(tvmFileDir, tvmFilePaths.at(i));
        
        QString tvmFileJsonData;
        QFile tvmFile(tvmFileInfo.absoluteFilePath());

        if (!tvmFile.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            std::cout << "ERROR: Failed to open tvm file: " << tvmFileInfo.absoluteFilePath().toStdString() << std::endl;
            result = -1;
        }

        tvmFileJsonData = tvmFile.readAll();

        QJsonDocument tvmJsonDocument = QJsonDocument::fromJson(tvmFileJsonData.toUtf8());

        if (tvmJsonDocument.isObject())
        {
            tvmObjects.push_back(tvmJsonDocument.object());
        }
        else if (tvmJsonDocument.isArray())
        {
            QJsonArray currentTvmArray = tvmJsonDocument.array();

            for (int j = 0; j < currentTvmArray.size(); ++j)
            {
                tvmObjects.push_back(currentTvmArray.at(j));
            }
        }
        else 
        {
            std::cout << "ERROR: tvm file contents are not valid json... " << tvmFileInfo.absoluteFilePath().toStdString() << std::endl;
            result = -1;
        }
    }

    if (tvmObjects.size() == 0)
    {
        std::cout << "TRICK_SBN ERROR: no valid tvm object definitions!" << std::endl;
        result = -1;
    }
    else
    {
        std::cout << "TRICK_SBN has the following mappings available:\n" << std::endl;

        for (int i = 0; i < tvmObjects.size(); ++i)
        {
            auto tvmObject = tvmObjects.at(i).toObject();
            std::cout << "TrickVariableMapping: mid = " << tvmObject["messageId"].toString().toStdString() << std::endl;

            QJsonDocument doc(tvmObject);
            QString strdoc(doc.toJson(QJsonDocument::Compact));
            tvmStrings.push_back(strdoc.toStdString());
        }

        std::cout << std::endl;
    }

    return result;
}


int TelemetryServer::initQsbn(std::string &config)
{
    packetBuffer = new QCcsdsPacket[packetBufferSize];
    sbn = new QSbn(QString(config.c_str()));

    if (sbn->GetCurrentState() == QSbn::Initialized)
    {
        std::cout << "QSbn initialized successfully..." << std::endl;
    }
    else if (sbn->GetCurrentState() == QSbn::InvalidConfiguration)
    {
        std::cout << "ERROR initializing QSbn... invalid configuration data!" << std::endl;
    }
    else
    {
        std::cout << "ERROR initializing QSbn..." << std::endl;
    }

    int result = -1;

    if (sbn->GetCurrentProtocol() == QSbn::SBN_UDP)
    {
        auto hostSubscriptions = mappingClient->GetInboundMids();

        int result = sbn->AddSubscriptions(hostSubscriptions);

        if (result < 0)
        {
            std::cout << "ERROR processing host subscriptions for QSbn..." << std::endl;
        }
    }

    result = sbn->StartQSbn();

    if (result < 0)
    {
        std::cout << "ERROR starting QSbn..." << std::endl;
    }

    return result;
}


void TelemetryServer::run()
{
    // map data from QSbn to trick memory
    int packetCount = sbn->ProcessIncomingMessages(packetBuffer, packetBufferSize);

    for (int i = 0; i < packetCount; ++i)
    {
        int result = mappingClient->WriteData(packetBuffer[i]);

        if (result < 0)
        {
            std::cout << "TRICK_SBN ERROR mapping data from QSbn to trick memory..." << std::endl;
        }
    }

    // map data from trick going out on QSbn
    packetCount = mappingClient->ReadData(packetBuffer, packetBufferSize);

    if (packetCount < 0)
    {
        std::cout << "TRICK_SBN ERROR calling TrickCcsdsMappingClient::ReadData()..." << std::endl;
    }

    if (packetCount > 0)
    {
        int result = sbn->Send(packetBuffer, packetCount);

        if (result < 0)
        {
            std::cout << "TRICK_SBN ERROR calling QSbn::Send()..." << std::endl;
        }
    }
}


void TelemetryServer::shutdown()
{
    // TODO: you should probably clean stuff up here...
    // but for practical purposes, we don't care what happens
    // once sim shutsdown
}


TelemetryServer::~TelemetryServer()
{

    delete sbn;
    delete mappingClient;
    delete[] packetBuffer;
}
