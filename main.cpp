//
// Created by Gabriel Raphael on 16/02/2019.
//

#include "canvas.h"
#include "drawable/point.h"

int main() {
    Canvas canvas;
    Point point;
    for (int x = 0; x < 100; x++) {
        point.setX(x);
        canvas.writePoint(point);
    }

    return 0;
}
