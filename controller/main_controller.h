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
                currentScene = currentScene->getChildScene();
            }
            if (currentScene->getParentScene() != nullptr && currentScene->isToParent()) {
                currentScene = currentScene->getParentScene();
            }
            currentScene->update();
        }
    }

    void dispatchEvent(BaseEvent event) {
        if (currentScene == nullptr) {
            return;
        }
        currentScene->onEvent(event);
    }
};


#endif //FRAME_BUFFER_MAIN_CONTROLLER_H
