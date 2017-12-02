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

TEST(MemoryStreamTest, pickByte)
{
    std::string buffer("\x01\x20\x00\x00\x00", 5);
    MemoryStream stream(buffer);
    ASSERT_EQ(0x01, stream.pickByte());
    ASSERT_EQ(0x01, stream.pickByte());
    ASSERT_EQ(0x01, stream.pickByte());

    MemoryStream stream1;
    try {
        stream1.pickByte();
        FAIL() << "Exception must be present";
    } catch (const std::out_of_range&) {
    }
}

TEST(MemoryStreamTest, readByte)
{
    std::string buffer("\x03\x04\x05", 3);
    MemoryStream stream(buffer);
    ASSERT_EQ(0x03, stream.readByte());
    ASSERT_EQ(0x04, stream.readByte());
    ASSERT_EQ(0x05, stream.readByte());

    try {
        stream.readByte();
        FAIL() << "Exception must be present";
    } catch (const std::out_of_range&) {
    }
}


TEST(MemoryStreamTest, readUint32)
{
    std::string buffer("\x00\x20\x00\x23\x00", 5);
    MemoryStream stream(buffer);

    ASSERT_EQ(0x230020, stream.readUint32());

    std::string data("\x01HELLO");
    MemoryStream stream1(data);

    try {
        stream1.readUint32();
        FAIL() << "Exception must be present";
    } catch (const std::runtime_error&) {
    }
}

TEST(MemoryStreamTest, readString)
{
    std::string data("\x01\x05\x00\x00\x00HELLO", 10);
    MemoryStream stream(data);

    ASSERT_EQ("HELLO", stream.readString());

    std::string buffer("\x00\x05\x00\x00\x00\x00\x04", 7);
    MemoryStream stream1(buffer);
    try {
        stream1.readString();
        FAIL() << "Exception must be present";
    } catch (const std::runtime_error&) {
    }
}
