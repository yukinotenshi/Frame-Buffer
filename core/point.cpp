//
// Created by Gabriel Raphael on 16/02/2019.
//

#include "point.h"

Point::Point() {
    this->x = 0;
    this->y = 0;
}

Point::Point(double x, double y) : x(x), y(y) {}

double Point::getX() const {
    return x;
}

void Point::setX(double x) {
    Point::x = x;
}

double Point::getY() const {
    return y;
}

void Point::setY(double y) {
    Point::y = y;
}

double Point::distance(Point p){
    return(sqrt( pow(this->x - p.getX(),2) + pow(this->y - p.getY(),2) ));
}

bool Point::operator<(const Point& p) const{

    return(
      (this->getX() < p.getX())
     || (this->getX() == p.getX() && this->getY() < p.getY())
   );
}

bool Point::operator==(const Point& p) const{
    return(this->getX() == p.getX() && this->getY() == p.getY());
}

// bool Point::operator<(const Point& p1, const Point& p2){
//     return(p1.getX() < p2.getX() && p1.getY() < p2.getY() );
// }
