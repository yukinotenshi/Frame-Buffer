//
// Created by yukinotenshi on 3/13/2019.
//

#include "group_factory.h"
#include <iostream>

GroupFactory::GroupFactory(const std::string &filename) : BaseFactory(filename) {}

Polygon* GroupFactory::parsePolygon() {
    int n, x, y;
    std::vector<Point> points;
 
    file >> n;
    for (int i = 0; i < n; i++) {
        file >> x >> y;
        Point temp(x,y);
        points.push_back(temp);
    }

    Polygon* polygon = new Polygon(points);
    return polygon;
}

Rectangle* GroupFactory::parseRectangle() {
    int x1, y1, x2, y2;

    file >> x1 >> y1 >> x2 >> y2;
    Point p1(x1, y1);
    Point p2(x2, y2);
    Rectangle* temp = new Rectangle(p1, p2);
    
    return temp;
}

Circle* GroupFactory::parseCircle() {
    int x1, y1, radius;
    
    file >> x1 >> y1 >> radius;
    Point center(x1, y1);
    Circle* temp = new Circle(center, radius);
    
    return temp;
}

Dot* GroupFactory::parseDot() {
    int x, y;

    file >> x >> y; 
    Point point(x, y);
    Dot* dot = new Dot(point);

    return dot;
}

Line* GroupFactory::parseLine() {
    int x1, y1, x2, y2;

    file >> x1 >> y1 >> x2 >> y2;
    Point from(x1, y1);
    Point to(x2, y2);
    Line * temp = new Line(from, to);

    return temp;
}

std::vector<Drawable*> GroupFactory::generate() {
    std::vector<Drawable*> drawables;
    char shape;

    while (file >> shape) {
        if (shape == 'c') {
            drawables.push_back(parseCircle());
        } else if (shape == 'p') {
            drawables.push_back(parsePolygon());
        } else if (shape == 'r') {
            drawables.push_back(parseRectangle());
        } else if (shape == 'd') {
            drawables.push_back(parseDot());
        } else if (shape == 'l') {
            drawables.push_back(parseLine());
        }
    }

    return drawables;
}

GroupObject GroupFactory::create() {
    std::vector<Drawable*> drawables = generate();
    GroupObject object(drawables);

    return object;
}