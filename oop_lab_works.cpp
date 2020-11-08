#include "tpoint.h"
#include <iostream>
#define QTY_FIGURES 100

int main() {
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    srand(time(nullptr));
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "OOP");
    window.setFramerateLimit(60);
    sf::Event event{};
    sf::Clock timer;
    auto figuresArr = new tFigure *[QTY_FIGURES];
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear(sf::Color::Black);
        window.display();
    }
    delete[] figuresArr;
    return 0;
}
