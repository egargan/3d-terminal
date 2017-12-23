
#ifndef INC_3DTERMINAL_MAT3_H
#define INC_3DTERMINAL_MAT3_H

#include <cmath>
#include "Vec3.h"

template <typename T>
struct Mat3 {

    T vals[3][3];

    // Scalar multiplication
    Mat3& operator*=(T const& rhs) {
        for (int i(0); i<3; i++)
            for (int j(0); j<3; j++)
                vals[i][j] *= rhs;
        return *this;
    }

    // Self by matrix mult.
    Mat3& operator*=(Mat3<T> const& rhs) {

        Mat3<T> product = Mat3<T>();

        for (int i(0); i < 3; i++)
            for (int j(0); j < 3; j++)
                for (int k(0); k < 3; k++)
                    product.vals[j][k] += (vals[j][i] * rhs.vals[i][k]);

        return (*this = std::move(product));
    }

    // Matrix by matrix mult.
    friend Mat3<T> operator*(Mat3<T> const& lhs, Mat3<T> const& rhs) {
        return (Mat3<T>(lhs) *= rhs);
    }

    // Matrix by vector mult.
    friend Vec3<T> operator*(Mat3<T> const& lhs, Vec3<T> const& rhs) {
        return {
                rhs.x * lhs.vals[0][0] + rhs.y * lhs.vals[1][0] + rhs.z * lhs.vals[2][0],
                rhs.x * lhs.vals[0][1] + rhs.y * lhs.vals[1][1] + rhs.z * lhs.vals[2][1],
                rhs.x * lhs.vals[0][2] + rhs.y * lhs.vals[1][2] + rhs.z * lhs.vals[2][2],
        };
    }

    // Vector by matrix mult. ('*' will be commutative)
    friend Vec3<T> operator*(Vec3<T> const& rhs, Mat3<T> const& lhs) {
        return lhs * rhs;
    }

    // Vector's self by matrix mult.
    friend Vec3<T>& operator*=(Vec3<T>& lhs, Mat3<T> const& rhs) {
        return lhs = rhs * lhs;
    }


    static Mat3<T> Scaling(T sfactor) {
        return {
                sfactor, (T)0, (T)0,
                (T)0, sfactor, (T)0,
                (T)0, (T)0, sfactor
        };
    }

    static Mat3<T> RotationX(T theta) {

        const T sineTheta = sin(theta);
        const T cosTheta = cos(theta);

        return {
                (T)1.0,  (T)0.0,       (T)0,
                (T)0,  cosTheta,   -sineTheta,
                (T)0,  sineTheta,  cosTheta
        };
    }

    static Mat3<T> RotationY(T theta) {

        const T sineTheta = sin(theta);
        const T cosTheta = cos(theta);

        return {
                cosTheta,  (T)0,   sineTheta,
                (T)0,      (T)1,   (T)0,
                -sineTheta, (T)0,   cosTheta
        };
    }

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
