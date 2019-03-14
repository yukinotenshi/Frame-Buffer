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
#include "scene/menu_scene.h"
#include "controller/main_controller.h"
#include "event_dispatcher/keyboard_dispatcher.h"
#include <unistd.h>
#include <vector>
#include <thread>

std::vector<Dot> drawName(std::string filename) {
    DotFactory dotFactory(filename);
    return dotFactory.generate();
}

int main() {
    GroupFactory objFactory("example_files/group");
    GroupObject object = objFactory.create();
    std::vector<Drawable*> drawables;
    drawables.push_back(&object);

    MenuScene scene(drawables);
    MainController controller(&scene);
    KeyboardDispatcher dispatcher(&controller);
    usleep(1000000);
    std::thread thread2([&dispatcher] {dispatcher.run();});
    usleep(1000000);
    std::thread thread([&controller] {controller.run();});

    thread.join();
    thread2.join();

    return 0;
}
