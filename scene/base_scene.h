//
// Created by yukinotenshi on 3/14/2019.
//

#ifndef FRAME_BUFFER_BASE_SCENE_H
#define FRAME_BUFFER_BASE_SCENE_H

#include <vector>
#include "../drawable/drawable.h"
#include "../event/base_event.h"


class BaseScene {
protected:
    BaseScene * childScene;
    BaseScene * parentScene;
    bool toParent;
    bool toChild;
    std::vector<Drawable*> drawables;
public:
    BaseScene() : drawables() {
        toParent = false;
        toChild = false;
    }

    BaseScene(BaseScene * scene) : drawables() {
        parentScene = scene;
    }

    BaseScene(std::vector<Drawable*> drawables) : drawables(drawables) {
        toParent = false;
        toChild = false;
    }

    virtual ~BaseScene() {
        delete childScene;
        for (Drawable * drawable : drawables) {
            delete drawable;
        }
    }

    void next() {
        Canvas * canvas = Canvas::getInstance();
        canvas->clear();
        toChild = true;
        toParent = false;
    }

    void back() {
        Canvas * canvas = Canvas::getInstance();
        canvas->clear();
        toChild = false;
        toParent = true;
    }

    virtual void start() = 0;
    virtual void update() = 0;
    virtual void onEvent(BaseEvent event) = 0;

    BaseScene *getChildScene() const {
        return childScene;
    }

    void setChildScene(BaseScene *childScene) {
        BaseScene::childScene = childScene;
    }

    BaseScene *getParentScene() const {
        return parentScene;
    }

    void setParentScene(BaseScene *parentScene) {
        BaseScene::parentScene = parentScene;
    }

    bool isToParent() const {
        return toParent;
    }

    void setToParent(bool toParent) {
        BaseScene::toParent = toParent;
    }

    bool isToChild() const {
        return toChild;
    }

    void setToChild(bool toChild) {
        BaseScene::toChild = toChild;
    }
};


#endif //FRAME_BUFFER_BASE_SCENE_H
