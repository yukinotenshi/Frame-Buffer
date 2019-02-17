//
// Created by Gabriel Raphael on 16/02/2019.
//

#include "line.h"

Line::Line() : Drawable(), from(), to(), prevFrom(), prevTo() {};

Line::Line(const Point &from, const Point &to) : Drawable(), from(from), to(to), prevFrom(from), prevTo(to) {}

const Point &Line::getFrom() const {
    return from;
}

void Line::setFrom(const Point &from) {
    Line::from = from;
}

const Point &Line::getTo() const {
    return to;
}

void Line::setTo(const Point &to) {
    Line::to = to;
}

void Line::execute(char action) {
    int dx = (int) fabs(to.getX() - from.getX());
    int dy = (int) fabs(to.getY() - from.getY());
    int signx = to.getX() > from.getX() ? 1 : -1;
    int signy = to.getY() > from.getY() ? 1 : -1;
    long x = from.getX();
    long y = from.getY();
    int temp;
    int interchange = 0;
    int error;
    Point p;

    if (dy > dx) {
        temp = dx;
        dx = dy;
        dy = temp;
        interchange = 1;
    }

    error = (2 * dy) - dx;
    for (int i = 0; i < dx; i++) {
        if (error < 0) {
            if (interchange == 1) {
                y = y + signy;
            }
            else {
                x = x + signx;
            }
            error = error + (2 * dy);
        }
        else {
            y = y + signy;
            x = x + signx;
            error = error + 2 * (dy - dx);
        }
        p.setX(x);
        p.setY(y);
        if (action == 'c') {
            this->writePoint(p, color);
        } else if (action == 'd') {
            this->deletePoint(p);
        }
    }
}

void Line::draw() {
    execute('c');
}

void Line::del() {
    execute('d');
}

void Line::move(long x, long y) {
    execute('d');
    from.setX(from.getX() + x);
    from.setY(from.getY() + y);
    to.setX(to.getX() + x);
    to.setY(to.getY() + y);
    execute('c');
}

//modified from : https://gamedev.stackexchange.com/questions/121478/how-to-rotate-a-2d-line
void Line::rotate(const Point& anchor, double degree) {
    del();

    from = prevFrom;
    to = prevTo;

    double fromdx = -anchor.getX() + from.getX();
    double fromdy = -anchor.getY() + from.getY();

    currentDegree += degree;
    double newX = fromdx * cos(currentDegree) - fromdy * sin(currentDegree) +  anchor.getX();
    double newY = fromdx * sin(currentDegree) + fromdy * cos(currentDegree) +  anchor.getY();

    double diffX = to.getX() - from.getX();
    double diffY = to.getY() - from.getY();

    from.setX(newX);
    from.setY(newY);
    to.setX(to.getX() - from.getX() + diffX);
    to.setY(to.getY() - from.getY() + diffY);

    draw();
}
