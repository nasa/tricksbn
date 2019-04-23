#ifndef TRICK_CCSDS_UTILS_H
#define TRICK_CCSDS_UTILS_H

#include "trick_ccsds_mapping.h"

namespace TrickCcsdsUtils {

    void SetInt(void *address, uint64_t size, int64_t value);

    void SetUInt(void *address, uint64_t size, uint64_t value);

    void SetFloat(void *address, float value);

    void SetDouble(void *address, double value);

    int64_t GetInt(void *address, uint64_t size);

    uint64_t GetUInt(void *address, uint64_t size);

    float GetFloat(void *address);

    double GetDouble(void *address);

    void PrintProtobetterData(TrickVariableMapping &mapping);
}

#endif // TRICK_CCSDS_UTILS_H
