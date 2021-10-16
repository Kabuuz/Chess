#include <ctype.h>

#include <mygame/chess/table/File.hpp>

#include <iostream>

namespace chess
{
namespace table
{
namespace
{
constexpr int ASCII_a = static_cast<int>('a');
}

File::File(int file)
    : file_(file)
{
}

File::File(char file)
{
    if (isalpha(file))
    {
        file_ = static_cast<int>(tolower(file)) - ASCII_a + 1;
    }
    else
    {
        file_ = -1;
    }
}

File::File(const File& other)
: file_(other.file_)
{}

File& File::operator=(const File& other)
{
    file_ = other.file_;
    return *this;
}

File::operator int() const
{
    return file_;
}

File::operator char() const
{
    return static_cast<char>(file_ + ASCII_a - 1);
}

File::operator std::size_t() const
{
    return file_ - 1;
}

File& File::operator--()
{
    file_--;
    return *this;
}

File& File::operator++()
{
    file_++;
    return *this;
}

File File::operator--(int)
{
    File temp = *this;
    --(*this);
    return temp;
}

File File::operator++(int)
{
    File temp = *this;
    ++(*this);
    return temp;
}

bool operator==(const File& file1, const File& file2)
{
    return file1.file_ == file2.file_;
}
bool operator==(char file1, const File& file2)
{
    return file1 == static_cast<char>(const_cast<File&>(file2));
}
bool operator==(const File& file1, char file2)
{
    return static_cast<char>(const_cast<File&>(file1)) == file2;
}
bool operator==(int file1, const File& file2)
{
    return file1 == file2.file_;
}
bool operator==(const File& file1, int file2)
{
    return file1.file_ == file2;
}

bool operator>=(const File& file, int value)
{
    return file.file_ >= value;
}

bool operator<(const File& file, int value)
{
    return file.file_ < value;
}

File operator+(const File& file, int value)
{
    return File(file.file_ + value);
}

File operator-(const File& file, int value)
{
    return File(file.file_ - value);
}

}  // namespace table
}  // namespace chess