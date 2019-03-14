//
// Created by yukinotenshi on 3/13/2019.
//

#ifndef FRAME_BUFFER_GROUP_FACTORY_H
#define FRAME_BUFFER_GROUP_FACTORY_H


#include "base_factory.h"
#include "../drawable/drawable.h"
#include "../drawable/polygon.h"
#include "../drawable/rectangle.h"
#include "../drawable/dot.h"
#include "../drawable/circle.h"
#include "../drawable/group_object.h"

class GroupFactory : BaseFactory<Drawable*> {
private:
    Polygon* parsePolygon();
    Rectangle* parseRectangle();
    Circle* parseCircle();
    Dot* parseDot();
    Line* parseLine();
public:
    GroupFactory(const std::string &filename);

    std::vector<Drawable*> generate() override;

    GroupObject create();
};


#endif //FRAME_BUFFER_GROUP_FACTORY_H
