#include <mygame/chess/table/Rank.hpp>

namespace chess
{
namespace table
{
Rank::Rank(int rank)
    : rank_(rank)
{
}

Rank::operator int()
{
    return rank_;
}

}  // namespace table
}  // namespace chess