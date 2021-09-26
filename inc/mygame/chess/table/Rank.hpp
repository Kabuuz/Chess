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

private:
    int rank_;
};
}  // namespace table
}  // namespace chess

#endif  // INC_MYGAME_CHESS_TABLE_RANK
