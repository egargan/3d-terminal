
#ifndef INC_3DTERMINAL_WORLD_H
#define INC_3DTERMINAL_WORLD_H

#include <vector>

#include "model.h"
#include "graphics.h"
#include "world_screen_transformer.h"

// Represents the space in which models / objects exist
class World {

 public:

  World(Graphics);
  ~World();

  void AddObject(Model &);

  void RenderObjects();

 private:

  Graphics graphics_;
  std::vector<Model *> objects_;

  // Object that handles projection of 3D objects to 2D space
  WorldScreenTransformer ws_transformer_;

};

#endif //INC_3DTERMINAL_WORLD_H
