#ifndef INC_3DTERMINAL_GRAPHICS_H
#define INC_3DTERMINAL_GRAPHICS_H

#include <string>
#include "Vec3.h"

class Graphics {

public :

    Graphics();
    ~Graphics();

    /* Draws pixel at (x, y), 'shade' is brightness of pixel, 0 to 1. */
    void drawPixel(int x, int y, float shade) const;

    /* Draws line between given coordinates. */
    void drawLine(int startx, int starty, int endx, int endy, float shade) const;

    /* Draws line between two 3d vectors. */
    void drawLine(Vec3f start, Vec3f end, float shade) const;

    void drawString(std::string& msg, int x, int y) const;

    int getScreenWidth() { return screenWidth; };
    int getScreenHeight() { return screenHeight; };

    /* methods for controlling ncurses drawing mechanism,
     * MUST call refresh to flush chars to screen */
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
