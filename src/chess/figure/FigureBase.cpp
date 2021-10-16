#include <mygame/chess/figure/FigureBase.hpp>

namespace chess
{
namespace figure
{
FigureBase::FigureBase(FigureType type, FigureColor color)
    : type_(type), color_(color)
{
}

FigureType FigureBase::getType() const
{
    return type_;
}

FigureColor FigureBase::getColor() const
{
    return color_;
}

void FigureBase::changeType(FigureType type)
{
    type_ = type;
}

}  // namespace figure
}  // namespace chess