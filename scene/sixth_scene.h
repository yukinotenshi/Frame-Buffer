//
// Created by yukinotenshi on 3/14/2019.
//

#ifndef FRAME_BUFFER_SIXTH_SCENE_H
#define FRAME_BUFFER_SIXTH_SCENE_H


#include "base_scene.h"
#include "../drawable/circle.h"
#include "../drawable/rectangle.h"
#include "../drawable/polygon.h"

class SixthScene : public BaseScene {
private:
    std::vector<Circle> circles;
    std::vector<Rectangle> rectangles;
    std::vector<Polygon> polygons;
public:
    SixthScene();

    explicit SixthScene(BaseScene * scene);

    SixthScene(std::vector<Drawable*> drawables);

    void start() override;

    void update() override;

    void onEvent(BaseEvent event) override;
};


#endif //FRAME_BUFFER_FIRST_SCENE_H
