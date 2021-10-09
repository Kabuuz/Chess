#include <mygame/chess/movement/RookMoveChecker.hpp>

namespace chess
{
namespace movement
{
std::unique_ptr<IMoveChecker> RookMoveChecker::create(table::Board& board)
{
    return std::make_unique<RookMoveChecker>(board);
}

RookMoveChecker::RookMoveChecker(table::Board& board)
    : board_(board)
{
}

RookMoveChecker::RookMoveChecker(const RookMoveChecker& other)
    : board_(other.board_)
{
}

std::vector<Position> RookMoveChecker::getAvailablePositions(const Position& actualPosition) const
{
    std::vector<Position> availablePositions;

    const auto& [rank, file] = actualPosition;

    // in the same rank
    std::vector<Position> availablePositionsInRank = getPositionsInRank(rank, file);
    availablePositions.insert(availablePositions.end(), availablePositionsInRank.begin(), availablePositionsInRank.end());

    // in the same file
    std::vector<Position> availablePositionsInFile = getPositionsInFile(rank, file);
    availablePositions.insert(availablePositions.end(), availablePositionsInFile.begin(), availablePositionsInFile.end());

    return availablePositions;
}

std::vector<Position> RookMoveChecker::getPositionsInFile(const table::Rank& rank, const table::File& file) const
{
    std::vector<Position> availablePositions;

    // check for this file and:
    // 1) rank >= MINIMAL_RANK (without current rank)
    // 2) rank < MINIMAL_RANK + BOARD_HEIGHT (without current rank)

    // 1)
    for (table::Rank currentRank = rank; currentRank >= table::MINIMAL_RANK; currentRank--)
    {
        if (currentRank == rank)
        {
            continue;
        }

        if (board_.getFigure(currentRank, file) == nullptr)
        {
            availablePositions.push_back({currentRank, file});
        }
        else
        {
            break;
        }
    }

    // 2)
    for (table::Rank currentRank = rank; currentRank < (table::MINIMAL_RANK + table::BOARD_HEIGHT); currentRank++)
    {
        if (currentRank == rank)
        {
            continue;
        }

        if (board_.getFigure(currentRank, file) == nullptr)
        {
            availablePositions.push_back({currentRank, file});
        }
        else
        {
            break;
        }
    }

    return availablePositions;
}

std::vector<Position> RookMoveChecker::getPositionsInRank(const table::Rank& rank, const table::File& file) const
{
    std::vector<Position> availablePositions;

    // check for this rank and:
    // 1) file >= MINIMAL_FILE (without current file)
    // 2) file < MINIMAL_FILE + BOARD_WIDTH (without current file)

    // 1)
    for (table::File currentfile = file; currentfile >= table::MINIMAL_FILE; currentfile--)
    {
        if (currentfile == file)
        {
            continue;
        }

        if (board_.getFigure(rank, currentfile) == nullptr)
        {
            availablePositions.push_back({rank, currentfile});
        }
        else
        {
            break;
        }
    }

    // 2)
    for (table::File currentfile = file; currentfile < (table::MINIMAL_FILE + table::BOARD_WIDTH); currentfile++)
    {
        if (currentfile == file)
        {
            continue;
        }

        if (board_.getFigure(rank, currentfile) == nullptr)
        {
            availablePositions.push_back({rank, currentfile});
        }
        else
        {
            break;
        }
    }

    return availablePositions;
}

std::unique_ptr<IMoveChecker> RookMoveChecker::clone() const
{
    return std::unique_ptr<IMoveChecker>(new RookMoveChecker(*this));
}

}  // namespace movement
}  // namespace chess