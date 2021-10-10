#ifndef INC_MYGAME_CHESS_MOVEMENT_ROOKMOVECHECKER
#define INC_MYGAME_CHESS_MOVEMENT_ROOKMOVECHECKER

#include <mygame/chess/figure/FigureBase.hpp>
#include <mygame/chess/movement/IMoveChecker.hpp>
#include <mygame/chess/table/Board.hpp>

namespace chess {
namespace movement {

class RookMoveChecker : public IMoveChecker {
public:
    static IMoveCheckerPtr create(table::Board &board);

    std::vector<Position> getAvailablePositions(const Position &actualPosition) const override;
    IMoveCheckerPtr clone() const override;

private:
    RookMoveChecker(table::Board &board);
    RookMoveChecker(const RookMoveChecker &other);

    std::vector<Position> getPositionsInFile(const table::Rank &rank, const table::File &file) const;
    std::vector<Position> getPositionsInRank(const table::Rank &rank, const table::File &file) const;

    table::Board &board_;
};
}  // namespace movement
}  // namespace chess

#endif  // INC_MYGAME_CHESS_MOVEMENT_ROOKMOVECHECKER
