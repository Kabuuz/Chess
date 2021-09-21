#include <mygame/chess/figure/PawnFigure.hpp>

namespace chess
{
namespace figure
{
PawnFigure::PawnFigure(FigureColor color)
    : FigureBase(FigureType::Pawn, color)
{
}

}  // namespace figure
}  // namespace chess