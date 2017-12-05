#include "figures/King.h"

Chess::King::King(const GameObject::ObjectId& id, Chess::Color color, uint32_t row, uint32_t column)
    : Figure(id, "K", row, column, color)
{
}
