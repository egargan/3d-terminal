
#include <ncurses.h>

#include "graphics.h"

// Graphics constructor - Initialises ncurses and defines character gamut
Graphics::Graphics() {
  // Initialise ncurses
  initscr();
  noecho();
  cbreak();
  timeout(-1);
  curs_set(0);

  screen_width_ = getmaxx(stdscr) - 1;
  screen_height_ = getmaxy(stdscr) - 1;

  // Array of chars used as grey levels in decreasing 'density' / increasing brightness
  characters_ = "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\\|()1{}[]?-_+~<>i!lI;:,\"^`'. ";

  // Count character array, useful if declared elsewhere
  num_chars_ = 0;
  while (characters_[++num_chars_] != ' '); // Assume whitespace ends list
}

// De-initialises ncurses by calling endwin()
Graphics::~Graphics() {
  endwin();
}

// Returns a character with given 'shade', i.e. 0 returns a high-density character, 1 returns whitespace
char Graphics::GetCharFromShade(const float shade) const {
  assert(shade >= 0 && shade <= 1);
  return characters_[int(num_chars_ * shade + 0.5)];
}

void Graphics::DrawPixel(int x, int y, float shade) const {
  //assert(x <= screen_width || x > 0);
  //assert(y <= screen_height || y > 0);
  //mvaddch(y, x, getCharFromShade(shade));

  // Currently only outputs '*' for demo purposes
  mvaddch(y, x, '*');
}

// Convenience method for drawing line between x and y coords of 2 3D vectors
void Graphics::DrawLine(Vec3f start, Vec3f end, float shade) const {
  DrawLine((int) start.x_, (int) start.y_, (int) end.x_, (int) end.y_, shade);
}

// Draws line between two 2d points using Bresenham's line algorithm
void Graphics::DrawLine(int startx, int starty, int endx, int endy, float shade) const {
  const int dx = endx - startx;
  const int dy = endy - starty;

  if (abs(dy) < abs(dx)) {
    int sx = (dx < 0) ? -1 : 1;

    float slope = dy / (float) dx;
    float pitch = starty - slope * startx;

    while (startx != endx) {
      DrawPixel(startx, (int) lround(slope * startx + pitch), shade);
      startx += sx;
    }
  } else {
    int sy = (dy < 0) ? -1 : 1;

    float slope = dx / (float) dy;
    float pitch = startx - slope * starty;

    while (starty != endy) {
      DrawPixel((int) lround(slope * starty + pitch), starty, shade);
      starty += sy;
    }
  }

  DrawPixel(endx, endy, shade);
}

void Graphics::DrawString(std::string msg, int x, int y) const {
  move(y, x);
  printw(msg.c_str());
}

// ncurses uses a conceptual frame buffer for output, which is only flushed to the screen on __NCURSES_H::refresh()
void Graphics::Refresh() const {
  __NCURSES_H::refresh();
  Clear();
}

void Graphics::Clear() const {
  erase();
}

void Graphics::Wait() const {
  __NCURSES_H::getch();
}
