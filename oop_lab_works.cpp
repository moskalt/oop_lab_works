#include "list.h"
#include "tpoint.h"
#include <iostream>
#include <vector>
#define QTY_FIGURES 1

int List::qtyLists = 0;

int main() {
    sf::ContextSettings settings;
    srand(time(NULL));
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "OOP");
    window.setFramerateLimit(60);
    sf::Event event{};
    sf::Clock timer;
    Queue tQueue;
    Stack tStack;
    for (int i = 0; i < QTY_FIGURES; i++) {
        tQueue.addItem(new tPoint());
        tQueue.addItem(new tCircle());
        tQueue.addItem(new tEllipse());
        tQueue.addItem(new tRect());
        tQueue.addItem(new tRhombus());
        tQueue.addItem(new tLine());
        tQueue.addItem(new tTriangle());
        tStack.addItem(new tPoint());
        tStack.addItem(new tCircle());
        tStack.addItem(new tEllipse());
        tStack.addItem(new tRect());
        tStack.addItem(new tRhombus());
        tStack.addItem(new tLine());
        tStack.addItem(new tTriangle());
    }
    std::cout << tQueue.getQTY() << std::endl;
    std::cout << tStack.getQTY() << std::endl;
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.key.code == sf::Keyboard::W) {
                vertex *tempHead = tQueue.getHead();
                while (tempHead != nullptr) {
                    tempHead->object->setRandomMovement();
                    tempHead = tempHead->ptr_next;
                }
                tempHead = tStack.getHead();
                while (tempHead != nullptr) {
                    tempHead->object->setRandomMovement();
                    tempHead = tempHead->ptr_next;
                }
            }
            if (event.key.code == sf::Keyboard::Q) {
                vertex *tempHead = tQueue.getHead();
                while (tempHead != nullptr) {
                    tempHead->object->setLinearMovement();
                    tempHead = tempHead->ptr_next;
                }
                tempHead = tStack.getHead();
                while (tempHead != nullptr) {
                    tempHead->object->setRandomMovement();
                    tempHead = tempHead->ptr_next;
                }
            }
        }
        window.clear(sf::Color::Black);
        vertex *tempHead = tQueue.getHead();
        while (tempHead != nullptr) {
            window.draw(tempHead->object->getObject());
            tempHead->object->movement();
            tempHead = tempHead->ptr_next;
        }
        tempHead = tStack.getHead();
        while (tempHead != nullptr) {
            window.draw(tempHead->object->getObject());
            tempHead->object->movement();
            tempHead = tempHead->ptr_next;
        }
        window.display();
    }
    return 0;
}
