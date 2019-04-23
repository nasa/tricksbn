#include <cstring>
#include <iostream>

#include "trick_ccsds_utils.h"

void TrickCcsdsUtils::SetInt(void *address, uint64_t size, int64_t value) 
{
    switch (size) 
    {
        case 1:
        {
            int8_t data = value;
            memcpy(address, &data, size);
            break;
        }
        case 2:
        {
            int16_t data = value;
            memcpy(address, &data, size);
            break;
        }
        case 4:
        {
            int32_t data = value;
            memcpy(address, &data, size);
            break;
        }
        case 8:
        {
            int64_t data = value;
            memcpy(address, &data, size);
            break;
        }
        default:
        {
            std::cout << "ERROR: Incorrect size (" << size << ") provided to SetTrickInt" << std::endl;
            break;
        }
    }
}

void TrickCcsdsUtils::SetUInt(void *address, uint64_t size, uint64_t value)
{
    switch (size)
    {
        case 1:
        {
            uint8_t data = value;
            memcpy(address, &data, size);
            break;
        }
        case 2:
        {
            uint16_t data = value;
            memcpy(address, &data, size);
            break;
        }
        case 4:
        {
            uint32_t data = value;
            memcpy(address, &data, size);
            break;
        }
        case 8:
        {
            uint64_t data = value;
            memcpy(address, &data, size);
            break;
        }
        default:
        {
            std::cout << "ERROR: Incorrect size (" << size << ") provided to SetTrickUInt" << std::endl;
            break;
        }
    }
}

void TrickCcsdsUtils::SetFloat(void *address, float value)
{
    memcpy(address, &value, 4);
}

void TrickCcsdsUtils::SetDouble(void *address, double value)
{
    memcpy(address, &value, 8);
}

int64_t TrickCcsdsUtils::GetInt(void *address, uint64_t size)
{
    int64_t value = -9999;

    switch (size)
    {
        case 1:
        {
            int8_t data;
            memcpy(&data, address, size);
            value = data;
            break;
        }
        case 2:
        {
            int16_t data;
            memcpy(&data, address, size);
            value = data;
            break;
        }
        case 4:
        {
            int32_t data;
            memcpy(&data, address, size);
            value = data;
            break;
        }
        case 8:
        {
            int64_t data;
            memcpy(&data, address, size);
            value = data;
            break;
        }
        default:
        {
            std::cout << "ERROR: Incorrect size (" << size << ") provided to GetTrickInt" << std::endl;
            break;
        }
    }

    return value;
}

uint64_t TrickCcsdsUtils::GetUInt(void *address, uint64_t size)
{
    uint64_t value = 9999;

    switch (size)
    {
        case 1:
        {
            uint8_t data;
            memcpy(&data, address, size);
            value = data;
            break;
        }
        case 2:
        {
            uint16_t data;
            memcpy(&data, address, size);
            value = data;
            break;
        }
        case 4:
        {
            uint32_t data;
            memcpy(&data, address, size);
            value = data;
            break;
        }
        case 8:
        {
            uint64_t data;
            memcpy(&data, address, size);
            value = data;
            break;
        }
        default:
        {
            std::cout << "ERROR: Incorrect size (" << size << ") provided to GetTrickInt" << std::endl;
            break;
        }
    }

    return value;
}

float TrickCcsdsUtils::GetFloat(void *address)
{
    float value;
    memcpy(&value, address, 4);
    return value;
}

double TrickCcsdsUtils::GetDouble(void *address)
{
    double value;
    memcpy(&value, address, 8);
    return value;
}

void TrickCcsdsUtils::PrintProtobetterData(TrickVariableMapping &mapping)
{
    for (int i = 0; i < mapping.ccsdsFieldNames.size(); ++i)
    {
        std::cout << " - " << mapping.ccsdsFieldNames[i].toStdString() << " = ";

        switch (mapping.ccsdsFieldTypes[i]) 
        {
            case Protobetter::UInt8:
                std::cout << mapping.data->GetUInt8(mapping.ccsdsFieldNames[i]) << std::endl;
                break;

            case Protobetter::UInt16:
                std::cout << mapping.data->GetUInt16(mapping.ccsdsFieldNames[i]) << std::endl;
                break;

            case Protobetter::UInt32:
                std::cout << mapping.data->GetUInt32(mapping.ccsdsFieldNames[i]) << std::endl;
                break;

            case Protobetter::UInt64:
                std::cout << mapping.data->GetUInt64(mapping.ccsdsFieldNames[i]) << std::endl;
                break;

            case Protobetter::Int8:
                std::cout << mapping.data->GetInt8(mapping.ccsdsFieldNames[i]) << std::endl;
                break;

            case Protobetter::Int16:
                std::cout << mapping.data->GetInt16(mapping.ccsdsFieldNames[i]) << std::endl;
                break;

            case Protobetter::Int32:
                std::cout << mapping.data->GetInt16(mapping.ccsdsFieldNames[i]) << std::endl;
                break;

            case Protobetter::Int64:
                std::cout << mapping.data->GetInt64(mapping.ccsdsFieldNames[i]) << std::endl;
                break;

            case Protobetter::Float:
                std::cout << mapping.data->GetFloat(mapping.ccsdsFieldNames[i]) << std::endl;
                break;

            case Protobetter::Double:
                std::cout << mapping.data->GetDouble(mapping.ccsdsFieldNames[i]) << std::endl;
                break;

            default:
                break;
        }
    }

    std::cout << std::endl;
}

