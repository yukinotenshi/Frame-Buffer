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
#include <stdio.h>
#include "drawable/point.h"


class Canvas {
private:
    struct fb_var_screeninfo screen_info;
    struct fb_fix_screeninfo fixed_info;
    char *buffer = NULL;
    size_t buflen;
    int file;
public:
    Canvas();
    ~Canvas();
    void writePoint(Point p);
    void deletePoint(Point p);
    void movePoint(Point from, Point to);
};

#endif //FRAME_BUFFER_CANVAS_H
