#include <gtest/gtest.h>

#include "GameObject.h"
#include "MemoryStream.h"

TEST(GameObjectTest, createGameObject)
{
    GameObject gameObject(1, "B");

    ASSERT_EQ(1, gameObject.getId());
    ASSERT_EQ("B", gameObject.getClassId());
}

TEST(GameObjectTest, write)
{
    GameObject gameObject(2, "ROOK");

    MemoryStream stream;
    const auto& data = stream.getData();
    ASSERT_TRUE(data.empty());

    std::string buffer("\x00\x02\x00\x00\x00\x01\x04\x00\x00\x00" "ROOK", 14);
    gameObject.write(stream);
    ASSERT_EQ(buffer, data);
}
