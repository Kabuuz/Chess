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

TEST_F(FileTests, ShouldSaveInteger)
{
    const int VALUE = 1;
    File sut = VALUE;

    EXPECT_EQ(sut, VALUE);
}

TEST_F(FileTests, ShouldSaveCharLowerCase)
{
    const char VALUE = 'a';
    File sut = VALUE;

    EXPECT_EQ(sut, VALUE);
}

TEST_F(FileTests, ShouldSaveCharUpperCaseAndReturnLowerCase)
{
    const char VALUE_UPPERCASE = 'A';
    const char VALUE_LOWERCASE = 'a';
    File sut = VALUE_UPPERCASE;

    EXPECT_EQ(sut, VALUE_LOWERCASE);
}

TEST_F(FileTests, ShouldReturnMinusOneOnWrongChar)
{
    const int ERROR = -1;
    const char VALUE = '.';
    File sut = VALUE;

    EXPECT_EQ(sut, ERROR);
}

}  // namespace table
}  // namespace chess