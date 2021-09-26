#include <gtest/gtest.h>

#include <mygame/chess/table/Rank.hpp>

namespace chess
{
namespace table
{
class RankTests : public ::testing::Test
{
protected:
    RankTests()
    {
    }
};

TEST_F(RankTests, ShouldConvertInt)
{
    const int VALUE = 1;
    Rank sut = VALUE;

    EXPECT_EQ(sut, VALUE);
}

}  // namespace table
}  // namespace chess