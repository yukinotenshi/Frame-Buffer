//
// Created by Gabriel Raphael on 16/02/2019.
//

#ifndef FRAME_BUFFER_DRAWABLE_H
#define FRAME_BUFFER_DRAWABLE_H

#include "../core/color.h"
#include "../core/canvas.h"

class Drawable {
protected:
    Color color;
    Canvas canvas;
public:
    Drawable(const Color &color, const Canvas &canvas) : color(color), canvas(canvas) {}

    virtual void draw() = 0;

    virtual void del() = 0;

    virtual void move(long x, long y) = 0;

    const Color &getColor() const {
        return color;
    }

    void setColor(const Color &color) {
        Drawable::color = color;
    }
};


#endif //FRAME_BUFFER_DRAWABLE_H
