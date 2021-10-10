#ifndef MYGAME_CHESS_MOVEMENT_FWD_HPP
#define MYGAME_CHESS_MOVEMENT_FWD_HPP

namespace chess
{
namespace movement
{
class IMoveChecker;
using IMoveCheckerPtr = std::unique_ptr<IMoveChecker>;
}
}

#endif //MYGAME_CHESS_MOVEMENT_FWD_HPP
