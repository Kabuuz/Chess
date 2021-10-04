#ifndef INC_MYGAME_CHESS_MOVEMENT_COMBINEDMOVECHECKERBUILDER
#define INC_MYGAME_CHESS_MOVEMENT_COMBINEDMOVECHECKERBUILDER

#include <mygame/chess/movement/CombinedMoveChecker.hpp>

namespace chess
{
namespace movement
{
class CombinedMoveCheckerBuilder
{
public:
    CombinedMoveCheckerBuilder();

    CombinedMoveCheckerBuilder& add(std::unique_ptr<IMoveChecker> checker);
    std::unique_ptr<IMoveChecker> build();

private:
    CombinedMoveChecker combinedChecker_;
};
}  // namespace movement
}  // namespace chess

#endif  // INC_MYGAME_CHESS_MOVEMENT_COMBINEDMOVECHECKERBUILDER
