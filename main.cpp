//
// Created by Gabriel Raphael on 16/02/2019.
//

#include "core/canvas.h"
#include "core/color.h"
#include "core/point.h"
#include "drawable/dot.h"
#include "drawable/circle.h"
#include "drawable/rectangle.h"
#include "drawable/polygon.h"
#include "drawable/line.h"
#include "drawable/group_object.h"
#include "factory/rectangle_factory.h"
#include "factory/polygon_factory.h"
#include "factory/circle_factory.h"
#include "factory/line_factory.h"
#include "factory/dot_factory.h"
#include "factory/group_factory.h"
#include "core/view.h"
#include <unistd.h>
#include <vector>

std::vector<Dot> drawName(std::string filename) {
    DotFactory dotFactory(filename);
    return dotFactory.generate();
}

int main() {
    Point p1(50,50);

    // GroupFactory objFactory("example_files/group");
    // GroupObject object = objFactory.create();

    // for (int i = 0; i < 1000; i++) {
    //     usleep(10000);
    //     object.rotate(p1, 0.01);
    // }
    std::vector<Dot> dots = drawName("example_files/listname.txt");
    for (int i = 0; i < dots.size(); i++) {
        dots[i].draw();
    }
    return 0;
}
