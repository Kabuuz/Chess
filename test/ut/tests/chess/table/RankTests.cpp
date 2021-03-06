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

TEST_F(RankTests, ShouldConvertAndCompareWithInt)
{
    const int VALUE = 1;
    Rank sut = VALUE;

    EXPECT_EQ(sut, VALUE);
}

TEST_F(RankTests, ShouldPreIncrement)
{
    const int VALUE = 1;
    Rank sut = VALUE;

    EXPECT_EQ(++sut, VALUE + 1);
}

TEST_F(RankTests, ShouldPostIncrement)
{
    const int VALUE = 1;
    Rank sut = VALUE;

    EXPECT_EQ(sut++, VALUE);
    EXPECT_EQ(sut, VALUE + 1);
}

TEST_F(RankTests, ShouldPreDecrement)
{
    const int VALUE = 1;
    Rank sut = VALUE;

    EXPECT_EQ(--sut, VALUE - 1);
}

TEST_F(RankTests, ShouldPostDecrement)

{
    const int VALUE = 1;
    Rank sut = VALUE;

    EXPECT_EQ(sut--, VALUE);
    EXPECT_EQ(sut, VALUE - 1);
}

TEST_F(RankTests, ShouldCompareWithRank)
{
    const int VALUE = 1;
    Rank sut = VALUE;

    EXPECT_EQ(sut, Rank(VALUE));
}

TEST_F(RankTests, ShouldCompareGreaterEqualThanInt)
{
    const int VALUE = 1;
    Rank sut = VALUE + 1;

    EXPECT_GE(sut, VALUE);
}

TEST_F(RankTests, ShouldCompareLessThanInt)
{
    const int VALUE = 1;
    Rank sut = VALUE - 1;

    EXPECT_LT(sut, VALUE);
}

TEST_F(RankTests, ShouldAddInt)
{
    const int VALUE = 1;
    Rank sut = VALUE;
    sut = sut + VALUE;

    EXPECT_EQ(sut, 2 * VALUE);
}

TEST_F(RankTests, ShouldSubtractInt)
{
    const int VALUE = 1;
    Rank sut = VALUE;
    sut = sut - VALUE;

    EXPECT_EQ(sut, 0);
}

}  // namespace table
}  // namespace chess