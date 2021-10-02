#ifndef INC_MYGAME_CHESS_MOVEMENT_PAWNMOVECHECKER
#define INC_MYGAME_CHESS_MOVEMENT_PAWNMOVECHECKER

#include <mygame/chess/figure/FigureBase.hpp>
#include <mygame/chess/movement/IMoveChecker.hpp>
#include <mygame/chess/table/Board.hpp>

namespace chess
{
namespace movement
{
class PawnMoveChecker : public IMoveChecker
{
public:
    PawnMoveChecker(table::Board& board, figure::FigureColor color);

    std::vector<Position> getAvailablePositions(const Position& actualPosition) const override;

private:
    std::vector<Position> getPositionsForWhitePawn(const Position& actualPosition) const;
    std::vector<Position> getPositionsForBlackPawn(const Position& actualPosition) const;

    table::Board& board_;
    figure::FigureColor color_;
};
}  // namespace movement
}  // namespace chess

#endif  // INC_MYGAME_CHESS_MOVEMENT_PAWNMOVECHECKER