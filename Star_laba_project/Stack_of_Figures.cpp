#include "Stack_of_Figures.h"

void FStack::push(Figure* f) {
    stack_of_figures.push(f);
}

void FStack::show() {
    while (!stack_of_figures.empty()) {
        stack_of_figures.top()->draw();
        stack_of_figures.pop();
    }
}

void FStack::clear() {
    while (!stack_of_figures.empty())
        stack_of_figures.pop();
}
