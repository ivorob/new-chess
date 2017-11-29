#include "figures/Knight.h"

Chess::Knight::Knight(const GameObject::ObjectId& id, Figure::Color color, uint32_t row, uint32_t column)
    : Figure(id, "N", row, column, color)
{
}
