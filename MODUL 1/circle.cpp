#include "circle.h"
#include "point.h"
#include <iostream>
#include <cmath>
using namespace std;

float distance(Circle *c, Point *p) {
    return sqrt((p->x - c->cx)*(p->x - c->cx) + 
                (p->y - c->cy)*(p->y - c->cy));
}

string CheckPointInCircle(Circle *c, Point *p) {
    float d = distance(c, p);

    if (d == c->r) return "On Circle";
    if (d < c->r) return "Inside";
    return "Outside";
}