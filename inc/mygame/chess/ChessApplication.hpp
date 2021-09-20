#ifndef INC_MYGAME_CHESS_CHESSAPPLICATION
#define INC_MYGAME_CHESS_CHESSAPPLICATION

#include <mygame/application/Application.hpp>

namespace chess
{
class ChessApplication : public application::Application
{
public:
    ChessApplication() = default;

    virtual void start() const override;
};

}  // namespace chess

#endif  // INC_MYGAME_CHESS_CHESSAPPLICATION
