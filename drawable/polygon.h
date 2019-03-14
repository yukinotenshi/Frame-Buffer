//
// Created by Gabriel Raphael on 16/02/2019.
//

#ifndef FRAME_BUFFER_POLYGON_H
#define FRAME_BUFFER_POLYGON_H

#include <vector>
#include <queue>
#include <cstdarg>
#include "drawable.h"
#include "../core/point.h"
#include "line.h"
#include <iostream>
#include<bits/stdc++.h>


class Polygon : public Drawable {
private:
    std::vector<Point> points;
    std::vector<Point> prevPoints;

public:
    explicit Polygon(const std::vector<Point>& points);

    explicit Polygon(Color &color, const std::vector<Point>& points);

    explicit Polygon(int count, ...);

    explicit Polygon(Color &color, int count, ...);

    std::vector<Point> getPoint();

    std::vector<Point> getPrevPoint();

    void draw() override;

    void move(long x, long y) override;

    void del() override;

    void rotate(const Point& anchor, double degree) override;

    void dilate(double multiplier) override;

    bool inBorder(Point p);

    Point getPointInTriangle();

    void fill() override;
};


#endif //FRAME_BUFFER_POLYGON_H
