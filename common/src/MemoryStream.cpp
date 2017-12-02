#include "MemoryStream.h"

MemoryStream::MemoryStream()
    : position()
{
}

MemoryStream::MemoryStream(const std::string& data)
    : data(data),
      position()
{
}

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

uint8_t
MemoryStream::pickByte()
{
    if (this->position >= this->data.size()) {
        throw std::out_of_range("Stream is end");
    }

    return this->data[this->position];
}

uint8_t
MemoryStream::readByte()
{
    uint8_t result = pickByte();
    ++this->position;
    return result;
}

uint32_t
MemoryStream::readUint32()
{
    if (pickByte() != DataType::UINT32) {
        throw std::runtime_error("Invalid type");
    }

    readByte();
    uint32_t result = *((uint32_t *)&this->data[this->position]);
    this->position += 4;
    return result;
}

std::string
MemoryStream::readString()
{
    if (pickByte() != DataType::STRING) {
        throw std::runtime_error("Invalid type");
    }

    readByte();
    if (this->data.size() < 5) {
        throw std::runtime_error("Invalid data size");
    }

    uint32_t size = *((uint32_t *)&this->data[this->position]);
    this->position += 4;
    if (this->data.size() < size + 5) {
        throw std::runtime_error("Invalid data size");
    }

    std::string result = this->data.substr(this->position, size);
    this->position += size;
    return result;
}
