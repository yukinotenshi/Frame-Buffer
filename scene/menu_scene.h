//
// Created by yukinotenshi on 3/14/2019.
//

#ifndef FRAME_BUFFER_MENU_SCENE_H
#define FRAME_BUFFER_MENU_SCENE_H


#include "base_scene.h"
#include "../drawable/rectangle.h"

class MenuScene : public  BaseScene {
private:
    Rectangle * pointer;
    int pointerPos;
public:
    MenuScene();

    MenuScene(BaseScene * scene);

    MenuScene(std::vector<Drawable*> drawables);

    void start();

    void update();

    void onEvent(BaseEvent event);
};


#endif //FRAME_BUFFER_MENU_SCENE_H
