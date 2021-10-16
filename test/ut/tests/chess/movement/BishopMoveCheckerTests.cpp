#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <mygame/chess/figure/BishopFigure.hpp>
#include <mygame/chess/figure/PawnFigure.hpp>
#include <mygame/chess/movement/BishopMoveChecker.hpp>
#include <mygame/chess/table/Board.hpp>

namespace chess
{
namespace movement
{
using ::testing::ContainerEq;
using ::testing::Contains;
using ::testing::Pair;
using ::testing::Property;

class BishopMoveCheckerTests : public ::testing::Test
{
protected:
    BishopMoveCheckerTests()
    {
    }

    void prepareBoard();
    void prepareMainFigure(table::Rank rank, table::File file, figure::FigureColor color);

    std::vector<std::unique_ptr<figure::FigureBase>> figures_;
    table::Board board_;
};

void BishopMoveCheckerTests::prepareBoard()
{
    std::vector<table::Rank> ranks = {6, 5, 2};
    std::vector<table::File> files = {table::File('b'), table::File('e'), table::File('b')};

    ASSERT_EQ(ranks.size(), files.size());

    for (unsigned int i = 0; i < ranks.size(); i++)
    {
        figures_.emplace_back(std::make_unique<figure::PawnFigure>(figure::FigureColor::White));

        board_.setFigure(figures_.at(i).get(), ranks.at(i), files.at(i));
    }
}

void BishopMoveCheckerTests::prepareMainFigure(table::Rank rank, table::File file, figure::FigureColor color)
{
    auto figure = std::make_unique<figure::BishopFigure>(color);
    board_.setFigure(figure.get(), rank, file);
    figures_.push_back(std::move(figure));
}

class BishopMoveCheckerTestsParametrized : public BishopMoveCheckerTests, public ::testing::WithParamInterface<std::tuple<table::Rank, table::File, figure::FigureColor>>
{
protected:
    BishopMoveCheckerTestsParametrized()
    {
    }
};

INSTANTIATE_TEST_CASE_P(
    Colors,
    BishopMoveCheckerTestsParametrized,
    ::testing::Values(
        std::make_tuple(table::Rank(4), table::File('d'), figure::FigureColor::White),
        std::make_tuple(table::Rank(4), table::File('d'), figure::FigureColor::Black)));

TEST_P(BishopMoveCheckerTestsParametrized, ShouldFindAvailableMoves)
{
    table::Rank mainFigureRank = std::get<0>(GetParam());
    table::File mainFigureFile = std::get<1>(GetParam());
    auto mainFigureColor = std::get<2>(GetParam());

    prepareBoard();
    prepareMainFigure(mainFigureRank, mainFigureFile, mainFigureColor);

    auto sut = BishopMoveChecker::create(board_);

    auto availableMoves = sut->getAvailablePositions({mainFigureRank, mainFigureFile});

    std::vector<Position> expectedPositions({{5, table::File('c')}, {3, table::File('c')}
    , {3, table::File('e')}, {2, table::File('f')}, {1, table::File('g')}});
    std::sort(availableMoves.begin(), availableMoves.end());
    std::sort(expectedPositions.begin(), expectedPositions.end());

    EXPECT_EQ(availableMoves.size(), expectedPositions.size());
    EXPECT_THAT(availableMoves, ContainerEq(expectedPositions));
}

}  // namespace movement
}  // namespace chess