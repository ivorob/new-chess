#pragma once

#include "Figure.h"

typedef unsigned long long  U64;
#define C64(constantU64) constantU64##ULL

namespace Chess {

class MoveValidator {
public:
    MoveValidator();

    void addFigure(const Figure& figure);
    void print(U64 position) const;
private:
    U64 rankMask(int sq) const; 
    U64 fileMask(int sq) const; 
private:
    const U64 universe = 0xffffffffffffffffULL;
private:
    U64 pieces[2];
};

}
