#pragma once
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <ctime>
const int windowWidth = 1200;
const int windowHeight = 700;

class tPoint {
private:
    sf::Color m_color;
    float m_x;
    float m_y;
    sf::CircleShape circle;
    sf::Vector2f movement_var = {4.0, 4.0};

    static int getRandomNum() {
        return rand() % 256;
    }
    static float getRandomNum(int windowSize) {
        return rand() % windowSize;
    }
    public:
    tPoint() {
        m_color.r = getRandomNum();
        m_color.g = getRandomNum();
        m_color.b = getRandomNum();
        m_x = getRandomNum(windowWidth);
        m_y = getRandomNum(windowHeight);
        circle.setFillColor(m_color);
        circle.setRadius(10.f);
        circle.setPosition(m_x, m_y);
    };

    sf::CircleShape getPoint() {
        return circle;
    }

    void setRandomMovement() {
        size_t random_x = rand() % 2;
        size_t random_y = rand() % 2;
        if (random_x == 0) {
            movement_var.x = -1 * movement_var.x;
        }
        if (random_y == 0) {
            movement_var.y = -1 * movement_var.y;
        }
    }
    void tickrateMove() {
        sf::Vector2f currentPosition = circle.getPosition();
        if (currentPosition.x > windowWidth - 2 * circle.getRadius()) {
            movement_var.x = -1 * movement_var.x;
        } else if (currentPosition.x - 2 * circle.getRadius() < 0) {
            movement_var.x = -1 * movement_var.x;
        }
        if (currentPosition.y > windowHeight - 2 * circle.getRadius()) {
            movement_var.y = -1 * movement_var.y;
        } else if (currentPosition.y - 2 * circle.getRadius() < 0) {
            movement_var.y = -1 * movement_var.y;
        }
        circle.move(movement_var.x, movement_var.y);
    }
};