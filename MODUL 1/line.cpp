#include <iostream>
#include "line.h"
#include "point.h"
using namespace std;

string Check(Line *l, Point *p) {
    double h = l->a * p->x + l->b * p->y + l->c;

    if (h > 0) return "Left";
    if (h < 0) return "Right";
    return "On Line";
}