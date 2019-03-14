//
// Created by yukinotenshi on 3/14/2019.
//

#include "first_scene.h"
#include "../drawable/dot.h"
#include "../factory/dot_factory.h"
#include <iostream>

FirstScene::FirstScene() : BaseScene() {}

FirstScene::FirstScene(BaseScene *scene) : BaseScene(scene) {}

FirstScene::FirstScene(std::vector<Drawable *> drawables) : BaseScene(drawables) {}

void FirstScene::start() {
    DotFactory dotFactory("example_files/listname.txt");
    dots = dotFactory.generate();
    for (Dot& dot : dots) {
        drawables.push_back(&dot);
    }
    
    for (Drawable* drawable : drawables) {
        drawable->draw();
    }
}

void FirstScene::update() {}

void FirstScene::onEvent(BaseEvent event) {}
