#include <gtest/gtest.h>

#include <mygame/chess/movement/PawnMoveChecker.hpp>

namespace chess
{
namespace movement
{
class PawnMoveCheckerTests : public ::testing::Test
{
protected:
    PawnMoveCheckerTests()
    {
    }
};

TEST_F(PawnMoveCheckerTests, Test1)
{
    EXPECT_EQ(1, 1);
}

}  // namespace movement
}  // namespace chess