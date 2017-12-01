#pragma once

#include "Figure.h"

namespace Chess {

class Rook : public Figure {
public:
    Rook(const GameObject::ObjectId& id,
         Figure::Color color,
         uint32_t row = 0,
         uint32_t column = 0);
};

}
