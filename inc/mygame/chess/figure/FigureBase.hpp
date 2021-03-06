#ifndef MYGAME_CHESS_FIGURE_FIGUREBASE_HPP
#define MYGAME_CHESS_FIGURE_FIGUREBASE_HPP

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

    FigureType getType() const;
    FigureColor getColor() const;
    void changeType(FigureType type);

    virtual ~FigureBase() = default;

private:
    FigureType type_;
    FigureColor color_;
};

}  // namespace figure
}  // namespace chess

#endif  // MYGAME_CHESS_FIGURE_FIGUREBASE_HPP
