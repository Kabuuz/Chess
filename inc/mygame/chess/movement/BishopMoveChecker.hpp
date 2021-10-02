#ifndef INC_MYGAME_CHESS_MOVEMENT_BISHOPMOVECHECKER
#define INC_MYGAME_CHESS_MOVEMENT_BISHOPMOVECHECKER

#include <mygame/chess/figure/FigureBase.hpp>
#include <mygame/chess/movement/IMoveChecker.hpp>
#include <mygame/chess/table/Board.hpp>

namespace chess
{
namespace movement
{
class BishopMoveChecker : public IMoveChecker
{
public:
    BishopMoveChecker(table::Board& board);

    std::vector<Position> getAvailablePositions(const Position& actualPosition) const override;

private:
    std::vector<Position> getTopRightPositions(const table::Rank& rank, const table::File& file) const;
    std::vector<Position> getTopLeftPositions(const table::Rank& rank, const table::File& file) const;
    std::vector<Position> getBottomRightPositions(const table::Rank& rank, const table::File& file) const;
    std::vector<Position> getBottomLeftPositions(const table::Rank& rank, const table::File& file) const;

    table::Board& board_;
};
}  // namespace movement
}  // namespace chess

#endif  // INC_MYGAME_CHESS_MOVEMENT_BISHOPMOVECHECKER
