#include <gtest/gtest.h>

#include "Figures.h"

TEST(FiguresTest, Bishop)
{
    Chess::Bishop blackBishop(1, Chess::Figure::Color::Black, 1, 2);

    ASSERT_EQ(1, blackBishop.getId());
    ASSERT_EQ("B", blackBishop.getClassId());
    ASSERT_EQ(Chess::Figure::Color::Black, blackBishop.getColor());
    ASSERT_EQ(1, blackBishop.getRow());
    ASSERT_EQ(2, blackBishop.getColumn());
}

TEST(FiguresTest, King)
{
    Chess::King blackKing(1, Chess::Figure::Color::Black, 1, 2);

    ASSERT_EQ(1, blackKing.getId());
    ASSERT_EQ("K", blackKing.getClassId());
    ASSERT_EQ(Chess::Figure::Color::Black, blackKing.getColor());
    ASSERT_EQ(1, blackKing.getRow());
    ASSERT_EQ(2, blackKing.getColumn());
}

TEST(FiguresTest, Knight)
{
    Chess::Knight blackKnight(1, Chess::Figure::Color::Black, 1, 2);

    ASSERT_EQ(1, blackKnight.getId());
    ASSERT_EQ("N", blackKnight.getClassId());
    ASSERT_EQ(Chess::Figure::Color::Black, blackKnight.getColor());
    ASSERT_EQ(1, blackKnight.getRow());
    ASSERT_EQ(2, blackKnight.getColumn());
}

TEST(FiguresTest, Pawn)
{
    Chess::Pawn blackPawn(1, Chess::Figure::Color::Black, 1, 2);

    ASSERT_EQ(1, blackPawn.getId());
    ASSERT_EQ("P", blackPawn.getClassId());
    ASSERT_EQ(Chess::Figure::Color::Black, blackPawn.getColor());
    ASSERT_EQ(1, blackPawn.getRow());
    ASSERT_EQ(2, blackPawn.getColumn());
}

TEST(FiguresTest, Queen)
{
    Chess::Queen blackQueen(1, Chess::Figure::Color::Black, 1, 2);

    ASSERT_EQ(1, blackQueen.getId());
    ASSERT_EQ("Q", blackQueen.getClassId());
    ASSERT_EQ(Chess::Figure::Color::Black, blackQueen.getColor());
    ASSERT_EQ(1, blackQueen.getRow());
    ASSERT_EQ(2, blackQueen.getColumn());
}

TEST(FiguresTest, Rook)
{
    Chess::Rook blackRook(1, Chess::Figure::Color::Black, 1, 2);

    ASSERT_EQ(1, blackRook.getId());
    ASSERT_EQ("R", blackRook.getClassId());
    ASSERT_EQ(Chess::Figure::Color::Black, blackRook.getColor());
    ASSERT_EQ(1, blackRook.getRow());
    ASSERT_EQ(2, blackRook.getColumn());
}
