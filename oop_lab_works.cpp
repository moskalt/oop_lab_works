#include "tpoint.h"
#include <iostream>
#include <vector>
#define QTY_FIGURES 10

int main() {
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "OOP");
    window.setFramerateLimit(60);
    sf::Event event{};
    sf::Clock timer;
    std::vector<tFigure *> vector(QTY_FIGURES); 
    for (int i = 0; i < QTY_FIGURES; i++) {
        (vector[i]) = new tPoint();
    }
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
        for (int i = 0; i < QTY_FIGURES; ++i) {
            window.draw((vector[i])->getObject());
        }
        window.display();
    }
    return 0;
}
