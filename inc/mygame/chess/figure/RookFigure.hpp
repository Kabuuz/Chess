#ifndef INC_MYGAME_CHESS_FIGURE_ROOKFIGURE
#define INC_MYGAME_CHESS_FIGURE_ROOKFIGURE

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

#endif  // INC_MYGAME_CHESS_FIGURE_ROOKFIGURE
