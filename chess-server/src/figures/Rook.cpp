#include "figures/Rook.h"

Rook::Rook(const GameObject::ObjectId& id, Figure::Color color, uint32_t row, uint32_t column)
    : Figure(id, "R", row, column, color)
{
}
