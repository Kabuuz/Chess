#include <gtest/gtest.h>

#include <mygame/chess/figure/FigureBase.hpp>
#include <mygame/chess/table/CapturedFiguresArea.hpp>

namespace chess
{
namespace table
{
class CapturedFiguresAreaTests : public ::testing::Test
{
protected:
    CapturedFiguresAreaTests()
    {
    }

    std::unique_ptr<CapturedFiguresArea> prepareSut(figure::FigureColor color)
    {
        return std::make_unique<CapturedFiguresArea>(color);
    }
};

TEST_F(CapturedFiguresAreaTests, ShouldNotAddFigureIfNullptr)
{
    auto sut = prepareSut(figure::FigureColor::White);

    EXPECT_EQ(sut->getFigures().size(), 0);

    figure::FigureBase* figure = nullptr;
    sut->add(figure);
    EXPECT_EQ(sut->getFigures().size(), 0);
}

TEST_F(CapturedFiguresAreaTests, ShouldNotAddFigureWithDifferentColor)
{
    auto sut = prepareSut(figure::FigureColor::White);

    EXPECT_EQ(sut->getFigures().size(), 0);

    auto figure = std::make_unique<figure::FigureBase>(figure::FigureType::Pawn, figure::FigureColor::Black);
    sut->add(figure.get());
    EXPECT_EQ(sut->getFigures().size(), 0);
}

TEST_F(CapturedFiguresAreaTests, ShouldNotAddFigureIfAlreadyCaptured)
{
    auto sut = prepareSut(figure::FigureColor::White);

    EXPECT_EQ(sut->getFigures().size(), 0);

    // add figure
    auto figure = std::make_unique<figure::FigureBase>(figure::FigureType::Pawn, figure::FigureColor::White);
    sut->add(figure.get());
    EXPECT_EQ(sut->getFigures().size(), 1);
    // add the same figure
    sut->add(figure.get());
    EXPECT_EQ(sut->getFigures().size(), 1);
}

}  // namespace table
}  // namespace chess