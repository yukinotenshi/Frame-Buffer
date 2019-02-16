//
// Created by Gabriel Raphael on 16/02/2019.
//

#include "color.h"

Color::Color() {
    r = (char) 0xFF;
    g = (char) 0xFF;
    b = (char) 0xFF;
    a = (char) 0xFF;
}

Color::Color(char r, char g, char b, char a) : r(r), g(g), b(b), a(a) {}

char Color::getR() const {
    return r;
}

void Color::setR(char r) {
    Color::r = r;
}

char Color::getG() const {
    return g;
}

void Color::setG(char g) {
    Color::g = g;
}

char Color::getB() const {
    return b;
}

void Color::setB(char b) {
    Color::b = b;
}

char Color::getA() const {
    return a;
}

void Color::setA(char a) {
    Color::a = a;
}
