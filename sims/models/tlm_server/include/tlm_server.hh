/*
PURPOSE:
    (job defs for tlm server)
LIBRARY DEPENDENCY:
    (
        (tlm_server/src/tlm_server.cpp)
        (../../extern/protobetter/protobetter_dynamic_lib/src/protobetterdynamic.cpp)
        (../../extern/ccsds_header_lib/src/cfe/cfe_sb_msg_id_util.c)
        (../../extern/trick_sbn_lib/qsbn.cpp)
        (../../extern/trick_sbn_lib/trick_ccsds_utils.cpp)
        (../../extern/trick_sbn_lib/trick_ccsds_mapping.cpp)
        (../../extern/trick_sbn_lib/trick_ccsds_sim_backend.cpp)
        (../../extern/trick_sbn_lib/trick_ccsds_memory_manager.cpp)
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
