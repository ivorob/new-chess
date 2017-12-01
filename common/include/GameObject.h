#pragma once

#include <stdint.h>
#include <string>

#include "MemoryStream.h"

class GameObject {
public:
    typedef uint32_t ObjectId;
public:
    GameObject(const ObjectId &id, const std::string& classId);
    virtual ~GameObject() = default;

    const ObjectId& getId() const;
    const std::string& getClassId() const;

    virtual void write(MemoryStream& stream) const;
private:
    ObjectId id;
    std::string classId;
};
