#include <iostream>
#include "MoveValidator.h"
#include "GameConstants.h"

Chess::MoveValidator::MoveValidator()
{
    this->pieces[0] = 0;
    this->pieces[1] = 0;
}

void
Chess::MoveValidator::addFigure(const Figure& figure)
{
    this->pieces[figure.getColor()] |= 1ULL << (64 - (figure.getRow() * 8 + (8 - figure.getColumn())));
}

void
Chess::MoveValidator::print(U64 position) const
{
    position = this->pieces[Chess::Color::White];
    for (int file = 0; file < 8; ++file) {
        for (int rank = 0; rank < 8; ++rank) {
            if ((position & (1ULL << (file * 8 + rank))) != 0) {
                std::cout << " 1 ";
            } else {
                std::cout << " 0 ";
            }
        }
        
        std::cout << std::endl;
    }
}

U64
Chess::MoveValidator::rankMask(int sq) const
{
    return C64(0xff) << (sq & 56);
}

U64
Chess::MoveValidator::fileMask(int sq) const
{
    return C64(0x0101010101010101) << (sq & 7);
}
