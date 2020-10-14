#pragma once
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <iostream>
const int windowWidth = 1200;
const int windowHeight = 700;

template<class T>
class tPoint {
private:
    // members
    T m_point;
    sf::Color m_PointColor;
    float m_pointRadius = 3.f;
    float m_x;
    float m_y;
    sf::Vector2f m_movementVar = {4.0, 0.0};

public:
    float getRandomNum(int windowSize, float size) {
        float res = rand() % windowSize;
        if (res <= size) {
            res += size;
        } else if (res >= (float) windowSize - size * 2) {
            res -= size * 2;
        }
        return res;
    }
    tPoint() {
        m_PointColor = {calcRandColor(), calcRandColor(), calcRandColor()};
        m_x = getRandomNum(windowWidth, m_pointRadius);
        m_y = getRandomNum(windowHeight, m_pointRadius);
        std::cout << m_x << " " << m_y << " point" << std::endl;
        m_point.setFillColor(m_PointColor);
        m_point.setRadius(m_pointRadius);
        m_point.setPosition(m_x, m_y);
    };
    static sf::Uint8 calcRandColor() {
        return rand() % 256;
    }
    sf::CircleShape getPoint() {
        return this->m_point;
    }
    float getPointRadius() {
        return this->m_pointRadius;
    };
    void setPoint(T temp) {
        this->m_point = temp;
    }
    void setRandomMovement() {
        this->m_movementVar.x = 1 + random() % 6;
        this->m_movementVar.y = 1 + random() % 6;
    }
    void setNormalMovement() {
        this->m_movementVar.x = 4;
        this->m_movementVar.y = 0;
    }
    virtual float getObjectSize() {
        return this->m_pointRadius;
    }
    T objectMotion(T object) {
        sf::Vector2f currentPosition = object.getPosition();
        if (currentPosition.x > windowWidth - getObjectSize() * 2 || currentPosition.x <= 0) {
            m_movementVar.x = -1 * m_movementVar.x;
        }
        if (currentPosition.y > windowHeight - getObjectSize() * 2 || currentPosition.y <= 0) {
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
    float m_circleRadius = getPointRadius() * 10;

public:
    tCircle() {
        m_color = {calcRandColor(), calcRandColor(), calcRandColor()};
        background_color = {0, 0, 0, 1};
        circle.setFillColor(background_color);
        circle.setRadius(m_circleRadius);
        circle.setOutlineColor(m_color);
        circle.setOutlineThickness(2.f);
        m_x = getRandomNum(windowWidth, m_circleRadius);
        m_y = getRandomNum(windowHeight, m_circleRadius);
        std::cout << m_x << " " << m_y << " circle" << std::endl;
        circle.setPosition(m_x, m_y);
    }

    T getCircle() {
        return this->circle;
    }
    void setCircle(T temp) {
        this->circle = temp;
    }
    float getObjectSize() override {
        return this->m_circleRadius;
    }
};

template<class T>
class tEllipse : public tPoint<sf::CircleShape> {
private:
    T ellipse;
    float m_x;
    float m_y;
    sf::Color m_color;
    sf::Color background_color;
    float m_ellipseRadius = getPointRadius() * 10;
    float m_scaleX = 1.5f;

public:
    tEllipse() {
        m_color = {calcRandColor(), calcRandColor(), calcRandColor()};
        background_color = {0, 0, 0, 1};
        ellipse.setFillColor(background_color);
        ellipse.setRadius(m_ellipseRadius);
        ellipse.setScale(m_scaleX, 1.0f);
        ellipse.setOutlineColor(m_color);
        ellipse.setOutlineThickness(2.0f);
        m_x = getRandomNum(windowWidth, m_ellipseRadius);
        m_y = getRandomNum(windowHeight, m_ellipseRadius);
        std::cout << m_x << " " << m_y << " ellipse" << std::endl;
        ellipse.setPosition(m_x, m_y);
    }
    T getEllipse() {
        return this->ellipse;
    }
    void setEllipse(T temp) {
        this->ellipse = temp;
    }
    float getObjectSize() override {
        return this->m_ellipseRadius * this->m_scaleX;
    }
};