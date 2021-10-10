#ifndef MYGAME_CHESS_TABLE_CAPTUREDFIGURESAREA_HPP
#define MYGAME_CHESS_TABLE_CAPTUREDFIGURESAREA_HPP

#include <mygame/chess/figure/FigureBase.hpp>
#include <vector>

namespace chess
{
namespace table
{
class CapturedFiguresArea
{
public:
    CapturedFiguresArea(figure::FigureColor color);

    figure::FigureColor getColor();

    void clear();
    void add(figure::FigureBase* figure);
    std::vector<figure::FigureBase*>& getFigures();

private:
    figure::FigureColor color_;
    std::vector<figure::FigureBase*> figures_;
};
}  // namespace table
}  // namespace chess

#endif  // MYGAME_CHESS_TABLE_CAPTUREDFIGURESAREA_HPP
