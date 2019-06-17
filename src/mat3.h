
#ifndef INC_3DTERMINAL_MAT3_H
#define INC_3DTERMINAL_MAT3_H

#include <cmath>

#include "vec3.h"

// Templated 3-dimensional matrix structure.
// Overrides most arithmetic operations between matrices, and other types, e.g. vectors and scalars.
// Also statically provides basic transformation matrices.
template<typename T>
struct Mat3 {

  T vals_[3][3];

  // Self by scalar multiplication
  Mat3 &operator*=(T const &rhs) {
    for (int i(0); i < 3; i++)
      for (int j(0); j < 3; j++)
        vals_[i][j] *= rhs;

    return *this;
  }

  // Self by matrix multiplication
  Mat3 &operator*=(Mat3<T> const &rhs) {
    Mat3<T> product = Mat3<T>();

    for (int i(0); i < 3; i++)
      for (int j(0); j < 3; j++)
        for (int k(0); k < 3; k++)
          product.vals_[j][k] += (vals_[j][i] * rhs.vals_[i][k]);

    return (*this = std::move(product));
  }

  // Commutative matrix by matrix multiplication
  friend Mat3<T> operator*(Mat3<T> const &lhs, Mat3<T> const &rhs) {
    // 'friend' separates method from class to allow any two matrices to be multiplied together regardless of order.
    // i.e. allows 'commutativity' of mat. by mat. multiplication.
    return (Mat3<T>(lhs) *= rhs);
  }

  // Matrix by vector multiplication
  friend Vec3<T> operator*(Mat3<T> const &lhs, Vec3<T> const &rhs) {
    return {
        rhs.x_ * lhs.vals_[0][0] + rhs.y_ * lhs.vals_[1][0] + rhs.z_ * lhs.vals_[2][0],
        rhs.x_ * lhs.vals_[0][1] + rhs.y_ * lhs.vals_[1][1] + rhs.z_ * lhs.vals_[2][1],
        rhs.x_ * lhs.vals_[0][2] + rhs.y_ * lhs.vals_[1][2] + rhs.z_ * lhs.vals_[2][2],
    };
  }

  // Vector by matrix multiplication
  friend Vec3<T> operator*(Vec3<T> const &rhs, Mat3<T> const &lhs) {
    return lhs * rhs;
  }

  // Vector's self by matrix multiplication
  friend Vec3<T> &operator*=(Vec3<T> &lhs, Mat3<T> const &rhs) {
    return lhs = rhs * lhs;
  }

  // Returns scaling transformation matrix
  static Mat3<T> Scaling(T scale_factor) {
    return {
        scale_factor, (T) 0, (T) 0,
        (T) 0, scale_factor, (T) 0,
        (T) 0, (T) 0, scale_factor
    };
  }

  // Transformation matrix for rotation about X axis
  static Mat3<T> RotationX(T theta_radians) {
    const T sin_theta = sin(theta_radians);
    const T cos_theta = cos(theta_radians);

    return {
        (T) 1.0, (T) 0.0, (T) 0,
        (T) 0, cos_theta, -sin_theta,
        (T) 0, sin_theta, cos_theta
    };
  }

  // Transformation matrix for rotation about Y axis
  static Mat3<T> RotationY(T theta_radians) {
    const T sin_theta = sin(theta_radians);
    const T cos_theta = cos(theta_radians);

    return {
        cos_theta, (T) 0, sin_theta,
        (T) 0, (T) 1, (T) 0,
        -sin_theta, (T) 0, cos_theta
    };
  }

  // Transformation matrix for rotation about Z axis
  static Mat3<T> RotationZ(T theta_radians) {
    const T sin_theta = sin(theta_radians);
    const T cos_theta = cos(theta_radians);

    return {
        cos_theta, -sin_theta, (T) 0,
        sin_theta, cos_theta, (T) 0,
        (T) 0, (T) 0, (T) 1
    };
  }

};

typedef Mat3<float> Mat3f;

#endif //INC_3DTERMINAL_MAT3_H
