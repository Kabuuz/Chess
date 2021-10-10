#ifndef MYGAME_CHESS_FIGURE_BISHOPFIGURE_HPP
#define MYGAME_CHESS_FIGURE_BISHOPFIGURE_HPP

#include <mygame/chess/figure/FigureBase.hpp>

namespace chess
{
namespace figure
{
class BishopFigure : public FigureBase
{
public:
    BishopFigure(FigureColor color);
};

}  // namespace figure
}  // namespace chess

#endif  // MYGAME_CHESS_FIGURE_BISHOPFIGURE_HPP
