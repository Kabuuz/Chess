#ifndef INC_MYGAME_CHESS_MOVEMENT_COMBINEDMOVECHECKER
#define INC_MYGAME_CHESS_MOVEMENT_COMBINEDMOVECHECKER

#include <memory>
#include <mygame/chess/movement/IMoveChecker.hpp>

namespace chess
{
namespace movement
{
class CombinedMoveChecker : public IMoveChecker
{
public:
    CombinedMoveChecker();
    CombinedMoveChecker(const CombinedMoveChecker& other);

    std::vector<Position> getAvailablePositions(const Position& actualPosition) const override;
    void addChecker(std::unique_ptr<IMoveChecker> checker);
    std::unique_ptr<IMoveChecker> clone() const override;

private:
    std::vector<std::unique_ptr<IMoveChecker>> checkers_;
};
}  // namespace movement
}  // namespace chess

#endif  // INC_MYGAME_CHESS_MOVEMENT_COMBINEDMOVECHECKER
