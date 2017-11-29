#pragma once

#include "Figure.h"

namespace Chess {

class Pawn : public Figure {
public:
    Pawn(const GameObject::ObjectId& id,
         Figure::Color color,
         uint32_t row = 0,
         uint32_t column = 0);
};

}
