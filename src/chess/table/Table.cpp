#include <mygame/chess/table/Table.hpp>

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
constexpr unsigned int PAWN_BLACK_QUANTITY = 8;
constexpr unsigned int ROOK_BLACK_QUANTITY = 2;
constexpr unsigned int KNIGHT_BLACK_QUANTITY = 2;
constexpr unsigned int BISHOP_BLACK_QUANTITY = 2;
constexpr unsigned int PAWN_WHITE_QUANTITY = 8;
constexpr unsigned int ROOK_WHITE_QUANTITY = 2;
constexpr unsigned int KNIGHT_WHITE_QUANTITY = 2;
constexpr unsigned int BISHOP_WHITE_QUANTITY = 2;
}
Table::Table()
    : board_(std::make_unique<Board>())
{
    createCapturedFiguresAreas();
    createAllFigures();
    reset();
}

Board& Table::getBoard()
{
    return *board_;
}

void Table::createAllFigures()
{
    for(unsigned int i = 0; i<PAWN_BLACK_QUANTITY; i++)
    {
        figures_.emplace_back(std::make_unique<figure::PawnFigure>(figure::FigureColor::Black));
    }

    for(unsigned int i = 0; i<ROOK_BLACK_QUANTITY; i++)
    {
        figures_.emplace_back(std::make_unique<figure::RookFigure>(figure::FigureColor::Black));
    }

    for(unsigned int i = 0; i<KNIGHT_BLACK_QUANTITY; i++)
    {
        figures_.emplace_back(std::make_unique<figure::KnightFigure>(figure::FigureColor::Black));
    }

    for(unsigned int i = 0; i<BISHOP_BLACK_QUANTITY; i++)
    {
        figures_.emplace_back(std::make_unique<figure::BishopFigure>(figure::FigureColor::Black));
    }

    figures_.emplace_back(std::make_unique<figure::KingFigure>(figure::FigureColor::Black));
    figures_.emplace_back(std::make_unique<figure::QueenFigure>(figure::FigureColor::Black));

    for(unsigned int i = 0; i<PAWN_WHITE_QUANTITY; i++)
    {
        figures_.emplace_back(std::make_unique<figure::PawnFigure>(figure::FigureColor::White));
    }

    for(unsigned int i = 0; i<ROOK_WHITE_QUANTITY; i++)
    {
        figures_.emplace_back(std::make_unique<figure::RookFigure>(figure::FigureColor::White));
    }

    for(unsigned int i = 0; i<KNIGHT_WHITE_QUANTITY; i++)
    {
        figures_.emplace_back(std::make_unique<figure::KnightFigure>(figure::FigureColor::White));
    }

    for(unsigned int i = 0; i<BISHOP_WHITE_QUANTITY; i++)
    {
        figures_.emplace_back(std::make_unique<figure::BishopFigure>(figure::FigureColor::White));
    }

    figures_.emplace_back(std::make_unique<figure::KingFigure>(figure::FigureColor::White));
    figures_.emplace_back(std::make_unique<figure::QueenFigure>(figure::FigureColor::White));
}

CapturedFiguresArea& Table::getCapturedFiguresArea(figure::FigureColor color)
{
    return *(capturedFiguresAreas_.at(color));
}

void Table::createCapturedFiguresAreas()
{
    capturedFiguresAreas_[figure::FigureColor::White] = std::make_unique<CapturedFiguresArea>(figure::FigureColor::White);
    capturedFiguresAreas_[figure::FigureColor::Black] = std::make_unique<CapturedFiguresArea>(figure::FigureColor::Black);
}

void Table::reset()
{
    resetBoard();
    resetCapturedFiguresAreas();
}

void Table::resetBoard()
{
    board_.reset();
    BoardSetter boardSetter;
    boardSetter.setBoard(*board_, figures_);
}

void Table::resetCapturedFiguresAreas()
{
    for(auto& [color, capturedFiguresArea] : capturedFiguresAreas_)
    {
        capturedFiguresArea->clear();
    }
}

}  // namespace table
}  // namespace chess