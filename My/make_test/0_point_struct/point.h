/*
header file for point class (aka struct)
*/

typedef struct Point{
    double x; 
    double y;
}Point;

Point init(double x, double y);
Point midpoint(Point p, Point q); 
