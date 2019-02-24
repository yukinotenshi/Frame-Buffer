//
// Created by Gabriel Raphael on 16/02/2019.
//

#include "polygon_factory.h"

PolygonFactory::PolygonFactory(const std::string &filename) : BaseFactory(filename) {}

std::vector<Polygon> PolygonFactory::generate() {
    int n, x, y;
    std::vector<Polygon> polygons;
    std::string c;

    while (file >> c >> n) {
        Color color(c);
        std::vector<Point> points;
        for (int i = 0; i < n; i++) {
            file >> x >> y;
            Point temp(x,y);
            points.push_back(temp);
        }

        Polygon polygon(color, points);
        polygons.push_back(polygon);
    }

    return polygons;
}
