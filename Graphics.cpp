#include "Graphics.h"

#include <ncurses.h>
#include <cassert>

Graphics::Graphics() {

    // Initialise ncurses nicely
    initscr();
    noecho();
    cbreak();
    timeout(-1);
    curs_set(0);

    screenWidth = getmaxx(stdscr) - 1;
    screenHeight = getmaxy(stdscr) - 1;

    // Array of chars used as grey levels in decreasing 'density' / increasing brightness
    characters = "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\\|()1{}[]?-_+~<>i!lI;:,\"^`'. ";

    numChars = 0;
    while (characters[++numChars] != ' '); // Assume whitespace ends list
}

Graphics::~Graphics() { endwin(); }

char Graphics::getCharFromShade(const float shade) const {

    assert(shade >= 0 && shade <= 1);
    return characters[int(numChars * shade + 0.5)];

}

void Graphics::drawPixel(int x, int y, float shade) const {

    //assert(x <= screenWidth || x > 0);
    //assert(y <= screenHeight || y > 0);
    //mvaddch(y, x, getCharFromShade(shade));
    mvaddch(y, x, '*');

}

/* Convenience method for drawing line between x and y coords of 2 3d vectors */
void Graphics::drawLine(const Vec3f start, const Vec3f end, const float shade) const {
    drawLine((int)start.x, (int)start.y, (int)end.x, (int)end.y, shade);
}

/* Draws line between two 2d points using 'Bresenham's line algorithm'. */
void Graphics::drawLine(int startx, int starty, const int endx, const int endy, const float shade) const {

    const int dx = endx - startx;
    const int dy = endy - starty;

    if (abs(dy) < abs(dx)) {

        int sx = (dx < 0) ? -1 : 1;

        float slope = dy / (float)dx;
        float pitch = starty - slope * startx;

        while (startx != endx) {
            drawPixel(startx, (int) lround(slope*startx + pitch), shade);
            startx += sx;
        }

    } else {

        int sy = (dy < 0) ? -1 : 1;

        float slope = dx / (float)dy;
        float pitch = startx - slope * starty;

        while (starty != endy) {
            drawPixel((int) lround(slope*starty + pitch), starty, shade);
            starty += sy;
        }
    }

    drawPixel(endx, endy, shade);
}


void Graphics::drawString(const std::string msg, const int x, const int y) const {
    move(y, x);
    printw(msg.c_str());
}

// ncurses uses a conceptual frame buffer for output, which is only flushed to the screen on __NCURSES_H::refresh()
void Graphics::refresh() const {
    __NCURSES_H::refresh();
    clear();
}

void Graphics::clear() const {
    erase();
}

void Graphics::wait() const {
    __NCURSES_H::getch();
}
