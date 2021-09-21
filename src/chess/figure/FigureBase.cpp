#include <mygame/chess/figure/FigureBase.hpp>

namespace chess
{
namespace figure
{
FigureBase::FigureBase(FigureType type, FigureColor color)
    : type_(type), color_(color)
{
}

FigureType FigureBase::getType()
{
    return type_;
}

FigureColor FigureBase::getColor()
{
    return color_;
}

}  // namespace figure
}  // namespace chess