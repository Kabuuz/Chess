#ifndef MYGAME_CHESS_FIGURE_KNIGHTFIGURE_HPP
#define MYGAME_CHESS_FIGURE_KNIGHTFIGURE_HPP

#include <mygame/chess/figure/FigureBase.hpp>

namespace chess
{
namespace figure
{
class KnightFigure : public FigureBase
{
public:
    KnightFigure(FigureColor color);
};

}  // namespace figure
}  // namespace chess

#endif  // MYGAME_CHESS_FIGURE_KNIGHTFIGURE_HPP
