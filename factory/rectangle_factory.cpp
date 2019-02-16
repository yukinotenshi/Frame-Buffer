//
// Created by Gabriel Raphael on 16/02/2019.
//

#include "rectangle_factory.h"

RectangleFactory::RectangleFactory(const std::string &filename) : BaseFactory(filename) {}

std::vector<Rectangle> RectangleFactory::generate() {
    int x1, y1, x2, y2;
    std::vector<Rectangle> rects;

    while (file >> x1 >> y1 >> x2 >> y2) {
        Point p1(x1, y1);
        Point p2(x2, y2);
        Rectangle temp(p1, p2);
        rects.push_back(temp);
    }

    return rects;
}
