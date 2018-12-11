#include "tlm_server/include/tlm_server.hh"

#include <iostream>

#include <QDir>
#include <QString>
#include <QStringList>

#include <QJsonObject>

void InitTlmServer(TelemetryServerConfig *config)
{
    // you can grab all inputs from the python input file and
    // do all your server initialization based on that here...

    std::cout << "TELEMETRY_SERVER: TVM File Directory = " << config->tvmFileDir << std::endl;

    QDir tvmFileDir(QString(config->tvmFileDir.c_str()));

    QStringList tvmFiles = tvmFileDir.entryList(QStringList() << "*.tvm", QDir::Files);

    for (int i = 0; i < tvmFiles.length(); ++i)
    {
        QFileInfo file(tvmFileDir, tvmFiles.at(i));

        std::cout << "filepath = " << file.absoluteFilePath().toStdString().c_str() << std::endl;

        config->prototypes.LoadPrototypesFromPType(file.absoluteFilePath());
    }

    if (config->prototypes.HasType("Struct_Cannon"))
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
