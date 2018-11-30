#include "tlm_server/include/tlm_server.hh"

#include <iostream>

void InitTlmServer(TelemetryServerConfig *config)
{
    // you can grab all inputs from the python input file and
    // do all your server initialization based on that here...

    std::cout << "TELEMETRY_SERVER: TVM File Directory = " << config->tvmFileDir << std::endl;
}

void RunTlmServer(TelemetryServerState *data)
{
    // this doesn't execute while sim is frozen
}

void ShutdownTlmServer(TelemetryServerState *data)
{
}
