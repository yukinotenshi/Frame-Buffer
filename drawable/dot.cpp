//
// Created by yukinotenshi on 13/03/2019.
//

#include "dot.h"

Dot::Dot() : Drawable(), point(), prevPoint() {};

Dot::Dot(const Point &point) : Drawable(), point(point), prevPoint(point) {}

void Dot::execute(char action) {
    if (action == 'c') {
        this->writePoint(point, color);
    } else if (action == 'd') {
        this->deletePoint(point);
    } else if (action == 'f') {
        this->writePoint(point, color);
    }
}

void Dot::draw() {
    execute('c');
}

void Dot::del() {
    execute('d');
}

void Dot::fill() {
    execute('f');
}

void Dot::move(long x, long y) {
    execute('d');
    point.setX(point.getX() + x);
    point.setY(point.getY() + y);
    execute('c');
}

//modified from : https://gamedev.stackexchange.com/questions/121478/how-to-rotate-a-2d-Dot
void Dot::rotate(const Point& anchor, double degree) {
    del();

    point = prevPoint;

    double dx = -anchor.getX() + point.getX();
    double dy = -anchor.getY() + point.getY();

    currentDegree += degree;

    point.setX((int) (dx * cos(currentDegree) - dy * sin(currentDegree) +  anchor.getX()));
    point.setY((int) (dx * sin(currentDegree) + dy * cos(currentDegree) +  anchor.getY()));

    draw();
}

void Dot::dilate(double multiplier) {
    return;
}
