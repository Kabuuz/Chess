#include <SFML/Graphics.hpp>
#include <mygame/chess/app/ChessApplication.hpp>

namespace chess
{
namespace app
{
void ChessApplication::start() const
{
    //TODO create proper function body
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        window.clear();
        window.draw(shape);
        window.display();
    }
}

}  // namespace app
}  // namespace chess
