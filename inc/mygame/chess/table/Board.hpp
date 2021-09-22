#ifndef INC_MYGAME_CHESS_TABLE_BOARD
#define INC_MYGAME_CHESS_TABLE_BOARD

#include <array>
#include <mygame/chess/figure/FigureBase.hpp>

namespace chess
{
namespace table
{
namespace
{
constexpr unsigned int BOARD_WIDTH = 8;
constexpr unsigned int BOARD_HEIGHT = 8;
}  // namespace

class Board
{
public:
    Board();

    figure::FigureBase* getFigure(unsigned int rank, char file);  //rank - rzad, file - kolumna
    void setFigure(figure::FigureBase* figure, unsigned int rank, char file);

private:
    unsigned int convertRankToIndex(unsigned int rank);
    unsigned int convertFileToIndex(char file);

    std::array<std::array<figure::FigureBase*, BOARD_HEIGHT>, BOARD_WIDTH> figures_;
};
}  // namespace table
}  // namespace chess

#endif  // INC_MYGAME_CHESS_TABLE_BOARD
