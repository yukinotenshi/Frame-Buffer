//
// Created by Gabriel Raphael on 16/02/2019.
//

#include "core/canvas.h"
#include "core/color.h"
#include "core/point.h"
#include "drawable/line.h"
#include <unistd.h>

int main() {
    Point from;
    Point to;
    to.setX(from.getX() + 100);
    to.setY(from.getY() + 100);
    Line line(from, to);
    line.draw();

    for (int x = 0; x < 1000; x++) {
        usleep(1000);
        line.move(1,1);
    }

    return 0;
}
