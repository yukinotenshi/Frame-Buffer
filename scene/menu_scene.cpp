//
// Created by yukinotenshi on 3/14/2019.
//

#include "menu_scene.h"
#include "../drawable/dot.h"
#include "../factory/group_factory.h"
#include "../drawable/group_object.h"

MenuScene::MenuScene() : BaseScene() {}

MenuScene::MenuScene(BaseScene *scene) : BaseScene(scene) {}

MenuScene::MenuScene(std::vector<Drawable *> drawables) : BaseScene(drawables) {}

void MenuScene::start() {
    Point p(0, 0);
    Drawable * dot = new Dot(p);
    drawables.push_back(dot);
    for (Drawable* drawable : drawables) {
        drawable->draw();
    }
}

void MenuScene::update() {}

void MenuScene::onEvent(BaseEvent event) {
    char c = (char) event.value;
    for (Drawable * drawable : drawables) {
        if (drawable == nullptr) {
            continue;
        }

        if (c == 'w') {
            drawable->move(0, -1);
        }
        if (c == 'a') {
            drawable->move(-1, 0);
        }
        if (c == 's') {
            drawable->move(0, 1);
        }
        if (c == 'd') {
            drawable->move(1, 0);
        }
        drawable->draw();
    }
}