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

Rank& Rank::operator--()
{
    rank_--;
    return *this;
}

Rank& Rank::operator++()
{
    rank_++;
    return *this;
}

Rank Rank::operator--(int)
{
    Rank temp = *this;
    --(*this);
    return temp;
}

Rank Rank::operator++(int)
{
    Rank temp = *this;
    ++(*this);
    return temp;
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

bool operator>=(const Rank& rank, const int value)
{
    return rank.rank_ >= value;
}

bool operator<(const Rank& rank, const int value)
{
    return rank.rank_ < value;
}

Rank operator+(const Rank& rank, const int value)
{
    return Rank(rank.rank_ + value);
}

}  // namespace table
}  // namespace chess