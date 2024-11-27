#include <iostream>
#include "Figure.h"
#include "Circle.h"
#include "Star.h"
#include "Compoud_Figure.h"
#include "Stack_of_Figures.h"

using namespace std;

const int NotUsed = system("color F0");

int main() {
    SetConsoleTitle((LPCWSTR)L"23VP2_28");
    setlocale(LC_ALL, "Russian");
    COORD p = { 1, 1 };

    COLORREF color_sky = RGB(100, 200, 255);
    COLORREF color_dark_sky = RGB(50, 100, 125);
    COLORREF color_yellow = RGB(250, 250, 100);
    COLORREF color_dark_yellow = RGB(175, 175, 100);
    COLORREF color_pink = RGB(255, 200, 225);
    COLORREF color_dark_pink = RGB(175, 100, 100);

    try {
        FStack stack_figures{ reinterpret_cast<Figure*>(new Circle(90, 90, 80, color_sky, color_dark_sky)),reinterpret_cast<Figure*>(new Star(200, 300, 80, 139, color_yellow, color_dark_yellow)),reinterpret_cast<Figure*>(new Compound_Figure(600, 300, 80, 139, color_pink, color_dark_pink, color_yellow, color_dark_yellow)) };
        stack_figures.show();
    }
 
    catch (const Figure::BorderException& ex) {
        cout << ex.getMessage() << endl;
        
    }
    catch (const Figure::NegativeNumber& ex) {
        cout << ex.getMessage() << endl; 
        
    }
    catch (const Star::IncorrectRadius& ex) {
        cout << ex.getMessage() << endl;
        
    }


    Sleep(3600);
    p = { 0, 25 };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);

    return 0;
}
