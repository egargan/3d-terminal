
#ifndef INC_3DTERMINAL_MAT3_H
#define INC_3DTERMINAL_MAT3_H

#include <cmath>
#include "Vec3.h"

/**
 * Templated 3-dimensional matrix structure.
 *
 * Overrides most arithmetic operations between matrices, and other types, e.g. vectors and scalars.
 * Also statically provides basic transformation matrices.
 *
 * @tparam T type of values held by matrix.
 */
template <typename T>
struct Mat3 {

    T vals[3][3];

    /** Self by scalar multiplication. */
    Mat3& operator*=(T const& rhs) {

        for (int i(0); i<3; i++)
            for (int j(0); j<3; j++)
                vals[i][j] *= rhs;

        return *this;
    }

    /** Self by matrix multiplication. */
    Mat3& operator*=(Mat3<T> const& rhs) {

        Mat3<T> product = Mat3<T>();

        for (int i(0); i < 3; i++)
            for (int j(0); j < 3; j++)
                for (int k(0); k < 3; k++)
                    product.vals[j][k] += (vals[j][i] * rhs.vals[i][k]);

        return (*this = std::move(product));
    }

    /** Matrix by matrix multiplication. */
    friend Mat3<T> operator*(Mat3<T> const& lhs, Mat3<T> const& rhs) {

        // 'friend' separates method from class to allow any two matrices to be multiplied together regardless of order.
        // i.e. allows 'commutativity' of mat. by mat. multiplication.

        return (Mat3<T>(lhs) *= rhs);
    }

    /** Matrix by vector multiplication. */
    friend Vec3<T> operator*(Mat3<T> const& lhs, Vec3<T> const& rhs) {

        return {
                rhs.x * lhs.vals[0][0] + rhs.y * lhs.vals[1][0] + rhs.z * lhs.vals[2][0],
                rhs.x * lhs.vals[0][1] + rhs.y * lhs.vals[1][1] + rhs.z * lhs.vals[2][1],
                rhs.x * lhs.vals[0][2] + rhs.y * lhs.vals[1][2] + rhs.z * lhs.vals[2][2],
        };
    }

    /** Vector by matrix multiplication. */
    friend Vec3<T> operator*(Vec3<T> const& rhs, Mat3<T> const& lhs) {

        return lhs * rhs;
    }

    /** Vector's self by matrix multiplication. */
    friend Vec3<T>& operator*=(Vec3<T>& lhs, Mat3<T> const& rhs) {

        return lhs = rhs * lhs;
    }


    /** Returns scaling transformation matrix.
     *
     * @param sfactor Scale factor of transformation. */
    static Mat3<T> Scaling(T sfactor) {

        return {
                sfactor, (T)0, (T)0,
                (T)0, sfactor, (T)0,
                (T)0, (T)0, sfactor
        };
    }

    /** Returns transformation matrix for rotation about X axis.
     *
     * @param theta Angle of rotation in radians. */
    static Mat3<T> RotationX(T theta) {

        const T sineTheta = sin(theta);
        const T cosTheta = cos(theta);

        return {
                (T)1.0,  (T)0.0,       (T)0,
                (T)0,  cosTheta,   -sineTheta,
                (T)0,  sineTheta,  cosTheta
        };
    }

    /** Returns transformation matrix for rotation about Y axis.
     *
     * @param theta Angle of rotation in radians. */
    static Mat3<T> RotationY(T theta) {

        const T sineTheta = sin(theta);
        const T cosTheta = cos(theta);

        return {
                cosTheta,  (T)0,   sineTheta,
                (T)0,      (T)1,   (T)0,
                -sineTheta, (T)0,   cosTheta
        };
    }

    /** Returns transformation matrix for rotation about Z axis.
     *
     * @param theta Angle of rotation in radians. */
    static Mat3<T> RotationZ(T theta) {

        const T sineTheta = sin(theta);
        const T cosTheta = cos(theta);

        return {
                cosTheta,  -sineTheta, (T)0,
                sineTheta, cosTheta,   (T)0,
                (T)0,      (T)0,       (T)1
        };
    }

};

typedef Mat3<float> Mat3f;

#endif //INC_3DTERMINAL_MAT3_H
