#pragma once
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <iostream>
const int windowWidth = 1200;
const int windowHeight = 700;
const int SPEED = 500;
const int SPEED_ROTATION = 500;
using namespace sf;

class Point {
public:
    float x;
    float y;

public:
    explicit Point(float x = 0, float y = 0) : x(x),
                                               y(y) {}
};

class tFigure {
protected:
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

    virtual void setRandomColor() = 0;
    virtual void draw(RenderWindow &window) = 0;
    virtual void linearMotion(double &elapsedTime) = 0;
    virtual void rotation(double &elapsedTime) = 0;
    void newpos(double &elapsedTime, int w, int h) {
        if (dir == 0) {
            y -= SPEED * elapsedTime;
            if (y < 0) {
                y = 0;
                dir = 1;
            }
        } else if (dir == 1) {
            y += SPEED * elapsedTime;
            if (y > (windowHeight - 8)) {
                y = (windowHeight - 8);
                dir = 0;
            }
        } else if (dir == 2) {
            x -= SPEED * elapsedTime;
            if (x < 0) {
                x = 0;
                dir = 3;
            }
        } else {
            x += SPEED * elapsedTime;
            if (x > (windowWidth - 8)) {
                x = (windowWidth - 8);
                dir = 2;
            }
        }
    }
};

class Line : public tFigure {
private:
    Point a;
    RectangleShape line;
    int length;

public:
    explicit Line(float x = 0, float y = 0, int length = 0, float alpha = 0) : tFigure(x, y),
                                                                               a(x, y),
                                                                               length(length) {
        line.setSize(Vector2f(length, 1));
        line.setOrigin(length / 2.0, 0.5);
        line.setRotation(alpha);
        line.setPosition(x, y);
    }
    explicit Line(Point point, int length = 0, float alpha = 0) : Line(point.x, point.y, length, alpha) {}

    void setRandomColor() override {
        line.setFillColor(Color(rand() % 256, rand() % 256, rand() % 256));
    }
    void draw(RenderWindow &window) override {
        window.draw(line);
    }
    void rotation(double &elapsedTime) override {
        line.rotate(elapsedTime * SPEED_ROTATION * directionOfRotation);
    }
    void linearMotion(double &elapsedTime) override {
        newpos(elapsedTime, length, length);
        line.setPosition(x, y);
    }
};