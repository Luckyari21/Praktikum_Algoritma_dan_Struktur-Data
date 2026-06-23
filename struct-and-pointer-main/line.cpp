#include "line.h"
#include <iostream>
using namespace std;

struct Line {
    float a, b, c;
};

struct Point {
    float x, y;
};

string Check(Line *l, Point *p) {
    float h = l->a * p->x + l->b * p->y + l->c;

    if (h > 0) return "Left";
    if (h < 0) return "Right";
    return "On Line";
}
