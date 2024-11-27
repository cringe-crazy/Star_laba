#pragma once
#include "Circle.h"
#include "Star.h"

class Compound_Figure : public Figure {
private:
    Star s;
    Circle c;
public:
    Compound_Figure(int x, int y, int r, int R,  COLORREF color_figure_star, COLORREF color_pen_star, 
        COLORREF color_figure_circle, COLORREF color_pen_circle) :  s(x, y, r, R,  color_figure_star, color_pen_star),
        c(x, y, r, color_figure_circle, color_pen_circle) {}

    void draw() const override;
    void move(int dx, int dy) override;
    void hide() const override;

};
