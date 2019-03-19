/*
PURPOSE:
    (job defs for tlm server)
LIBRARY DEPENDENCY:
    (
        (tlm_server/src/tlm_server.cpp)
        (../../extern/protobetter/protobetter_dynamic_lib/src/protobetterdynamic.cpp)
        (../../extern/ccsds_header_lib/src/cfe/cfe_sb_msg_id_util.c)
        (../../extern/trick_sbn_lib/qsbn.cpp)
        (../../extern/trick_sbn_lib/trick_ccsds_mapping.cpp)
        (../../extern/trick_sbn_lib/trick_ccsds_sim_backend.cpp)
        (../../extern/trick_sbn_lib/trick_ccsds_memory_manager.cpp)
    )
*/

#ifndef __TRICK_TLM_SERVER_H__
#define __TRICK_TLM_SERVER_H__

#include <string>

typedef struct
{
    std::string qsbnJsonConfig;
    std::string tvmFileDir;
    std::string prototypeFileDir;

    // TODO: just here for debugging purposes
    bool useSimulatedTrickBackend;

} TelemetryServerConfig;

typedef struct
{
    bool debugEnabled;
    // TODO: Decide if anything else needs to be exposed
    // or create a TelemetryServer class
} TelemetryServerState;

void InitTlmServer(TelemetryServerConfig *data);
void RunTlmServer(TelemetryServerState *data);
void ShutdownTlmServer(TelemetryServerState *data);

#endif /* __TRICK_TLM_SERVER_H__ */
