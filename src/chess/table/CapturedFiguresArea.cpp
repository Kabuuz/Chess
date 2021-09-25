#include <algorithm>
#include <iostream>
#include <mygame/chess/table/CapturedFiguresArea.hpp>

namespace chess
{
namespace table
{
CapturedFiguresArea::CapturedFiguresArea(figure::FigureColor color)
    : color_(color)
{
}

figure::FigureColor CapturedFiguresArea::getColor()
{
    return color_;
}

void CapturedFiguresArea::clear()
{
    figures_.clear();
}

void CapturedFiguresArea::add(figure::FigureBase* figure)
{
    if (figure == nullptr)
    {
        std::cout << "[ERR][CapturedFiguresArea] add : invalid pointer" << std::endl;
        return;
    }

    if (figure->getColor() != color_)
    {
        std::cout << "[ERR][CapturedFiguresArea] add : color of figure does not match with area" << std::endl;
        return;
    }

    auto iter = std::find(figures_.begin(), figures_.end(), figure);

    if (iter == figures_.end())
    {
        figures_.push_back(figure);
    }
    else
    {
        std::cout << "[INFO][CapturedFiguresArea] add : figure already captured" << std::endl;
    }
}

std::vector<figure::FigureBase*>& CapturedFiguresArea::getFigures()
{
    return figures_;
}

}  // namespace table
}  // namespace chess