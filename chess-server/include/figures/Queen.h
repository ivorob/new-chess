#pragma once

#include "Figure.h"

class Queen : public Figure {
public:
    Queen(const GameObject::ObjectId& id,
          Figure::Color color,
          uint32_t row = 0,
          uint32_t column = 0);
};
