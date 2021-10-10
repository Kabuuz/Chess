#ifndef MYGAME_CHESS_MOVEMENT_KINGMOVECHECKER_HPP
#define MYGAME_CHESS_MOVEMENT_KINGMOVECHECKER_HPP

#include <mygame/chess/movement/IMoveChecker.hpp>
#include <mygame/chess/table/Board.hpp>

namespace chess
{
namespace movement
{
class KingMoveChecker : public IMoveChecker
{
public:
    static IMoveCheckerPtr create(table::Board& board);

    std::vector<Position> getAvailablePositions(const Position& actualPosition) const override;
    IMoveCheckerPtr clone() const override;

private:
    KingMoveChecker(table::Board& board);
    KingMoveChecker(const KingMoveChecker& other);

    table::Board& board_;
};
}  // namespace movement
}  // namespace chess

#endif //MYGAME_CHESS_MOVEMENT_KINGMOVECHECKER_HPP