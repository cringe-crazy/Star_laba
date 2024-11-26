#pragma once
#include <windows.h>
#include<windowsx.h>
#include<iostream>
using namespace std;

struct Point {
    int x, y;
    Point(int x0 = 0, int y0 = 0) : x(x0), y(y0) {};
};


class Figure {
public:
    Point center;
    int r;
    HWND hwnd;
    HDC hdc;
    RECT rt;
    COLORREF color_pen;
    COLORREF color_figure;

    Figure() {}
    Figure(int _x, int _y, int _r, COLORREF col_fig, COLORREF col_pen) : center(_x, _y), r(_r), color_figure(col_fig), color_pen(col_pen) {
        hwnd = GetConsoleWindow();
        hdc = GetDC(hwnd);
        GetClientRect(hwnd, &rt);
    }
    class BorderException {
    public:
        std::string message;
        BorderException(std::string message) : message(message) {}
        virtual std::string getMessage() const {
            return message;
        }
    };
    class NegativeNumber {
    public:
        std::string message;
        NegativeNumber(std::string message) : message(message) {}
        virtual std::string getMessage() const {
            return message;
        }
    };

    virtual void draw() const = 0;
    virtual void hide() const = 0;
    virtual void move(int dx, int dy) {}

};
