#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow renderWin(sf::VideoMode(800, 600), "Win");

    while (renderWin.isOpen())
    {
        sf::Event winEvent;
        while (renderWin.pollEvent(winEvent)) 
        {
            if (winEvent.type == sf::Event::EventType::Closed) 
            {
                renderWin.close();
            }
        }
    }
    
    std::cout << "Build Successful. Application closed." << std::endl; 
}