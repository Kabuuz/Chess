#ifndef MYGAME_CHESS_MOVEMENT_COMBINEDMOVECHECKERBUILDER_HPP
#define MYGAME_CHESS_MOVEMENT_COMBINEDMOVECHECKERBUILDER_HPP

#include <mygame/chess/movement/CombinedMoveChecker.hpp>

namespace chess
{
namespace movement
{
class CombinedMoveCheckerBuilder
{
public:
    CombinedMoveCheckerBuilder();

    CombinedMoveCheckerBuilder& add(IMoveCheckerPtr checker);
    IMoveCheckerPtr build();

private:
    CombinedMoveChecker combinedChecker_;
};
}  // namespace movement
}  // namespace chess

#endif  // MYGAME_CHESS_MOVEMENT_COMBINEDMOVECHECKERBUILDER_HPP
