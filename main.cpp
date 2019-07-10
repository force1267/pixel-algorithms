#include "headers/dcontext2d.h"
#include "headers/shape.h"

int main() {
    DContext2d ctx(500, 500);
    ctx.draw(new Circle(250, 250, 250));
    ctx.draw(new Triangle(250, 0, 50, 400, 450, 400));
    ctx.draw(new Triangle(150, 200, 350, 200, 250, 400));
    ctx.draw(new Square(120, 260, 60, 90));
    ctx.draw(new Square(380, 260, 440, 90));
    ctx.done();
    ctx.wait(); // wait for keydown
}