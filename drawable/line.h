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
public:
    Line();

    Line(const Point &from, const Point &to);

    const Point &getFrom() const;

    void setFrom(const Point &from);

    const Point &getTo() const;

    void setTo(const Point &to);

    void execute(char action);

    void draw() override;

    void del() override;

    void move(long x, long y) override;

    void rotate(const Point& anchor, double degree) override;
};


#endif //FRAME_BUFFER_LINE_H
