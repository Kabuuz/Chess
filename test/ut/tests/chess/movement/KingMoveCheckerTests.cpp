#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <mygame/chess/figure/KingFigure.hpp>
#include <mygame/chess/movement/KingMoveChecker.hpp>
#include <mygame/chess/table/Board.hpp>

namespace chess
{
namespace movement
{
using ::testing::ContainerEq;
using ::testing::Contains;
using ::testing::Pair;
using ::testing::Property;

class KingMoveCheckerTests : public ::testing::Test
{
protected:
    KingMoveCheckerTests()
    {
    }

    void prepareMainFigure(table::Rank rank, table::File file, figure::FigureColor color);

    std::vector<std::unique_ptr<figure::FigureBase>> figures_;
    table::Board board_;
};

void KingMoveCheckerTests::prepareMainFigure(table::Rank rank, table::File file, figure::FigureColor color)
{
    auto figure = std::make_unique<figure::KingFigure>(color);
    board_.setFigure(figure.get(), rank, file);
    figures_.push_back(std::move(figure));
}

class KingMoveCheckerTestsParametrized : public KingMoveCheckerTests, public ::testing::WithParamInterface<std::tuple<table::Rank, table::File, figure::FigureColor>>
{
protected:
    KingMoveCheckerTestsParametrized()
    {
    }
};

INSTANTIATE_TEST_CASE_P(
        Colors,
        KingMoveCheckerTestsParametrized,
        ::testing::Values(
                std::make_tuple(table::Rank(4), table::File('d'), figure::FigureColor::White),
                std::make_tuple(table::Rank(4), table::File('d'), figure::FigureColor::Black)));

TEST_P(KingMoveCheckerTestsParametrized, ShouldFindAvailableMoves)
{
    table::Rank mainFigureRank = std::get<0>(GetParam());
    table::File mainFigureFile = std::get<1>(GetParam());
    auto mainFigureColor = std::get<2>(GetParam());

    prepareMainFigure(mainFigureRank, mainFigureFile, mainFigureColor);

    auto sut = KingMoveChecker::create(board_);

    auto availableMoves = sut->getAvailablePositions({mainFigureRank, mainFigureFile});

    std::vector<Position> expectedPositions({{5,table::File('c')},{5,table::File('d')},{5,table::File('e')}
    ,{4,table::File('c')},{4,table::File('e')},{3,table::File('c')},{3,table::File('d')},{3,table::File('e')}});
    std::sort(availableMoves.begin(), availableMoves.end());
    std::sort(expectedPositions.begin(), expectedPositions.end());

    EXPECT_EQ(availableMoves.size(), expectedPositions.size());
    EXPECT_THAT(availableMoves, ContainerEq(expectedPositions));
}

}  // namespace movement
}  // namespace chess