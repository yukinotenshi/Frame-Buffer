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

Color::Color(char b, char g, char r, char a) : r(r), g(g), b(b), a(a) {}

Color::Color(std::string color) {
  if (color == "blue") {
    r = (char) 0x00;
    g = (char) 0x00;
    b = (char) 0xFF;
    a = (char) 0xFF;
  } else if (color == "red") {
    r = (char) 0xFF;
    g = (char) 0x00;
    b = (char) 0x00;
    a = (char) 0xFF;
  } else if (color == "green") {
    r = (char) 0x00;
    g = (char) 0xFF;
    b = (char) 0x00;
    a = (char) 0xFF;
  } else {
    r = (char) 0xFF;
    g = (char) 0xFF;
    b = (char) 0xFF;
    a = (char) 0xFF;
  }
}

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
