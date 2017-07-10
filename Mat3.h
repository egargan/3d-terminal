
#ifndef INC_3DTERMINAL_MAT3_H
#define INC_3DTERMINAL_MAT3_H

#include <initializer_list>

template <typename T>
struct Mat3 {

    T vals[3][3];

    Mat3();
    Mat3(T);
    Mat3(std::initializer_list<T> vals);

    Mat3<T>& operator*=(T const& rhs) {
        for (int i(0); i<3; i++)
            for (int j(0); j<3; j++)
                vals[i][j] *= rhs;
        return *this;
    }

    Mat3<T>& operator*=(Mat3<T> const& rhs) {
        for (int i(0); i < 3; i++)
            for (int j(0); j < 3; j++)
                vals[i][j] *= rhs.vals[j][i];
        return *this;
    }

    friend Mat3<T> operator*(Mat3<T> const& lhs, Mat3<T> const& rhs) {
        return (Mat3<T>(lhs) *= rhs);
    }

};




#endif //INC_3DTERMINAL_MAT3_H
