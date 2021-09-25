#include <mygame/chess/table/Table.hpp>

namespace chess
{
namespace table
{
Table::Table()
    : board_(std::make_unique<Board>())
{
    createCapturedFiguresAreas();
}

Board& Table::getBoard()
{
    return *board_;
}

CapturedFiguresArea& Table::getCapturedFiguresArea(figure::FigureColor color)
{
    return *(capturedFiguresAreas_.at(color));
}

void Table::createCapturedFiguresAreas()
{
    capturedFiguresAreas_[figure::FigureColor::White] = std::make_unique<CapturedFiguresArea>(figure::FigureColor::White);
    capturedFiguresAreas_[figure::FigureColor::Black] = std::make_unique<CapturedFiguresArea>(figure::FigureColor::Black);
}

}  // namespace table
}  // namespace chess