#include "tpoint.h"
#include <SFML/Graphics.hpp>
#include <ctime>

int main() {
    srand(time(nullptr));
    tPoint *point_array = new tPoint[100];
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "tPoint");
    window.setFramerateLimit(60);
    sf::Event event{};
    sf::Clock timer;
    sf::Time tickRate;
    sf::Vector2f movement(50.0, 0.0);
    sf::CircleShape circle = point_array[0].getPoint();
    circle.setPosition(0, 500);
    while (window.isOpen()) 
        {   
            while (window.pollEvent(event)) {
                if (event.key.code == sf::Keyboard::Escape) {
                    window.close();
                }
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
            }
            tickRate = timer.restart();
            circle.move(movement * ((float) tickRate.asMilliseconds() / 1000));
            window.clear(sf::Color::Black);
            window.draw(circle);
            window.display();
            
            /*if (event.type == sf::Event::Closed) {
                window.close();
            }*/
        }
    return 0;
}
