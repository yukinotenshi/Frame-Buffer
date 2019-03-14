//
// Created by yukinotenshi on 3/13/2019.
//

#include "group_object.h"

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
        } else if (action == 'f') {
            drawable->fill();
        }
    }
}

void GroupObject::draw() {
    execute('c');
}

void GroupObject::del() {
    execute('d');
}

void GroupObject::fill() {
    execute('f');
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
