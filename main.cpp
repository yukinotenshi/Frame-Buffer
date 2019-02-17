//
// Created by Gabriel Raphael on 16/02/2019.
//

#include "core/canvas.h"
#include "core/color.h"
#include "core/point.h"
#include "drawable/circle.h"
#include "drawable/rectangle.h"
#include "drawable/polygon.h"
#include "drawable/line.h"
#include "factory/rectangle_factory.h"
#include "factory/polygon_factory.h"
#include "factory/circle_factory.h"
#include "factory/line_factory.h"
#include "core/view.h"
#include <unistd.h>
#include <vector>

int main() {
    std::vector<Rectangle> rects;
    RectangleFactory rectangleFactory("example_files/rectangle.txt");
    rects = rectangleFactory.generate();

    std::vector<Polygon> polygons;
    PolygonFactory polygonFactory("example_files/polygon.txt");
    polygons = polygonFactory.generate();

    std::vector<Circle> circles;
    CircleFactory circleFactory("example_files/circle.txt");
    circles = circleFactory.generate();

    std::vector<Line> lines;
    LineFactory lineFactory("example_files/line.txt");
    lines = lineFactory.generate();

    Point p1, p2, p3, p4;
    View view;
    view.pushLeft(p1);
    view.pushTop(p1);
    p2.setX(500);
    view.pushTop(p2);
    view.pushRight(p2);
    p3.setX(500);
    p3.setY(500);
    view.pushRight(p3);
    view.pushBottom(p3);
    p4.setY(500);
    view.pushLeft(p4);
    view.pushBottom(p4);

    /*for (Line& line : lines) {
        line.setView(view);
    }
    for (Polygon& polygon : polygons) {
        polygon.setView(view);
    }
    for (Circle& circle : circles) {
        circle.setView(view);
    }*/

    p1.setX(500);
    p1.setY(500);

    for (int i = 0; i < 1000; i++) {
        usleep(10000);
        for (Rectangle& rect : rects) {
            rect.rotate(p1, 0.01);
        }
        for (Polygon& polygon : polygons) {
            polygon.rotate(p1, 0.01);
        }
        for (Circle& circle : circles) {
            circle.rotate(p1, 0.01);
        }
        for (Line& line: lines) {
            line.rotate(p1, 0.01);
        }
    }

    return 0;
}
