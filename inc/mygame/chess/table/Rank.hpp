#ifndef INC_MYGAME_CHESS_TABLE_RANK
#define INC_MYGAME_CHESS_TABLE_RANK

namespace chess
{
namespace table
{
class Rank
{
public:
    Rank(int rank);

    operator int();

    friend bool operator==(const Rank& rank1, const Rank& rank2);
    friend bool operator==(int rank1, const Rank& rank2);
    friend bool operator==(const Rank& rank1, int rank2);

private:
    int rank_;
};
}  // namespace table
}  // namespace chess

#endif  // INC_MYGAME_CHESS_TABLE_RANK
