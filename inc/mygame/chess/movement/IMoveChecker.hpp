#ifndef INC_MYGAME_CHESS_MOVEMENT_IMOVECHECKER
#define INC_MYGAME_CHESS_MOVEMENT_IMOVECHECKER

namespace chess
{
namespace movement
{
class IMoveChecker
{
public:
    //TODO
    /*
        Add method which will return vector of pairs (rank, file) with available moves
    */

    virtual ~IMoveChecker() = default;
};
}  // namespace movement
}  // namespace chess

#endif  // INC_MYGAME_CHESS_MOVEMENT_IMOVECHECKER
