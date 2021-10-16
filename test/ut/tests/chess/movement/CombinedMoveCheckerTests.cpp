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
    firstChecker->setAvailableMoves({{1, table::File('a')}, {2, table::File('b')}
    , {3, table::File('c')}, {4, table::File('d')}});
    auto secondChecker = std::make_unique<MoveCheckerStub>();
    secondChecker->setAvailableMoves({{1, table::File('a')}, {5, table::File('e')}
    , {6, table::File('f')}, {7, table::File('g')}, {8, table::File('h')}});

    sut.addChecker(std::move(firstChecker));
    sut.addChecker(std::move(secondChecker));

    Position actualPosition(4, 'd');

    auto availablePositions = sut.getAvailablePositions(actualPosition);

    std::vector<Position> expectedPositions({{1, table::File('a')}, {2, table::File('b')}
    , {3, table::File('c')}, {4, table::File('d')}, {5, table::File('e')}, {6, table::File('f')}
    , {7, table::File('g')}, {8, table::File('h')}});
    std::sort(availablePositions.begin(), availablePositions.end());
    std::sort(expectedPositions.begin(), expectedPositions.end());

    EXPECT_EQ(expectedPositions.size(), availablePositions.size());
    EXPECT_THAT(availablePositions, ContainerEq(expectedPositions));
}

}  // namespace movement
}  // namespace chess