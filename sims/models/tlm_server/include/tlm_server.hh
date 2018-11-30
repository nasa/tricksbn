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

typedef struct
{
    int a;
    int b;

    int result;

} TestData;

void InitTlmServer(TestData *data);
void RunTlmServer(TestData *data);
void ShutdownTlmServer(TestData *data);

#endif /* __TRICK_TLM_SERVER_H__ */
