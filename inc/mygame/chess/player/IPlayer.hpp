#ifndef MYGAME_CHESS_PLAYER_IPLAYER_HPP
#define MYGAME_CHESS_PLAYER_IPLAYER_HPP

#include <mygame/chess/figure/FigureBase.hpp>

namespace chess
{
namespace player
{
class IPlayer
{
public:
    ~IPlayer() = default;

    virtual void makeMove(const IMove& move) const = 0;
    virtual void promotePawn(const figure::FigureBase& figure, figure::FigureType type) const = 0;
};
}  // namespace player
}  // namespace chess

#endif  // MYGAME_CHESS_PLAYER_IPLAYER_HPP
