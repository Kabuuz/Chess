#include <mygame/chess/table/Rank.hpp>

namespace chess
{
namespace table
{
Rank::Rank(int rank)
    : rank_(rank)
{
}

Rank::operator int() const
{
    return rank_;
}

Rank::operator std::size_t() const
{
    return rank_ - 1;
}

bool operator==(const Rank& rank1, const Rank& rank2)
{
    return rank1.rank_ == rank2.rank_;
}

bool operator==(int rank1, const Rank& rank2)
{
    return rank1 == static_cast<int>(const_cast<Rank&>(rank2));
}

bool operator==(const Rank& rank1, int rank2)
{
    return static_cast<int>(const_cast<Rank&>(rank1)) == rank2;
}

}  // namespace table
}  // namespace chess