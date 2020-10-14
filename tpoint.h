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
        m_x = getRandomNum(float(windowWidth) - m_pointRadius);
        m_y = getRandomNum(float(windowHeight) - m_pointRadius);
        figure.setFillColor(m_color);
        figure.setRadius(m_pointRadius);
        figure.setPosition(m_x, m_y);
    };
    float getRandomNum(int windowSize) {
        windowSize -= getPointRadius() * 10;
        return (float) (rand() % windowSize + getPointRadius()*10);
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
    void setPoint(T temp) {
        this->figure = temp;
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
    T tickRateMove(T object) {
        sf::Vector2f currentPosition = object.getPosition();
        if (currentPosition.x > windowWidth - object.getRadius() || currentPosition.x + object.getRadius() < 0) {
            m_movementVar.x = -1 * m_movementVar.x;
        }
        if (currentPosition.y > windowHeight - object.getRadius() || currentPosition.y + object.getRadius() < 0) {
            m_movementVar.y = -1 * m_movementVar.y;
        }
        object.move(m_movementVar.x, m_movementVar.y);
        return object;
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
    tCircle() {
        m_color = {calcRandColor(), calcRandColor(), calcRandColor()};
        background_color = {0, 0, 0, 1};
        circle.setFillColor(background_color);
        circle.setRadius(getPointRadius() * 10);
        circle.setOutlineColor(m_color);
        circle.setOutlineThickness(2.f);
        m_x = getRandomNum(float(windowHeight) - getPointRadius() * 10);
        m_y = getRandomNum(windowWidth - getPointRadius() * 10);
        circle.setPosition(m_x, m_y);
    }

    T getCircle() {
        return this->circle;
    }
    void setCircle(T temp) {
        this->circle = temp;
    }
};

template <class T>
class tEllipse : public tPoint<sf::CircleShape> {
private:
    T ellipse;
    float m_x;
    float m_y;
    sf::Color m_color;
    sf::Color background_color;

public:
    tEllipse() {
        m_color = {calcRandColor(),calcRandColor(),calcRandColor()};
        background_color = {0, 0, 0, 1};
        ellipse.setFillColor(background_color);
        ellipse.setRadius(getPointRadius() * 10);
        ellipse.setScale(1.5f, 1.0f);
        ellipse.setOutlineColor(m_color);
        ellipse.setOutlineThickness(2.0f);
        m_x = getRandomNum(float(windowHeight) - getPointRadius() * 10);
        m_y = getRandomNum(windowWidth - getPointRadius() * 10);
        ellipse.setPosition(m_x, m_y);
    }
    T getEllipse() {
        return this->ellipse;
    }
    void setEllipse(T temp) {
        this->ellipse = temp;
    }
};