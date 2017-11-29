#pragma once

#include "Figure.h"

class King : public Figure {
public:
    King(const GameObject::ObjectId& id,
         Figure::Color color,
         uint32_t row = 0,
         uint32_t column = 0);
};
