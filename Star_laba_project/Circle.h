#pragma once
#include "Figure.h"
#include <windows.h>
#include<windowsx.h>
#include <string>
using namespace std;

class Circle : public Figure {
public:
    Circle(int _x, int _y, int r, COLORREF color_figure, COLORREF color_pen) : Figure(_x, _y, r, color_figure, color_pen) {}
    void draw() const override;
    void hide() const override;
    void move(int dx, int dy) override;
};