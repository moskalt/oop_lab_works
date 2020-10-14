#pragma once
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
const int windowWidth = 1200;
const int windowHeight = 700;

template<class T>
class tPoint {
private:
    // members
    sf::Color m_color;
    float m_x;
    float m_y;
    T figure;
    float m_pointRadius = 10.f;
    sf::Vector2f m_movementVar = {4.0, 4.0};
    // methods
    static float getRandomNum(int windowSize) {
        return (float) (rand() % windowSize);
    }

public:
    tPoint() {
        m_color = {calcRandColor(), calcRandColor(), calcRandColor()};
        m_x = getRandomNum(windowWidth);
        m_y = getRandomNum(windowHeight);
        figure.setFillColor(m_color);
        figure.setRadius(m_pointRadius);
        figure.setPosition(m_x, m_y);
    };
    static sf::Uint8 calcRandColor() {
        return rand() % 256;
    }
    T getFigure() {
        return figure;
    }
    float getPointRadius() {
        return this->m_pointRadius;
    };

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
        sf::Vector2f currentPosition = figure.getPosition();
        if (currentPosition.x > windowWidth - 2 * figure.getRadius() || currentPosition.x - 2 * figure.getRadius() < 0) {
            m_movementVar.x = -1 * m_movementVar.x;
        }
        if (currentPosition.y > windowHeight - 2 * figure.getRadius() || currentPosition.y - 2 * figure.getRadius() < 0) {
            m_movementVar.y = -1 * m_movementVar.y;
        }
        figure.move(m_movementVar.x, m_movementVar.y);
    }
};

template<class T>
class tCircle : public tPoint<sf::CircleShape> {
private:
    T circle;


public:
    tCircle() {

        circle.setFillColor(0, 0, 0);
        circle.setRadius(getPointRadius() * 5);
        circle.setOutlineColor(calcRandColor(), calcRandColor(), calcRandColor());
    }
};

class tEllipse : protected tPoint<sf::CircleShape> {
};