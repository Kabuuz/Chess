#ifndef TEST_UT_STUBS_MOVECHECKERSTUB
#define TEST_UT_STUBS_MOVECHECKERSTUB

#include <mygame/chess/movement/IMoveChecker.hpp>

namespace chess
{
namespace movement
{
class MoveCheckerStub : public IMoveChecker
{
public:
    MoveCheckerStub() = default;
    MoveCheckerStub(const MoveCheckerStub& other) = default;

    std::vector<Position> getAvailablePositions(const Position& actualPosition) const override;
    void setAvailableMoves(std::initializer_list<Position> availablePositions);
    std::unique_ptr<IMoveChecker> clone() const override;

private:
    std::vector<Position> availablePositions_;
};

std::vector<Position> MoveCheckerStub::getAvailablePositions(const Position& actualPosition) const
{
    (void)actualPosition;  //silence unsused variable
    return availablePositions_;
}

void MoveCheckerStub::setAvailableMoves(std::initializer_list<Position> availablePositions)
{
    availablePositions_ = std::move(availablePositions);
}

std::unique_ptr<IMoveChecker> MoveCheckerStub::clone() const
{
    return std::unique_ptr<IMoveChecker>(new MoveCheckerStub(*this));
}

}  // namespace movement
}  // namespace chess

#endif  // TEST_UT_STUBS_MOVECHECKERSTUB
