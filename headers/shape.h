#pragma once

#include "dcontext2d.h"



class Line :public Shape {
public:
    Line(int, int, int, int);
    virtual void draw(DContext2d*) override;
private:
    int x0, y0, x1, y1;
};

class Triangle :public Shape {
public:
    Triangle(int, int, int, int, int, int);
    virtual void draw(DContext2d*) override;
private:
    int x0, y0, x1, y1, x2, y2;
};

class Square :public Shape {
public:
    Square(int, int, int, int);
    virtual void draw(DContext2d*) override;
private:
    int x0, y0, x1, y1;
};

class Circle :public Shape {
public:
    Circle(int, int, int);
    virtual void draw(DContext2d*) override;
private:
    int xc, yc, r;
};

// add more shapes here
// implement `void draw(DContext2d*)`