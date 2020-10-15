#pragma once
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <iostream>
const int windowWidth = 1200;
const int windowHeight = 700;
sf::Color getOpacityBgc() {
    sf::Color opacityBgc = {0, 0, 0, 1};
    return opacityBgc;
}

template<class T>
class figure {
private:
    sf::Vector2f m_movementVar = {4.0, 0.0};
    float m_size;

public:
    figure() {
        m_size = 0;
    }
    // static methods
    static sf::Uint8 calcRandColor() {
        return rand() % 256;
    }
    static float getRandomNum(int windowSize, float size) {
        size *= 1.2;
        auto res = (float) (rand() % windowSize);
        if (res <= size) {
            res += size;
        } else if (res >= (float) windowSize - size * 2) {
            res -= size * 2;
        }
        return res;
    }
    // setters
    void setRandomMovement() {
        this->m_movementVar.x = 1 + rand() % 6;
        this->m_movementVar.y = 1 + rand() % 6;
    }
    void setNormalMovement() {
        this->m_movementVar.x = 4;
        this->m_movementVar.y = 0;
    }
    // virtual
    virtual float getObjectSize() {
        return this->m_size;
    }
    // motion
    T objectMotion(T object) {
        sf::Vector2f currentPosition = object.getPosition();
        if (currentPosition.x > windowWidth - this->getObjectSize() * 2 || currentPosition.x <= 0) {
            m_movementVar.x = -1 * m_movementVar.x;
        }
        if (currentPosition.y > windowHeight - this->getObjectSize() * 2 || currentPosition.y <= 0) {
            m_movementVar.y = -1 * m_movementVar.y;
        }
        object.move(m_movementVar.x, m_movementVar.y);
        return object;
    }
};

template<class T>
class tPoint : public figure<sf::CircleShape> {
private:
    // members
    T m_point;
    sf::Color m_PointColor;
    float m_pointRadius = 3.f;
    float m_x;
    float m_y;

public:
    tPoint() {
        m_PointColor = {calcRandColor(), calcRandColor(), calcRandColor()};
        m_x = getRandomNum(windowWidth, m_pointRadius);
        m_y = getRandomNum(windowHeight, m_pointRadius);
        m_point.setFillColor(m_PointColor);
        m_point.setRadius(m_pointRadius);
        m_point.setPosition(m_x, m_y);
    };
    // virtual methods
    float getObjectSize() override {
        return this->m_pointRadius;
    }
    virtual sf::CircleShape getObject() {
        return this->m_point;
    }
    virtual void setObject(T temp) {
        this->m_point = temp;
    }
    // getters
    float getPointRadius() {
        return this->m_pointRadius;
    };
};

template<class T>
class tCircle : public tPoint<sf::CircleShape> {
private:
    T circle;
    float m_x;
    float m_y;
    sf::Color m_color;
    float m_circleRadius = getPointRadius() * 10;

public:
    tCircle() {
        m_color = {calcRandColor(), calcRandColor(), calcRandColor()};
        circle.setFillColor(getOpacityBgc());
        circle.setRadius(m_circleRadius);
        circle.setOutlineColor(m_color);
        circle.setOutlineThickness(2.f);
        m_x = getRandomNum(windowWidth, m_circleRadius);
        m_y = getRandomNum(windowHeight, m_circleRadius);
        circle.setPosition(m_x, m_y);
    }
    T getObject() override {
        return this->circle;
    }
    void setObject(T temp) override {
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
    float m_ellipseRadius = getPointRadius() * 10;
    float m_scaleX = 1.5f;

public:
    tEllipse() {
        m_color = {calcRandColor(), calcRandColor(), calcRandColor()};
        ellipse.setFillColor(getOpacityBgc());
        ellipse.setRadius(m_ellipseRadius);
        ellipse.setScale(m_scaleX, 1.0f);
        ellipse.setOutlineColor(m_color);
        ellipse.setOutlineThickness(2.0f);
        m_x = getRandomNum(windowWidth, m_ellipseRadius * m_scaleX);
        m_y = getRandomNum(windowHeight, m_ellipseRadius * m_scaleX);
        ellipse.setPosition(m_x, m_y);
    }
    T getObject() override {
        return this->ellipse;
    }
    void setObject(T temp) override {
        this->ellipse = temp;
    }
    float getObjectSize() override {
        return this->m_ellipseRadius * this->m_scaleX;
    }
};

template<class T>
class tLine : public figure<sf::RectangleShape> {
private:
    T line;
    float m_x;
    float m_y;
    sf::Color m_color;
    float m_lineLength = 60.f;
    sf::Vector2f m_size{3.f, m_lineLength};

public:
    tLine() {
        line.setSize(m_size);
        m_color = {calcRandColor(), calcRandColor(), calcRandColor()};
        line.setFillColor(m_color);
        line.setRotation(rand() % 360);
        m_x = getRandomNum(windowWidth, m_lineLength);
        m_y = getRandomNum(windowHeight, m_lineLength);
        line.setPosition(m_x, m_y);
    }
    virtual T getObject() {
        return this->line;
    }
    virtual void setObject(T temp) {
        this->line = temp;
    }
    float getObjectSize() override {
        return this->m_lineLength;
    }
};

//template<class T>
//class tRect : public  tLine<sf::RectangleShape> {
//private:
//    T rect;
//    float m_x;
//    float m_y;
//    sf::Color m_color;
//    float m_ellipseRadius;
//
//public:
//    tRect() {
//    }
//};
//
//template<class T>
//class tRhombus : public tLine<sf::RectangleShape> {
//private:
//    T rhombus;
//    float m_x;
//    float m_y;
//    sf::Color m_color;
//    float m_ellipseRadius;
//
//public:
//    tRhombus() {
//    }
//};