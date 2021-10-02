#ifndef INC_MYGAME_CHESS_TABLE_RANK
#define INC_MYGAME_CHESS_TABLE_RANK

#include <cstdio>

namespace chess
{
namespace table
{
class Rank
{
public:
    Rank(int rank);

    operator int() const;
    operator std::size_t() const;

    // TODO add tests to ++ and -- operators
    Rank& operator--();
    Rank& operator++();
    Rank operator--(int);
    Rank operator++(int);

    // TODO add tests to >= and < opertors, try to remove additional == operators
    friend bool operator==(const Rank& rank1, const Rank& rank2);
    friend bool operator==(int rank1, const Rank& rank2);
    friend bool operator==(const Rank& rank1, int rank2);
    friend bool operator>=(const Rank& rank, const int value);
    friend bool operator<(const Rank& rank, const int value);

private:
    int rank_;
};
}  // namespace table
}  // namespace chess

#endif  // INC_MYGAME_CHESS_TABLE_RANK
