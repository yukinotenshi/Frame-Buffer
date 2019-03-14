//
// Created by yukinotenshi on 3/14/2019.
//

#ifndef FRAME_BUFFER_FIFTH_SCENE_H
#define FRAME_BUFFER_FIFTH_SCENE_H


#include "base_scene.h"
#include "../drawable/circle.h"
#include "../drawable/rectangle.h"
#include "../drawable/polygon.h"

class FifthScene : public BaseScene {
private:
    std::vector<Circle> circles;
    std::vector<Rectangle> rectangles;
    std::vector<Polygon> polygons;
public:
    FifthScene();

    explicit FifthScene(BaseScene * scene);

    FifthScene(std::vector<Drawable*> drawables);

    void start() override;

    void update() override;

    void onEvent(BaseEvent event) override;
};


#endif //FRAME_BUFFER_FIRST_SCENE_H
