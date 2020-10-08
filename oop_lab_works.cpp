#include "tpoint.h"
#include <SFML/Graphics.hpp>
#include <ctime>

int main() {
    srand(time(nullptr));
    tPoint *point_array = new tPoint[100];
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "tPoint");
    window.setFramerateLimit(60);
    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            window.display();
            window.clear(sf::Color::Black);
            for (size_t i = 0; i < 100; i++) {
                window.draw(point_array[i].getPoint());
                window.display();
            }
        }
    }
    return 0;
}
