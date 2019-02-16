//
// Created by Gabriel Raphael on 16/02/2019.
//

#ifndef FRAME_BUFFER_POINT_H
#define FRAME_BUFFER_POINT_H


class Point {
private:
    long x;
    long y;
public:
    Point();

    Point(long x, long y);

    long getX() const;

    void setX(long x);

    long getY() const;

    void setY(long y);
};


#endif //FRAME_BUFFER_POINT_H
