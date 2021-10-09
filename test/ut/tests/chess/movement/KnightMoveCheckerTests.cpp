#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <mygame/chess/figure/KnightFigure.hpp>
#include <mygame/chess/figure/PawnFigure.hpp>
#include <mygame/chess/movement/KnightMoveChecker.hpp>
#include <mygame/chess/table/Board.hpp>

namespace chess
{
namespace movement
{
using ::testing::ContainerEq;
using ::testing::Contains;
using ::testing::Pair;
using ::testing::Property;

class KnightMoveCheckerTests : public ::testing::Test
{
protected:
    KnightMoveCheckerTests()
    {
    }

    void prepareBoard();
    void prepareMainFigure(table::Rank rank, table::File file, figure::FigureColor color);

    std::vector<std::unique_ptr<figure::FigureBase>> figures_;
    table::Board board_;
};

void KnightMoveCheckerTests::prepareBoard()
{
    std::vector<table::Rank> ranks = {6, 5, 3, 2};
    std::vector<table::File> files = {'c', 'c', 'e', 'c'};

    ASSERT_EQ(ranks.size(), files.size());

    for (unsigned int i = 0; i < ranks.size(); i++)
    {
        figures_.emplace_back(std::make_unique<figure::PawnFigure>(figure::FigureColor::White));

        board_.setFigure(figures_.at(i).get(), ranks.at(i), files.at(i));
    }
}

void KnightMoveCheckerTests::prepareMainFigure(table::Rank rank, table::File file, figure::FigureColor color)
{
    auto figure = std::make_unique<figure::KnightFigure>(color);
    board_.setFigure(figure.get(), rank, file);
    figures_.push_back(std::move(figure));
}

class KnightMoveCheckerTestsParametrized : public KnightMoveCheckerTests, public ::testing::WithParamInterface<std::tuple<table::Rank, table::File, figure::FigureColor>>
{
protected:
    KnightMoveCheckerTestsParametrized()
    {
    }
};

INSTANTIATE_TEST_CASE_P(
    Colors,
    KnightMoveCheckerTestsParametrized,
    ::testing::Values(
        std::make_tuple(table::Rank(4), table::File('d'), figure::FigureColor::White),
        std::make_tuple(table::Rank(4), table::File('d'), figure::FigureColor::Black)));

TEST_P(KnightMoveCheckerTestsParametrized, ShouldFindAvailableMoves)
{
    table::Rank mainFigureRank = std::get<0>(GetParam());
    table::File mainFigureFile = std::get<1>(GetParam());
    auto mainFigureColor = std::get<2>(GetParam());

    prepareBoard();
    prepareMainFigure(mainFigureRank, mainFigureFile, mainFigureColor);

    auto sut = KnightMoveChecker::create(board_);

    auto availableMoves = sut->getAvailablePositions({mainFigureRank, mainFigureFile});

    std::vector<Position> expectedPositions({{6, 'e'}, {5, 'f'}, {3, 'f'}, {2, 'e'}, {3, 'b'}, {5, 'b'}});
    std::sort(availableMoves.begin(), availableMoves.end());
    std::sort(expectedPositions.begin(), expectedPositions.end());

    EXPECT_EQ(availableMoves.size(), expectedPositions.size());
    EXPECT_THAT(availableMoves, ContainerEq(expectedPositions));
}

}  // namespace movement
}  // namespace chess