#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
const int windowWidth = 1200;
const int windowHeight = 800;

using namespace sf;

enum objects { varCircle,
               varRect };

struct object_type {
    objects type;
    union {
        sf::RectangleShape rect;
        sf::CircleShape circle;
    };
    object_type(CircleShape _circle) : type(varCircle), circle(_circle) {}
    object_type(RectangleShape _rect) : type(varRect), rect(_rect) {}

     object_type writeTo() {
        switch (type) {
            case varCircle:
                return circle;
                break;
            case varRect:
                return rect;
                break;
        }
    }
};


class tFigure {
private:
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
    virtual object_type getObject(void) = 0;
    virtual void movement() = 0;
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
    void movement() override {
        circle.move(4, 4);
    }
    object_type getObject(void) override {
        return object_type(this->circle);
    }
};
