#include <gtest/gtest.h>
#include <mygame/temp/Dummy.hpp>

#include <IDummyMock.hpp>

using testing::_;

namespace temp
{
TEST(CategoryTest, SpecificTest)
{
    IDummyMock mock;
    Dummy dummy(&mock);

    EXPECT_CALL(mock, method1).Times(1);

    dummy.hello();

    ASSERT_EQ(0, 0);
}

}   // namespace temp
