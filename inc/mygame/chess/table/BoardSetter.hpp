#ifndef MYGAME_CHESS_TABLE_BOARDSETTER_HPP
#define MYGAME_CHESS_TABLE_BOARDSETTER_HPP

#include <mygame/chess/figure/FigureBase.hpp>
#include <mygame/chess/table/Board.hpp>

#include <map>
#include <memory>
#include <vector>

namespace chess
{
namespace table
{

using FigurePositions = std::vector<Position>;

class BoardSetter
{
public:
    BoardSetter();

    void setBoard(Board& board, const std::vector<std::unique_ptr<figure::FigureBase>>& figures);

private:
    void setFigureOnBoard(Board& board, const figure::FigureBase& figure);
    FigurePositions getBlackFigurePositions(const figure::FigureType type);
    FigurePositions getWhiteFigurePositions(const figure::FigureType type);

    FigurePositions getBlackPawnPositions();
    FigurePositions getBlackRookPositions();
    FigurePositions getBlackBishopPositions();
    FigurePositions getBlackKnightPositions();
    FigurePositions getBlackQueenPositions();
    FigurePositions getBlackKingPositions();
    FigurePositions getWhitePawnPositions();
    FigurePositions getWhiteRookPositions();
    FigurePositions getWhiteBishopPositions();
    FigurePositions getWhiteKnightPositions();
    FigurePositions getWhiteQueenPositions();
    FigurePositions getWhiteKingPositions();
};
}  // namespace table
}  // namespace chess

#endif  // MYGAME_CHESS_TABLE_BOARDSETTER_HPP
