#include <iostream>
using namespace std;
#include "circle.cpp"

int main() {
    Circle c;
    Point p;

    cin >> c.cx >> c.cy >> c.r >> p.x >> p.y;

    cout << CheckPointInCircle(&c, &p);

    return 0; 
}