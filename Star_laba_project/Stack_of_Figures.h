#pragma once
#include"Figure.h"
#include <stack>
#include <initializer_list>
#include <list>

class FStack {
private:
    stack<Figure*, list <Figure*> > stack_of_figures;

public:
    FStack() {}
    FStack(initializer_list<Figure*> s) {
        for (Figure* x : s) {
            stack_of_figures.push(x);
        }
    }
    void push(Figure* f) ;
    void show();
    void clear();
};