//
// Created by RenjiraND on 3/14/2019.
//

#include "fourth_scene.h"
#include <iostream>

FourthScene::FourthScene() : BaseScene() {}

FourthScene::FourthScene(BaseScene *scene) : BaseScene(scene) {}

FourthScene::FourthScene(std::vector<Drawable *> drawables) : BaseScene(drawables) {}

FourthScene::~FourthScene() {
    for (GroupObject * groupObject : object) {
        delete groupObject;
    }
}

void FourthScene::start() {
    GroupFactory tankFactory("example_files/tank.txt");
    GroupObject * tank = new GroupObject(tankFactory.create());
    object.push_back(tank);

    GroupFactory planeFactory("example_files/plane.txt");
    GroupObject * plane = new GroupObject(planeFactory.create());
    object.push_back(plane);

    GroupFactory bulletFactory("example_files/bullet.txt");
    GroupObject * bullet = new GroupObject(bulletFactory.create());
    object.push_back(bullet);
    
    GroupFactory buildingFactory("example_files/building.txt");
    GroupObject * building = new GroupObject(buildingFactory.create());
    object.push_back(building);

    for (GroupObject * groupObject : object) {
        groupObject->draw();
    }
}

void FourthScene::update() {
    Circle circ(Point{700,100},30);
    for(size_t i = 0; i < 20; i++)
    {
        circ.dilate(1.1);
        object[2]->move(0,5);
        object[0]->move(5,0);
        object[1]->rotate(Point{400,600}, -0.05);
        usleep(50000);
        object[3]->draw();
    }
    circ.dilate(-2.2);
    object[2]->move(0,-100);   
}

void FourthScene::onEvent(BaseEvent event) {}

