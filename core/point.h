//
// Created by Gabriel Raphael on 16/02/2019.
//

#ifndef FRAME_BUFFER_POINT_H
#define FRAME_BUFFER_POINT_H

#include "math.h"

class Point {
private:
    double x;
    double y;
public:
    Point();

    Point(double x, double y);

    double getX() const;

    void setX(double x);

    double getY() const;

    void setY(double y);

    double distance(Point p);

    bool operator<(const Point& p) const;

    bool operator==(const Point& p) const;


    // bool operator<(const Point& p1, const Point& p2);

};


#endif //FRAME_BUFFER_POINT_H
