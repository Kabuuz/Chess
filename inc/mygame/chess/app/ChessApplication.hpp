#ifndef MYGAME_CHESS_APP_CHESSAPPLICATION_HPP
#define MYGAME_CHESS_APP_CHESSAPPLICATION_HPP

#include <mygame/application/Application.hpp>

namespace chess
{
namespace app
{
class ChessApplication : public application::Application
{
public:
    ChessApplication() = default;

    virtual void start() const override;
};
}  // namespace app
}  // namespace chess

#endif  // MYGAME_CHESS_APP_CHESSAPPLICATION_HPP
