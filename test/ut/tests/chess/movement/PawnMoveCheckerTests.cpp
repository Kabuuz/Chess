#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <mygame/chess/figure/PawnFigure.hpp>
#include <mygame/chess/movement/PawnMoveChecker.hpp>
#include <mygame/chess/table/Board.hpp>

namespace chess
{
namespace movement
{
using ::testing::Contains;
using ::testing::ElementsAre;
using ::testing::Pair;
using ::testing::Property;

class PawnMoveCheckerTests : public ::testing::Test
{
protected:
    PawnMoveCheckerTests()
    {
    }

    void prepareBoard();
    void prepareMainFigure(table::Rank rank, table::File file, figure::FigureColor color);

    std::vector<std::unique_ptr<figure::FigureBase>> figures_;
    table::Board board_;
};

void PawnMoveCheckerTests::prepareBoard()
{
    std::vector<table::Rank> ranks = {5, 5, 5, 4, 4, 3, 3, 3};
    std::vector<table::File> files = {'c', 'd', 'e', 'c', 'e', 'c', 'd', 'e'};

    ASSERT_EQ(ranks.size(), files.size());

    for (unsigned int i = 0; i < ranks.size(); i++)
    {
        figures_.emplace_back(std::make_unique<figure::PawnFigure>(figure::FigureColor::White));

        board_.setFigure(figures_.at(i).get(), ranks.at(i), files.at(i));
    }
}

void PawnMoveCheckerTests::prepareMainFigure(table::Rank rank, table::File file, figure::FigureColor color)
{
    auto figure = std::make_unique<figure::PawnFigure>(color);
    board_.setFigure(figure.get(), rank, file);
    figures_.push_back(std::move(figure));
}

TEST_F(PawnMoveCheckerTests, WhiteShouldReturnOneSquare)
{
    table::Rank rank(4);
    table::File file('d');
    figure::FigureColor color = figure::FigureColor::White;

    prepareMainFigure(rank, file, color);

    auto sut = PawnMoveChecker::create(board_, color);

    auto availableMoves = sut->getAvailablePositions({rank, file});

    constexpr int expecteNumberOfMoves = 1;
    const table::Rank expectedRank = 5;
    const table::File expectedFile = 'd';

    EXPECT_EQ(availableMoves.size(), expecteNumberOfMoves);
    EXPECT_THAT(availableMoves, ElementsAre(Pair(expectedRank, expectedFile)));
}

TEST_F(PawnMoveCheckerTests, BlackShouldReturnOneSquare)
{
    table::Rank rank(4);
    table::File file('d');
    figure::FigureColor color = figure::FigureColor::Black;

    prepareMainFigure(rank, file, color);

    auto sut = PawnMoveChecker::create(board_, color);

    auto availableMoves = sut->getAvailablePositions({rank, file});

    constexpr int expecteNumberOfMoves = 1;
    const table::Rank expectedRank = 3;
    const table::File expectedFile = 'd';

    EXPECT_EQ(availableMoves.size(), expecteNumberOfMoves);
    EXPECT_THAT(availableMoves, ElementsAre(Pair(expectedRank, expectedFile)));
}

class PawnMoveCheckerTestsParametrized : public PawnMoveCheckerTests, public ::testing::WithParamInterface<std::tuple<table::Rank, table::File, figure::FigureColor>>
{
protected:
    PawnMoveCheckerTestsParametrized()
    {
    }
};

INSTANTIATE_TEST_CASE_P(
    Colors,
    PawnMoveCheckerTestsParametrized,
    ::testing::Values(
        std::make_tuple(table::Rank(4), table::File('d'), figure::FigureColor::White),    //in the center and surrounded
        std::make_tuple(table::Rank(4), table::File('d'), figure::FigureColor::Black),    //in the center and surrounded
        std::make_tuple(table::Rank(8), table::File('d'), figure::FigureColor::White),    //on the border
        std::make_tuple(table::Rank(1), table::File('d'), figure::FigureColor::Black)));  //on the border

TEST_P(PawnMoveCheckerTestsParametrized, ShouldNotFindAnyMovesWhenSurrounded)
{
    table::Rank mainFigureRank = std::get<0>(GetParam());
    table::File mainFigureFile = std::get<1>(GetParam());
    auto mainFigureColor = std::get<2>(GetParam());

    prepareBoard();
    prepareMainFigure(mainFigureRank, mainFigureFile, mainFigureColor);

    auto sut = PawnMoveChecker::create(board_, mainFigureColor);

    auto availableMoves = sut->getAvailablePositions({mainFigureRank, mainFigureFile});

    EXPECT_EQ(availableMoves.size(), 0);
}

}  // namespace movement
}  // namespace chess