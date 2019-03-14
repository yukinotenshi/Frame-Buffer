//
// Created by RenjiraND on 3/14/2019.
//

#ifndef FRAME_BUFFER_FOURTH_SCENE_H
#define FRAME_BUFFER_FOURTH_SCENE_H

#include "base_scene.h"
#include "../drawable/group_object.h"
#include "../factory/group_factory.h"

class FourthScene : public BaseScene {
private:
    std::vector<GroupObject*> object;
public:
    FourthScene();

    explicit FourthScene(BaseScene * scene);

    FourthScene(std::vector<Drawable*> drawables);
    
    ~FourthScene();

    void start() override;
    
    void update() override;

    void onEvent(BaseEvent event) override;
};


#endif //FRAME_BUFFER_FOURTH_SCENE_H
