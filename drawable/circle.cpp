//
// Created by Gabriel Raphael on 16/02/2019.
//

#include "circle.h"
#include "math.h"

std::vector<Point> Circle::generateQuadrants(Point p) {
    std::vector<Point> points;
    Point temp;

    temp.setX(center.getX() + p.getX());
    temp.setY(center.getY() + p.getY());
    points.push_back(temp);

    temp.setX(center.getX() + p.getX());
    temp.setY(center.getY() - p.getY());
    points.push_back(temp);

    temp.setX(center.getX() - p.getX());
    temp.setY(center.getY() + p.getY());
    points.push_back(temp);

    temp.setX(center.getX() - p.getX());
    temp.setY(center.getY() - p.getY());
    points.push_back(temp);

    temp.setX(center.getX() + p.getY());
    temp.setY(center.getY() + p.getX());
    points.push_back(temp);

    temp.setX(center.getX() + p.getY());
    temp.setY(center.getY() - p.getX());
    points.push_back(temp);

    temp.setX(center.getX() - p.getY());
    temp.setY(center.getY() + p.getX());
    points.push_back(temp);

    temp.setX(center.getX() - p.getY());
    temp.setY(center.getY() - p.getX());
    points.push_back(temp);

    return points;
}

void Circle::drawQuadrants(Point p) {
    std::vector<Point> points;
    points = generateQuadrants(p);

    for (auto point : points) {
        this->writePoint(point, color);
    }
}

void Circle::delQuadrants(Point p) {
    std::vector<Point> points;
    points = generateQuadrants(p);

    for (auto point : points) {
        this->deletePoint(point);
    }
}

void Circle::execute(char action) {
    int x = 0;
    int y = radius;
    int d = 3 - 2 * radius;

    Point p(x, y);
    if (action == 'c') {
        drawQuadrants(p);
    } else {
        delQuadrants(p);
    }

    while (x <= y)
    {
        x++;
        if (d < 0)
        {
            d = d + 4 * x + 6;
        }
        else
        {
            d = d + 4 * (x - y) + 10;
            y--;
        }
        p.setX(x);
        p.setY(y);
        if (action == 'c') {
            drawQuadrants(p);
        } else {
            delQuadrants(p);
        }
    }
}

void Circle::draw() {
    execute('c');
}

void Circle::del() {
    execute('d');
}

void Circle::move(long x, long y) {
    execute('d');
    center.setY(center.getY() + y);
    center.setX(center.getX() + x);
    prevCenter = center;
    execute('c');
}

void Circle::rotate(const Point &anchor, double degree) {
    del();
    center = prevCenter;
    double dx = -anchor.getX() + center.getX();
    double dy = -anchor.getY() + center.getY();
    currentDegree += degree;
    center.setX((long) (dx * cos(currentDegree) - dy * sin(currentDegree) + anchor.getX()));
    center.setY((long) (dx * sin(currentDegree) + dy * cos(currentDegree) + anchor.getY()));
    draw();
}

void Circle::dilate(double multipler) {
    del();
    double scale = sqrt(multipler);
    radius = scale * radius;
    draw();
}