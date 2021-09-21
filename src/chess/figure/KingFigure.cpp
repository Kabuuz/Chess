#include <mygame/chess/figure/KingFigure.hpp>

namespace chess
{
namespace figure
{
KingFigure::KingFigure(FigureColor color)
    : FigureBase(FigureType::King, color)
{
}

}  // namespace figure
}  // namespace chess