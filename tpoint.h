#pragma once
#include <SFML/Graphics.hpp>
#include <ctime>
#include <iostream>
const int windowWidth = 1200;
const int windowHeight = 800;

using namespace sf;

class tFigure {
protected:
    Vector2f m_movementVar = {4.0, 4.0};

public:
    // static methods
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
    // virtual methods
    virtual CircleShape getObject() = 0;
    virtual void movement() = 0;
    void setLinearMovement() {
        m_movementVar = {4, 4};
    }
    void setRandomMovement() {
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
};

class tPoint : public tFigure {
private:
    CircleShape circle;
    sf::Color m_PointColor;
    float m_pointRadius = 7.f;
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
    explicit tPoint(Color color) {
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
    explicit tCircle(Color color) {
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
        m_ellipseColor = {calcRandColor(), calcRandColor(), calcRandColor()};
        m_x = getRandomNum(windowWidth, m_ellipseRadius);
        m_y = getRandomNum(windowHeight, m_ellipseRadius);
        ellipse.setFillColor(getOpacityBgc());
        ellipse.setOutlineColor(m_ellipseColor);
        ellipse.setOutlineThickness(2.f);
        ellipse.setRadius(m_ellipseRadius);
        ellipse.setScale(m_scale, 1.1f);
        ellipse.setPosition(m_x, m_y);
    }
    explicit tEllipse(float scale, Color color = Color::Blue) {
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
        if (position.x > windowWidth - m_ellipseRadius * 2.2 || position.x + (1.2 * m_ellipseRadius) <= 0) {
            m_movementVar.x = -1 * m_movementVar.x;
        }
        if (position.y > windowHeight - m_ellipseRadius * 2.2 || position.y + (1.2 * m_ellipseRadius) <= 0) {
            m_movementVar.y = -1 * m_movementVar.y;
        }
        this->ellipse.move(m_movementVar);
    }
    CircleShape getObject() override {
        return (this->ellipse);
    }
};

class tRect : public tFigure {
private:
    CircleShape rect;
    float m_x;
    float m_y;
    Color m_rectColor;
    float m_rectSize = 40.f;

public:
    tRect() {
        m_rectColor = {calcRandColor(), calcRandColor(), calcRandColor()};
        m_x = getRandomNum(windowWidth, m_rectSize);
        m_y = getRandomNum(windowHeight, m_rectSize);
        rect.setFillColor(getOpacityBgc());
        rect.setOutlineColor(m_rectColor);
        rect.setOutlineThickness(2.f);
        rect.setRadius(m_rectSize * 2);
        rect.rotate(45.f);
        rect.setPointCount(4);
        rect.setPosition(m_x, m_y);
    }
    void movement() override {
        Vector2f position = this->rect.getPosition();
        if (position.x > windowWidth - m_rectSize * 2 || position.x + (m_rectSize * 2) <= 0) {
            m_movementVar.x = -1 * m_movementVar.x;
        }
        if (position.y > windowHeight - m_rectSize * 2 || position.y + (m_rectSize * 2) <= 0) {
            m_movementVar.y = -1 * m_movementVar.y;
        }
        this->rect.move(m_movementVar);
    }
    CircleShape getObject() override {
        return (this->rect);
    }
};

class tRhombus : public tFigure {
private:
    CircleShape rhombus;
    float m_x;
    float m_y;
    Color m_rhombusColor;
    float m_rhombusSize = 25.f;

public:
    tRhombus() {
        m_rhombusColor = {calcRandColor(), calcRandColor(), calcRandColor()};
        m_x = getRandomNum(windowWidth, m_rhombusSize);
        m_y = getRandomNum(windowHeight, m_rhombusSize);
        rhombus.setFillColor(getOpacityBgc());
        rhombus.setOutlineColor(m_rhombusColor);
        rhombus.setOutlineThickness(2.f);
        rhombus.setRadius(m_rhombusSize * 2);
        rhombus.setPointCount(4);
        rhombus.setPosition(m_x, m_y);
    }
    void movement() override {
        Vector2f position = this->rhombus.getPosition();
        if (position.x > windowWidth - m_rhombusSize * 2 || position.x + (m_rhombusSize * 2) <= 0) {
            m_movementVar.x = -1 * m_movementVar.x;
        }
        if (position.y > windowHeight - m_rhombusSize * 2 || position.y + (m_rhombusSize * 2) <= 0) {
            m_movementVar.y = -1 * m_movementVar.y;
        }
        this->rhombus.move(m_movementVar);
    }
    CircleShape getObject() override {
        return (this->rhombus);
    }
};

class tLine : public tFigure {
private:
    CircleShape line;
    float m_x;
    float m_y;
    Color m_lineColor;
    float m_lineSize = 40.f;

public:
    tLine() {
        m_lineColor = {calcRandColor(), calcRandColor(), calcRandColor()};
        m_x = getRandomNum(windowWidth, m_lineSize);
        m_y = getRandomNum(windowHeight, m_lineSize);
        line.setFillColor(getOpacityBgc());
        line.setOutlineColor(m_lineColor);
        line.setOutlineThickness(2.f);
        line.setRadius(m_lineSize);
        line.setPointCount(4);
        line.scale(0.1, m_lineSize * 2);
        line.setPosition(m_x, m_y);
    }
    void movement() override {
        Vector2f position = this->line.getPosition();
        if (position.x > windowWidth - 2 || position.x + 2 <= 0) {
            m_movementVar.x = -1 * m_movementVar.x;
        }
        if (position.y > windowHeight - (m_lineSize * 8) || position.y + m_lineSize * 4.5 <= 0) {
            m_movementVar.y = -1 * m_movementVar.y;
        }
        this->line.move(m_movementVar);
    }
    CircleShape getObject() override {
        return (this->line);
    }
};

class tTriangle : public tFigure {
private:
    CircleShape triangle;
    float m_x;
    float m_y;
    Color m_triangleColor;
    float m_triangleSize = 80.f;

public:
    tTriangle() {
        m_triangleColor = {calcRandColor(), calcRandColor(), calcRandColor()};
        m_x = getRandomNum(windowWidth, m_triangleSize);
        m_y = getRandomNum(windowHeight, m_triangleSize);
        triangle.setFillColor(getOpacityBgc());
        triangle.setOutlineColor(m_triangleColor);
        triangle.setOutlineThickness(2.f);
        triangle.setRadius(m_triangleSize);
        triangle.setPointCount(3);
        triangle.setPosition(m_x, m_y);
    }
    void movement() override {
        Vector2f position = this->triangle.getPosition();
        if (position.x > windowWidth - m_triangleSize * 2 || position.x + (m_triangleSize) <= 0) {
            m_movementVar.x = -1 * m_movementVar.x;
        }
        if (position.y > windowHeight - m_triangleSize * 2.5 || position.y + (m_triangleSize) <= 0) {
            m_movementVar.y = -1 * m_movementVar.y;
        }
        this->triangle.move(m_movementVar);
    }
    CircleShape getObject() override {
        return (this->triangle);
    }
};