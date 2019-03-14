//
// Created by RenjiraND on 3/14/2019.
//

#include "third_scene.h"
#include <iostream>

ThirdScene::ThirdScene() : BaseScene() {}

ThirdScene::ThirdScene(BaseScene *scene) : BaseScene(scene) {}

ThirdScene::ThirdScene(std::vector<Drawable *> drawables) : BaseScene(drawables) {}

void ThirdScene::start() {
    CircleFactory circleFactory("example_files/circle.txt");
    RectangleFactory rectangleFactory("example_files/rectangle.txt");
    PolygonFactory polygonFactory("example_files/polygon.txt");
    circles = circleFactory.generate();
    rectangles = rectangleFactory.generate();
    polygons = polygonFactory.generate();
    for (Circle& circle : circles) {
        drawables.push_back(&circle);
    }
    for (Rectangle& rectangle : rectangles) {
        drawables.push_back(&rectangle);
    }
    for (Polygon& polygon : polygons) {
        drawables.push_back(&polygon);
    }

    for (Drawable* drawable : drawables) {
        drawable->draw();
    }
}

void ThirdScene::update() {}

void ThirdScene::onEvent(BaseEvent event) {}

