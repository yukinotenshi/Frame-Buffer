//
// Created by Gabriel Raphael on 16/02/2019.
//

#include "core/canvas.h"
#include "core/color.h"
#include "core/point.h"
#include "drawable/circle.h"
#include "drawable/line.h"
#include "drawable/polygon.h"
#include "factory/line_factory.h"
#include "factory/polygon_factory.h"
#include "factory/circle_factory.h"
#include "core/view.h"
#include <unistd.h>
#include <vector>

int main() {
    std::vector<Line> lines;
    LineFactory lineFactory("example_files/line.txt");
    lines = lineFactory.generate();

    std::vector<Polygon> polygons;
    PolygonFactory polygonFactory("example_files/polygon.txt");
    polygons = polygonFactory.generate();

    std::vector<Circle> circles;
    CircleFactory circleFactory("example_files/circle.txt");
    circles = circleFactory.generate();

    Point p1;
    View view;
    view.pushLeft(p1);
    view.pushTop(p1);
    p1.setX(1000);
    view.pushTop(p1);
    view.pushRight(p1);
    p1.setY(1000);
    view.pushRight(p1);
    view.pushBottom(p1);
    p1.setX(1000);
    view.pushLeft(p1);
    view.pushRight(p1);

    for (Line& line : lines) {
        line.setView(view);
    }
    for (Polygon& polygon : polygons) {
        polygon.setView(view);
    }
    for (Circle& circle : circles) {
        circle.setView(view);
    }

    for (int x = 0; x < 1000; x++) {
        usleep(1000);
        for (Line& line : lines) {
            line.move(1,1);
        }
        for (Polygon& polygon : polygons) {
            polygon.move(1,1);
        }
        for (Circle& circle : circles) {
            circle.move(1,1);
        }
    }

    return 0;
}
