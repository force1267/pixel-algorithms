#include "../headers/shape.h"
#define abs(n) ((n) >= 0 ? (n) : -(n))
#define swap(a, b, c) c = b; b = a; a = c;

Line::Line(int x0, int y0, int x1, int y1) : x0(x0), y0(y0), x1(x1), y1(y1) {}
void Line::draw(DContext2d *ctx) {

    // Bresenham's line algorithm :

    const bool steep = (abs(y1 - y0) > abs(x1 - x0));
    int c;
    if (steep) {
        swap(x0, y0, c);
        swap(x1, y1, c);
    }

    if (x0 > x1) {
        swap(x0, x1, c);
        swap(y0, y1, c);
    }

    const float dx = x1 - x0;
    const float dy = abs(y1 - y0);

    float error = dx / 2.0f;
    const int ystep = (y0 < y1) ? 1 : -1;
    int y = (int)y0;

    const int maxX = (int)x1;

    for (int x = (int)x0; x < maxX; x++) {
        if (steep) {
            ctx->pixel(y, x);
        } else {
            ctx->pixel(x, y);
        }

        error -= dy;
        if (error < 0) {
            y += ystep;
            error += dx;
        }
    }
}

Triangle::Triangle(int x0, int y0, int x1, int y1, int x2, int y2)
    :x0(x0), y0(y0), x1(x1), y1(y1), x2(x2), y2(y2) {}
void Triangle::draw(DContext2d *ctx) {
    (new Line(x0, y0, x1, y1))->draw(ctx);
    (new Line(x1, y1, x2, y2))->draw(ctx);
    (new Line(x0, y0, x2, y2))->draw(ctx);
}

Square::Square(int x0, int y0, int x1, int y1) :x0(x0), y0(y0), x1(x1), y1(y1) {}
void Square::draw(DContext2d *ctx) {

    // Center point
    int xc = (x0 + x1)/2;
    int yc = (y0 + y1)/2;
    // Half-diagonal
    int xd = (x0 - x1)/2;
    int yd = (y0 - y1)/2;
    
    // Third corner
    int x2 = xc - yd;
    int y2 = yc + xd;
    // Fourth corner
    int x3 = xc + yd;
    int y3 = yc - xd;

    (new Line(x0, y0, x2, y2))->draw(ctx);
    (new Line(x0, y0, x3, y3))->draw(ctx);
    (new Line(x1, y1, x2, y2))->draw(ctx);
    (new Line(x1, y1, x3, y3))->draw(ctx);
}

Circle::Circle(int xc, int yc, int r) : xc(xc), yc(yc), r(r) {}
void Circle::draw(DContext2d *ctx) {
    // circle-generation using Bresenham's algorithm
    int x = 0, y = r;
    int d = 3 - 2 * r;

    // drawCircle(x, y):
    ctx->pixel(xc+x, yc+y);
    ctx->pixel(xc-x, yc+y);
    ctx->pixel(xc+x, yc-y);
    ctx->pixel(xc-x, yc-y);
    ctx->pixel(xc+y, yc+x);
    ctx->pixel(xc-y, yc+x);
    ctx->pixel(xc+y, yc-x);
    ctx->pixel(xc-y, yc-x);

    while (y >= x) {
        // for each pixel we will 
        // draw all eight pixels 
        x++;
        // check for decision parameter 
        // and correspondingly  
        // update d, x, y 
        if (d > 0) {
            y--;
            d = d + 4 * (x - y) + 10;
        } else {
            d = d + 4 * x + 6;
        }
        // drawCircle(x, y):
        ctx->pixel(xc+x, yc+y);
        ctx->pixel(xc-x, yc+y);
        ctx->pixel(xc+x, yc-y);
        ctx->pixel(xc-x, yc-y);
        ctx->pixel(xc+y, yc+x);
        ctx->pixel(xc-y, yc+x);
        ctx->pixel(xc+y, yc-x);
        ctx->pixel(xc-y, yc-x);
    }
}
