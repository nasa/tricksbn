
#include "trick_ccsds_memory_manager.h"

TrickMemoryManagerClient::TrickMemoryManagerClient()
{

}

TrickMemoryManagerClient::~TrickMemoryManagerClient()
{

}

int TrickMemoryManagerClient::Initialize(Protobetter::DynamicTypeCollection &prototypes, QJsonArray &trickVariableMappings)
{
    TrickCcsdsMappingClient::Initialize(prototypes, trickVariableMappings);

    for (int i = 0 ; i < this->mappings.size(); ++i)
    {
        // TODO: use the trickFieldNames in this->mappings to get REF2* data
        // and populate this->fieldAccessors with it...
    }

    return 1;
}

namespace
{
    void SetTrickInt(void *address, uint64_t size, int64_t value)
    {
        if (size == 1)
        {
            int8_t data = value;

            memcpy(address, &data, 1);
        }
        else if (size == 2)
        {
            int16_t data = value;

            memcpy(address, &data, 2);
        }
        else if (size == 4)
        {
            int16_t data = value;

            memcpy(address, &data, 4);

        }
        else if (size == 8)
        {
            int64_t data = value;

            memcpy(address, &data, 8);
        }
    }

    void SetTrickUInt(void *address, uint64_t size, uint64_t value)
    {
        if (size == 1)
        {
            uint8_t data = value;

            memcpy(address, &data, 1);
        }
        else if (size == 2)
        {
            uint16_t data = value;

            memcpy(address, &data, 2);
        }
        else if (size == 4)
        {
            uint16_t data = value;

            memcpy(address, &data, 4);

        }
        else if (size == 8)
        {
            uint64_t data = value;

            memcpy(address, &data, 8);
        }
    }

    int64_t GetTrickInt(void *address, uint64_t size)
    {
        int64_t value = -9999;

        if (size == 1)
        {
            int8_t data;

            memcpy(&data, address, 1);

            value = data;
        }
        else if (size == 2)
        {
            int16_t data;

            memcpy(&data, address, 2);

            value = data;
        }
        else if (size == 4)
        {
            int32_t data;

            memcpy(&data, address, 4);

            value = data;
        }
        else if (size == 8)
        {
            int64_t data;

            memcpy(&data, address, 8);

            value = data;
        }

        return value;
    }

    uint64_t GetTrickUInt(void *address, uint64_t size)
    {
        uint64_t value = 9999;

        if (size == 1)
        {
            uint8_t data;

            memcpy(&data, address, 1);

            value = data;
        }
        else if (size == 2)
        {
            uint16_t data;

            memcpy(&data, address, 2);

            value = data;
        }
        else if (size == 4)
        {
            uint32_t data;

            memcpy(&data, address, 4);

            value = data;
        }
        else if (size == 8)
        {
            uint64_t data;

            memcpy(&data, address, 8);

            value = data;
        }

        return value;
    }
}

QVariant TrickMemoryManagerClient::GetData(TrickFieldAccessor &accessor)
{
    QVariant value;

    if (accessor.type == TrickFieldAccessor::Float)
    {
        float data;
        memcpy(&data, accessor.address, 4);

        value = data;
    }
    else if (accessor.type == TrickFieldAccessor::Double)
    {
        double data;
        memcpy(&data, accessor.address, 8);

        value = data;
    }
    else if (accessor.type == TrickFieldAccessor::Int)
    {
        int64_t data = GetTrickInt(accessor.address, accessor.size);

        value = data;
    }
    else if (accessor.type == TrickFieldAccessor::UInt)
    {
        uint64_t data = GetTrickUInt(accessor.address, accessor.size);

        value = data;
    }

    return value;
}

void TrickMemoryManagerClient::SetData(TrickFieldAccessor &accessor, QVariant value)
{
    if (accessor.type == TrickFieldAccessor::Float)
    {
        float data = value.toFloat();

        memcpy(accessor.address, &data, 4);
    }
    else if (accessor.type == TrickFieldAccessor::Double)
    {
        double data = value.toDouble();

        memcpy(accessor.address, &data, 8);
    }
    else if (accessor.type == TrickFieldAccessor::Int)
    {
        SetTrickInt(accessor.address, accessor.size, value.toLongLong());
    }
    else if (accessor.type == TrickFieldAccessor::UInt)
    {
        SetTrickUInt(accessor.address, accessor.size, value.toULongLong());
    }
}

int TrickMemoryManagerClient::ReadData(QCcsdsPacket *packetArray, int maxMessages)
{
    int messageCount = 0;

    for (int i = 0; i < this->mappings.size(); ++i)
    {
        if (this->mappings[i].flowDirection == 1 || this->mappings[i].flowDirection == 3)
        {
            int memberCount = this->mappings[i].ccsdsFieldNames.size();
            uint32_t messageId = this->mappings[i].messageId;

            for (int j = 0; j < memberCount; ++j)
            {
                QVariant data = this->GetData(this->fieldAccessors[messageId][j]);

                this->mappings[i].SetProtobetterField(j, data);
            }
        }
    }

    return messageCount;
}

int TrickMemoryManagerClient::WriteData(QCcsdsPacket &packet)
{
    return -1;
}
