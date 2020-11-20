#pragma once
#include <SFML/Graphics.hpp>
#include <ctime>
#include <iostream>
const int windowWidth = 1200;
const int windowHeight = 800;

using namespace sf;

//enum objects { varCircle,
//               varRect };
//
//struct object_type {
//    objects type;
//    union {
//        sf::RectangleShape rect;
//        sf::CircleShape circle;
//    };
//    object_type(CircleShape _circle) : type(varCircle), circle(_circle) {
//    }
//    object_type(RectangleShape _rect) : type(varRect), rect(_rect) {
//    }
//};


class tFigure {
private:
public:
    // static methods
    Vector2f m_movementVar = {4.0, 4.0};
    static sf::Color getOpacityBgc() {
        sf::Color opacityBgc = {0, 0, 0, 1};
        return opacityBgc;
    }
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
    virtual ~tFigure(){};
    virtual CircleShape getObject() = 0;
    virtual void movement() = 0;
    virtual void setRandomMovement() = 0;
    virtual void setLinearMovement() = 0;
};

class tPoint : public tFigure {
private:
    CircleShape circle;
    sf::Color m_PointColor;
    float m_pointRadius = 10.f;
    float m_x;
    float m_y;

public:
    tPoint() {
        m_PointColor = {calcRandColor(), calcRandColor(), calcRandColor()};
        m_x = getRandomNum(windowWidth, m_pointRadius);
        m_y = getRandomNum(windowHeight, m_pointRadius);
        circle.setFillColor(m_PointColor);
        circle.setRadius(m_pointRadius);
        circle.setPosition(m_x, m_y);
    }
    tPoint(Color color) {
        m_PointColor = color;
        m_x = getRandomNum(windowWidth, m_pointRadius);
        m_y = getRandomNum(windowHeight, m_pointRadius);
        circle.setFillColor(m_PointColor);
        circle.setRadius(m_pointRadius);
        circle.setPosition(m_x, m_y);
    }
    void movement() override {
        Vector2f position = this->circle.getPosition();
        if (position.x > windowWidth - m_pointRadius * 2 || position.x + m_pointRadius <= 0) {
            m_movementVar.x = -1 * m_movementVar.x;
        }
        if (position.y > windowHeight - m_pointRadius * 2 || position.y + m_pointRadius <= 0) {
            m_movementVar.y = -1 * m_movementVar.y;
        }
        this->circle.move(m_movementVar);
    }
    void setLinearMovement() override {
        m_movementVar = {4, 4};
    }
    void setRandomMovement() override {
        int random = rand() % 8;
        switch (random) {
            case 0:
                m_movementVar.x = 0;
                m_movementVar.y = 4;
                break;
            case 1:
                m_movementVar.x = 4;
                m_movementVar.y = 0;
                break;
            case 2:
                m_movementVar.x = 0;
                m_movementVar.y = -4;
                break;
            case 3:
                m_movementVar.x = -4;
                m_movementVar.y = 0;
                break;
            case 4:
                m_movementVar.x = -4;
                m_movementVar.y = -4;
                break;
            case 5:
                m_movementVar.x = -4;
                m_movementVar.y = 4;
                break;
            case 6:
                m_movementVar.x = 4;
                m_movementVar.y = -4;
            case 7:
                m_movementVar.x = 4;
                m_movementVar.y = 4;
            default:
                break;
        }
    }
    CircleShape getObject() override {
        return (this->circle);
    }
};


class tCircle : public tFigure {
private:
    CircleShape circle;
    sf::Color m_circleColor;
    float m_circleRadius = 50.f;
    float m_x;
    float m_y;

public:
    tCircle() {
        m_circleColor = {calcRandColor(), calcRandColor(), calcRandColor()};
        m_x = getRandomNum(windowWidth, m_circleRadius);
        m_y = getRandomNum(windowHeight, m_circleRadius);
        circle.setFillColor(getOpacityBgc());
        circle.setOutlineColor(m_circleColor);
        circle.setOutlineThickness(2.f);
        circle.setRadius(m_circleRadius);
        circle.setPosition(m_x, m_y);
    }
    tCircle(Color color) {
        m_circleColor = color;
        m_x = getRandomNum(windowWidth, m_circleRadius);
        m_y = getRandomNum(windowHeight, m_circleRadius);
        circle.setFillColor(getOpacityBgc());
        circle.setOutlineColor(m_circleColor);
        circle.setOutlineThickness(2.f);
        circle.setRadius(m_circleRadius);
        circle.setPosition(m_x, m_y);
    }

