/*
PURPOSE:
    (job defs for tlm server)
LIBRARY DEPENDENCY:
    (
        (tlm_server/src/tlm_server.cpp)
    )
*/

#ifndef __TRICK_TLM_SERVER_H__
#define __TRICK_TLM_SERVER_H__

#include <string>

/* Forward-declare necessary classes instead including .h to avoid Qt ICG error */
class QSbn;
class TrickCcsdsMappingClient;
class QCcsdsPacket;


typedef struct
{
    std::string qsbnJsonConfig;
    std::string tvmFileDir;
    std::string prototypeFileDir;
    bool useSimulatedTrickBackend;
} TelemetryServerConfig;


class TelemetryServer
{
public:

    TelemetryServer();
    ~TelemetryServer();

    void init(TelemetryServerConfig *config);

    void run();

    void shutdown();

    bool debugEnabled;

private:

    static const int packetBufferSize = 1000;

    QSbn *sbn; /**< ** Instance of QSbn */

    TrickCcsdsMappingClient *mappingClient; /**< ** Instance of Trick client */

    QCcsdsPacket *packetBuffer; /**< ** Container to store QSbn packets */

};

#endif /* __TRICK_TLM_SERVER_H__ */
