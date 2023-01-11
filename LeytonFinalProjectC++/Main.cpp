#include <SFML/Graphics.hpp>
#include "Monster.cpp"
using namespace sf;

int main()
{

    Monster testMonser("Charizard", 100, 110, 70, 140, 80, 100, 1);


    RenderWindow window(sf::VideoMode(1200, 800), "SFML works!");
    CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}