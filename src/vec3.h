
#ifndef INC_3DTERMINAL_VEC3_H
#define INC_3DTERMINAL_VEC3_H

#include <vector>
#include <cmath>
#include <cassert>
#include <string>

// Templated 3-length vector class.
// Overrides most arithmetic operations between vectors and other types.
template<typename T>
struct Vec3 {

  T x_, y_, z_;

  Vec3 &operator+=(Vec3<T> const &rhs) {
    x_ += rhs.x_;
    y_ += rhs.y_;
    z_ += rhs.z_;
    return *this;
  }

  Vec3 &operator-=(Vec3<T> const &rhs) {
    x_ -= rhs.x_;
    y_ -= rhs.y_;
    z_ -= rhs.z_;
    return *this;
  }

  Vec3 &operator*=(T const &rhs) {
    x_ *= rhs;
    y_ *= rhs;
    z_ *= rhs;
    return *this;
  }

  Vec3 &operator/=(T const &rhs) {
    x_ /= rhs;
    y_ /= rhs;
    z_ /= rhs;
    return *this;
  }

  friend Vec3<T> operator-(Vec3<T> const &lhs, Vec3<T> const &rhs) {
    return (Vec3<T>(lhs) -= rhs);
  }

  friend Vec3<T> operator+(Vec3<T> const &lhs, Vec3<T> const &rhs) {
    return (Vec3<T>(lhs) += rhs);
  }

  friend Vec3<T> operator*(Vec3<T> const &lhs, T const &rhs) {
    return (Vec3<T>(lhs) *= rhs);
  }

  friend Vec3<T> operator/(Vec3<T> const &lhs, T const &rhs) {
    return (Vec3<T>(lhs) /= rhs);
  }

  // Vector values gettable using the [] operator
  T &operator[](int i) {
    assert(i < 3 && i >= 0);
    switch (i) {
      case 0 : return x_;
      case 1 : return y_;
      case 2 : return z_;
      default : return (T) 0;
    }
  }

  T operator[](int i) const {
    assert(i < 3 && i >= 0);
    switch (i) {
      case 0 : return x_;
      case 1 : return y_;
      case 2 : return z_;
      default : return (T) 0;
    }
  }

  T Magnitude() {
    return sqrt(x_ ^ 2 + y_ ^ 2 + z_ ^ 2);
  }

  std::string ToString() {
    std::string str;
    str.append(x_ + ", " + y_ + ", " + z_);
    return std::move(str);
  }

};

typedef Vec3<float> Vec3f;

#endif //INC_3DTERMINAL_VEC3_H