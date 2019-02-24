//
// Created by Gabriel Raphael on 16/02/2019.
//

#ifndef FRAME_BUFFER_LINE_H
#define FRAME_BUFFER_LINE_H

#include <math.h>
#include "../core/point.h"
#include "drawable.h"

class Line : public Drawable{
private:
    Point from;
    Point to;
    Point prevFrom;
    Point prevTo;
public:
    Line();

    Line(Color &color);

    Line(const Point &from, const Point &to, Color &color);

    const Point &getFrom() const;

    void setFrom(const Point &from);

    const Point &getTo() const;

    void setTo(const Point &to);

    void execute(char action);

    void draw() override;

    void del() override;

    void move(long x, long y) override;

    void rotate(const Point& anchor, double degree) override;

    void dilate(double multiplier) override;
};


#endif //FRAME_BUFFER_LINE_H
