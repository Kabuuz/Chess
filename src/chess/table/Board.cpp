#include <mygame/chess/table/Board.hpp>

namespace chess
{
namespace table
{
Board::Board()
    : figures_({nullptr})
{
}

figure::FigureBase* Board::getFigure(const Rank& rank, const File& file)
{
    return figures_.at(rank).at(file);
}

void Board::setFigure(figure::FigureBase* figure, const Rank& rank, const File& file)
{
    figures_.at(rank).at(file) = figure;
}

bool Board::isFigurePresent(const Rank& rank, const File& file)
{
    return figures_.at(rank).at(file) == nullptr;
}

void Board::reset()
{
    for(Rank rank=MINIMAL_RANK; rank<MINIMAL_RANK+BOARD_HEIGHT; rank++)
    {
        for(File file=MINIMAL_FILE; file<MINIMAL_FILE+BOARD_WIDTH; file++)
        {
            figures_.at(rank).at(file) = nullptr;
        }
    }
}

}  // namespace table
}  // namespace chess