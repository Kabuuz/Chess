#include <mygame/chess/figure/FigureBase.hpp>

namespace chess
{
namespace figure
{
FigureBase::FigureBase(FigureType type)
    : type_(type)
{
}

FigureType FigureBase::getType()
{
    return type_;
}

}  // namespace figure
}  // namespace chess