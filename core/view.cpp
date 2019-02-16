//
// Created by Gabriel Raphael on 16/02/2019.
//

#include "view.h"

void View::pushLeft(const Point &p) {
    left.push_back(p);
}

void View::pushRight(const Point &p) {
    right.push_back(p);
}

void View::pushTop(const Point &p) {
    top.push_back(p);
}

void View::pushBottom(const Point &p) {
    bottom.push_back(p);
}

bool View::inBoundary(const Point &p) {
    for (Point& point : left) {
        if (p.getX() < point.getX()) {
            return false;
        }
    }

    for (Point& point : right) {
        if (p.getX() > point.getX()) {
            return false;
        }
    }

    for (Point& point : top) {
        if (p.getY() > point.getY()) {
            return false;
        }
    }

    for (Point& point : bottom) {
        if (p.getY() < point.getY()) {
            return false;
        }
    }

    return true;
}

bool View::viewDefined() {
    int result = 0;
    result += left.size();
    result += top.size();
    result += bottom.size();
    result += right.size();

    return result > 0;
}
