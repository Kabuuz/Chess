#ifndef INC_MYGAME_CHESS_FIGURE_KINGFIGURE
#define INC_MYGAME_CHESS_FIGURE_KINGFIGURE

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

#endif  // INC_MYGAME_CHESS_FIGURE_KINGFIGURE
