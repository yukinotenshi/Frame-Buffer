//
// Created by Gabriel Raphael on 16/02/2019.
//

#include "polygon.h"
#include <iostream>

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

    Color c(0, 0, 0, 0);
    scanlineFill(c);
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

void Polygon::initEdgeTable() {
    int height = canvas->getHeight();
    std::cout << height;
    edgeTable = new EdgeTableTuple[height];
    for (int i = 0; i < canvas->getHeight(); i++) 
    { 
        edgeTable[i].countEdgeBucket = 0; 
    }   
    activeEdgeTuple.countEdgeBucket = 0; 
}

void Polygon::sortEdges(EdgeTableTuple *ett) {
    int i,j; 
    EdgeBucket temp;  
  
    for (i = 1; i < ett->countEdgeBucket; i++)  
    { 
        temp.ymax = ett->buckets[i].ymax; 
        temp.xofymin = ett->buckets[i].xofymin; 
        temp.slopeinverse = ett->buckets[i].slopeinverse; 
        j = i - 1; 
  
    while ((temp.xofymin < ett->buckets[j].xofymin) && (j >= 0))  
    { 
        ett->buckets[j + 1].ymax = ett->buckets[j].ymax; 
        ett->buckets[j + 1].xofymin = ett->buckets[j].xofymin; 
        ett->buckets[j + 1].slopeinverse = ett->buckets[j].slopeinverse; 
        j = j - 1; 
    } 
    ett->buckets[j + 1].ymax = temp.ymax; 
    ett->buckets[j + 1].xofymin = temp.xofymin; 
    ett->buckets[j + 1].slopeinverse = temp.slopeinverse; 
    } 
}

void Polygon::storeEdgeInTuple (EdgeTableTuple *receiver,int ym,int xm,float slopInv) { 
    // both used for edgetable and active edge table.. 
    // The edge tuple sorted in increasing ymax and x of the lower end. 
    (receiver->buckets[(receiver)->countEdgeBucket]).ymax = ym; 
    (receiver->buckets[(receiver)->countEdgeBucket]).xofymin = (float)xm; 
    (receiver->buckets[(receiver)->countEdgeBucket]).slopeinverse = slopInv; 
              
    // sort the buckets 
    sortEdges(receiver); 
          
    (receiver->countEdgeBucket)++;  
       
} 

void Polygon::storeEdgeInTable (int x1,int y1, int x2, int y2) { 
    float m,minv; 
    int ymaxTS,xwithyminTS, scanline; //ts stands for to store 
      
    if (x2==x1) 
    { 
        minv=0.000000; 
    } 
    else
    { 
    m = ((float)(y2-y1))/((float)(x2-x1)); 
      
    // horizontal lines are not stored in edge table 
    if (y2==y1) 
        return; 
          
    minv = (float)1.0/m; 
    } 
      
    if (y1>y2) 
    { 
        scanline=y2; 
        ymaxTS=y1; 
        xwithyminTS=x2; 
    } 
    else
    { 
        scanline=y1; 
        ymaxTS=y2; 
        xwithyminTS=x1;      
    } 
    // the assignment part is done..now storage.. 
    storeEdgeInTuple(&edgeTable[scanline],ymaxTS,xwithyminTS,minv);    
} 

void Polygon::storeAllEdgeInTable() {
    for (unsigned int i = 0; i < points.size()-1; i++) {
        storeEdgeInTable(
            points.at(i).getX(), 
            points.at(i).getY(), 
            points.at(i+1).getX(), 
            points.at(i+1).getY()
        );
    }
}

void Polygon::removeEdgeByYmax(EdgeTableTuple *Tup,int yy) { 
    int i,j; 
    for (i=0; i< Tup->countEdgeBucket; i++) 
    { 
        if (Tup->buckets[i].ymax == yy) 
        {               
            for ( j = i ; j < Tup->countEdgeBucket -1 ; j++ ) 
            { 
                Tup->buckets[j].ymax =Tup->buckets[j+1].ymax; 
                Tup->buckets[j].xofymin =Tup->buckets[j+1].xofymin; 
                Tup->buckets[j].slopeinverse = Tup->buckets[j+1].slopeinverse; 
            } 
            Tup->countEdgeBucket--; 
            i--; 
        } 
    } 
}   

