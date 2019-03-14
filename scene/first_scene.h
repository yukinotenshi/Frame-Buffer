//
// Created by yukinotenshi on 3/14/2019.
//

#ifndef FRAME_BUFFER_FIRST_SCENE_H
#define FRAME_BUFFER_FIRST_SCENE_H


#include "base_scene.h"
#include "../drawable/dot.h"

class FirstScene : public BaseScene {
private:
    std::vector<Dot> dots;
public:
    FirstScene();

    explicit FirstScene(BaseScene * scene);

    FirstScene(std::vector<Drawable*> drawables);
    
    void start() override;
    
    void update() override;

    void onEvent(BaseEvent event) override;
};


#endif //FRAME_BUFFER_FIRST_SCENE_H
