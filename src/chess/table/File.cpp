#include <mygame/chess/table/File.hpp>

namespace chess
{
namespace table
{
File::File(int file)
    : file_(file)
{
}

File::File(char file)
    : file_(static_cast<int>(file) - 96)
{
}

File::operator int()
{
    return file_;
}

File::operator char()
{
    return static_cast<char>(file_ + 96);
}

}  // namespace table
}  // namespace chess