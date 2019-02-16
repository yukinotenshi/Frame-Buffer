//
// Created by Gabriel Raphael on 16/02/2019.
//

#include "core/canvas.h"
#include "core/color.h"
#include "core/point.h"
#include "drawable/line.h"

int main() {
    Canvas canvas;
    Color color;
    Point from;
    Point to;
    to.setX(from.getX() + 100);
    to.setY(from.getY() + 100);
    Line line(color, canvas, from, to);
    line.draw();

    for (int x = 0; x < 1000; x++) {
        line.move(x,x);
    }

    return 0;
}
