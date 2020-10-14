#include "tpoint.h"
#include <iostream>
#define QTY_FIGURES 10

int main() {
    srand(time(nullptr));
    auto *pointsArray = new tPoint<sf::CircleShape>[QTY_FIGURES];
    auto *circleArray = new tCircle<sf::CircleShape>[QTY_FIGURES];
    auto *ellipseArray = new tEllipse<sf::CircleShape>[QTY_FIGURES];
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
                }
            }
            if (event.key.code == sf::Keyboard::W) {
                for (size_t i = 0; i < QTY_FIGURES; i++) {
                    pointsArray[i].setNormalMovement();
                    circleArray[i].setNormalMovement();
                    ellipseArray[i].setNormalMovement();
                }
            }
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear(sf::Color::Black);
        for (size_t i = 0; i < QTY_FIGURES; i++) {
            pointsArray[i].setPoint(pointsArray[i].objectMotion(pointsArray[i].getPoint()));
            window.draw(pointsArray[i].getPoint());
            circleArray[i].setCircle(circleArray[i].objectMotion(circleArray[i].getCircle()));
            window.draw(circleArray[i].getCircle());
            ellipseArray[i].setEllipse(ellipseArray[i].objectMotion(ellipseArray[i].getEllipse()));
            window.draw(ellipseArray[i].getEllipse());
        }
        window.display();
    }
    delete[] circleArray;
    delete[] pointsArray;
    delete[] ellipseArray;
    return 0;
}
