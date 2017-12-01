#include "GameObject.h"

GameObject::GameObject(const ObjectId& id, const std::string& classId)
    : id(id),
      classId(classId)
{
}

const GameObject::ObjectId&
GameObject::getId() const
{
    return this->id;
}

const std::string&
GameObject::getClassId() const
{
    return this->classId;
}

void
GameObject::write(MemoryStream& stream) const
{
    stream.write(getId());
    stream.write(getClassId());
}
