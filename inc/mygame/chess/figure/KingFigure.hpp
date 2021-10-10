#ifndef MYGAME_CHESS_FIGURE_KINGFIGURE_HPP
#define MYGAME_CHESS_FIGURE_KINGFIGURE_HPP

#include <mygame/chess/figure/FigureBase.hpp>

namespace chess
{
namespace figure
{
class KingFigure : public FigureBase
{
public:
    KingFigure(FigureColor color);
};

}  // namespace figure
}  // namespace chess

#endif  // MYGAME_CHESS_FIGURE_KINGFIGURE_HPP
