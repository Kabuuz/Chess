#ifndef INC_MYGAME_CHESS_FIGURE_FIGUREBASE
#define INC_MYGAME_CHESS_FIGURE_FIGUREBASE

namespace chess
{
namespace figure
{
enum class FigureType
{
    Pawn,
    Rook,
    Knight,
    Bishop,
    Queen,
    King
};

class Figure
{
public:
    Figure(FigureType type);

    FigureType getType();

private:
    FigureType type_;
};

}  // namespace figure
}  // namespace chess

#endif  // INC_MYGAME_CHESS_FIGURE_FIGUREBASE
