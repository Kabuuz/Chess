#include <iterator>
#include <mygame/chess/movement/CombinedMoveChecker.hpp>
#include <set>

namespace chess
{
namespace movement
{
CombinedMoveChecker::CombinedMoveChecker() = default;

CombinedMoveChecker::CombinedMoveChecker(const CombinedMoveChecker& other)
{
    for (const auto& checker : other.checkers_)
    {
        checkers_.push_back(checker->clone());
    }
}

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

void CombinedMoveChecker::addChecker(IMoveCheckerPtr checker)
{
    checkers_.push_back(std::move(checker));
}

IMoveCheckerPtr CombinedMoveChecker::clone() const
{
    return std::unique_ptr<IMoveChecker>(new CombinedMoveChecker(*this));
}

}  // namespace movement
}  // namespace chess