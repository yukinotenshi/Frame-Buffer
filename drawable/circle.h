//
// Created by Gabriel Raphael on 16/02/2019.
//

#ifndef FRAME_BUFFER_CIRCLE_H
#define FRAME_BUFFER_CIRCLE_H

#include "drawable.h"
#include "../core/point.h"
#include <vector>

class Circle : Drawable {
private:
    Point center;
    int radius;

    std::vector<Point> generateQuadrants(Point p);

    void drawQuadrants(Point p);

    void delQuadrants(Point p);
public:
    Circle() : Drawable(), center() {radius = 0;}

    Circle(const Point &center, int radius) : center(center), radius(radius) {}

    void draw() override;

    void move(long x, long y) override;

    void del() override;

    void execute(char action);
};


#endif //FRAME_BUFFER_CIRCLE_H
