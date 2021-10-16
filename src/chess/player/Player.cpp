#include <mygame/chess/player/Player.hpp>
#include <iostream>

namespace chess
{
namespace player
{

void Player::makeMove(const IMove& move) const
{
    move.make();
}

void Player::promotePawn(figure::FigureBase& figure, figure::FigureType type) const
{
    auto isPawn = [](const figure::FigureBase& figure) constexpr{ return figure.getType() == figure::FigureType::Pawn; };
    if(!isPawn(figure))
    {
        std::cout << "[ERR][Player] promotePawn : Figure is not a pawn, actual: " << static_cast<int>(figure.getType()) << std::endl;
    }

    figure.changeType(type);
}

}  // namespace player
}  // namespace chess
