//
// Created by Gabriel Raphael on 16/02/2019.
//

#include "polygon.h"


Polygon::Polygon(const std::vector<Point>& points) {
    for (const Point& p : points) {
        this->points.push_back(p);
        this->prevPoints.push_back(p);
    }
}

Polygon::Polygon(int count, ...) {
    va_list args;
    va_start(args, count);
    for (int i = 0; i < count; i++) {
        this->points.push_back(va_arg(args, Point));
        this->prevPoints.push_back(va_arg(args, Point));
    }
    va_end(args);
}

void Polygon::draw() {
    Line temp;
    for (unsigned int i = 0; i < points.size()-1; i++) {
        temp.setFrom(points.at(i));
        temp.setTo(points.at(i+1));
        temp.setView(view);
        temp.draw();
    }

    temp.setFrom(points.back());
    temp.setTo(points.front());
    temp.draw();
}

void Polygon::del() {
    Line temp;
    for (unsigned int i = 0; i < points.size()-1; i++) {
        temp.setFrom(points.at(i));
        temp.setTo(points.at(i+1));
        temp.setView(view);
        temp.del();
    }

    temp.setFrom(points.back());
    temp.setTo(points.front());
    temp.del();
}

void Polygon::move(long x, long y) {
    del();
    for (unsigned int i = 0; i < points.size(); i++) {
        Point& p = points.at(i);
        p.setX(p.getX() + x);
        p.setY(p.getY() + y);
        prevPoints.at(i) = p;
    }

    draw();
}

//modified from : https://gamedev.stackexchange.com/questions/121478/how-to-rotate-a-2d-line
void Polygon::rotate(const Point &anchor, double degree) {
    del();
    for (unsigned int i = 0; i < points.size(); i++) {
        points.at(i) = prevPoints.at(i);
    }
    currentDegree += degree;
    double sin_ = sin(currentDegree);
    double cos_ = cos(currentDegree);

    for (Point& point : points) {
        double dx = -anchor.getX() + point.getX();
        double dy = -anchor.getY() + point.getY();
        point.setX((dx * cos_ - dy * sin_ +  anchor.getX()));
        point.setY((dx * sin_ + dy * cos_ +  anchor.getY()));
    }
    draw();
}

void Polygon::dilate(double multiplier) {
    del();
    for (Point& point : points) {
        point.setX(point.getX() * multiplier);
        point.setY(point.getY() * multiplier);
    }
    draw();
}

std::vector<Point> Polygon::getPoint(){
    return this->points;
}

std::vector<Point> Polygon::getPrevPoint(){
    return this->prevPoints;
}

Point Polygon::getPointInTriangle(){
    std::vector<Point> triangle;
    for(size_t i = 0; i < 3; i++)
    {
        triangle.push_back(this->getPoint()[i]);
    }
    double new_X = (triangle[0].getX()+triangle[1].getX()+triangle[2].getX())/3;
    double new_Y = (triangle[0].getY()+triangle[1].getY()+triangle[2].getY())/3;
    Point res(new_X,new_Y);
    std::cout << new_X << " " << new_Y << std::endl;
    return(res);
}

bool Polygon::inBorder(Point checked){
    for(size_t i = 0; i < this->getPoint().size(); i++)
    {
        if (this->getPoint()[i].distance(checked) + this->getPrevPoint()[i].distance(checked) == this->getPrevPoint()[i].distance(this->getPrevPoint()[i]))
        {    
            return true;
        }
    }
    return false;
}

void Polygon::fill(){
    std::queue<Point> queue_point;
    std::set<Point> set_point;
    Point curr;
    queue_point.push(this->getPointInTriangle());
    set_point.insert(queue_point.front());
    while(!queue_point.empty()){
        curr = queue_point.front();
        queue_point.pop();
        std::set<Point>::iterator it;
        // if(! (this->inBorder(curr)) ){
            this->writePoint(curr,color);
            std::cout << curr.getX() << " " << curr.getY() << std::endl;

            it = set_point.find(Point{curr.getX() + 1, curr.getY()});
            if (it != set_point.end()) {
                queue_point.push(Point{curr.getX() + 1, curr.getY()});
                set_point.insert(queue_point.back());    
            }

            it = set_point.find(Point{curr.getX() - 1, curr.getY()});
            if (it != set_point.end()) {
                queue_point.push(Point{curr.getX() - 1, curr.getY()});
                set_point.insert(queue_point.back());
            }

            it = set_point.find(Point{curr.getX(), curr.getY() + 1});
            if (it != set_point.end()) {
                queue_point.push(Point{curr.getX(), curr.getY() + 1});
                set_point.insert(queue_point.back());             
            }

            it = set_point.find(Point{curr.getX(), curr.getY() - 1});
            if (it != set_point.end()) {
                queue_point.push(Point{curr.getX(), curr.getY() - 1});
                set_point.insert(queue_point.back());
            }
        // }
    }
    
}