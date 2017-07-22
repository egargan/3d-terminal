
#ifndef INC_3DTERMINAL_WORLDSCREENTRANSFORMER_H
#define INC_3DTERMINAL_WORLDSCREENTRANSFORMER_H

#include "Graphics.h"
#include "Vec3.h"


class WorldScreenTransformer {

    float widthScaler;
    float heightScaler;

public:

    WorldScreenTransformer(Graphics gfx) : widthScaler{gfx.getScreenWidth() / 2.0f},
                                           heightScaler{gfx.getScreenHeight() / 2.0f} {};

    Vec3f& TransformVec(Vec3f& vector) const {
        vector.x = (vector.x + 1.0f) * widthScaler;
        vector.y = (vector.y + 1.0f) * heightScaler;
        return vector;
    }

    Vec3f getTransformedVec(const Vec3f& vector) const {
        return Vec3f{(vector.x + 1.0f) * widthScaler,
                     (-vector.y + 1.0f) * heightScaler,
                     0.0f};
    }

};

#endif //INC_3DTERMINAL_WORLDSCREENTRANSFORMER_H
