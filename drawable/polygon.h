//
// Created by Gabriel Raphael on 16/02/2019.
//

#ifndef FRAME_BUFFER_POLYGON_H
#define FRAME_BUFFER_POLYGON_H

#include <vector>
#include <cstdarg>
#include "drawable.h"
#include "../core/point.h"
#include "line.h"


class Polygon : Drawable {
private:
    std::vector<Point> points;

public:
    explicit Polygon(const std::vector<Point>& points);

    explicit Polygon(int count, ...);

    void draw() override;

    void move(long x, long y) override;

    void del() override;
};


#endif //FRAME_BUFFER_POLYGON_H
