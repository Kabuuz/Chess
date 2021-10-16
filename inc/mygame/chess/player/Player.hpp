#ifndef MYGAME_CHESS_PLAYER_PLAYER_HPP
#define MYGAME_CHESS_PLAYER_PLAYER_HPP

#include <mygame/chess/player/IPlayer.hpp>

#include <mygame/chess/table/Table.hpp>

namespace chess
{
namespace player
{
class Player : public IPlayer
{
public:
    Player(table::Table& table);

    void makeMove(const IMove& move) const override; //TODO move to HumanPlayer
    void promotePawn(figure::FigureBase& figure, figure::FigureType type) const override; //TODO move to HumanPlayer

private:
    table::Table& table_;
};
}  // namespace player
}  // namespace chess

#endif  // MYGAME_CHESS_PLAYER_PLAYER_HPP