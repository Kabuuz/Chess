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

    friend bool operator==(const File& file1, const File& file2);
    friend bool operator==(char file1, const File& file2);
    friend bool operator==(const File& file1, char file2);
    friend bool operator==(int file1, const File& file2);
    friend bool operator==(const File& file1, int file2);

private:
    int file_;
};

}  // namespace table
}  // namespace chess

#endif  // INC_MYGAME_CHESS_TABLE_FILE
