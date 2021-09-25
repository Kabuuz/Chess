#ifndef INC_MYGAME_CHESS_TABLE_TABLE
#define INC_MYGAME_CHESS_TABLE_TABLE

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

private:
    void createCapturedFiguresAreas();

    std::unique_ptr<Board> board_;
    std::map<figure::FigureColor, std::unique_ptr<CapturedFiguresArea>> capturedFiguresAreas_;
};
}  // namespace table
}  // namespace chess

#endif  // INC_MYGAME_CHESS_TABLE_TABLE