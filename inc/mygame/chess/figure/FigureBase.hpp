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

enum class FigureColor
{
    Black,
    White
};

class FigureBase
{
public:
    FigureBase(FigureType type, FigureColor color);

    FigureType getType();
    FigureColor getColor();

    virtual ~FigureBase() = default;

private:
    FigureType type_;
    FigureColor color_;
};

}  // namespace figure
}  // namespace chess

#endif  // INC_MYGAME_CHESS_FIGURE_FIGUREBASE
