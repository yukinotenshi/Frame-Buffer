//
// Created by Gabriel Raphael on 16/02/2019.
//

#include "core/canvas.h"
#include "core/color.h"
#include "core/point.h"
#include "drawable/circle.h"
#include "drawable/line.h"
#include "drawable/polygon.h"
#include "factory/line_factory.h"
#include <unistd.h>
#include <vector>

int main() {
    std::vector<Line> lines;
    LineFactory lineFactory("example_files/line.txt");
    lines = lineFactory.generate();
    Line line = lines.at(0);

    Point p1, p2, p3;
    p1.setY(100);
    p2.setY(200);
    p3.setX(100);

    Polygon polygon(3, p1, p2, p3);
    polygon.draw();

    Circle circle(p1, 100);
    circle.draw();

    for (int x = 0; x < 1000; x++) {
        usleep(1000);
        line.move(1,1);
        polygon.move(1,1);
        circle.move(1,1);
    }

    return 0;
}
