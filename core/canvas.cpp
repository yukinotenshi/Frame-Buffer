//
// Created by Gabriel Raphael on 16/02/2019.
//

#include "canvas.h"

Canvas* Canvas::instance = nullptr;

Canvas::Canvas() {
    file = open("/dev/fb0", O_RDWR);
    if (file >= 0) {
        if (!ioctl(file, FBIOGET_VSCREENINFO, &screen_info) &&
            !ioctl(file, FBIOGET_FSCREENINFO, &fixed_info)) {
            buflen = screen_info.yres_virtual * fixed_info.line_length;
            buffer = (char *) mmap(NULL,
                          buflen,
                          PROT_READ | PROT_WRITE,
                          MAP_SHARED,
                          file,
                          0);
        }
    }
}

Canvas* Canvas::getInstance() {
    if (!instance) {
        instance = new Canvas;
    }
    return instance;
}

Canvas::~Canvas() {
    if (file >= 0) {
        close(file);
    }

    if (buffer && buffer != MAP_FAILED) {
        munmap(buffer, buflen);
    }

    delete instance;
}

void Canvas::writePoint(Point p, Color c) {
    long offset = p.getX() * screen_info.bits_per_pixel/8 + p.getY() * fixed_info.line_length;
    if (offset >= ((long) buflen-3) || offset < 0) {
        return;
    }
    buffer[offset] = c.getR();
    buffer[offset+1] = c.getG();
    buffer[offset+2] = c.getB();
    buffer[offset+3] = c.getA();
}

Color Canvas::getPointColor(Point p) {
    long offset = p.getX() * screen_info.bits_per_pixel/8 + p.getY() * fixed_info.line_length;
    Color c(0,0,0,0);
    if (offset >= ((long) buflen-3) || offset < 0) {
        return c;
    }

    c.setR(buffer[offset]);
    c.setG(buffer[offset+1]);
    c.setB(buffer[offset+2]);
    c.setA(buffer[offset+3]);

    return c;
}

void Canvas::deletePoint(Point p) {
    long offset = p.getX() * screen_info.bits_per_pixel/8 + p.getY() * fixed_info.line_length;
    if (offset >= ((long) buflen-3) || offset < 0) {
        return;
    }
    buffer[offset] = 0x00;
    buffer[offset+1] = 0x00;
    buffer[offset+2] = 0x00;
    buffer[offset+3] = 0x00;
}

void Canvas::movePoint(Point from, Point to, Color c) {
    deletePoint(from);
    from.setX(to.getX());
    from.setY(to.getY());
    writePoint(from, c);
}

void Canvas::clear() {
    for (long i = 0; i < (long) buflen-3; i++) {
      this->buffer[i] = 0x00;
    }
}
