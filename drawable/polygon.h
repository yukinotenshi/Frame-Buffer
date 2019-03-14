//
// Created by Gabriel Raphael on 16/02/2019.
//

#ifndef FRAME_BUFFER_POLYGON_H
#define FRAME_BUFFER_POLYGON_H

#include <vector>
#include <queue>
#include <cstdarg>
#include "drawable.h"
#include "../core/point.h"
#include "line.h"
#include <iostream>
#include<bits/stdc++.h>


class Polygon : public Drawable {
private:
    std::vector<Point> points;
    std::vector<Point> prevPoints;

    const static int maxVertices = 1000;

    typedef struct edgebucket
    {
        int ymax;   //max y-coordinate of edge
        float xofymin;  //x-coordinate of lowest edge point updated only in aet
        float slopeinverse;
    } EdgeBucket;

    typedef struct edgetabletup
    {
        // the array will give the scanline number
        // The edge table (ET) with edges entries sorted
        // in increasing y and x of the lower end

        int countEdgeBucket;    //no. of edgebuckets
        EdgeBucket buckets[maxVertices];
    } EdgeTableTuple;

    EdgeTableTuple *edgeTable;
    EdgeTableTuple activeEdgeTuple;

    void initEdgeTable();
    void sortEdges(EdgeTableTuple *ett);
    void storeEdgeInTuple (EdgeTableTuple *receiver,int ym,int xm,float slopInv);
    void storeEdgeInTable (int x1,int y1, int x2, int y2);
    void storeAllEdgeInTable();
    void removeEdgeByYmax(EdgeTableTuple *Tup, int yy);
    void updatexbyslopeinv(EdgeTableTuple *Tup);



public:
    explicit Polygon(const std::vector<Point>& points);

    explicit Polygon(Color &color, const std::vector<Point>& points);

    explicit Polygon(int count, ...);

    explicit Polygon(Color &color, int count, ...);

    std::vector<Point> getPoint();

    std::vector<Point> getPrevPoint();

    void draw() override;

    void move(long x, long y) override;

    void del() override;

    void rotate(const Point& anchor, double degree) override;

    void dilate(double multiplier) override;

    Point getPointInTriangle();

    void fill() override;

    void scanlineFill(Color c);

};


#endif //FRAME_BUFFER_POLYGON_H
