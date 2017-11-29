#include "figures/Queen.h"

Queen::Queen(const GameObject::ObjectId& id, Figure::Color color, uint32_t row, uint32_t column)
    : Figure(id, "Q", row, column, color)
{
}
