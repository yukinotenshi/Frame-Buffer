//
// Created by yukinotenshi on 3/14/2019.
//

#ifndef FRAME_BUFFER_MAIN_CONTROLLER_H
#define FRAME_BUFFER_MAIN_CONTROLLER_H


#include "../scene/base_scene.h"
#include <unistd.h>
#include <mutex>

class MainController {
private:
    BaseScene * currentScene;
public:
    MainController(BaseScene * scene) {
        currentScene = scene;
    }

    void run() {
        if (currentScene == nullptr) {
            return;
        }
        currentScene->start();
        while (true) {
            usleep(1000);
            if (currentScene == nullptr) {
                continue;
            }
            if (currentScene->getChildScene() != nullptr && currentScene->isToChild()) {
                currentScene->setToChild(false);
                currentScene = currentScene->getChildScene();
                currentScene->start();
                continue;
            }
            if (currentScene->getParentScene() != nullptr && currentScene->isToParent()) {
                currentScene->setToParent(false);
                currentScene = currentScene->getParentScene();
                currentScene->start();
                continue;
            }
            currentScene->update();
        }
    }

    void dispatchEvent(BaseEvent event) {
        if (currentScene == nullptr) {
            return;
        }
        if (event.value == 27) {

            currentScene->back();
            return;
        }
        currentScene->onEvent(event);
    }
};


#endif //FRAME_BUFFER_MAIN_CONTROLLER_H
