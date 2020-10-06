#pragma once
#include <ctime>
#include <cstdlib>
#include <SFML/Graphics.hpp>
const int windowWidth = 1000;
const int windowHeigth = 1000;

class tPoint {
private:
    sf::Color m_color;
    int m_x;
    int m_y;

    static int getRandomNum() {
        srand(time(nullptr));
        return rand() % 256;
    }
    static int getRandomNum(int windowSize) {
        srand(time(nullptr));
        return rand() % windowSize;
    }
    public:
        tPoint() {
            m_color.r = getRandomNum();
            m_color.g = getRandomNum();
            m_color.b = getRandomNum();
            m_x = getRandomNum(windowWidth);
            m_y = getRandomNum(windowHeigth);
    }

};