
#include "1_Clock.h"

const Clock operator+(const Clock &left, const Clock &right)
{
     // return an anonymous reference
    return Clock(left) += right;
    // declaration of anonymous variable with Clock (left)
}

const Clock operator-(const Clock &left, const Clock &right)
{

    return Clock(left) -= right;
}
