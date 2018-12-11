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
        std::cout << tvmFiles.at(i).toLocal8Bit().constData() << std::endl;
    }

    if (config->prototypes.HasType("bob"))
        std::cout << "hello bob o/" << std::endl;
    else
        std::cout << "hello protobetter o/" << std::endl;
}

void RunTlmServer(TelemetryServerState *data)
{
    // this doesn't execute while sim is frozen
}

void ShutdownTlmServer(TelemetryServerState *data)
{
}
