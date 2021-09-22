#include <mygame/chess/table/Board.hpp>

namespace chess
{
namespace table
{
Board::Board()
    : figures_({nullptr})
{
}

figure::FigureBase* Board::getFigure(unsigned int rank, char file)
{
    return figures_.at(convertRankToIndex(rank)).at(convertFileToIndex(file));
}

void Board::setFigure(figure::FigureBase* figure, unsigned int rank, char file)
{
    figures_.at(convertRankToIndex(rank)).at(convertFileToIndex(file)) = figure;
}

unsigned int Board::convertRankToIndex(unsigned int rank)
{
    return rank - 1;
}

unsigned int Board::convertFileToIndex(char file)
{
    return static_cast<unsigned int>(file) - 97;
}

}  // namespace table
}  // namespace chess