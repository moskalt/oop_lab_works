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
    for (int i = 0; i < QTY_FIGURES; ++i) {
        figuresArr[i] = new Line(rand() % windowWidth, rand() % windowHeight, rand() % (int) (windowHeight * 0.08), rand() % 181);
        figuresArr[i]->setRandomColor();
    }
    Clock clock;
    double elapsedTime;
    while (window.isOpen()) {
        elapsedTime = clock.getElapsedTime().asMicroseconds() / 1000000.0;
        while (window.pollEvent(event)) {
            if (event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        for (int i = 0; i < QTY_FIGURES; i++) {
            figuresArr[i]->linearMotion(elapsedTime);
        }
        window.clear(sf::Color::Black);
        for (int i = 0; i < QTY_FIGURES; i++) {
            figuresArr[i]->draw(window);
        }
        window.display();
        window.display();
    }
    delete[] figuresArr;
    return 0;
}
