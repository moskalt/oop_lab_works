#include "tpoint.h"
#include <iostream>

int main() {
    srand(time(nullptr));
    auto *pointsArray = new tPoint<sf::CircleShape>[20];
    auto *circleArray = new tCircle<sf::CircleShape>[20];
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "tPoint");
    window.setFramerateLimit(60);
    sf::Event event{};
    sf::Clock timer;
    size_t check;
    std::cout << "1: no random "
              << std::endl
              << "2: random " << std::endl;
    std::cin >> check;
    if (check == 2) {
        for (size_t i = 0; i < 20; i++) {
            pointsArray[i].setRandomMovement();
            circleArray[i].setRandomMovement();
        }
    }
    size_t counter = 0;
    while (window.isOpen()) {
        counter++;
        while (window.pollEvent(event)) {
            if (event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        if (counter % 50 == 0 && check == 2) {
            for (size_t i = 0; i < 20; i++) {
                pointsArray[i].setRandomMovement();
                circleArray[i].setRandomMovement();
            }
        }
        window.clear(sf::Color::Black);
        for (size_t i = 0; i < 20; i++) {
            pointsArray[i].tickRateMove(pointsArray[i].getFigure());
            window.draw(pointsArray[i].getFigure());
            circleArray[i].setCircle(circleArray[i].tickRateMove(circleArray[i].getCircle()));
            window.draw(circleArray[i].getCircle());
        }
        window.display();
    }
    delete[] circleArray;
    delete[] pointsArray;
    return 0;
}
