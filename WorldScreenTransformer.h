
#ifndef INC_3DTERMINAL_WORLDSCREENTRANSFORMER_H
#define INC_3DTERMINAL_WORLDSCREENTRANSFORMER_H

#include "Graphics.h"
#include "Vec3.h"

/* Transforms coordinates from World space (-1.0 to +1.0 in x/y, 0.0 to 1.0 in z; mimics 'NDC' space),
 * to Screen space, 0 to screen width / height. */
class WorldScreenTransformer {

    float widthScaler;
    float heightScaler;

public:

    explicit WorldScreenTransformer(Graphics gfx) : widthScaler{gfx.getScreenWidth() / 2.0f},
                                           heightScaler{gfx.getScreenHeight() / 2.0f} {};

    Vec3f& TransformVec(Vec3f& vector) const {
        const float inverseZ = 1.0f / vector.z;
        vector.x = (vector.x * inverseZ + 1.0f) * widthScaler;
        vector.y = (-vector.y * inverseZ + 1.0f) * heightScaler;
        return vector;
    }

    Vec3f getTransformedVec(const Vec3f& vector) const {
        Vec3f transformed(vector);
        return TransformVec(transformed);
    }

};

#endif //INC_3DTERMINAL_WORLDSCREENTRANSFORMER_H
