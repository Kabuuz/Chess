#ifndef INC_MYGAME_CHESS_TABLE_FILE
#define INC_MYGAME_CHESS_TABLE_FILE

namespace chess
{
namespace table
{
class File
{
public:
    File(int file);
    File(char file);

    operator int();
    operator char();

private:
    int file_;
};
}  // namespace table
}  // namespace chess

#endif  // INC_MYGAME_CHESS_TABLE_FILE
