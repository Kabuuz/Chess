#include <iostream>
#include <mygame/application/fwd.hpp>
#include <mygame/chess/ChessApplication.hpp>

using namespace std;

int main()
{
    application::IApplicationPtr app = std::make_unique<chess::ChessApplication>();
    app->start();

    return 0;
}
