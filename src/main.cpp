#include <iostream>
#include <mygame/application/fwd.hpp>
#include <mygame/chess/app/ChessApplication.hpp>

using namespace std;

int main()
{
    application::IApplicationPtr app = std::make_unique<chess::app::ChessApplication>();
    app->start();

    return 0;
}
