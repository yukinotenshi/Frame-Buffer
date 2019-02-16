//
// Created by Gabriel Raphael on 16/02/2019.
//

#include "canvas.h"

Canvas::Canvas() {
    file = open("/dev/fb0", O_RDWR);
    if (file >= 0) {
        if (!ioctl(file, FBIOGET_VSCREENINFO, &screen_info) &&
            !ioctl(file, FBIOGET_FSCREENINFO, &fixed_info)) {
            buflen = screen_info.yres_virtual * fixed_info.line_length;
            buffer = mmap(NULL,
                          buflen,
                          PROT_READ | PROT_WRITE,
                          MAP_SHARED,
                          file,
                          0);
        }
    }
}

Canvas::~Canvas() {
    if (file >= 0) {
        close(file);
    }

    if (buffer && buffer != MAP_FAILED) {
        munmap(buffer, buflen);
    }
}

void Canvas::writePoint(Point p) {
    long offset = p.getX() * screen_info.bits_per_pixel/8 + p.getY() * fixed_info.line_length;
    buffer[offset] = p.getR();
    buffer[offset+1] = p.getG();
    buffer[offset+2] = p.getB();
    buffer[offset+3] = p.getA();
}

void Canvas::deletePoint(Point p) {
    long offset = p.getX() * screen_info.bits_per_pixel/8 + p.getY() * fixed_info.line_length;
    buffer[offset] = 0x00;
    buffer[offset+1] = 0x00;
    buffer[offset+2] = 0x00;
    buffer[offset+3] = 0x00;
}

void Canvas::movePoint(Point from, Point to) {
    deletePoint(from);
    from.setX(to.getX());
    from.setY(to.getY());
    writePoint(from);
}
