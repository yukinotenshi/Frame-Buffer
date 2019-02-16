//
// Created by Gabriel Raphael on 16/02/2019.
//

#include "line_factory.h"

LineFactory::LineFactory(const std::string &filename) : BaseFactory(filename) {}

std::vector<Line> LineFactory::generate() {
    int x1, y1, x2, y2;
    std::vector<Line> lines;

    while (file >> x1 >> y1 >> x2 >> y2) {
        Point from(x1, y1);
        Point to(x2, y2);
        Line temp(from, to);
        lines.push_back(temp);
    }

    return lines;
}