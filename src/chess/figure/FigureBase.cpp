#include <mygame/chess/figure/FigureBase.hpp>

namespace chess
{
namespace figure
{
Figure::Figure(FigureType type)
    : type_(type)
{
}

FigureType Figure::getType()
{
    return type_;
}

}  // namespace figure
}  // namespace chess