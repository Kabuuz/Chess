#include <iterator>
#include <mygame/chess/movement/CombinedMoveChecker.hpp>
#include <set>

namespace chess
{
namespace movement
{
CombinedMoveChecker::CombinedMoveChecker() = default;

std::vector<Position> CombinedMoveChecker::getAvailablePositions(const Position& actualPosition) const
{
    std::vector<Position> availablePositions;

    for (const auto& checker : checkers_)
    {
        std::vector<Position> availablePositionsFromChecker = checker->getAvailablePositions(actualPosition);

        std::copy(availablePositionsFromChecker.begin(), availablePositionsFromChecker.end(), std::back_inserter(availablePositions));
    }

    std::set<Position> uniqueAvailablePositions(availablePositions.begin(), availablePositions.end());

    return std::vector<Position>(uniqueAvailablePositions.begin(), uniqueAvailablePositions.end());
}

void CombinedMoveChecker::addChecker(std::unique_ptr<IMoveChecker> checker)
{
    checkers_.push_back(std::move(checker));
}

}  // namespace movement
}  // namespace chess