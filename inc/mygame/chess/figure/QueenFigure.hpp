#ifndef MYGAME_CHESS_FIGURE_QUEENFIGURE_HPP
#define MYGAME_CHESS_FIGURE_QUEENFIGURE_HPP

#include <mygame/chess/figure/FigureBase.hpp>

namespace chess
{
namespace figure
{
class QueenFigure : public FigureBase
{
public:
    QueenFigure(FigureColor color);
};

}  // namespace figure
}  // namespace chess

#endif  // MYGAME_CHESS_FIGURE_QUEENFIGURE_HPP
