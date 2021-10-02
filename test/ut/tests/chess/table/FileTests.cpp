#include <gtest/gtest.h>

#include <mygame/chess/table/File.hpp>

namespace chess
{
namespace table
{
class FileTests : public ::testing::Test
{
protected:
    FileTests()
    {
    }
};

TEST_F(FileTests, ShouldReturnMinusOneOnWrongChar)
{
    const int ERROR = -1;
    const char VALUE = '.';
    File sut = VALUE;

    EXPECT_EQ(sut, ERROR);
}

TEST_F(FileTests, ShouldPreIncrement)
{
    const int VALUE = 1;
    File sut = VALUE;

    EXPECT_EQ(++sut, VALUE + 1);
}

TEST_F(FileTests, ShouldPostIncrement)
{
    const int VALUE = 1;
    File sut = VALUE;

    EXPECT_EQ(sut++, VALUE);
    EXPECT_EQ(sut, VALUE + 1);
}

TEST_F(FileTests, ShouldPreDecrement)
{
    const int VALUE = 1;
    File sut = VALUE;

    EXPECT_EQ(--sut, VALUE - 1);
}

TEST_F(FileTests, ShouldPostDecrement)

{
    const int VALUE = 1;
    File sut = VALUE;

    EXPECT_EQ(sut--, VALUE);
    EXPECT_EQ(sut, VALUE - 1);
}

TEST_F(FileTests, ShouldCompareWithRank)
{
    const int VALUE = 1;
    File sut = VALUE;

    EXPECT_EQ(sut, File(VALUE));
}

TEST_F(FileTests, ShouldCompareGreaterEqualThanInt)
{
    const int VALUE = 1;
    File sut = VALUE + 1;

    EXPECT_GE(sut, VALUE);
}

TEST_F(FileTests, ShouldCompareLessThanInt)
{
    const int VALUE = 1;
    File sut = VALUE - 1;

    EXPECT_LT(sut, VALUE);
}

TEST_F(FileTests, ShouldAddInt)
{
    const int VALUE = 1;
    File sut = VALUE;
    sut = sut + VALUE;

    EXPECT_EQ(sut, 2 * VALUE);
}

class FileTestsParametrized : public ::testing::TestWithParam<std::tuple<int, char, char>>
{
protected:
    FileTestsParametrized()
    {
    }
};

INSTANTIATE_TEST_CASE_P(
    Parameters,
    FileTestsParametrized,
    ::testing::Values(
        std::make_tuple(1, 'a', 'A'),
        std::make_tuple(2, 'b', 'B'),
        std::make_tuple(3, 'c', 'C'),
        std::make_tuple(4, 'd', 'D'),
        std::make_tuple(5, 'e', 'E'),
        std::make_tuple(6, 'f', 'F'),
        std::make_tuple(7, 'g', 'G'),
        std::make_tuple(8, 'h', 'H')));

TEST_P(FileTestsParametrized, ShouldSaveInteger)
{
    const int VALUE = std::get<0>(GetParam());
    File sut = VALUE;

    EXPECT_EQ(sut, VALUE);
}

TEST_P(FileTestsParametrized, ShouldSaveCharLowerCase)
{
    const char VALUE = std::get<1>(GetParam());
    File sut = VALUE;

    EXPECT_EQ(sut, VALUE);
}

TEST_P(FileTestsParametrized, ShouldSaveCharUpperCaseAndReturnLowerCase)
{
    const char VALUE_UPPERCASE = std::get<2>(GetParam());
    const char VALUE_LOWERCASE = std::get<1>(GetParam());
    File sut = VALUE_UPPERCASE;

    EXPECT_EQ(sut, VALUE_LOWERCASE);
}

TEST_P(FileTestsParametrized, ShouldConvertUpperCaseToInt)
{
    const char VALUE_UPPERCASE = std::get<2>(GetParam());
    const int VALUE = std::get<0>(GetParam());
    File sut = VALUE_UPPERCASE;

    EXPECT_EQ(sut, VALUE);
}

TEST_P(FileTestsParametrized, ShouldConvertLowerCaseToInt)
{
    const char VALUE_LOWERCASE = std::get<1>(GetParam());
    const int VALUE = std::get<0>(GetParam());
    File sut = VALUE_LOWERCASE;

    EXPECT_EQ(sut, VALUE);
}

}  // namespace table
}  // namespace chess