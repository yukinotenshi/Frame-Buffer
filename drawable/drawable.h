//
// Created by Gabriel Raphael on 16/02/2019.
//

#ifndef FRAME_BUFFER_DRAWABLE_H
#define FRAME_BUFFER_DRAWABLE_H

#include "../core/color.h"
#include "../core/canvas.h"
#include "../core/view.h"

class Drawable {
protected:
    Color color;
    Canvas* canvas;
    View view;
    double currentDegree;

    void writePoint(const Point& p, Color c) {
        if (view.viewDefined() && view.inBoundary(p)) {
            canvas->writePoint(p, c);
        }

        if (! view.viewDefined()) {
            canvas->writePoint(p, c);
        }
    }

    void deletePoint(const Point& p) {
        if (view.viewDefined() && view.inBoundary(p)) {
            canvas->deletePoint(p);
        }

        if (! view.viewDefined()) {
            canvas->deletePoint(p);
        }
    }

public:
    Drawable() {
        canvas = Canvas::getInstance();
        currentDegree = 0.0;
    }

    virtual void draw() = 0;

    virtual void del() = 0;

    virtual void move(long x, long y) = 0;

    virtual void rotate(const Point& anchor, double degree) = 0;

    virtual void dilate(double multiplier) = 0;

    const Color &getColor() const {
        return color;
    }

    void setColor(const Color &color) {
        Drawable::color = color;
    }

    const View &getView() const {
        return view;
    }

    void setView(const View &view) {
        this->view = view;
    }
};


#endif //FRAME_BUFFER_DRAWABLE_H
