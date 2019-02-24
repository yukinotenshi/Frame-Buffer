//
// Created by Gabriel Raphael on 16/02/2019.
//

#include "line_factory.h"

LineFactory::LineFactory(std::string filename) : BaseFactory<Line>(filename) {}

std::vector<Line> LineFactory::generate() {
    int x1, y1, x2, y2;
    std::vector<Line> lines;
    std::string c;

    while (file >> c >>  x1 >> y1 >> x2 >> y2) {
        Point from(x1, y1);
        Point to(x2, y2);
        Color color(c);
        Line temp(from, to, color);
        lines.push_back(temp);
    }

    return lines;
}
