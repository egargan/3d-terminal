#ifndef INC_3DTERMINAL_GRAPHICS_H
#define INC_3DTERMINAL_GRAPHICS_H

#include <vector>
#include "Vec3.h"

class Graphics {

public :

    Graphics();
    ~Graphics();

    /* Draws pixel at (x, y), 'shade' is brightness of pixel, 0 to 1. */
    void drawPixel(int x, int y, float shade);

    /* Draws line between given coordinates. */
    void drawLine(int startx, int starty, int endx, int endy, float shade);

    /* Draws line between two 3d vectors. */
    void drawLine(Vec3f start, Vec3f end, float shade);

    /* Draws polygon between given coordinates. */
    void drawPolygon(std::vector<int> xpts, std::vector<int> ypts, float shade, bool fill);

    int getScreenWidth() { return screenWidth; };
    int getScreenHeight() { return screenHeight; };

    void wait() const;

private :

    int screenWidth;
    int screenHeight;

    const char* characters;
    int numChars;

    char getCharFromShade(float shade);

};


#endif //INC_3DTERMINAL_GRAPHICS_H
