
#include "2-Clock.h"

const Clock
        operator+(const Clock &left, const Clock &right) {
    return Clock(left) += right;
}

const Clock
        operator-(const Clock &left, const Clock &right) {
    return Clock(left) -= right;
}