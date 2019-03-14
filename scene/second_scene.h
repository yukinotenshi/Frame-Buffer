//
// Created by RenjiraND on 3/14/2019.
//

#ifndef FRAME_BUFFER_SECOND_SCENE_H
#define FRAME_BUFFER_SECOND_SCENE_H

#include "base_scene.h"
#include "../drawable/line.h"

class SecondScene : public BaseScene {
private:
    std::vector<Line> lines;
public:
    SecondScene();

    explicit SecondScene(BaseScene * scene);

    SecondScene(std::vector<Drawable*> drawables);
    
    void start() override;
    
    void update() override;

    void onEvent(BaseEvent event) override;
};


#endif //FRAME_BUFFER_SECOND_SCENE_H
