//
// Created by yukinotenshi on 3/13/2019.
//

#include "dot_factory.h"

DotFactory::DotFactory(std::string filename) : BaseFactory<Dot>(filename) {}

std::vector<Dot> DotFactory::generate() {
    int x, y;
    std::vector<Dot> dots;

    while (file >> x >> y) {
        Point point(x, y);
        Dot dot(point);
        dots.push_back(dot);
    }

    return dots;
}