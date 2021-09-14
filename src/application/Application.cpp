#include <mygame/application/Application.hpp>

#include <SFML/Graphics.hpp>

namespace application
{

    void Application::start() const
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

    void Application::exit() const
    {
//
    }

}   // namespace application
