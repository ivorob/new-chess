#include "figures/Queen.h"

Chess::Queen::Queen(const GameObject::ObjectId& id, Chess::Color color, uint32_t row, uint32_t column)
    : Figure(id, "Q", row, column, color)
{
}
