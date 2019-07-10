#pragma once

// #include <stdlib.h>
#include <SDL2/SDL.h>

// #include "shape.h" // context2d uses this shapes

class DContext2d;
class Shape {
public:
    virtual void draw(DContext2d*) = 0;
private:
};

class DContext2d {
public:
    DContext2d(int W, int H);
    ~DContext2d();
    void draw(Shape*);
    void color(int, int, int);
    void done();
    void pixel(int, int);
    void clear();
    void wait();
    const int W, H;
private:
    int r, g, b;
    SDL_Renderer *renderer;
    SDL_Window *window;
};