#include "point.h"
#include <assert.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    double x = 1.;
    double y = 2.;
    Point p = init(x, y); 
    assert(p.x == 1);
    return 0;
}
