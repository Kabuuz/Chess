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
    static IMoveCheckerPtr create(table::Board& board);

    std::vector<Position> getAvailablePositions(const Position& actualPosition) const override;
    IMoveCheckerPtr clone() const override;

private:
    BishopMoveChecker(table::Board& board);
    BishopMoveChecker(const BishopMoveChecker& other);

    std::vector<Position> getTopRightPositions(const table::Rank& rank, const table::File& file) const;
    std::vector<Position> getTopLeftPositions(const table::Rank& rank, const table::File& file) const;
    std::vector<Position> getBottomRightPositions(const table::Rank& rank, const table::File& file) const;
    std::vector<Position> getBottomLeftPositions(const table::Rank& rank, const table::File& file) const;

    table::Board& board_;
};
}  // namespace movement
}  // namespace chess

#endif  // INC_MYGAME_CHESS_MOVEMENT_BISHOPMOVECHECKER
