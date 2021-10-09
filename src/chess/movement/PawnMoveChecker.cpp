#include <mygame/chess/movement/PawnMoveChecker.hpp>

namespace chess
{
namespace movement
{
std::unique_ptr<IMoveChecker> PawnMoveChecker::create(table::Board& board, figure::FigureColor color)
{
    return std::make_unique<PawnMoveChecker>(board, color);
}

PawnMoveChecker::PawnMoveChecker(table::Board& board, figure::FigureColor color)
    : board_(board), color_(color)
{
}

PawnMoveChecker::PawnMoveChecker(const PawnMoveChecker& other)
    : board_(other.board_), color_(other.color_)
{
}

std::vector<Position> PawnMoveChecker::getAvailablePositions(const Position& actualPosition) const
{
    if (color_ == figure::FigureColor::White)
    {
        return getPositionsForWhitePawn(actualPosition);
    }
    else
    {
        return getPositionsForBlackPawn(actualPosition);
    }
}

std::vector<Position> PawnMoveChecker::getPositionsForWhitePawn(const Position& actualPosition) const
{
    std::vector<Position> availablePositions;

    auto [rank, file] = actualPosition;

    if (rank == table::BOARD_HEIGHT)
    {
        return {};
    }

    table::Rank nextRank = static_cast<int>(rank) + 1;

    if (board_.getFigure(nextRank, file) == nullptr)
    {
        availablePositions.push_back({nextRank, file});
    }

    return availablePositions;
}
std::vector<Position> PawnMoveChecker::getPositionsForBlackPawn(const Position& actualPosition) const
{
    std::vector<Position> availablePositions;

    auto [rank, file] = actualPosition;

    if (rank == table::MINIMAL_RANK)
    {
        return {};
    }

    table::Rank nextRank = static_cast<int>(rank) - 1;

    if (board_.getFigure(nextRank, file) == nullptr)
    {
        availablePositions.push_back({nextRank, file});
    }

    return availablePositions;
}

std::unique_ptr<IMoveChecker> PawnMoveChecker::clone() const
{
    return std::unique_ptr<IMoveChecker>(new PawnMoveChecker(*this));
}

}  // namespace movement
}  // namespace chess