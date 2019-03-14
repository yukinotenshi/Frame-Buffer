//
// Created by yukinotenshi on 13/03/2019.
//

#ifndef FRAME_BUFFER_DOT_H
#define FRAME_BUFFER_DOT_H

#include <math.h>
#include "../core/point.h"
#include "drawable.h"

class Dot : public Drawable{
private:
    Point point;
    Point prevPoint;
public:
    Dot();

    Dot(const Point &point);

    void execute(char action);

    void draw() override;

    void del() override;

    void move(long x, long y) override;

    void rotate(const Point& anchor, double degree) override;

    void dilate(double multiplier) override;
};


#endif //FRAME_BUFFER_DOT_H
