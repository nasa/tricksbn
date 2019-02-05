#include "tlm_server/include/tlm_server.hh"

#include <iostream>

#include <QDir>
#include <QString>
#include <QStringList>

#include <QJsonObject>

#include "protobetterdynamic.h"

#include "trick/MemoryManager.hh"

namespace {

    extern Trick::MemoryManager *trick_MM;

    Protobetter::PrototypeCollection *prototypes = nullptr;
    Protobetter::DynamicTypeCollection *dynamicTypes = nullptr;
}

void InitTlmServer(TelemetryServerConfig *config)
{
    // you can grab all inputs from the python input file and
    // do all your server initialization based on that here...

    prototypes = new Protobetter::PrototypeCollection;

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

    if (prototypes->HasType("Struct_Cannon"))
        std::cout << "loaded cannon type successfully!" << std::endl;
    else
        std::cout << "failed to load cannon type..." << std::endl;
}

void RunTlmServer(TelemetryServerState *data)
{
    // this doesn't execute while sim is frozen
}

void ShutdownTlmServer(TelemetryServerState *data)
{
}
