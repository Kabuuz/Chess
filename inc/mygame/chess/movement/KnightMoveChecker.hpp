#ifndef MYGAME_CHESS_MOVEMENT_KNIGHTMOVECHECKER_HPP
#define MYGAME_CHESS_MOVEMENT_KNIGHTMOVECHECKER_HPP

#include <mygame/chess/movement/IMoveChecker.hpp>
#include <mygame/chess/table/Board.hpp>

namespace chess
{
namespace movement
{
class KnightMoveChecker : public IMoveChecker
{
public:
    static IMoveCheckerPtr create(table::Board &board);

    std::vector<Position> getAvailablePositions(const Position& actualPosition) const override;
    IMoveCheckerPtr clone() const override;

private:
    KnightMoveChecker(table::Board& board);
    KnightMoveChecker(const KnightMoveChecker& other);

    table::Board& board_;
};
}  // namespace movement
}  // namespace chess

#endif  // MYGAME_CHESS_MOVEMENT_KNIGHTMOVECHECKER_HPP
