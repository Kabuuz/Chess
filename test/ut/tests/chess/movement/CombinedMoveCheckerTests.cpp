#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <MoveCheckerStub.hpp>
#include <mygame/chess/movement/CombinedMoveChecker.hpp>

namespace chess
{
namespace movement
{
using ::testing::ContainerEq;

class CombinedMoveCheckerTests : public ::testing::Test
{
protected:
    CombinedMoveCheckerTests()
    {
    }
};

TEST_F(CombinedMoveCheckerTests, ShouldCombineResultsWithoutRepetitions)
{
    CombinedMoveChecker sut;

    auto firstChecker = std::make_unique<MoveCheckerStub>();
    firstChecker->setAvailableMoves({{1, 'a'}, {2, 'b'}, {3, 'c'}, {4, 'd'}});
    auto secondChecker = std::make_unique<MoveCheckerStub>();
    secondChecker->setAvailableMoves({{1, 'a'}, {5, 'e'}, {6, 'f'}, {7, 'g'}, {8, 'h'}});

    sut.addChecker(std::move(firstChecker));
    sut.addChecker(std::move(secondChecker));

    Position actualPosition(4, 'd');

    auto availablePositions = sut.getAvailablePositions(actualPosition);

    std::vector<Position> expectedPositions({{1, 'a'}, {2, 'b'}, {3, 'c'}, {4, 'd'}, {5, 'e'}, {6, 'f'}, {7, 'g'}, {8, 'h'}});
    std::sort(availablePositions.begin(), availablePositions.end());
    std::sort(expectedPositions.begin(), expectedPositions.end());

    EXPECT_EQ(expectedPositions.size(), availablePositions.size());
    EXPECT_THAT(availablePositions, ContainerEq(expectedPositions));
}

}  // namespace movement
}  // namespace chess