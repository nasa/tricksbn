#ifndef __TRICK_TLM_SERVER_H__
#define __TRICK_TLM_SERVER_H__

typedef struct
{
    int a;
    int b;

    int result;

} TestData;

void InitServer(TestData &data);
void Run(TestData &data);
void Shutdown(TestData &data);

#endif /* __TRICK_TLM_SERVER_H__ */
