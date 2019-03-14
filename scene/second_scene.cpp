//
// Created by RenjiraND on 3/14/2019.
//

#include "second_scene.h"
#include "../factory/line_factory.h"
#include <iostream>

SecondScene::SecondScene() : BaseScene() {}

SecondScene::SecondScene(BaseScene *scene) : BaseScene(scene) {}

SecondScene::SecondScene(std::vector<Drawable *> drawables) : BaseScene(drawables) {}

void SecondScene::start() {
    LineFactory lineFactory("example_files/gunung.txt");
    lines = lineFactory.generate();
    for (Line& line : lines) {
        drawables.push_back(&line);
    }
    
    for (Drawable* drawable : drawables) {
        drawable->draw();
    }
}

void SecondScene::update() {}

void SecondScene::onEvent(BaseEvent event) {}

