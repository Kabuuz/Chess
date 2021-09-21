#ifndef INC_MYGAME_CHESS_FIGURE_BISHOPFIGURE
#define INC_MYGAME_CHESS_FIGURE_BISHOPFIGURE

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

#endif  // INC_MYGAME_CHESS_FIGURE_BISHOPFIGURE
