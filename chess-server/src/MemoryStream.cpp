#include "MemoryStream.h"

const std::string&
MemoryStream::getData() const
{
    return this->data;
}

void
MemoryStream::writeByte(uint8_t value)
{
    this->data.append((const char *)&value, sizeof(value));
}

void
MemoryStream::write(uint32_t value)
{
    writeByte(DataType::UINT32);
    this->data.append((const char *)&value, sizeof(value));
}

void
MemoryStream::write(const std::string& value)
{
    writeByte(DataType::STRING);
    uint32_t size = static_cast<uint32_t>(value.size());
    this->data.append((const char *)&size, sizeof(size));
    this->data.append(value);
}
