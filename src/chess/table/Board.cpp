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

}  // namespace table
}  // namespace chess