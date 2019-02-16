//
// Created by Gabriel Raphael on 16/02/2019.
//

#include "core/canvas.h"
#include "core/color.h"
#include "core/point.h"
#include "drawable/line.h"
#include "drawable/polygon.h"
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

    Point p1, p2, p3;
    p1.setY(100);
    p2.setY(200);
    p3.setX(100);

    Polygon polygon(3, p1, p2, p3);
    polygon.draw();
    return 0;
}