    void movement() override {
        Vector2f position = this->circle.getPosition();
        if (position.x > windowWidth - m_circleRadius * 2 || position.x + m_circleRadius <= 0) {
            m_movementVar.x = -1 * m_movementVar.x;
        }
        if (position.y > windowHeight - m_circleRadius * 2 || position.y + m_circleRadius <= 0) {
            m_movementVar.y = -1 * m_movementVar.y;
        }
        this->circle.move(m_movementVar);
    }
    void setLinearMovement() override {
        m_movementVar = {4, 4};
    }
    void setRandomMovement() override {
        int random = rand() % 8;
        switch (random) {
            case 0:
                m_movementVar.x = 0;
                m_movementVar.y = 4;
                break;
            case 1:
                m_movementVar.x = 4;
                m_movementVar.y = 0;
                break;
            case 2:
                m_movementVar.x = 0;
                m_movementVar.y = -4;
                break;
            case 3:
                m_movementVar.x = -4;
                m_movementVar.y = 0;
                break;
            case 4:
                m_movementVar.x = -4;
                m_movementVar.y = -4;
                break;
            case 5:
                m_movementVar.x = -4;
                m_movementVar.y = 4;
                break;
            case 6:
                m_movementVar.x = 4;
                m_movementVar.y = -4;
            case 7:
                m_movementVar.x = 4;
                m_movementVar.y = 4;
            default:
                break;
        }
    }
    CircleShape getObject() override {
        return (this->circle);
    }
};

class tEllipse : public tFigure {
private:
    CircleShape ellipse;
    float m_x;
    float m_y;
    Color m_ellipseColor;
    float m_ellipseRadius = 40.f;
    float m_scale = 1.5f;

public:
    tEllipse() {
        m_ellipseColor = {calcRandColor(), calcRandColor(),calcRandColor()};
        m_x = getRandomNum(windowWidth, m_ellipseRadius);
        m_y = getRandomNum(windowHeight, m_ellipseRadius);
        ellipse.setFillColor(getOpacityBgc());
        ellipse.setOutlineColor(m_ellipseColor);
        ellipse.setOutlineThickness(2.f);
        ellipse.setRadius(m_ellipseRadius);
        ellipse.setScale(m_scale, 1.1f);
        ellipse.setPosition(m_x, m_y);
    }
    tEllipse(float scale, Color color = Color::Blue) {
        m_ellipseColor = {calcRandColor(), calcRandColor(), calcRandColor()};
        m_x = getRandomNum(windowWidth, m_ellipseRadius);
        m_y = getRandomNum(windowHeight, m_ellipseRadius);
        ellipse.setFillColor(getOpacityBgc());
        ellipse.setOutlineColor(color);
        ellipse.setOutlineThickness(2.f);
        ellipse.setRadius(m_ellipseRadius);
        ellipse.setScale(scale, 1.1f);
        ellipse.setPosition(m_x, m_y);
    }
    void movement() override {
        Vector2f position = this->ellipse.getPosition();
        if (position.x > windowWidth - m_ellipseRadius * 2 || position.x + m_ellipseRadius <= 0) {
            m_movementVar.x = -1 * m_movementVar.x;
        }
        if (position.y > windowHeight - m_ellipseRadius * 2 || position.y + m_ellipseRadius <= 0) {
            m_movementVar.y = -1 * m_movementVar.y;
        }
        this->ellipse.move(m_movementVar);
    }
    void setLinearMovement() override {
        m_movementVar = {4, 4};
    }
    void setRandomMovement() override {
        int random = rand() % 8;
        switch (random) {
            case 0:
                m_movementVar.x = 0;
                m_movementVar.y = 4;
                break;
            case 1:
                m_movementVar.x = 4;
                m_movementVar.y = 0;
                break;
            case 2:
                m_movementVar.x = 0;
                m_movementVar.y = -4;
                break;
            case 3:
                m_movementVar.x = -4;
                m_movementVar.y = 0;
                break;
            case 4:
                m_movementVar.x = -4;
                m_movementVar.y = -4;
                break;
            case 5:
                m_movementVar.x = -4;
                m_movementVar.y = 4;
                break;
            case 6:
                m_movementVar.x = 4;
                m_movementVar.y = -4;
            case 7:
                m_movementVar.x = 4;
                m_movementVar.y = 4;
            default:
                break;
        }
    }
    CircleShape getObject() override {
        return (this->ellipse);
    }

};