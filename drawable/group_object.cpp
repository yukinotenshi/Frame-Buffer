//
// Created by yukinotenshi on 3/13/2019.
//

#include "group_object.h"
#include <iostream>

GroupObject::GroupObject() : Drawable(), drawables() {}

GroupObject::GroupObject(std::vector<Drawable*> drawables) : Drawable(), drawables(drawables) {}

GroupObject::GroupObject(const GroupObject& other) : Drawable(), drawables(other.drawables) {}

GroupObject::~GroupObject() {
    for (Drawable* drawable : drawables) {
        delete drawable;
    }
}

void GroupObject::execute(char action) {
    for (Drawable * drawable : drawables) {
        if (action == 'c') {
            drawable->draw();
        } else if (action == 'd') {
            drawable->del();
        }
    }
}

void GroupObject::draw() {
    execute('c');
}

void GroupObject::del() {
    execute('d');
}

void GroupObject::move(long x, long y) {
    for (Drawable* drawable : drawables) {
        drawable->move(x, y);
    }
}

void GroupObject::rotate(const Point& anchor, double degree) {
    for (Drawable* drawable : drawables) {
        drawable->rotate(anchor, degree);
    }
}

void GroupObject::dilate(double multiplier) {
    for (Drawable* drawable : drawables) {
        drawable->dilate(multiplier);
    }
}

// GroupObject& GroupObject::operator=(const GroupObject& other) {
//     this->drawables = other.drawables;
//     // for (Drawable* drawable : other.drawables)
//     return *this;
// }

