#ifndef MYGAME_CHESS_MOVEMENT_PAWNMOVECHECKER_HPP
#define MYGAME_CHESS_MOVEMENT_PAWNMOVECHECKER_HPP

#include <mygame/chess/figure/FigureBase.hpp>
#include <mygame/chess/movement/IMoveChecker.hpp>
#include <mygame/chess/table/Board.hpp>

namespace chess {
namespace movement {
class PawnMoveChecker : public IMoveChecker {
public:
    static IMoveCheckerPtr create(table::Board &board, figure::FigureColor color);

    std::vector<Position> getAvailablePositions(const Position &actualPosition) const override;
    IMoveCheckerPtr clone() const override;

private:
    PawnMoveChecker(table::Board &board, figure::FigureColor color);
    PawnMoveChecker(const PawnMoveChecker &other);

    std::vector<Position> getPositionsForWhitePawn(const Position &actualPosition) const;
    std::vector<Position> getPositionsForBlackPawn(const Position &actualPosition) const;

    table::Board &board_;
    figure::FigureColor color_;
};
}  // namespace movement
}  // namespace chess

#endif  // MYGAME_CHESS_MOVEMENT_PAWNMOVECHECKER_HPP
