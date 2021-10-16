#include <mygame/chess/movement/KingMoveChecker.hpp>

namespace chess
{
namespace movement
{
IMoveCheckerPtr KingMoveChecker::create(table::Board& board)
{
    return std::unique_ptr<KingMoveChecker>(new KingMoveChecker(board));
}

KingMoveChecker::KingMoveChecker(table::Board& board)
        : board_(board)
{
}

KingMoveChecker::KingMoveChecker(const KingMoveChecker& other)
        : board_(other.board_)
{
}

std::vector<Position> KingMoveChecker::getAvailablePositions(const Position& actualPosition) const
{
    std::vector<Position> availablePositions;

    const auto& [rank, file] = actualPosition;

    for(table::Rank currentRank = rank-1; currentRank<rank+2; currentRank++)
    {
        for(table::File currentFile = file-1; currentFile<file+2;currentFile++)
        {
            if(currentRank == rank && currentFile ==file)
            {
                continue;
            }

            if(currentRank>= table::MINIMAL_RANK && currentRank<table::MINIMAL_RANK+table::BOARD_HEIGHT
                && currentFile>=table::MINIMAL_FILE && currentFile<table::MINIMAL_FILE+table::BOARD_WIDTH)
            {
                if (!board_.isFigurePresent(currentRank, currentFile))
                {
                    availablePositions.emplace_back(currentRank, currentFile);
                }
            }
        }
    }

    return availablePositions;
}

IMoveCheckerPtr KingMoveChecker::clone() const
{
    return std::unique_ptr<IMoveChecker>(new KingMoveChecker(*this));
}

}  // namespace movement
}  // namespace chess