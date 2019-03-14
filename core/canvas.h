//
// Created by Gabriel Raphael on 16/02/2019.
//

#ifndef FRAME_BUFFER_CANVAS_H
#define FRAME_BUFFER_CANVAS_H

#include <sys/types.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <linux/fb.h>
#include <unistd.h>
#include <fcntl.h>
#include "point.h"
#include "color.h"


class Canvas {
private:
    struct fb_var_screeninfo screen_info;
    struct fb_fix_screeninfo fixed_info;
    char *buffer = nullptr;
    size_t buflen;
    int file;

    static Canvas* instance;
    Canvas();
public:
    static Canvas* getInstance();
    ~Canvas();
    void writePoint(Point p, Color c);
    void deletePoint(Point p);
    Color getPointColor(Point p);
    void movePoint(Point from, Point to, Color c);
    void clear();
};

#endif //FRAME_BUFFER_CANVAS_H
