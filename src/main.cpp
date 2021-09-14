#include <SFML/Graphics.hpp>
#include <iostream>
#include <mygame/temp/Dummy.hpp>

#include <mygame/application/Application.hpp>

using namespace std;

int main()
{
    // temp::Dummy dummy;
    // dummy.hello();
    // sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    // sf::CircleShape shape(100.f);
    // shape.setFillColor(sf::Color::Green);

    // while (window.isOpen())
    // {
    //     sf::Event event;
    //     while (window.pollEvent(event))
    //     {
    //         if (event.type == sf::Event::Closed)
    //         {
    //             window.close();
    //         }
    //     }
    //     window.clear();
    //     window.draw(shape);
    //     window.display();
    // }

    auto app = std::make_unique<application::Application>();
    app->start();

    return 0;
}
