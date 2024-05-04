#include <SFML/Graphics.hpp>
#include "Menu.h"
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 600), "SFML works!");

    Menu menu(window.getSize().x, window.getSize().y);

    sf::Event event;

    sf::CircleShape shape(300.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::KeyReleased:
                switch (event.key.code)
                {
                case sf::Keyboard::Up:
                    menu.MoveUp();
                    break;

                case sf::Keyboard::Down:
                    menu.MoveDown();
                    break;

                case sf::Keyboard::Return:
                    switch (menu.getPressedItem())
                    {
                    case 0:
                        std::cout << "Play" << std::endl;
                        window.clear();
                        window.draw(shape);
                        window.display();
                        break;

                    case 1:
                        std::cout << "Option" << std::endl;
                        break;

                    case 2:
                        std::cout << "Exit" << std::endl;
                        break;

                    }
                    break;
                }
                break;

            case sf::Event::Closed:
                window.close();
                break;
            }
        }

        window.clear();
        menu.draw(window);
        window.display();
    }

    return 0;
}