void Polygon::updatexbyslopeinv(EdgeTableTuple *Tup) 
{ 
    int i; 
      
    for (i=0; i<Tup->countEdgeBucket; i++) 
    { 
        (Tup->buckets[i]).xofymin =(Tup->buckets[i]).xofymin + (Tup->buckets[i]).slopeinverse; 
    } 
}

void Polygon::scanlineFill(Color c)
{
    int i, j, x1, ymax1, x2, ymax2, FillFlag = 0, coordCount;

    initEdgeTable();
    storeAllEdgeInTable();
    // we will start from scanline 0;
    // Repeat until last scanline:
    for (i = 0; i < canvas->getHeight(); i++) //4. Increment y by 1 (next scan line)
    {

        // 1. Move from ET bucket y to the
        // AET those edges whose ymin = y (entering edges)
        for (j = 0; j < edgeTable[i].countEdgeBucket; j++)
        {
            storeEdgeInTuple(&activeEdgeTuple, edgeTable[i].buckets[j].ymax, edgeTable[i].buckets[j].xofymin,
                             edgeTable[i].buckets[j].slopeinverse);
        }

        // 2. Remove from AET those edges for
        // which y=ymax (not involved in next scan line)
        removeEdgeByYmax(&activeEdgeTuple, i);

        //sort AET (remember: ET is presorted)
        sortEdges(&activeEdgeTuple);


        //3. Fill lines on scan line y by using pairs of x-coords from AET
        j = 0;
        FillFlag = 0;
        coordCount = 0;
        x1 = 0;
        x2 = 0;
        ymax1 = 0;
        ymax2 = 0;
        while (j < activeEdgeTuple.countEdgeBucket)
        {
            if (coordCount % 2 == 0)
            {
                x1 = (int)(activeEdgeTuple.buckets[j].xofymin);
                ymax1 = activeEdgeTuple.buckets[j].ymax;
                if (x1 == x2)
                {
                    /* three cases can arrive- 
                    1. lines are towards top of the intersection 
                    2. lines are towards bottom 
                    3. one line is towards top and other is towards bottom 
                */
                    if (((x1 == ymax1) && (x2 != ymax2)) || ((x1 != ymax1) && (x2 == ymax2)))
                    {
                        x2 = x1;
                        ymax2 = ymax1;
                    }

                    else
                    {
                        coordCount++;
                    }
                }

                else
                {
                    coordCount++;
                }
            }
            else
            {
                x2 = (int)activeEdgeTuple.buckets[j].xofymin;
                ymax2 = activeEdgeTuple.buckets[j].ymax;

                FillFlag = 0;

                // checking for intersection...
                if (x1 == x2)
                {
                    /*three cases can arive- 
                    1. lines are towards top of the intersection 
                    2. lines are towards bottom 
                    3. one line is towards top and other is towards bottom 
                */
                    if (((x1 == ymax1) && (x2 != ymax2)) || ((x1 != ymax1) && (x2 == ymax2)))
                    {
                        x1 = x2;
                        ymax1 = ymax2;
                    }
                    else
                    {
                        coordCount++;
                        FillFlag = 1;
                    }
                }
                else
                {
                    coordCount++;
                    FillFlag = 1;
                }

                if (FillFlag)
                {
                    //drawing actual lines...
                    Point p1(x1, i);
                    Point p2(x2, i);
                    Line line;
                    line.setFrom(p1);
                    line.setTo(p2);
                    line.setView(view);
                    line.setColor(c);
                    line.draw();
                    // printf("\nLine drawn from %d,%d to %d,%d",x1,i,x2,i);
                }
            }

            j++;
        }

        // 5. For each nonvertical edge remaining in AET, update x for new y
        updatexbyslopeinv(&activeEdgeTuple);
    }
}