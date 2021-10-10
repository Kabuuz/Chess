#ifndef MYGAME_CHESS_FIGURE_PAWNFIGURE_HPP
#define MYGAME_CHESS_FIGURE_PAWNFIGURE_HPP

#include <mygame/chess/figure/FigureBase.hpp>

namespace chess
{
namespace figure
{
class PawnFigure : public FigureBase
{
public:
    PawnFigure(FigureColor color);
};

}  // namespace figure
}  // namespace chess

#endif  // MYGAME_CHESS_FIGURE_PAWNFIGURE_HPP
