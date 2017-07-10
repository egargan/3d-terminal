
#include "Mat3.h"

template <typename T>
Mat3<T>::Mat3(T defval) {

    for (int i(0); i<3; i++)
        for (int j(0); j<3; j++)
            vals[i][j] = defval;

}

template <typename T>
Mat3::Mat3() : Mat3(T()) {};

template <typename T>
Mat3<T>::Mat3(std::initializer_list<T> args) {

    int count(0);

    for (T arg : args) {
        vals[count/3][count%3] = arg;
        count++;
    }
}