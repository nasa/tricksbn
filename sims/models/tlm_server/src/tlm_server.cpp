#include "tlm_server/include/tlm_server.hh"

#include <iostream>

void InitTlmServer(TestData *data)
{
    // you can grab all inputs from the python input file and
    // do all your server initialization based on that here...

}

void RunTlmServer(TestData *data)
{
    // this doesn't execute while sim is frozen
}

void ShutdownTlmServer(TestData *data)
{
    std::cout << "result = " << data->result << std::endl;
}
