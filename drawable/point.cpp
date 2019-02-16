//
// Created by Gabriel Raphael on 16/02/2019.
//

#include "point.h"

Point::Point() {
    this->x = 0;
    this->y = 0;
    this->r = (char) 0xFF;
    this->g = (char) 0xFF;
    this->b = (char) 0xFF;
    this->a = (char) 0xFF;
}

long Point::getX() const {
    return x;
}

void Point::setX(long x) {
    Point::x = x;
}

long Point::getY() const {
    return y;
}

void Point::setY(long y) {
    Point::y = y;
}

char Point::getR() const {
    return r;
}

void Point::setR(char r) {
    Point::r = r;
}

char Point::getG() const {
    return g;
}

void Point::setG(char g) {
    Point::g = g;
}

char Point::getB() const {
    return b;
}

void Point::setB(char b) {
    Point::b = b;
}

char Point::getA() const {
    return a;
}

void Point::setA(char a) {
    Point::a = a;
}
