#pragma once

#include <string>

class MemoryStream {
public:
    MemoryStream() = default;

    const std::string& getData() const;

    void writeByte(uint8_t value);
    void write(uint32_t value);
    void write(const std::string& value);
private:
    typedef enum {
        UINT32 = 0,
        STRING,
    } DataType;
private:
    std::string data;
};
