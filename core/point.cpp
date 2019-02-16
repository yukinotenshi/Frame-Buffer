//
// Created by Gabriel Raphael on 16/02/2019.
//

#include "point.h"

Point::Point() {
    this->x = 0;
    this->y = 0;
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