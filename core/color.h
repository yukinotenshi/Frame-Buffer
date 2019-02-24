//
// Created by Gabriel Raphael on 16/02/2019.
//

#ifndef FRAME_BUFFER_COLOR_H
#define FRAME_BUFFER_COLOR_H

#include <string>

class Color {
private:
    char r;
    char g;
    char b;
    char a;
public:
    Color();

    Color(char r, char g, char b, char a);

    Color(std::string color);

    char getR() const;

    void setR(char r);

    char getG() const;

    void setG(char g);

    char getB() const;

    void setB(char b);

    char getA() const;

    void setA(char a);
};


#endif //FRAME_BUFFER_COLOR_H
