#include "tpoint.h"
#include <iostream>
#define QTY_FIGURES 10

int main() {
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    srand(time(nullptr));
    auto *pointsArray = new tPoint<sf::CircleShape>[QTY_FIGURES];
    auto *circleArray = new tCircle<sf::CircleShape>[QTY_FIGURES];
    auto *ellipseArray = new tEllipse<sf::CircleShape>[QTY_FIGURES];
    auto *linesArray = new tLine<sf::RectangleShape>[QTY_FIGURES];
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "tPoint");
    window.setFramerateLimit(60);
    sf::Event event{};
    sf::Clock timer;
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
            if (event.key.code == sf::Keyboard::Q) {
                for (size_t i = 0; i < QTY_FIGURES; i++) {
                    pointsArray[i].setRandomMovement();
                    circleArray[i].setRandomMovement();
                    ellipseArray[i].setRandomMovement();
                    linesArray[i].setRandomMovement();
                }
            }
            if (event.key.code == sf::Keyboard::W) {
                for (size_t i = 0; i < QTY_FIGURES; i++) {
                    pointsArray[i].setNormalMovement();
                    circleArray[i].setNormalMovement();
                    ellipseArray[i].setNormalMovement();
                    linesArray[i].setNormalMovement();
                }
            }
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear(sf::Color::Black);
        for (size_t i = 0; i < QTY_FIGURES; i++) {
            pointsArray[i].setObject(pointsArray[i].objectMotion(pointsArray[i].getObject()));
            window.draw(pointsArray[i].getObject());
            circleArray[i].setObject(circleArray[i].objectMotion(circleArray[i].getObject()));
            window.draw(circleArray[i].getObject());
            ellipseArray[i].setObject(ellipseArray[i].objectMotion(ellipseArray[i].getObject()));
            window.draw(ellipseArray[i].getObject());
            linesArray[i].setObject(linesArray[i].objectMotion(linesArray[i].getObject()));
            window.draw(linesArray[i].getObject());
        }
        window.display();
    }
    delete[] circleArray;
    delete[] pointsArray;
    delete[] ellipseArray;
    delete[] linesArray;
    return 0;
}
