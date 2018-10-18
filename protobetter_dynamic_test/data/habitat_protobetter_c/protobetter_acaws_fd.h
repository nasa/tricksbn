#ifndef __PROTOBETTER_ACAWS_FD_H__
#define __PROTOBETTER_ACAWS_FD_H__

#ifdef __cplusplus
extern "C"
{
#endif
#include <stdint.h>
#include "protobetter_core.h"

#include "acaws_fd_types.h"


#define STRUCT_ACAWS_FD_TEST_RESULTS_MSG_TYPE_PACKED_SIZE 16 + (1*CFS_ACAWS_FD_TEST_RESULTS_SERIALIZED_SIZE)

uint32_t Packacaws_fd_test_results_msg_type(void *buffer, void *protobetter_type);


uint32_t Unpackacaws_fd_test_results_msg_type(void *protobetter_type, void *buffer);


#include "acaws_fd_types.h"


#define STRUCT_ACAWS_FD_TEST_RESULTS_TYPE_PACKED_SIZE 20 + (1*ACAWS_FD_MAX_MODES) + (1*ACAWS_FD_MAX_TESTS)

uint32_t Packacaws_fd_test_results_type(void *buffer, void *protobetter_type);


uint32_t Unpackacaws_fd_test_results_type(void *protobetter_type, void *buffer);


#include "acaws_fd_types.h"


#define STRUCT_CFS_ACAWS_FD_WAKEUP_PROCESS_T_PACKED_SIZE 12

uint32_t PackCFS_ACAWS_FD_WAKEUP_PROCESS_t(void *buffer, void *protobetter_type);


uint32_t UnpackCFS_ACAWS_FD_WAKEUP_PROCESS_t(void *protobetter_type, void *buffer);


#include "acaws_fd_types.h"


#define STRUCT_CFS_ACAWS_FD_WAKEUP_SEND_T_PACKED_SIZE 12

uint32_t PackCFS_ACAWS_FD_WAKEUP_SEND_t(void *buffer, void *protobetter_type);


uint32_t UnpackCFS_ACAWS_FD_WAKEUP_SEND_t(void *protobetter_type, void *buffer);


#include "acaws_fd_types.h"


#define STRUCT_ACAWS_FD_WAKEUP_MID_PACKED_SIZE 12

uint32_t PackACAWS_FD_WAKEUP_MID(void *buffer, void *protobetter_type);


uint32_t UnpackACAWS_FD_WAKEUP_MID(void *protobetter_type, void *buffer);


#ifdef __cplusplus
}
#endif
#endif //__PROTOBETTER_ACAWS_FD_H__

