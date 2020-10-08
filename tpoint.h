#pragma once
#include <cstdlib>
#include <SFML/Graphics.hpp>
const int windowWidth = 1200;
const int windowHeight = 700;

class tPoint {
private:
    sf::Color m_color;
    float m_x;
    float m_y;
    sf::CircleShape circle;

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

};