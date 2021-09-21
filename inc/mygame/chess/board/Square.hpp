#ifndef INC_MYGAME_CHESS_BOARD_SQUARE
#define INC_MYGAME_CHESS_BOARD_SQUARE

#include <mygame/chess/figure/FigureBase.hpp>
#include <tuple>

namespace chess
{
namespace board
{
class Square
{
public:
    Square(int rank, char file);  //rank - rząd, file - kolumna
    Square(int rank, char file, figure::FigureBase* figure);

    std::tuple<int, char> getCoordinates() const;

    void setFigure(figure::FigureBase* figure);
    figure::FigureBase* getFigure();

private:
    int rank_;
    char file_;

    figure::FigureBase* figure_;
};
}  // namespace board
}  // namespace chess

#endif  // INC_MYGAME_CHESS_BOARD_SQUARE
