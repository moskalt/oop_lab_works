#pragma once
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <iostream>
const int windowWidth = 1200;
const int windowHeight = 700;


class Point {
public:
    float x;
    float y;

public:
    explicit Point(float x = 0, float y = 0) : x(x),
                                               y(y) {}
};

class tFigure {
    double x;
    double y;
    int directionOfRotation;
    int dir;
    double r{};

public:
    explicit tFigure(double x = 0, double y = 0) : x(x),
                                                   y(y) {
        directionOfRotation = ((rand() % 2) == 0 ? -1 : 1);
        dir = rand() % 4;
    }
    explicit tFigure(Point point) : tFigure(point.x, point.y) {}
};