//
// Created by yukinotenshi on 3/14/2019.
//

#include "sixth_scene.h"
#include "../factory/circle_factory.h"
#include "../factory/rectangle_factory.h"
#include "../factory/polygon_factory.h"
#include <iostream>

SixthScene::SixthScene() : BaseScene() {}

SixthScene::SixthScene(BaseScene *scene) : BaseScene(scene) {}

SixthScene::SixthScene(std::vector<Drawable *> drawables) : BaseScene(drawables) {}

void SixthScene::start() {
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

    for (Drawable* drawable : drawables) {
        drawable->draw();
        drawable->fill();
    }
}

void SixthScene::update() {}

void SixthScene::onEvent(BaseEvent event) {}
