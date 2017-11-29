#include <gtest/gtest.h>
#include "MemoryStream.h"

TEST(MemoryStreamTest, writeByte)
{
    MemoryStream stream;
    stream.writeByte(0x27);

    std::string buffer("\x27", 1);

    const auto& data = stream.getData();
    ASSERT_EQ(buffer, data);
}

TEST(MemoryStreamTest, writeUint32)
{
    MemoryStream stream;
    stream.write(0x20);

    std::string buffer("\x00\x20\x00\x00\x00", 5);

    const auto& data = stream.getData();
    ASSERT_EQ(buffer, data);
}

TEST(MemoryStreamTest, writeString)
{
    MemoryStream stream;
    stream.write("Hello");

    std::string buffer("\x01\x05\x00\x00\x00Hello", 10);
    ASSERT_EQ(buffer, stream.getData());
}
