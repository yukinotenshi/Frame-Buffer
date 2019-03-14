//
// Created by RenjiraND on 3/14/2019.
//

#include "seventh_scene.h"
#include <iostream>

SeventhScene::SeventhScene() : BaseScene() {}

SeventhScene::SeventhScene(BaseScene *scene) : BaseScene(scene) {}

SeventhScene::SeventhScene(std::vector<Drawable *> drawables) : BaseScene(drawables) {}

SeventhScene::~SeventhScene() {}

void SeventhScene::start() {
    PolygonFactory polygonFactory("example_files/polygon.txt");
    std::vector<Polygon> polygons = polygonFactory.generate();
    for (Polygon& polygon : polygons) {
        polygon.draw();
        Color c(200,123,50,1);
        polygon.scanlineFill(c);
    }
}

void SeventhScene::update() {}

void SeventhScene::onEvent(BaseEvent event) {}

