#include <mygame/chess/movement/KnightMoveChecker.hpp>

namespace chess
{
namespace movement
{
IMoveCheckerPtr KnightMoveChecker::create(table::Board& board)
{
    return std::unique_ptr<KnightMoveChecker>(new KnightMoveChecker(board));
}

KnightMoveChecker::KnightMoveChecker(table::Board& board)
    : board_(board)
{
}

KnightMoveChecker::KnightMoveChecker(const KnightMoveChecker& other)
    : board_(other.board_)
{
}

std::vector<Position> KnightMoveChecker::getAvailablePositions(const Position& actualPosition) const
{
    std::vector<Position> availablePositions;

    std::vector<std::pair<int, int>> rankAndFileCombinations({{2, 1},
                                                              {1, 2},
                                                              {-1, 2},
                                                              {-2, 1},
                                                              {-2, -1},
                                                              {-1, -2},
                                                              {1, -2},
                                                              {2, -1}});

    const auto& [actualRank, actualFile] = actualPosition;

    for (auto [rank, file] : rankAndFileCombinations)
    {
        table::Rank rankToCheck = actualRank + rank;
        table::File fileToCheck = actualFile + file;

        if (rankToCheck >= table::MINIMAL_RANK && rankToCheck < (table::MINIMAL_RANK + table::BOARD_HEIGHT) && fileToCheck >= table::MINIMAL_FILE && fileToCheck < (table::MINIMAL_FILE + table::BOARD_WIDTH))
        {
            if (!board_.isFigurePresent(rankToCheck, fileToCheck))
            {
                availablePositions.push_back({rankToCheck, fileToCheck});
            }
        }
    }

    return availablePositions;
}

IMoveCheckerPtr KnightMoveChecker::clone() const
{
    return std::unique_ptr<IMoveChecker>(new KnightMoveChecker(*this));
}

}  // namespace movement
}  // namespace chess