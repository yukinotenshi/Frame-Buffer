//s
// Created by Gabriel Raphael on 16/02/2019.
//

#include "circle_factory.h"

CircleFactory::CircleFactory(const std::string &filename) : BaseFactory(filename) {}

std::vector<Circle> CircleFactory::generate() {
    int x1, y1, radius;
    std::vector<Circle> circles;
    std::string c;

    while (file >> c >> x1 >> y1 >> radius) {
        Point center(x1, y1);
        Color color(c);
        Circle temp(color, center, radius);
        circles.push_back(temp);
    }

    return circles;
}
