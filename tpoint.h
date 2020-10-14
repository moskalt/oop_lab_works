#pragma once
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
const int windowWidth = 1200;
const int windowHeight = 700;

class tPoint {
private:
    // members
    sf::Color m_color;
    float m_x;
    float m_y;
    sf::CircleShape m_circle;
    sf::Vector2f m_movementVar = {4.0, 4.0};
    // methods
    static sf::Uint8 calcRandColor() {
        return rand() % 256;
    }
    static float getRandomNum(int windowSize) {
        return rand() % windowSize;
    }

public:
    tPoint() {
        m_color = {calcRandColor(), calcRandColor(), calcRandColor()};
        m_x = getRandomNum(windowWidth);
        m_y = getRandomNum(windowHeight);
        m_circle.setFillColor(m_color);
        m_circle.setRadius(10.f);
        m_circle.setPosition(m_x, m_y);
    };

    sf::CircleShape getPoint() {
        return m_circle;
    }

    void setRandomMovement() {
        size_t random_x = rand() % 2;
        size_t random_y = rand() % 2;
        if (random_x == 0) {
            m_movementVar.x = -1 * m_movementVar.x + random_x;
        }
        if (random_y == 0) {
            m_movementVar.y = -1 * m_movementVar.y + random_y;
        }
    }
    void tickRateMove() {
        sf::Vector2f currentPosition = m_circle.getPosition();
        if (currentPosition.x > windowWidth - 2 * m_circle.getRadius()) {
            m_movementVar.x = -1 * m_movementVar.x;
        } else if (currentPosition.x - 2 * m_circle.getRadius() < 0) {
            m_movementVar.x = -1 * m_movementVar.x;
        }
        if (currentPosition.y > windowHeight - 2 * m_circle.getRadius()) {
            m_movementVar.y = -1 * m_movementVar.y;
        } else if (currentPosition.y - 2 * m_circle.getRadius() < 0) {
            m_movementVar.y = -1 * m_movementVar.y;
        }
        m_circle.move(m_movementVar.x, m_movementVar.y);
    }
};