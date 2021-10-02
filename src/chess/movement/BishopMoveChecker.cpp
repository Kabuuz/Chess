#include <mygame/chess/movement/BishopMoveChecker.hpp>

namespace chess
{
namespace movement
{
BishopMoveChecker::BishopMoveChecker(table::Board& board)
    : board_(board)
{
}

std::vector<Position> BishopMoveChecker::getAvailablePositions(const Position& actualPosition) const
{
    std::vector<Position> availablePositions;

    const auto& [rank, file] = actualPosition;

    //TODO
    std::vector<Position> topRightPositions = getTopRightPositions(rank, file);
    availablePositions.insert(availablePositions.end(), topRightPositions.begin(), topRightPositions.end());

    std::vector<Position> topLeftPositions = getTopLeftPositions(rank, file);
    availablePositions.insert(availablePositions.end(), topLeftPositions.begin(), topLeftPositions.end());

    std::vector<Position> bottomRightPositions = getBottomRightPositions(rank, file);
    availablePositions.insert(availablePositions.end(), bottomRightPositions.begin(), bottomRightPositions.end());

    std::vector<Position> bottomLeftPositions = getBottomLeftPositions(rank, file);
    availablePositions.insert(availablePositions.end(), bottomLeftPositions.begin(), bottomLeftPositions.end());

    return availablePositions;
}

std::vector<Position> BishopMoveChecker::getTopRightPositions(const table::Rank& rank, const table::File& file) const
{
    std::vector<Position> availablePositions;

    table::Rank rankToCheck = rank + 1;
    table::File fileToCheck = file + 1;

    while (rankToCheck < (table::MINIMAL_RANK + table::BOARD_HEIGHT) && fileToCheck < (table::MINIMAL_FILE + table::BOARD_WIDTH))
    {
        if (board_.getFigure(rankToCheck, fileToCheck) == nullptr)
        {
            availablePositions.push_back({rankToCheck, fileToCheck});
        }
        else
        {
            break;
        }

        rankToCheck++;
        fileToCheck++;
    }

    return availablePositions;
}

std::vector<Position> BishopMoveChecker::getTopLeftPositions(const table::Rank& rank, const table::File& file) const
{
    std::vector<Position> availablePositions;

    table::Rank rankToCheck = rank + 1;
    table::File fileToCheck = file - 1;

    while (rankToCheck < (table::MINIMAL_RANK + table::BOARD_HEIGHT) && fileToCheck >= table::MINIMAL_FILE)
    {
        if (board_.getFigure(rankToCheck, fileToCheck) == nullptr)
        {
            availablePositions.push_back({rankToCheck, fileToCheck});
        }
        else
        {
            break;
        }

        rankToCheck++;
        fileToCheck--;
    }

    return availablePositions;
}

std::vector<Position> BishopMoveChecker::getBottomRightPositions(const table::Rank& rank, const table::File& file) const
{
    std::vector<Position> availablePositions;

    table::Rank rankToCheck = rank - 1;
    table::File fileToCheck = file + 1;

    while (rankToCheck >= table::MINIMAL_RANK && fileToCheck < (table::MINIMAL_FILE + table::BOARD_WIDTH))
    {
        if (board_.getFigure(rankToCheck, fileToCheck) == nullptr)
        {
            availablePositions.push_back({rankToCheck, fileToCheck});
        }
        else
        {
            break;
        }

        rankToCheck--;
        fileToCheck++;
    }

    return availablePositions;
}

std::vector<Position> BishopMoveChecker::getBottomLeftPositions(const table::Rank& rank, const table::File& file) const
{
    std::vector<Position> availablePositions;

    table::Rank rankToCheck = rank - 1;
    table::File fileToCheck = file - 1;

    while (rankToCheck >= table::MINIMAL_RANK && fileToCheck >= table::MINIMAL_FILE)
    {
        if (board_.getFigure(rankToCheck, fileToCheck) == nullptr)
        {
            availablePositions.push_back({rankToCheck, fileToCheck});
        }
        else
        {
            break;
        }

        rankToCheck--;
        fileToCheck--;
    }

    return availablePositions;
}

}  // namespace movement
}  // namespace chess