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

typedef struct
{
    std::string tvmFileDir;

} TelemetryServerConfig;

typedef struct
{

} TelemetryServerState;

void InitTlmServer(TelemetryServerConfig *data);
void RunTlmServer(TelemetryServerState *data);
void ShutdownTlmServer(TelemetryServerState *data);

#endif /* __TRICK_TLM_SERVER_H__ */
