//
// Created by Gabriel Raphael on 16/02/2019.
//

#include "polygon.h"


Polygon::Polygon(const std::vector<Point>& points) {
    for (const Point& p : points) {
        this->points.push_back(p);
    }
}

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
        temp.setView(view);
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
        temp.setView(view);
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

//modified from : https://gamedev.stackexchange.com/questions/121478/how-to-rotate-a-2d-line
void Polygon::rotate(const Point &anchor, double degree) {
    del();
    for (Point& point : points) {
        double dx = -anchor.getX() + point.getX();
        double dy = -anchor.getY() + point.getY();
        double sin_ = sin(degree);
        double cos_ = cos(degree);
        point.setX(floor(dx * cos_ - dy * sin_ + (double) anchor.getX()));
        point.setY(floor(dx * sin_ + dy * cos_ + (double) anchor.getY()));
    }
    draw();
}
