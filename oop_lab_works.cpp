#include "tpoint.h"
#include <iostream>
#include <vector>
#define QTY_FIGURES 10

int main() {
    sf::ContextSettings settings;
    srand(time(NULL));
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "OOP");
    window.setFramerateLimit(60);
    sf::Event event{};
    sf::Clock timer;
    std::vector<tFigure*> vector; 
    for (int i = 0; i < QTY_FIGURES; i++) {
        vector.push_back( new tPoint());
        vector.push_back(new tCircle(sf::Color::Green));
        vector.push_back(new tEllipse());
    }
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.key.code == sf::Keyboard::W) {
                for (auto& item : vector) {
                    item->setRandomMovement();
                }
            }
            if (event.key.code == sf::Keyboard::Q) {
                for (auto& item : vector) {
                    item->setLinearMovement();
                }
            }
        }
        window.clear(sf::Color::Black);
        for (auto &item: vector) {
            window.draw(item->getObject());
            item->movement();
        }
        window.display();
    }
    return 0;
}
