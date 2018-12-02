
#ifndef INC_3DTERMINAL_VEC3_H
#define INC_3DTERMINAL_VEC3_H

#include <vector>
#include <cmath>
#include <cassert>
#include <string>

/**
 * Templated 3-length vector class.
 * Overrides most arithmetic operations between vectors and other types.
 *
 * @tparam T Type of values contained by vector.
 */
template <typename T>
struct Vec3 {

    T x, y, z;

    /** Self plus vector addition. */
    Vec3& operator+=(Vec3<T> const& rhs) {
        x += rhs.x;
        y += rhs.y;
        z += rhs.z;
        return *this;
    }

    /** Self by vector subtraction. */
    Vec3& operator-=(Vec3<T> const& rhs) {
        x -= rhs.x;
        y -= rhs.y;
        z -= rhs.z;
        return *this;
    }

    /** Self by vector multiplication. */
    Vec3& operator*=(T const& rhs) {
        x *= rhs;
        y *= rhs;
        z *= rhs;
        return *this;
    }

    /** Self by vector division. */
    Vec3& operator/=(T const& rhs) {
        x /= rhs;
        y /= rhs;
        z /= rhs;
        return *this;
    }

    /** Vector by vector subtraction. */
    friend Vec3<T> operator-(Vec3<T> const& lhs, Vec3<T> const& rhs) {
        return (Vec3<T>(lhs) -= rhs);
    }

    /** Vector by vector addition. */
    friend Vec3<T> operator+(Vec3<T> const& lhs, Vec3<T> const& rhs) {
        return (Vec3<T>(lhs) += rhs);
    }

    /** Vector by vector multiplication. */
    friend Vec3<T> operator*(Vec3<T> const& lhs, T const& rhs) {
        return (Vec3<T>(lhs) *= rhs);
    }

    /** Vector by vector division. */
    friend Vec3<T> operator/(Vec3<T> const& lhs, T const& rhs) {
        return (Vec3<T>(lhs) /= rhs);
    }

    /** Vector values gettable using the [] operator. */
    T& operator[](int i) {
        assert(i < 3 && i >= 0);
        switch (i) {
            case 0 : return x;
            case 1 : return y;
            case 2 : return z;
            default : return (T)0;
        }
    }

    T operator[](int i) const {
        assert(i < 3 && i >= 0);
        switch (i) {
            case 0 : return x;
            case 1 : return y;
            case 2 : return z;
            default : return (T)0;
        }
    }

    /** Returns magnitude of vector. */
    T magnitude() {
        return sqrt(x^2 + y^2 + z^2);
    }

    /** Prints each of a vector's values. */
    std::string tostring() {

        std::string str;
        str.append(x + ", " + y + ", " + z);
        return std::move(str);
    }

};

typedef Vec3<float> Vec3f;

#endif //INC_3DTERMINAL_VEC3_H
