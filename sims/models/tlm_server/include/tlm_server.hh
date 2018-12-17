/*
PURPOSE:
    (job defs for tlm server)
LIBRARY DEPENDENCY:
    (
        (tlm_server/src/tlm_server.cpp)
        (../../extern/protobetter/protobetter_dynamic_lib/src/protobetterdynamic.cpp)
        (../../extern/ccsds_header_lib/src/cfe/cfe_sb_msg_id_util.c)
    )
*/

#ifndef __TRICK_TLM_SERVER_H__
#define __TRICK_TLM_SERVER_H__

#include <string>

#if !defined(TRICK_ICG) && !defined(SWIG)

#include "protobetterdynamic.h"
#include "ccsds_header_lib.h"

#endif

typedef struct
{

// TODO: doesn't this mess up offsets for memory manager?
#if !defined(TRICK_ICG) && !defined(SWIG)

    Protobetter::PrototypeCollection prototypes;

#endif

    std::string tvmFileDir;
    std::string prototypeFileDir;

} TelemetryServerConfig;

typedef struct
{

} TelemetryServerState;

void InitTlmServer(TelemetryServerConfig *data);
void RunTlmServer(TelemetryServerState *data);
void ShutdownTlmServer(TelemetryServerState *data);

#endif /* __TRICK_TLM_SERVER_H__ */
