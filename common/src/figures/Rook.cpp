#include "figures/Rook.h"

Chess::Rook::Rook(const GameObject::ObjectId& id, Chess::Color color, uint32_t row, uint32_t column)
    : Figure(id, "R", row, column, color)
{
}
