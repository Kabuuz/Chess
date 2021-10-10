#ifndef MYGAME_CHESS_FIGURE_ROOKFIGURE_HPP
#define MYGAME_CHESS_FIGURE_ROOKFIGURE_HPP

#include <mygame/chess/figure/FigureBase.hpp>

namespace chess
{
namespace figure
{
class RookFigure : public FigureBase
{
public:
    RookFigure(FigureColor color);
};

}  // namespace figure
}  // namespace chess

#endif  // MYGAME_CHESS_FIGURE_ROOKFIGURE_HPP
