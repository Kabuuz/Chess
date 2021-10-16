#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <mygame/chess/figure/PawnFigure.hpp>
#include <mygame/chess/figure/RookFigure.hpp>
#include <mygame/chess/movement/RookMoveChecker.hpp>
#include <mygame/chess/table/Board.hpp>

namespace chess
{
namespace movement
{
using ::testing::ContainerEq;
using ::testing::Contains;
using ::testing::Pair;
using ::testing::Property;

class RookMoveCheckerTests : public ::testing::Test
{
protected:
    RookMoveCheckerTests()
    {
    }

    void prepareBoard();
    void prepareMainFigure(table::Rank rank, table::File file, figure::FigureColor color);

    std::vector<std::unique_ptr<figure::FigureBase>> figures_;
    table::Board board_;
};

void RookMoveCheckerTests::prepareBoard()
{
    std::vector<table::Rank> ranks = {6, 6, 4, 4};
    std::vector<table::File> files = {table::File('c'), table::File('d'), table::File('a'), table::File('e')};

    ASSERT_EQ(ranks.size(), files.size());

    for (unsigned int i = 0; i < ranks.size(); i++)
    {
        figures_.emplace_back(std::make_unique<figure::PawnFigure>(figure::FigureColor::White));

        board_.setFigure(figures_.at(i).get(), ranks.at(i), files.at(i));
    }
}

void RookMoveCheckerTests::prepareMainFigure(table::Rank rank, table::File file, figure::FigureColor color)
{
    auto figure = std::make_unique<figure::RookFigure>(color);
    board_.setFigure(figure.get(), rank, file);
    figures_.push_back(std::move(figure));
}

class RookMoveCheckerTestsParametrized : public RookMoveCheckerTests, public ::testing::WithParamInterface<std::tuple<table::Rank, table::File, figure::FigureColor>>
{
protected:
    RookMoveCheckerTestsParametrized()
    {
    }
};

INSTANTIATE_TEST_CASE_P(
    Colors,
    RookMoveCheckerTestsParametrized,
    ::testing::Values(
        std::make_tuple(table::Rank(4), table::File('d'), figure::FigureColor::White),
        std::make_tuple(table::Rank(4), table::File('d'), figure::FigureColor::Black)));

TEST_P(RookMoveCheckerTestsParametrized, ShouldFindAvailableMoves)
{
    table::Rank mainFigureRank = std::get<0>(GetParam());
    table::File mainFigureFile = std::get<1>(GetParam());
    auto mainFigureColor = std::get<2>(GetParam());

    prepareBoard();
    prepareMainFigure(mainFigureRank, mainFigureFile, mainFigureColor);

    auto sut = RookMoveChecker::create(board_);

    auto availableMoves = sut->getAvailablePositions({mainFigureRank, mainFigureFile});

    std::vector<Position> expectedPositions({{5, table::File('d')}, {4, table::File('b')}, {4, table::File('c')}
        , {3, table::File('d')}, {2, table::File('d')}, {1, table::File('d')}});
    std::sort(availableMoves.begin(), availableMoves.end());
    std::sort(expectedPositions.begin(), expectedPositions.end());

    EXPECT_EQ(availableMoves.size(), expectedPositions.size());
    EXPECT_THAT(availableMoves, ContainerEq(expectedPositions));
}

}  // namespace movement
}  // namespace chess