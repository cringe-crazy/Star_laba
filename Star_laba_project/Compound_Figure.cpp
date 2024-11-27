#include "Compoud_Figure.h"

void Compound_Figure::draw() const  {
    s.draw();
    c.draw();
}

void Compound_Figure::move(int dx, int dy) {
    hide();
    s.center.x += dx;
    s.center.y += dy;
    c.center.x += dx;
    c.center.y += dy;
    draw();
}

void Compound_Figure::hide() const {
    s.hide();
}