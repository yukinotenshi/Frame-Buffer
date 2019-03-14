//
// Created by RenjiraND on 3/14/2019.
//

#ifndef FRAME_BUFFER_THIRD_SCENE_H
#define FRAME_BUFFER_THIRD_SCENE_H

#include "base_scene.h"
#include "../drawable/circle.h"
#include "../factory/circle_factory.h"
#include "../drawable/rectangle.h"
#include "../factory/rectangle_factory.h"
#include "../drawable/polygon.h"
#include "../factory/polygon_factory.h"

class ThirdScene : public BaseScene {
private:
    std::vector<Circle> circles;
    std::vector<Rectangle> rectangles;
    std::vector<Polygon> polygons;
public:
    ThirdScene();

    explicit ThirdScene(BaseScene * scene);

    ThirdScene(std::vector<Drawable*> drawables);
    
    void start() override;
    
    void update() override;

    void onEvent(BaseEvent event) override;
};


#endif //FRAME_BUFFER_THIRD_SCENE_H
