//
// Created by Gabriel Raphael on 16/02/2019.
//

#include "polygon.h"

Polygon::Polygon(int count, ...) {
    va_list args;
    va_start(args, count);
    for (int i = 0; i < count; i++) {
        this->points.push_back(va_arg(args, Point));
    }
    va_end(args);
}

void Polygon::draw() {
    Line temp;
    for (unsigned int i = 0; i < points.size()-1; i++) {
        temp.setFrom(points.at(i));
        temp.setTo(points.at(i+1));
        temp.draw();
    }

    temp.setFrom(points.back());
    temp.setTo(points.front());
    temp.draw();
}

void Polygon::del() {
    Line temp;
    for (unsigned int i = 0; i < points.size()-1; i++) {
        temp.setFrom(points.at(i));
        temp.setTo(points.at(i+1));
        temp.del();
    }

    temp.setFrom(points.back());
    temp.setTo(points.front());
    temp.del();
}

void Polygon::move(long x, long y) {
    del();
    for (unsigned int i = 0; i < points.size(); i++) {
        Point& p = points.at(i);
        p.setX(p.getX() + x);
        p.setY(p.getY() + y);
    }

    draw();
}
