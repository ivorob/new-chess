#include "figures/King.h"

King::King(const GameObject::ObjectId& id, Figure::Color color, uint32_t row, uint32_t column)
    : Figure(id, "K", row, column, color)
{
}
