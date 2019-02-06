#include "tlm_server/include/tlm_server.hh"

#include <iostream>

#include <QDir>
#include <QString>
#include <QStringList>

#include <QJsonObject>

#include "protobetterdynamic.h"
#include "qsbn.h"
#include "trick_ccsds_mapping.h"
#include "trick_ccsds_memory_manager.h"

#include "trick/MemoryManager.hh"

namespace {

    Protobetter::PrototypeCollection *prototypes = nullptr;
    Protobetter::DynamicTypeCollection *dynamicTypes = nullptr;
    QSbn *sbn = nullptr;
    TrickCcsdsMappingClient *client = nullptr;

    bool debugLoggingEnabled = false;
}

extern Trick::MemoryManager *trick_MM;

void InitTlmServer(TelemetryServerConfig *config)
{
    // you can grab all inputs from the python input file and
    // do all your server initialization based on that here...

    prototypes = new Protobetter::PrototypeCollection;

    if (config->debugLoggingEnabled)
    {
        std::cout << "Initializing Trick-SBN with debug logging enabled" << std::endl;
    } 

    QDir tvmFileDir(QString(config->tvmFileDir.c_str()));
    QDir prototypeFileDir(QString(config->prototypeFileDir.c_str()));

    QStringList tvmFiles = tvmFileDir.entryList(QStringList() << "*.tvm", QDir::Files);
    QStringList prototypeFiles = prototypeFileDir.entryList(QStringList() << "*.ptype", QDir::Files);

    for (int i = 0; i < tvmFiles.length(); ++i)
    {
        QFileInfo tvmFile(tvmFileDir, tvmFiles.at(i));

    }

    for (int i = 0; i < prototypeFiles.length(); ++i)
    {
        QFileInfo prototypeFile(prototypeFileDir, prototypeFiles.at(i));

        // TODO: load a prototype file - not tvm files here
        prototypes->LoadPrototypesFromPType(prototypeFile.absoluteFilePath());
    }

    dynamicTypes->FromPrototypeCollection(*prototypes);

    std::cout << "qsbn: \n\n" << config->qsbnJsonConfig << std::endl;

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

    // start qsbn last - no point in acquiring network resources
    // before validating all configuration data...

//    sbn->StartQSbn();
}

void RunTlmServer(TelemetryServerState *data)
{
    // this doesn't execute while sim is frozen
}

void ShutdownTlmServer(TelemetryServerState *data)
{
}
