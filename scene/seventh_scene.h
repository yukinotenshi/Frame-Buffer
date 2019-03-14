//
// Created by RenjiraND on 3/14/2019.
//

#ifndef FRAME_BUFFER_SEVENTH_SCENE_H
#define FRAME_BUFFER_SEVENTH_SCENE_H

#include "base_scene.h"

#include "../drawable/polygon.h"
#include "../factory/polygon_factory.h"

class SeventhScene : public BaseScene {
public:
    SeventhScene();

    explicit SeventhScene(BaseScene * scene);

    SeventhScene(std::vector<Drawable*> drawables);
    
    ~SeventhScene();

    void start() override;
    
    void update() override;

    void onEvent(BaseEvent event) override;
};


#endif //FRAME_BUFFER_SEVENTH_SCENE_H
