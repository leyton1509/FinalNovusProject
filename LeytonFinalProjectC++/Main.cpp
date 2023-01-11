#include <SFML/Graphics.hpp>
#include "MonsterManager.cpp"
#include <iostream>  
using namespace sf;

int main()
{

   // MonsterManager availableMonsters;

   // Monster charizard = availableMonsters.getDefaultMonster("Charizard");

   // std::cout << charizard.monsterName << " " << charizard.physcialAttackBase << " " << charizard.healthBase << "\n";


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