//
// Created by Gabriel Raphael on 16/02/2019.
//

#ifndef FRAME_BUFFER_CIRCLE_H
#define FRAME_BUFFER_CIRCLE_H

#include "drawable.h"
#include "../core/point.h"
#include <vector>

class Circle : public Drawable {
private:
    Point center;
    Point prevCenter;
    double radius;

    std::vector<Point> generateQuadrants(Point p);

    void drawQuadrants(Point p);

    void delQuadrants(Point p);
public:
    Circle() : Drawable(), center() {radius=0; prevCenter = center;}

    Circle(Color color) : Drawable(color), center() {radius = 0; prevCenter = center;}

    Circle(Color color, const Point &center, int radius) : Drawable(color), center(center), radius(radius) {}

    Point getCenter();

    void draw() override;

    void move(long x, long y) override;

    void del() override;

    void execute(char action);

    void rotate(const Point& anchor, double degree) override;

    void dilate(double multipler) override;
};


#endif //FRAME_BUFFER_CIRCLE_H
