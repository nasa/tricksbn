#include <iostream>

#include <QCoreApplication>

#include <QThread>

#include <QCommandLineParser>
#include <QFileInfo>
#include <QFile>

#include "qsbn.h"
#include "trick_ccsds_mapping.h"

class TvsIoStandaloneCli
{
public:

    enum Mode
    {
        GenerateConfig,
        SpawnPeer
    };

    TvsIoStandaloneCli::Mode mode;
    QFileInfo configFileInfo;
};

TvsIoStandaloneCli ProcessCliInputs(QCoreApplication &app)
{
    QCommandLineParser parser;

    parser.setApplicationDescription("TVS_IO Standalone - can be configured to run w/ simulated trick backend or an actual variable server backend.");
    parser.addHelpOption();

    parser.addPositionalArgument("<filename>.tricksbn", QCoreApplication::translate("main", "TVS_IO configuration file."));

    QCommandLineOption standaloneMode(QStringList() << "g" << "generate",
                                      QCoreApplication::translate("main", "Generate sample config."));

    parser.addOption(standaloneMode);

    parser.process(app);

    TvsIoStandaloneCli cli;

    auto positionalArgs = parser.positionalArguments();

    if (positionalArgs.size() != 1)
    {
        parser.showHelp();
        std::cout << "invalid num of positional args..." << std::endl;
        app.exec();
    }

    QString configFilePath = positionalArgs.at(0);

    cli.configFileInfo = QFileInfo(configFilePath);

    bool modeOptionSet = parser.isSet(standaloneMode);

    if (modeOptionSet)
    {
        cli.mode = TvsIoStandaloneCli::GenerateConfig;
    }
    else
    {
        cli.mode = TvsIoStandaloneCli::SpawnPeer;
    }

    return cli;
}

void GenerateTvsIoConfig(TvsIoStandaloneCli &cli)
{
    QFile configFile(":/data/default_config.tricksbn");

    if (!configFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        std::cout << "Failed to open default config file." << std::endl;
    }

    QString configJsonData = configFile.readAll();

    QFile outFile(cli.configFileInfo.absoluteFilePath());

    if (!outFile.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        std::cout << "Failed to open output file: "
                  << cli.configFileInfo
                     .absoluteFilePath()
                     .toStdString() << std::endl;
    }

    outFile.write(configJsonData.toUtf8());

    std::cout << "Generated sample TrickSbn config at: "
              << cli.configFileInfo.absoluteFilePath().toStdString() << std::endl;
}

void RunTvsIoStandalone(TvsIoStandaloneCli &cli)
{
    // load up default 'streaming' protocol config and verify it's valid
    QString configFilePath(cli.configFileInfo.absoluteFilePath());

    QString configJsonData;
    QFile configFile(configFilePath);

    if (!configFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        std::cout << "Failed to open default config file." << std::endl;
        exit(-1);
    }

    configJsonData = configFile.readAll();

    QJsonDocument configJsonDoc = QJsonDocument::fromJson(configJsonData.toUtf8());

    if (!configJsonDoc.isObject())
    {
        std::cout << "Config file contents are not a valid json object!" << std::endl;
        exit(-1);
    }

    auto jsonConfig = configJsonDoc.object();

    // TODO: validation bud...

    float frequency = jsonConfig["frequency"].toDouble();
    int interval = 1000.0f / frequency;

    int backend = jsonConfig["backend"].toInt();

    auto qsbnJsonConfig = jsonConfig["qsbnConfig"].toObject();

    auto prototypesJson = jsonConfig["prototypes"].toArray();

    auto trickVariableMappingsJson = jsonConfig["trickVariableMappings"].toArray();

    // initialize protobetter and the trick mapping client
    std::cout << "Processing prototypes and trick variable mappings..." << std::endl;

    auto prototypes = Protobetter::PrototypeCollection();
    prototypes.LoadPrototypesFromPType(QJsonDocument(prototypesJson));

    auto dynamicTypes = Protobetter::DynamicTypeCollection::FromPrototypeCollection(prototypes);

    TrickCcsdsMappingClient *mappingClient = nullptr;

    if (backend == 0)
    {
        mappingClient = new SimulatedTrickBackend();
        mappingClient->Initialize(dynamicTypes, trickVariableMappingsJson);
    }
    else if (backend == 1)
    {
        // TODO: instantiate variable server client
    }
    else
    {
        std::cout << "ERROR: unkown backend selected in configuration..." << std::endl;
    }

    // initialize QSbn
    std::cout << "Starting QSbn..." << std::endl;

    QSbn sbn(qsbnJsonConfig);

    auto hostSubscriptions = mappingClient->GetInboundMids();

    int result = sbn.AddSubscriptions(hostSubscriptions);

    if (result < 0)
    {
        std::cout << "ERROR processing host subscriptions for QSbn..." << std::endl;
    }

    result = sbn.StartQSbn();

    if (result < 0)
    {
        std::cout << "ERROR starting QSbn..." << std::endl;
    }

    const int packetArraySize = 1000;

    QCcsdsPacket *packets = new QCcsdsPacket[packetArraySize];

    int packetCount = -1;

    while (true)
    {
        // map data received from QSbn to trick
        packetCount = sbn.ProcessIncomingMessages(packets, packetArraySize);

        if (packetCount < 0)
        {
            std::cout << "ERROR calling QSbn::ProcessIncomingMessages()..." << std::endl;
            continue;
        }

        for (int i = 0; i < packetCount; ++i)
        {
            int result = mappingClient->WriteData(packets[i]);

            if (result < 0)
            {
                std::cout << "ERROR mapping data from QSbn to trick memory..." << std::endl;
                exit(-1);
            }
        }

        // map data from trick going out on QSbn
        packetCount = mappingClient->ReadData(packets, packetArraySize);

        if (packetCount < 0)
        {
            std::cout << "ERROR calling TrickCcsdsMappingClient::ReadData()..." << std::endl;
            exit(-1);
        }

        if (packetCount > 0)
        {
            int result = sbn.Send(packets, packetCount);

            if (result < 0)
            {
                std::cout << "ERROR calling QSbn::Send()..." << std::endl;
                exit(-1);
            }
        }

        QThread::msleep(interval);
    }
}

void Run(TvsIoStandaloneCli &cli)
{
    if (cli.mode == TvsIoStandaloneCli::GenerateConfig)
    {
        std::cout << "Generating config at " << cli.configFileInfo.absoluteFilePath().toStdString() << std::endl;
        GenerateTvsIoConfig(cli);
    }
    else if (cli.mode == TvsIoStandaloneCli::SpawnPeer)
    {
        std::cout << "Initializing TVS_IO Standalone..." << std::endl;
        RunTvsIoStandalone(cli);
    }
    else
    {
        std::cout << "ERROR: unkown command line configuration..." << std::endl;
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    std::cout << "TVS_IO Standalone" << std::endl;

    TvsIoStandaloneCli cli = ProcessCliInputs(app);

    Run(cli);

    return 0;
}



