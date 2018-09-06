#include <gtest/gtest.h>

#include "ccsds_header_lib.h"

typedef struct
{
    char header[16];
    char payload[512];

} MyCcsdsMessage;

TEST(CcsdsV2Tests,InitMsgTest)
{
    MyCcsdsMessage msg;

    CFE_SB_MsgId_t expectedMID = (CFE_SB_MsgId_t)0x7E6A;

    CFE_SB_InitMsg(&msg, expectedMID, sizeof(MyCcsdsMessage), TRUE);

    CFE_SB_MsgId_t actualMID = CFE_SB_GetMsgId((CFE_SB_MsgPtr_t)&msg);

    ASSERT_EQ(actualMID, expectedMID);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
