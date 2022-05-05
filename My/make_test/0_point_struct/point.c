#include "point.h"

Point init(double x, double y){
    Point p;
    p.x = x; 
    p.y = y;
    return p;
}

Point midpoint(Point p, Point q){
    Point mid; 
    mid.x = (p.x + q.x) / 2.;
    mid.y = (p.y + p.y) / 2.;
    return mid;
}