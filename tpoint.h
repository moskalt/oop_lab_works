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
    float m_pointRadius = 3.f;
    sf::Vector2f m_movementVar = {4.0, 4.0};


public:
    tPoint() {
        m_color = {calcRandColor(), calcRandColor(), calcRandColor()};
        m_x = getRandomNum(windowWidth - m_pointRadius);
        m_y = getRandomNum(windowHeight - m_pointRadius);
        figure.setFillColor(m_color);
        figure.setRadius(m_pointRadius);
        figure.setPosition(m_x, m_y);
    };
    static float getRandomNum(int windowSize) {
        return (float) (rand() % windowSize);
    }
    static sf::Uint8 calcRandColor() {
        return rand() % 256;
    }
    sf::CircleShape getFigure() {
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
    void tickRateMove(T object) {   
        sf::Vector2f currentPosition = object.figure.getPosition();
        if (currentPosition.x > windowWidth - 2 * object.getRadius() || currentPosition.x - 2 * object.getRadius() < 0) {
            m_movementVar.x = -1 * m_movementVar.x;
        }
        if (currentPosition.y > windowHeight - 2 * object.getRadius() || currentPosition.y - 2 * object.getRadius() < 0) {
            m_movementVar.y = -1 * m_movementVar.y;
        }
        object.move(m_movementVar.x, m_movementVar.y);
    }
};

template<class T>
class tCircle : public tPoint<sf::CircleShape> {
private:
    T circle;
    float m_x;
    float m_y;
    sf::Color m_color;
    sf::Color background_color;

public:
    tCircle(){
        m_color = {calcRandColor(), calcRandColor(), calcRandColor()};
        background_color = {0, 0, 0, 1};
        circle.setFillColor(background_color);
        circle.setRadius(getPointRadius() * 10);
        circle.setOutlineColor(m_color);
        circle.setOutlineThickness(2.f);
        m_x = getRandomNum(windowHeight);
        m_y = getRandomNum(windowWidth);
        circle.setPosition(m_x, m_y);
    }
    
    T getCircle() {
        return this->circle;
    }
};

class tEllipse : public tPoint<sf::CircleShape> {
};