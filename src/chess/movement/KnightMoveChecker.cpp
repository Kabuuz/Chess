#include <mygame/chess/movement/KnightMoveChecker.hpp>

namespace chess
{
namespace movement
{
KnightMoveChecker::KnightMoveChecker(table::Board& board)
    : board_(board)
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
            if (board_.getFigure(rankToCheck, fileToCheck) != nullptr)
            {
                availablePositions.push_back({rankToCheck, fileToCheck});
            }
        }
    }

    return availablePositions;
}

}  // namespace movement
}  // namespace chess