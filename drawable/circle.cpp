//
// Created by Gabriel Raphael on 16/02/2019.
//

#include "circle.h"
#include "math.h"

std::vector<Point> Circle::generateQuadrants(Point p) {
    std::vector<Point> points;
    Point temp;

    temp.setX(center.getX() + p.getX());
    temp.setY(center.getY() + p.getY());
    points.push_back(temp);

    temp.setX(center.getX() + p.getX());
    temp.setY(center.getY() - p.getY());
    points.push_back(temp);

    temp.setX(center.getX() - p.getX());
    temp.setY(center.getY() + p.getY());
    points.push_back(temp);

    temp.setX(center.getX() - p.getX());
    temp.setY(center.getY() - p.getY());
    points.push_back(temp);

    temp.setX(center.getX() + p.getY());
    temp.setY(center.getY() + p.getX());
    points.push_back(temp);

    temp.setX(center.getX() + p.getY());
    temp.setY(center.getY() - p.getX());
    points.push_back(temp);

    temp.setX(center.getX() - p.getY());
    temp.setY(center.getY() + p.getX());
    points.push_back(temp);

    temp.setX(center.getX() - p.getY());
    temp.setY(center.getY() - p.getX());
    points.push_back(temp);

    return points;
}

Point Circle::getCenter() {
    return this->center;
}

double Circle::getRadius() {
  return this->radius;
}

void Circle::drawQuadrants(Point p) {
    std::vector<Point> points;
    points = generateQuadrants(p);

    for (auto point : points) {
        this->writePoint(point, color);
    }
}

void Circle::delQuadrants(Point p) {
    std::vector<Point> points;
    points = generateQuadrants(p);

    for (auto point : points) {
        this->deletePoint(point);
    }
}

void Circle::execute(char action) {
    int x = 0;
    int y = radius;
    int d = 3 - 2 * radius;

    Point p(x, y);
    if (action == 'c') {
        drawQuadrants(p);
    } else {
        delQuadrants(p);
    }

    while (x <= y)
    {
        x++;
        if (d < 0)
        {
            d = d + 4 * x + 6;
        }
        else
        {
            d = d + 4 * (x - y) + 10;
            y--;
        }
        p.setX(x);
        p.setY(y);
        if (action == 'c') {
            drawQuadrants(p);
        } else {
            delQuadrants(p);
        }
    }
}

void Circle::draw() {
    execute('c');
}

void Circle::del() {
    execute('d');
}

void Circle::move(long x, long y) {
    execute('d');
    center.setY(center.getY() + y);
    center.setX(center.getX() + x);
    prevCenter = center;
    execute('c');
}

void Circle::rotate(const Point &anchor, double degree) {
    del();
    center = prevCenter;
    double dx = -anchor.getX() + center.getX();
    double dy = -anchor.getY() + center.getY();
    currentDegree += degree;
    center.setX((long) (dx * cos(currentDegree) - dy * sin(currentDegree) + anchor.getX()));
    center.setY((long) (dx * sin(currentDegree) + dy * cos(currentDegree) + anchor.getY()));
    draw();
}

void Circle::dilate(double multipler) {
    del();
    double scale = sqrt(multipler);
    radius = scale * radius;
    draw();
}

void Circle::fill(){
    std::queue<Point> queue_point;
    std::set<Point> set_point;
    Point curr;
    Point temp;
    std::set<Point>::iterator it2;


    queue_point.push(this->getCenter());
    set_point.insert(queue_point.front());

    while(!queue_point.empty()){
        curr = queue_point.front();
        queue_point.pop();
        std::set<Point>::iterator it;

        if(this->isInside(curr)){
            this->writePoint(curr,color);

            temp = Point(curr.getX()+1, curr.getY());
            it = set_point.find(temp);
            if (it == set_point.end()) {
                queue_point.push(Point{curr.getX() + 1, curr.getY()});
                set_point.insert(queue_point.back());
            } else {
              Point p = *it;
            }

            it = set_point.find(Point{curr.getX() - 1, curr.getY()});
            if (it == set_point.end()) {
                queue_point.push(Point{curr.getX() - 1, curr.getY()});
                set_point.insert(queue_point.back());
            }

            it = set_point.find(Point{curr.getX(), curr.getY() + 1});
            if (it == set_point.end()) {
                queue_point.push(Point{curr.getX(), curr.getY() + 1});
                set_point.insert(queue_point.back());
            }

            it = set_point.find(Point{curr.getX(), curr.getY() - 1});
            if (it == set_point.end()) {
                queue_point.push(Point{curr.getX(), curr.getY() - 1});
                set_point.insert(queue_point.back());
            }
        } else {
          // std::cout << "HAHAHAA" << std::endl;
        }
    }
}

bool Circle::isInside(Point p) {
  if (this->getCenter().distance(p) < this->getRadius()) {
    return true;
  } else {
    return false;
  }
}
