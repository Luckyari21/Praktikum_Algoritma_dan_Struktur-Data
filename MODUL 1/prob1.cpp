#include <iostream>
using namespace std;
#include "line.cpp"

int main() {
    Line l;
    Point p;

    cin >> l.a >> l.b >> l.c >> p.x >> p.y;

    cout << Check(&l, &p);

    return 0;
}