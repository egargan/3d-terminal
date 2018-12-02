#ifndef INC_3DTERMINAL_GRAPHICS_H
#define INC_3DTERMINAL_GRAPHICS_H

#include <string>
#include "Vec3.h"

/**
 * Graphics class header file.
 *
 * Provides 2D drawing mechanisms that output characters to the terminal.
 * Current implementation expects no colour output in implementation, only shade, or 'lightness'.
 * */
class Graphics {

public :

    Graphics();
    ~Graphics();

    /** Draws pixel at (x, y), 'shade' is brightness of pixel, 0 to 1. */
    void drawPixel(int x, int y, float shade) const;

    /** Draws line between given coordinates. */
    void drawLine(int startx, int starty, int endx, int endy, float shade) const;

    /** Draws line between two 3d vectors, i.e. using only their x and y coordinates. */
    void drawLine(Vec3f start, Vec3f end, float shade) const;

    /** Draws string at given coordinates. */
    void drawString(std::string msg, int x, int y) const;

    int getScreenWidth() { return screenWidth; };
    int getScreenHeight() { return screenHeight; };

    /** Control methods for graphics implementation. */
    void clear() const;
    void refresh() const;
    void wait() const;

private :

    int screenWidth;
    int screenHeight;

    const char* characters;
    int numChars;

    char getCharFromShade(float shade) const;

};


#endif //INC_3DTERMINAL_GRAPHICS_H
