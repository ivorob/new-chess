#pragma once

#include <string>

class MemoryStream {
public:
    MemoryStream();
    MemoryStream(const std::string& data);

    const std::string& getData() const;

    void writeByte(uint8_t value);
    void write(uint32_t value);
    void write(const std::string& value);

    uint8_t pickByte();
    uint8_t readByte();
    uint32_t readUint32();
    std::string readString();
private:
    typedef enum {
        UINT32 = 0,
        STRING,
    } DataType;
private:
    std::string data;
    int position;
};
