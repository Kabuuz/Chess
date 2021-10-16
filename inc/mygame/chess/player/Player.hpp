#ifndef MYGAME_CHESS_PLAYER_PLAYER_HPP
#define MYGAME_CHESS_PLAYER_PLAYER_HPP

#include <mygame/chess/player/IPlayer.hpp>

namespace chess
{
namespace player
{
class Player : public IPlayer
{
public:
    void makeMove(const IMove& move) const override;
    void promotePawn(figure::FigureBase& figure, figure::FigureType type) const override;
};
}  // namespace player
}  // namespace chess

#endif  // MYGAME_CHESS_PLAYER_PLAYER_HPP