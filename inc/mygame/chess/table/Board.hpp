#ifndef MYGAME_CHESS_TABLE_BOARD_HPP
#define MYGAME_CHESS_TABLE_BOARD_HPP

#include <array>
#include <mygame/chess/figure/FigureBase.hpp>
#include <mygame/chess/table/File.hpp>
#include <mygame/chess/table/Rank.hpp>

namespace chess
{
namespace table
{
constexpr int BOARD_WIDTH = 8;
constexpr int BOARD_HEIGHT = 8;
const Rank MINIMAL_RANK = 1;
const File MINIMAL_FILE = File('A');

//TODO move all "using Position" to fwd.hpp in table folder
using Position = std::pair<table::Rank, table::File>;

class Board
{
public:
    Board();

    figure::FigureBase* getFigure(const Rank& rank, const File& file);  //rank - rzad, file - kolumna
    void setFigure(figure::FigureBase* figure, const Rank& rank, const File& file);
    bool isFigurePresent(const Rank& rank, const File& file);
    void reset();

private:
    std::array<std::array<figure::FigureBase*, BOARD_HEIGHT>, BOARD_WIDTH> figures_;
};
}  // namespace table
}  // namespace chess

#endif  // MYGAME_CHESS_TABLE_BOARD_HPP
