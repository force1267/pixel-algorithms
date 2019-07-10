#include "../headers/dcontext2d.h"

DContext2d::DContext2d(int W = 500, int H = 500) :W(W), H(H) {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(W, H, 0, &window, &renderer);
    this->clear();
    this->color(255, 0, 0); // default color = red
}

DContext2d::~DContext2d() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}


void DContext2d::draw(Shape* shape) {
    shape->draw(this);
    delete shape;
}

void DContext2d::color(int r, int g, int b) {
    this->r = r;
    this->g = g;
    this->b = b;
    SDL_SetRenderDrawColor(renderer, r, g, b, 255);
}

void DContext2d::done() {
    SDL_RenderPresent(renderer);
}

void DContext2d::pixel(int x, int y) {
    SDL_RenderDrawPoint(renderer, x, y);
}

void DContext2d::clear() {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0); // background color = white
    SDL_RenderClear(renderer); // clear
    this->color(r, g, b); // reset last color
}

void DContext2d::wait() {
    SDL_Event event;
    while (1) {
        if (SDL_PollEvent(&event) && event.type == SDL_KEYDOWN) // wait till keydown
            break;
    }
}