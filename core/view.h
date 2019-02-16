//
// Created by Gabriel Raphael on 16/02/2019.
//

#ifndef FRAME_BUFFER_VIEW_H
#define FRAME_BUFFER_VIEW_H

#include <vector>
#include "point.h"
#include "canvas.h"

class View {
private:
    std::vector<Point> left;
    std::vector<Point> top;
    std::vector<Point> right;
    std::vector<Point> bottom;

public:
    void pushLeft(const Point& p);
    void pushRight(const Point& p);
    void pushTop(const Point& p);
    void pushBottom(const Point& p);
    bool inBoundary(const Point& p);
    bool viewDefined();
};


#endif //FRAME_BUFFER_VIEW_H
