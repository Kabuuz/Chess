#ifndef MYGAME_CHESS_TABLE_TABLE_HPP
#define MYGAME_CHESS_TABLE_TABLE_HPP

#include <map>
#include <memory>
#include <mygame/chess/figure/FigureBase.hpp>
#include <mygame/chess/table/Board.hpp>
#include <mygame/chess/table/CapturedFiguresArea.hpp>

namespace chess
{
namespace table
{
class Table
{
public:
    Table();

    Board& getBoard();
    CapturedFiguresArea& getCapturedFiguresArea(figure::FigureColor color);
    void addFigure(std::unique_ptr<figure::FigureBase> figure);
    void reset();

private:
    void createCapturedFiguresAreas();
    void createAllFigures();
    void resetBoard();
    void resetCapturedFiguresAreas();

    std::unique_ptr<Board> board_;
    std::map<figure::FigureColor, std::unique_ptr<CapturedFiguresArea>> capturedFiguresAreas_;
    std::vector<std::unique_ptr<figure::FigureBase>> figures_;
};
}  // namespace table
}  // namespace chess

#endif  // MYGAME_CHESS_TABLE_TABLE_HPP
