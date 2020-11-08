#include "tpoint.h"
#include <iostream>
#define QTY_FIGURES 10
#include <vector>

int main() {
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    srand(time(nullptr));
    auto *pointsArray = new tPoint<sf::CircleShape>[QTY_FIGURES];
    auto *circleArray = new tCircle<sf::CircleShape>[QTY_FIGURES];
    auto *ellipseArray = new tEllipse<sf::CircleShape>[QTY_FIGURES];
    auto *linesArray = new tLine<sf::RectangleShape>[QTY_FIGURES];
    auto *rectsArray = new tRect<sf::RectangleShape>[QTY_FIGURES];
    auto *rhombusArray = new tRhombus<sf::RectangleShape>[QTY_FIGURES];
    auto *triangleArray = new tTriangle<sf::CircleShape>[QTY_FIGURES];
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "OOP");
    window.setFramerateLimit(60);
    sf::Event event{};
    sf::Clock timer;
    int mode = 0;
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
            if (event.key.code == sf::Keyboard::Q) {
                mode = 0;
                for (size_t i = 0; i < QTY_FIGURES; i++) {
                    pointsArray[i].setRandomMovement();
                    circleArray[i].setRandomMovement();
                    ellipseArray[i].setRandomMovement();
                    linesArray[i].setRandomMovement();
                    rectsArray[i].setRandomMovement();
                    rhombusArray[i].setRandomMovement();
                    triangleArray[i].setRandomMovement();
                }
            }
            if (event.key.code == sf::Keyboard::W) {
                mode = 0;
                for (size_t i = 0; i < QTY_FIGURES; i++) {
                    pointsArray[i].setNormalMovement();
                    circleArray[i].setNormalMovement();
                    ellipseArray[i].setNormalMovement();
                    linesArray[i].setNormalMovement();
                    rectsArray[i].setNormalMovement();
                    rhombusArray[i].setNormalMovement();
                    triangleArray[i].setNormalMovement();
                }
            }
            if (event.key.code == sf::Keyboard::E) {
                mode = 1;
            }
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear(sf::Color::Black);
        for (size_t i = 0; i < QTY_FIGURES; i++) {
            if (mode != 1) {
                pointsArray[i].setObject(pointsArray[i].objectMotion(pointsArray[i].getObject()));
                window.draw(pointsArray[i].getObject());
                circleArray[i].setObject(circleArray[i].objectMotion(circleArray[i].getObject()));
                window.draw(circleArray[i].getObject());
                ellipseArray[i].setObject(ellipseArray[i].objectMotion(ellipseArray[i].getObject()));
                window.draw(ellipseArray[i].getObject());
                linesArray[i].setObject(linesArray[i].objectMotion(linesArray[i].getObject()));
                window.draw(linesArray[i].getObject());
                rectsArray[i].setObject(rectsArray[i].objectMotion(rectsArray[i].getObject()));
                window.draw(rectsArray[i].getObject());
                rhombusArray[i].setObject(rhombusArray[i].objectMotion(rhombusArray[i].getObject()));
                window.draw(rhombusArray[i].getObject());
                triangleArray[i].setObject(triangleArray[i].objectMotion(triangleArray[i].getObject()));
                window.draw(triangleArray[i].getObject());
            } else {
                pointsArray[i].setObject(pointsArray[i].objectRotation(pointsArray[i].getObject()));
                window.draw(pointsArray[i].getObject());
                circleArray[i].setObject(circleArray[i].objectRotation(circleArray[i].getObject()));
                window.draw(circleArray[i].getObject());
                ellipseArray[i].setObject(ellipseArray[i].objectRotation(ellipseArray[i].getObject()));
                window.draw(ellipseArray[i].getObject());
                linesArray[i].setObject(linesArray[i].objectRotation(linesArray[i].getObject()));
                window.draw(linesArray[i].getObject());
                rectsArray[i].setObject(rectsArray[i].objectRotation(rectsArray[i].getObject()));
                window.draw(rectsArray[i].getObject());
                rhombusArray[i].setObject(rhombusArray[i].objectRotation(rhombusArray[i].getObject()));
                window.draw(rhombusArray[i].getObject());
                triangleArray[i].setObject(triangleArray[i].objectRotation(triangleArray[i].getObject()));
                window.draw(triangleArray[i].getObject());
            }
        }
        window.display();
    }
    delete[] circleArray;
    delete[] pointsArray;
    delete[] ellipseArray;
    delete[] linesArray;
    delete[] rectsArray;
    delete[] rhombusArray;
    delete[] triangleArray;
    return 0;
}
