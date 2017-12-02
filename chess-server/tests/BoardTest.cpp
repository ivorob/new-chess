#include <gtest/gtest.h>

#include "Board.h"
#include "figures.h"

TEST(BoardTest, create)
{
    Chess::Board board(8, 8);

    ASSERT_EQ(0, board.getId());
    ASSERT_EQ("BOARD", board.getClassId());
    ASSERT_EQ(8, board.getRows());
    ASSERT_EQ(8, board.getColumns());
}

TEST(BoardTest, getFigureById)
{
    Chess::Board board(8, 8);

    try {
        const Chess::Figure& figure = board.getFigureById(1);
        FAIL() << "Must throw exception!";
    } catch (const Chess::BoardException&) {
    }
}

TEST(BoardTest, addFigure)
{
    Chess::Board board(8, 8);

    board.addFigure(Chess::Rook(1, Chess::Figure::Color::White, 0, 0));
    board.addFigure(Chess::Bishop(2, Chess::Figure::Color::White, 0, 5));

    const Chess::Figure& figure = board.getFigureById(1);
    ASSERT_EQ(1, figure.getId());
    ASSERT_EQ("R", figure.getClassId());
    ASSERT_EQ(Chess::Figure::Color::White, figure.getColor());
    ASSERT_EQ(0, figure.getRow());
    ASSERT_EQ(0, figure.getColumn());

    const Chess::Figure& figure1 = board.getFigureById(2);
    ASSERT_EQ(2, figure1.getId());
    ASSERT_EQ("B", figure1.getClassId());
    ASSERT_EQ(Chess::Figure::Color::White, figure1.getColor());
    ASSERT_EQ(0, figure1.getRow());
    ASSERT_EQ(5, figure1.getColumn());
}

TEST(BoardTest, write)
{
    MemoryStream stream;
    const auto& data = stream.getData();
    ASSERT_TRUE(data.empty());

    Chess::Board board(8, 8);

    board.addFigure(Chess::Rook(1, Chess::Figure::Color::White, 0, 0));
    board.addFigure(Chess::Bishop(2, Chess::Figure::Color::White, 0, 5));

    std::string buffer("\x00\x00\x00\x00\x00\x01\x05\x00\x0\x00" "BOARD"
            "\x00\b\x00\x00\x00\x00\b\x00\x00\x00\x00\x02\x00\x00\x00\x00\x01\x00\x00\x00\x01\x01\x00\x00\x00"
            "R\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x02\x00\x00\x00\x01\x01"
            "\x00\x00\x00" "B\x00\x00\x00\x00\x00\x00\x05\x00\x00\x00\x00\x00\x00\x00\x00", 82);
    board.write(stream);
    ASSERT_EQ(buffer, data);
}

TEST(BoardTest, read)
{
    std::string buffer("\x00\x00\x00\x00\x00\x01\x05\x00\x0\x00" "BOARD"
            "\x00\b\x00\x00\x00\x00\b\x00\x00\x00\x00\x02\x00\x00\x00\x00\x01\x00\x00\x00\x01\x01\x00\x00\x00"
            "R\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x02\x00\x00\x00\x01\x01"
            "\x00\x00\x00" "B\x00\x00\x00\x00\x00\x00\x05\x00\x00\x00\x00\x00\x00\x00\x00", 82);
    MemoryStream stream(buffer);

    Chess::Board board;
    board.read(stream);
    ASSERT_EQ(0, board.getId());
    ASSERT_EQ("BOARD", board.getClassId());

    auto figure1 = board.getFigureById(1);
    ASSERT_EQ(1, figure1.getId());
    ASSERT_EQ("R", figure1.getClassId());
    ASSERT_EQ(0, figure1.getRow());
    ASSERT_EQ(0, figure1.getColumn());
    ASSERT_EQ(Chess::Figure::Color::White, figure1.getColor());

    auto figure2 = board.getFigureById(2);
    ASSERT_EQ(2, figure2.getId());
    ASSERT_EQ("B", figure2.getClassId());
    ASSERT_EQ(0, figure2.getRow());
    ASSERT_EQ(5, figure2.getColumn());
    ASSERT_EQ(Chess::Figure::Color::White, figure2.getColor());
}
