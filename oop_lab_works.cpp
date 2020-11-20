#include "tpoint.h"
#include <iostream>
#define QTY_FIGURES 100

int main() {
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "OOP");
    window.setFramerateLimit(60);
    sf::Event event{};
    sf::Clock timer;
    auto arr = new tFigure *[QTY_FIGURES];
    for (int i = 0; i < QTY_FIGURES; ++i) {
        tPoint point;
        arr[i] = &point;
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
            tPoint ppoint;
            //            window.draw(arr[i]->getObject());
            window.draw(ppoint.getObject());
        }
        window.display();
    }
    return 0;
}
