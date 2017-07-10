
#ifndef INC_3DTERMINAL_VEC3_H
#define INC_3DTERMINAL_VEC3_H

#include <vector>
#include <cmath>

template <typename T>
struct Vec3 {

    T x, y, z;

    Vec3();
    Vec3(T,T,T);

    /* Operators */
    Vec3<T>& operator+=(Vec3<T> const& rhs) {
        x += rhs.x;
        y += rhs.y;
        z += rhs.z;
        return *this;
    }
    Vec3<T>& operator-=(Vec3<T> const& rhs) {
        x -= rhs.x;
        y -= rhs.y;
        z -= rhs.z;
        return *this;
    }
    Vec3<T>& operator*=(Vec3<T> const& rhs) {
        x *= rhs.x;
        y *= rhs.y;
        z *= rhs.z;
        return *this;
    }
    Vec3<T>& operator/=(Vec3<T> const& rhs) {
        x /= rhs.x;
        y /= rhs.y;
        z /= rhs.z;
        return *this;
    }

    friend Vec3<T> operator-(Vec3<T> const& lhs, Vec3<T> const& rhs) const {
        return (Vec3<T>(lhs) -= rhs);
    }
    friend Vec3<T> operator+(Vec3<T> const& lhs, Vec3<T> const& rhs) const {
        return (Vec3<T>(lhs) += rhs);
    }
    friend Vec3<T> operator*(Vec3<T> const& lhs, Vec3<T> const& rhs) const {
        return (Vec3<T>(lhs) *= rhs);
    }
    friend Vec3<T> operator/(Vec3<T> const& lhs, Vec3<T> const& rhs) const {
        return (Vec3<T>(lhs) /= rhs);
    }

    T magnitude() { return sqrt(x^2 + y^2 + z^2); }

};

typedef Vec3<float> Vec3f;

#endif //INC_3DTERMINAL_VEC3_H
