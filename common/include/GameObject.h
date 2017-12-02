#pragma once

#include <stdint.h>
#include <string>

#include "MemoryStream.h"

class GameObject {
public:
    typedef uint32_t ObjectId;
public:
    GameObject();
    GameObject(const ObjectId &id, const std::string& classId);
    virtual ~GameObject() = default;

    const ObjectId& getId() const;
    const std::string& getClassId() const;

    virtual void write(MemoryStream& stream) const;
    virtual void read(MemoryStream& stream);
private:
    ObjectId id;
    std::string classId;
};
