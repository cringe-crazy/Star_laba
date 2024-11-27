#pragma once
#include "Figure.h"
#include <math.h>
#include <string>

class Star : public Figure {
protected:
    int R;
public:
    Star(int _x, int _y, int r, int R,  COLORREF color_figure, COLORREF color_pen) : Figure(_x, _y, r, color_figure, color_pen), R(R) {}
    class IncorrectRadius {
    public:
        std::string message;
        IncorrectRadius(std::string message) : message(message) {}
        virtual std::string getMessage() const {
            return message;
        }
    };

    void draw() const override;
    void hide() const override;
    void move(int dx, int dy) override ;
};