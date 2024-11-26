
#include "Circle.h"


void Circle::draw() const {
    if ((center.x - r <= rt.left) || (center.x + r >= rt.right) || (center.y - r <= rt.top) || (center.y + r >= rt.bottom))
        throw BorderException{ "Выход за границы окна. Окружность: координаты центра (" + std::to_string(center.x) + ", " + std::to_string(center.y) + "), радиус: " + std::to_string(r) };

    if (r<=0)
        throw NegativeNumber{ "Нулевые или отрицательные значения параметров. Окружность: координаты центра(" + std::to_string(center.x) + ", " + std::to_string(center.y) + "), радиус : " + std::to_string(r) };

    HPEN pen = CreatePen(PS_SOLID, 3, color_pen);
    HBRUSH brush = CreateSolidBrush(color_figure);

    SelectObject(hdc, pen);
    SelectObject(hdc, brush);
    Ellipse(hdc, center.x - r, center.y - r, center.x + r, center.y + r);

    DeleteObject(pen);
    DeleteObject(brush);
    DeletePen(pen);
    DeleteBrush(brush);

}

void Circle::hide() const {
    HPEN pen = CreatePen(PS_SOLID, 3, GetBkColor(hdc));
    HBRUSH brush = CreateSolidBrush(GetBkColor(hdc));

    SelectObject(hdc, pen);
    SelectObject(hdc, brush);
    Ellipse(hdc, center.x - r, center.y - r, center.x + r, center.y + r);

    DeleteObject(pen);
    DeleteObject(brush);
    DeletePen(pen);
    DeleteBrush(brush);
}

void Circle::move(int dx, int dy) {
    hide();
    center.x += dx;
    center.y += dy;
    draw();
}

