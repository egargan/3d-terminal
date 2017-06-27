#include "Graphics.h"

#include <ncurses.h>
#include <cassert>

Graphics::Graphics() {

    initscr();

    screenWidth = getmaxx(stdscr);
    screenHeight = getmaxy(stdscr);

    // Array of chars used as grey levels in decreasing 'density' / increasing brightness
    characters = "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\\|()1{}[]?-_+~<>i!lI;:,\"^`'. ";

    numChars = 0;
    while (characters[++numChars] != ' '); // Assume whitespace ends list
}

Graphics::~Graphics() {

    endwin();

}

char Graphics::getCharFromShade(float shade) {

    assert(shade >= 0 && shade <= 1);

    return characters[int(numChars * shade + 0.5)];
}

void Graphics::drawPixel(int x, int y, float shade) {

    ungetch(0);
    // Push char into input buffer to stop 'getch' blocking
    // Works for now but probably smells bad.

    assert(x <= screenWidth);
    assert(y <= screenHeight);

    mvaddch(y, x, getCharFromShade(shade));

    getch();
}

void Graphics::drawLine(int startx, int starty, int endx, int endy, float shade) {

    int dx = endx - startx;
    int sx = (dx < 0) ? -1 : 1;

    int dy = endy - starty;
    int sy = (dy < 0) ? -1 : 1;

    float slope = 0, pitch = 0;

    if (abs(dy) < abs(dx)) {

        slope = dy / (float)dx;
        pitch = starty - slope * startx;

        while (startx != endx) {
            drawPixel(startx, (int)(slope*startx + pitch + 0.5), shade);
            startx += sx;
        }
    } else {

        slope = dx / (float)dy;
        pitch = startx - slope * starty;

        while (starty != endy) {
            drawPixel((int)(slope*starty + pitch + 0.5), starty, shade);
            starty += sy;
        }
    }

    drawPixel(endx, endy, shade);

    getch();

}

