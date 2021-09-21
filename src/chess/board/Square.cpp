#include <mygame/chess/board/Square.hpp>

namespace chess
{
namespace board
{
Square::Square(int rank, char file)
    : rank_(rank), file_(file), figure_(nullptr)
{
}

Square::Square(int rank, char file, figure::FigureBase* figure)
    : rank_(rank), file_(file), figure_(figure)
{
}

std::tuple<int, char> Square::getCoordinates() const
{
    return std::make_tuple(rank_, file_);
}

void Square::setFigure(figure::FigureBase* figure)
{
    figure_ = figure;
}

figure::FigureBase* Square::getFigure()
{
    return figure_;
}

}  // namespace board
}  // namespace chess