
#ifndef INC_3DTERMINAL_WORLDSCREENTRANSFORMER_H
#define INC_3DTERMINAL_WORLDSCREENTRANSFORMER_H

#include "graphics.h"
#include "vec3.h"

// Transforms coordinates from World space (-1.0 to +1.0 in x/y/z; 'NDC'ish space),
// to screen space, 0 to screen width / height. */
class WorldScreenTransformer {

  const float width_scaler_;
  const float height_scaler_;

 public:

  // Constructor accepting graphics context for getting screen dimensions
  explicit WorldScreenTransformer(Graphics gfx) : width_scaler_{gfx.GetScreenWidth() / 2.0f},
                                                  height_scaler_{gfx.GetScreenHeight() / 2.0f} {};

  // Performs 'weak' perspective projection by reference
  Vec3f &TransformVec(Vec3f &vector) const {
    const float inverseZ = 1.0f / vector.z_;
    vector.x_ = (vector.x_ * inverseZ + 1.0f) * width_scaler_;
    vector.y_ = (-vector.y_ * inverseZ + 1.0f) * height_scaler_;
    return vector;
  }

  // Perspective project on a 3D vector by value
  Vec3f GetTransformedVec(const Vec3f &vector) const {
    Vec3f transformed(vector);
    return TransformVec(transformed);
  }

};

#endif //INC_3DTERMINAL_WORLDSCREENTRANSFORMER_H
