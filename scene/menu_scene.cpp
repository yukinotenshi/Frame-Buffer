//
// Created by yukinotenshi on 3/14/2019.
//

#include "menu_scene.h"
#include "../drawable/dot.h"
#include "../factory/group_factory.h"
#include "../drawable/group_object.h"
#include "first_scene.h"
#include "fifth_scene.h"
#include "sixth_scene.h"

MenuScene::MenuScene() : BaseScene() {}

MenuScene::MenuScene(BaseScene *scene) : BaseScene(scene) {}

MenuScene::MenuScene(std::vector<Drawable *> drawables) : BaseScene(drawables) {}

void MenuScene::start() {
    if (pointer == nullptr) {
        Point p1(315, 225);
        Point p2(330, 240);
        pointerPos = 0;
        pointer = new Rectangle(p1, p2);
        drawables.push_back(pointer);
    }
    for (Drawable* drawable : drawables) {
        drawable->draw();
    }
}

void MenuScene::update() {}

void MenuScene::onEvent(BaseEvent event) {
    char c = (char) event.value;

    if (c == 'w' && pointerPos > 0) {
        pointer->move(0, -42);
        pointerPos -= 1;
    }
    if (c == 's' && pointerPos < 5) {
        pointer->move(0, 42);
        pointerPos += 1;
    }
    if (c == (char) 10) {
        changeScene();
        return;
    }

    pointer->draw();
}

void MenuScene::changeScene() {
    switch (pointerPos) {
        case 0:
            childScene = new FirstScene(this);
            next();
            break;
        case 4:
            childScene = new FifthScene(this);
            next();
            break;
        case 5:
            childScene = new SixthScene(this);
            next();
            break;
        default:
            break;
    }
}
