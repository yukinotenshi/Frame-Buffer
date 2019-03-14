//
// Created by Gabriel Raphael on 16/02/2019.
//

#ifndef FRAME_BUFFER_RECTANGLE_H
#define FRAME_BUFFER_RECTANGLE_H

#include "polygon.h"

class Rectangle : public Polygon {
private:

public:
    static std::vector<Point> generatePoint(Point p1, Point p2) {
        std::vector<Point> points;
        int dx = p2.getX() - p1.getX();
        points.push_back(p1);
        p1.setX(p1.getX() + dx);
        points.push_back(p1);
        points.push_back(p2);
        p2.setX(p2.getX() - dx);
        points.push_back(p2);
        return points;
    }

    Rectangle(const Point& p1, const Point& p2) : Polygon(generatePoint(p1, p2)) {};

    Rectangle(Color color, const Point& p1, const Point& p2) : Polygon(color, generatePoint(p1, p2)) {};
};


#endif //FRAME_BUFFER_RECTANGLE_H
