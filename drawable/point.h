//
// Created by Gabriel Raphael on 16/02/2019.
//

#ifndef FRAME_BUFFER_POINT_H
#define FRAME_BUFFER_POINT_H


class Point {
private:
    long x;
    long y;
    char r;
    char g;
    char b;
    char a;
public:
    Point();

    long getX() const;

    void setX(long x);

    long getY() const;

    void setY(long y);

    char getR() const;

    void setR(char r);

    char getG() const;

    void setG(char g);

    char getB() const;

    void setB(char b);

    char getA() const;

    void setA(char a);
};


#endif //FRAME_BUFFER_POINT_H
