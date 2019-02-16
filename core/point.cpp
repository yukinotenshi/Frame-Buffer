//
// Created by Gabriel Raphael on 16/02/2019.
//

#include "point.h"

Point::Point() {
    this->x = 0;
    this->y = 0;
}

Point::Point(double x, double y) : x(x), y(y) {}

double Point::getX() const {
    return x;
}

void Point::setX(double x) {
    Point::x = x;
}

double Point::getY() const {
    return y;
}

void Point::setY(double y) {
    Point::y = y;
}
