#pragma once

#include "Figure.h"

class Bishop : public Figure {
public:
    Bishop(const GameObject::ObjectId& id,
           Figure::Color color,
           uint32_t row = 0,
           uint32_t column = 0);
};
