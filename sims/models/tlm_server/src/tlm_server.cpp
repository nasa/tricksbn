#include "tlm_server/include/tlm_server.hh"

#include <iostream>

#include <QDir>
#include <QString>
#include <QStringList>

#include <QJsonObject>

#include "protobetterdynamic.h"
#include "qsbn.h"
#include "trick_ccsds_mapping.h"
#include "trick_ccsds_sim_backend.h"
#include "trick_ccsds_memory_manager.h"

#include "trick/MemoryManager.hh"

namespace {

    Protobetter::PrototypeCollection *prototypes = nullptr;
    Protobetter::DynamicTypeCollection *dynamicTypes = nullptr;
    QSbn *sbn = nullptr;
    TrickCcsdsMappingClient *mappingClient = nullptr;

    const int packetBufferSize = 1000;
    QCcsdsPacket *packetBuffer = nullptr;
}

extern Trick::MemoryManager *trick_MM;

void InitTlmServer(TelemetryServerConfig *config)
{
    // you can grab all inputs from the python input file and
    // do all your server initialization based on that here...

    packetBuffer = new QCcsdsPacket[packetBufferSize];

    prototypes = new Protobetter::PrototypeCollection;

    std::cout << "Initializing Trick-SBN" << std::endl;

    QDir tvmFileDir(QString(config->tvmFileDir.c_str()));
    QDir prototypeFileDir(QString(config->prototypeFileDir.c_str()));

    QStringList tvmFilePaths = tvmFileDir.entryList(QStringList() << "*.tvm", QDir::Files);
    QStringList prototypeFilePaths = prototypeFileDir.entryList(QStringList() << "*.ptype", QDir::Files);

    if (tvmFilePaths.size() == 0)
    {
        std::cout << "TRICK_SBN ERROR: no tvm files found in tvm dir - " << tvmFileDir.absolutePath().toStdString() << std::endl;
    }
    else if (prototypeFilePaths.size() == 0)
    {
        std::cout << "TRICK_SBN ERROR: no ptype files found in ptype dir - " << prototypeFileDir.absolutePath().toStdString() << std::endl;
    }

    // process prototype data & build dynamic types
    for (int i = 0; i < prototypeFilePaths.length(); ++i)
    {
        QFileInfo prototypeFile(prototypeFileDir, prototypeFilePaths.at(i));

        prototypes->LoadPrototypesFromPType(prototypeFile.absoluteFilePath());
    }

    dynamicTypes = new Protobetter::DynamicTypeCollection;
    *dynamicTypes = Protobetter::DynamicTypeCollection::FromPrototypeCollection(*prototypes);

    if (dynamicTypes->Size() == 0)
    {
        std::cout << "TRICK_SBN ERROR - no valid prototype definitions available!" << std::endl;
    }
    else
    {
        std::cout << "TRICK_SBN: " << dynamicTypes->Size() << " prototypes available!" << std::endl; 
    }

    // process tvm data & initialize ccsds mapping client
    QJsonArray tvmObjects;

    for (int i = 0; i < tvmFilePaths.length(); ++i)
    {
        QFileInfo tvmFileInfo(tvmFileDir, tvmFilePaths.at(i));
        
        QString tvmFileJsonData;
        QFile tvmFile(tvmFileInfo.absoluteFilePath());

        if (!tvmFile.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            std::cout << "ERROR: Failed to open tvm file: " << tvmFileInfo.absoluteFilePath().toStdString() << std::endl;
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
        }
    }

    if (config->useSimulatedTrickBackend)
    {
        mappingClient = new SimulatedTrickBackend();
        std::cout << "Trick-SBN using simulated trick backend..." << std::endl; 
    }
    else
    {
        mappingClient = new TrickMemoryManagerClient();
        std::cout << "Trick-SBN using Trick memory manager API..." << std::endl;
    }

    if (tvmObjects.size() == 0)
    {
        std::cout << "TRICK_SBN ERROR: no valid tvm object definitions!" << std::endl;
    }
    else
    {
        std::cout << "TRICK_SBN has the following mappings available:\n" << std::endl;

        for (int i = 0; i < tvmObjects.size(); ++i)
        {
            auto tvmObject = tvmObjects.at(i).toObject();
            std::cout << "TrickVariableMapping: mid = " << tvmObject["messageId"].toString().toStdString() << std::endl;
        }

        std::cout << std::endl;
    }

    mappingClient->Initialize(*dynamicTypes, tvmObjects);

    // initialize and run qsbn
    sbn = new QSbn(QString(config->qsbnJsonConfig.c_str()));

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
}

void RunTlmServer(TelemetryServerState *data)
{
    // this doesn't execute while sim is frozen
    mappingClient->SetDebug(data->debugEnabled);

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

void ShutdownTlmServer(TelemetryServerState *data)
{
    // TODO: you should probably clean stuff up here...
    // but for practical purposes, we don't care what happens
    // once sim shutsdown
}
