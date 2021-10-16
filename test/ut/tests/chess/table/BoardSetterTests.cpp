#include <gtest/gtest.h>

#include <mygame/chess/table/BoardSetter.hpp>

#include <mygame/chess/figure/PawnFigure.hpp>
#include <mygame/chess/figure/RookFigure.hpp>
#include <mygame/chess/figure/KnightFigure.hpp>
#include <mygame/chess/figure/BishopFigure.hpp>
#include <mygame/chess/figure/KingFigure.hpp>
#include <mygame/chess/figure/QueenFigure.hpp>

namespace chess
{
namespace table
{

namespace
{
constexpr int PAWN_QUANTITY = 8;
constexpr int ROOK_QUANTITY = 2;
constexpr int KNIGHT_QUANTITY = 2;
constexpr int BISHOP_QUANTITY = 2;
}

class BoardSetterTests : public ::testing::Test
{
protected:
    BoardSetterTests()
    {
    }

    bool hasCorrectArrangement();
    void createFigures();
    bool isFigureCorrect(const Rank& rank, const File& file, figure::FigureType type, figure::FigureColor color);

    std::vector<std::unique_ptr<figure::FigureBase>> figures_;
    Board board_;
};

void BoardSetterTests::createFigures()
{
    for(unsigned int i = 0; i<PAWN_QUANTITY; i++)
    {
        figures_.emplace_back(std::make_unique<figure::PawnFigure>(figure::FigureColor::Black));
        figures_.emplace_back(std::make_unique<figure::PawnFigure>(figure::FigureColor::White));
    }

    for(unsigned int i = 0; i<ROOK_QUANTITY; i++)
    {
        figures_.emplace_back(std::make_unique<figure::RookFigure>(figure::FigureColor::Black));
        figures_.emplace_back(std::make_unique<figure::RookFigure>(figure::FigureColor::White));
    }

    for(unsigned int i = 0; i<KNIGHT_QUANTITY; i++)
    {
        figures_.emplace_back(std::make_unique<figure::KnightFigure>(figure::FigureColor::Black));
        figures_.emplace_back(std::make_unique<figure::KnightFigure>(figure::FigureColor::White));
    }

    for(unsigned int i = 0; i<BISHOP_QUANTITY; i++)
    {
        figures_.emplace_back(std::make_unique<figure::BishopFigure>(figure::FigureColor::Black));
        figures_.emplace_back(std::make_unique<figure::BishopFigure>(figure::FigureColor::White));
    }

    figures_.emplace_back(std::make_unique<figure::KingFigure>(figure::FigureColor::Black));
    figures_.emplace_back(std::make_unique<figure::QueenFigure>(figure::FigureColor::Black));

    figures_.emplace_back(std::make_unique<figure::KingFigure>(figure::FigureColor::White));
    figures_.emplace_back(std::make_unique<figure::QueenFigure>(figure::FigureColor::White));
}

bool BoardSetterTests::isFigureCorrect(const Rank& rank, const File& file, figure::FigureType type, figure::FigureColor color)
{
    if(!board_.isFigurePresent(rank, file))
    {
        return false;
    }

    auto figure = board_.getFigure(rank, file);

    return figure->getType() == type && figure->getColor() == color;
}

bool BoardSetterTests::hasCorrectArrangement()
{
    for(int i =0; i<PAWN_QUANTITY; i++)
    {
        if(!isFigureCorrect(7,File(static_cast<char>('a'+i)), figure::FigureType::Pawn, figure::FigureColor::Black)) return false;
        if(!isFigureCorrect(2,File(static_cast<char>('a'+i)), figure::FigureType::Pawn, figure::FigureColor::White)) return false;
    }

    {
        if(!isFigureCorrect(8,File('a'), figure::FigureType::Rook, figure::FigureColor::Black)) return false;
        if(!isFigureCorrect(1,File('a'), figure::FigureType::Rook, figure::FigureColor::White)) return false;
        if(!isFigureCorrect(8,File('h'), figure::FigureType::Rook, figure::FigureColor::Black)) return false;
        if(!isFigureCorrect(1,File('h'), figure::FigureType::Rook, figure::FigureColor::White)) return false;
    }

    {
        if(!isFigureCorrect(8,File('b'), figure::FigureType::Knight, figure::FigureColor::Black)) return false;
        if(!isFigureCorrect(1,File('b'), figure::FigureType::Knight, figure::FigureColor::White)) return false;
        if(!isFigureCorrect(8,File('g'), figure::FigureType::Knight, figure::FigureColor::Black)) return false;
        if(!isFigureCorrect(1,File('g'), figure::FigureType::Knight, figure::FigureColor::White)) return false;
    }

    {
        if(!isFigureCorrect(8,File('c'), figure::FigureType::Bishop, figure::FigureColor::Black)) return false;
        if(!isFigureCorrect(1,File('c'), figure::FigureType::Bishop, figure::FigureColor::White)) return false;
        if(!isFigureCorrect(8,File('f'), figure::FigureType::Bishop, figure::FigureColor::Black)) return false;
        if(!isFigureCorrect(1,File('f'), figure::FigureType::Bishop, figure::FigureColor::White)) return false;
    }

    {
        if(!isFigureCorrect(8,File('d'), figure::FigureType::Queen, figure::FigureColor::Black)) return false;
        if(!isFigureCorrect(1,File('d'), figure::FigureType::Queen, figure::FigureColor::White)) return false;
    }

    {
        if(!isFigureCorrect(8,File('e'), figure::FigureType::King, figure::FigureColor::Black)) return false;
        if(!isFigureCorrect(1,File('e'), figure::FigureType::King, figure::FigureColor::White)) return false;
    }

    for(Rank rank=3; rank<7; rank++)
    {
        for(File file=MINIMAL_FILE; file<MINIMAL_FILE+BOARD_WIDTH; file++)
        {
            if(board_.isFigurePresent(rank, file)) return false;
        }
    }

    return true;
}

TEST_F(BoardSetterTests, ShouldPutFiguresOnBoard)
{
    createFigures();

    BoardSetter boardSetter;

    EXPECT_FALSE(hasCorrectArrangement());
    boardSetter.setBoard(board_, figures_);
    EXPECT_TRUE(hasCorrectArrangement());
}



}  // namespace table
}  // namespace chess