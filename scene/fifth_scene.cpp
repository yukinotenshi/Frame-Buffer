//
// Created by yukinotenshi on 3/14/2019.
//

#include "fifth_scene.h"
#include "../factory/circle_factory.h"
#include "../factory/rectangle_factory.h"
#include "../factory/polygon_factory.h"
#include <iostream>

FifthScene::FifthScene() : BaseScene() {}

FifthScene::FifthScene(BaseScene *scene) : BaseScene(scene) {}

FifthScene::FifthScene(std::vector<Drawable *> drawables) : BaseScene(drawables) {}

void FifthScene::start() {
    CircleFactory circleFactory("example_files/circle.txt");
    circles = circleFactory.generate();
    for (Circle& circle : circles) {
        drawables.push_back(&circle);
    }

    RectangleFactory rectangleFactory("example_files/rectangle.txt");
    rectangles = rectangleFactory.generate();
    for (Rectangle& rectangle : rectangles) {
        drawables.push_back(&rectangle);
    }

    PolygonFactory polygonFactory("example_files/polygon.txt");
    polygons = polygonFactory.generate();
    for (Polygon& polygon : polygons) {
        drawables.push_back(&polygon);
    }

    View view;
    view.pushTop(Point(0,100));
    view.pushLeft(Point(100,0));
    view.pushRight(Point(400,0));
    view.pushBottom(Point(0,400));

    for (Drawable* drawable : drawables) {
        drawable->setView(view);
    }

    for (Drawable* drawable : drawables) {
        drawable->draw();
    }
}

void FifthScene::update() {}

void FifthScene::onEvent(BaseEvent event) {}
