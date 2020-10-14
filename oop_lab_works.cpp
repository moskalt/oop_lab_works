#include "tpoint.h"
#include <iostream>

int main() {
    srand(time(nullptr));
    auto *pointsArray = new tPoint<sf::CircleShape>[20];
    auto *circleArray = new tCircle<sf::CircleShape>[20];
    auto *ellipseArray = new tEllipse<sf::CircleShape>[20];
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "tPoint");
    window.setFramerateLimit(60);
    sf::Event event{};
    sf::Clock timer;
    size_t check;
    size_t random_object;
    check = 1;
    size_t counter = 0;
    while (window.isOpen()) {
        counter++;
        while (window.pollEvent(event)) {
            if (event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
            if (event.key.code == sf::Keyboard::F1) {
                check = 2;
            }
            if (event.key.code == sf::Keyboard::F2) {
                check = 1;
            }
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        if (counter % 50 == 0 && check == 2) {
            for (size_t i = 0; i < 20; i++) {
                random_object = rand() % 3;
                if (random_object == 2) {
                    pointsArray[i].setRandomMovement();
                } else if (random_object == 1) {
                    circleArray[i].setRandomMovement();
                } else {
                    ellipseArray[i].setRandomMovement();
                }
            }
        }
        window.clear(sf::Color::Black);
        for (size_t i = 0; i < 20; i++) {
            pointsArray[i].setPoint(pointsArray[i].tickRateMove(pointsArray[i].getFigure()));
            window.draw(pointsArray[i].getFigure());
            circleArray[i].setCircle(circleArray[i].tickRateMove(circleArray[i].getCircle()));
            window.draw(circleArray[i].getCircle());
            ellipseArray[i].setEllipse(ellipseArray[i].tickRateMove(ellipseArray[i].getEllipse()));
            window.draw(ellipseArray[i].getEllipse());
        }
        window.display();
    }
    delete[] circleArray;
    delete[] pointsArray;
    delete[] ellipseArray;
    return 0;
}
