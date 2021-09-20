#ifndef INC_MYGAME_CHESS_APP_CHESSAPPLICATION
#define INC_MYGAME_CHESS_APP_CHESSAPPLICATION

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

#endif  // INC_MYGAME_CHESS_APP_CHESSAPPLICATION
