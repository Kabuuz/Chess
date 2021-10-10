#include <mygame/chess/movement/CombinedMoveCheckerBuilder.hpp>

namespace chess
{
namespace movement
{
CombinedMoveCheckerBuilder::CombinedMoveCheckerBuilder() = default;

CombinedMoveCheckerBuilder& CombinedMoveCheckerBuilder::add(IMoveCheckerPtr checker)
{
    combinedChecker_.addChecker(std::move(checker));
    return *this;
}

IMoveCheckerPtr CombinedMoveCheckerBuilder::build()
{
    return std::unique_ptr<IMoveChecker>(new CombinedMoveChecker(combinedChecker_));
}

}  // namespace movement
}  // namespace chess