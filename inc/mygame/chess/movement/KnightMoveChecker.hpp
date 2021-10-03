#ifndef INC_MYGAME_CHESS_MOVEMENT_KNIGHTMOVECHECKER
#define INC_MYGAME_CHESS_MOVEMENT_KNIGHTMOVECHECKER

#include <mygame/chess/figure/FigureBase.hpp>
#include <mygame/chess/movement/IMoveChecker.hpp>
#include <mygame/chess/table/Board.hpp>

namespace chess
{
namespace movement
{
class KnightMoveChecker : public IMoveChecker
{
public:
    KnightMoveChecker(table::Board& board);

    std::vector<Position> getAvailablePositions(const Position& actualPosition) const override;

private:
    table::Board& board_;
};
}  // namespace movement
}  // namespace chess

#endif  // INC_MYGAME_CHESS_MOVEMENT_KNIGHTMOVECHECKER
