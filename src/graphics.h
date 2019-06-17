
#ifndef INC_3DTERMINAL_GRAPHICS_H
#define INC_3DTERMINAL_GRAPHICS_H

#include <string>

#include "vec3.h"

// Provides 2D drawing mechanisms that output characters to the terminal.
// Current implementation expects no colour output in implementation, only shade, or 'lightness'.
class Graphics {

 public :

  Graphics();
  ~Graphics();

  // Draws pixel at (x, y), 'shade' is brightness of pixel, 0 to 1
  void DrawPixel(int x, int y, float shade) const;

  // Draws line between given coordinates
  void DrawLine(int startx, int starty, int endx, int endy, float shade) const;

  // Draws line between two 3d vectors, i.e. using only their x and y coordinates
  void DrawLine(Vec3f start, Vec3f end, float shade) const;

  // Draws string at given coordinates
  void DrawString(std::string msg, int x, int y) const;

  int GetScreenWidth() { return screen_width_; };
  int GetScreenHeight() { return screen_height_; };

  // Control methods for graphics implementation
  void Clear() const;
  void Refresh() const;
  void Wait() const;

 private :

  int screen_width_;
  int screen_height_;

  const char *characters_;
  int num_chars_;

  char GetCharFromShade(float shade) const;

};

#endif //INC_3DTERMINAL_GRAPHICS_H
