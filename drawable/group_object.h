//
// Created by yukinotenshi on 3/13/2019.
//

#ifndef FRAME_BUFFER_GROUP_OBJECT_H
#define FRAME_BUFFER_GROUP_OBJECT_H


#include "../core/point.h"
#include "drawable.h"
#include <vector>


class GroupObject : public Drawable {
public:
    std::vector<Drawable *> drawables;

    GroupObject();

    ~GroupObject();

    GroupObject(const GroupObject& other);

    GroupObject(std::vector<Drawable*> drawables);

    void execute(char action);

    void draw() override;

    void del() override;

    void move(long x, long y) override;

    void rotate(const Point& anchor, double degree) override;

    void dilate(double multiplier) override;

    // GroupObject& operator=(const GroupObject& other);
};


#endif //FRAME_BUFFER_GROUP_OBJECT_H
