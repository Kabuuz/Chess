#ifndef MYGAME_CHESS_TABLE_FILE_HPP
#define MYGAME_CHESS_TABLE_FILE_HPP

#include <cstdio>

namespace chess
{
namespace table
{
class File
{
public:
    explicit File(int file);
    explicit File(char file);
    File(const File& other);
    File& operator=(const File& other);

    operator int() const;
    operator char() const;
    operator std::size_t() const;

    // TODO add tests to ++ and -- operators
    File& operator--();
    File& operator++();
    File operator--(int);
    File operator++(int);

    // TODO add tests to >= and < opertors, try to remove additional == operators
    friend bool operator==(const File& file1, const File& file2);
    friend bool operator==(char file1, const File& file2);
    friend bool operator==(const File& file1, char file2);
    friend bool operator==(int file1, const File& file2);
    friend bool operator==(const File& file1, int file2);
    friend bool operator>=(const File& file, int value);
    friend bool operator<(const File& file, int value);
    friend File operator+(const File& file, int value);
    friend File operator-(const File& file, int value);

private:
    int file_;
};

}  // namespace table
}  // namespace chess

#endif  // MYGAME_CHESS_TABLE_FILE_HPP
