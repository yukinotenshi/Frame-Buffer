//
// Created by Gabriel Raphael on 16/02/2019.
//

#include "core/canvas.h"
#include "core/color.h"
#include "core/point.h"
#include "drawable/circle.h"
#include "drawable/rectangle.h"
#include "drawable/polygon.h"
#include "factory/rectangle_factory.h"
#include "factory/polygon_factory.h"
#include "factory/circle_factory.h"
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

    for (Rectangle& rect : rects) {
        rect.draw();
    }
    for (Polygon& polygon : polygons) {
        polygon.draw();
    }
    for (Circle& circle : circles) {
        circle.draw();
    }

    return 0;
}
