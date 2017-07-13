
#ifndef INC_3DTERMINAL_MAT3_H
#define INC_3DTERMINAL_MAT3_H

#include "Vec3.h"

template <typename T>
struct Mat3 {

    T vals[3][3];


    Mat3() : Mat3(T()) {};

    Mat3(T defval) {
        for (int i(0); i<3; i++)
            for (int j(0); j<3; j++)
                vals[i][j] = defval;
    };

    Mat3(std::initializer_list<T> args) : Mat3() {

        int count(0);

        for (T arg : args) {
            vals[count / 3][count % 3] = arg;
            count++;
        };
    }

    // Scalar multiplication
    Mat3<T>& operator*=(T const& rhs) {
        for (int i(0); i<3; i++)
            for (int j(0); j<3; j++)
                vals[i][j] *= rhs;
        return *this;
    }

    // Self by matrix mult. (dot product)
    Mat3<T>& operator*=(Mat3<T> const& rhs) {

        Mat3<T> product;

        for (int i(0); i < 3; i++)
            for (int j(0); j < 3; j++)
                for (int k(0); k < 3; k++)
                    product.vals[i][j] += (vals[i][k] * rhs.vals[k][j]);

        return (*this = std::move(product));
    }

    // Matrix by matrix mult.
    friend Mat3<T> operator*(Mat3<T> const& lhs, Mat3<T> const& rhs) {
        return (Mat3<T>(lhs) *= rhs);
    }

    // Matrix by vector mult.
    friend Vec3<T> operator*(Mat3<T> const& lhs, Vec3<T> const& rhs) {
        Vec3<T> product;
        for (int i(0); i < 3; i++)
            for (int j(0); j < 3; j++) {
                product[i] += (lhs.vals[i][j] * rhs[j]);
            }
        return product;
    }

    // Vector by matrix mult. ('*' will be commutative)
    friend Vec3<T> operator*(Vec3<T> const& rhs, Mat3<T> const& lhs) {
        return lhs * rhs;
    }

    static Mat3<T> Scaling(T sfactor) {
        return Mat3<T>{
                {sfactor, (T)0, (T)0},
                {(T)0, sfactor, (T)0},
                {(T)0, (T)0, sfactor}
        };
    }

};

typedef Mat3<float> Mat3f;

#endif //INC_3DTERMINAL_MAT3_H
