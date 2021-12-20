
#include <iostream>
#include <string.h> // C library

template<typename T>

T* find(T* start, T* finish, const T& v) {
    while (start != finish && *start != v)
        ++start;
    return start;
}

template<typename T>
T min(T g, T d) {
    return ((g<d)?g:d);
}

// there must be a template for which this
// template is a special case
template<>
char* min<char*>(char*g, char*d) {
    if (strcmp(g, d) < 0) return g;
    else return d;
}

int main()
{
    int v[10] = {1, 4, 7, 9, 14, 36, 42, 51, 56, 65};

    int *p = find (v, v+5, 7);
    if (p != v+5)
        std::cout << "It was found." << std::endl;
    else
        std::cout << "We didn't find it." << std::endl;

    int *q = find (v, v+7, 56);
    if (q != v+7)
        std::cout << "It was found." << std::endl;
    else
        std::cout << "We didn't find it." << std::endl;

    int x = 5, y = 7;
    double a = 4.2, b = 6.8;
    char c[] = "bonjour", d[] = "salut";

    int z = min(x, y);
    double w = min(a, b);

     // does not work without the static_cast;
    // all T types must match the same type.
    int u = min(static_cast<int>(a), y);

    // calls the second function template min;
    // a call to the first function would return
    // the char* array with the smallest address
    char* s = min(c, d);

    std::cout << "z = " << z << std::endl;
    std::cout << "w = " << w << std::endl;
    std::cout << "u = " << u << std::endl;
    std::cout << "s = " << s << std::endl;


    /*----------------- results ----------------------*\
    It was found.
    We didn't find it.
    z = 5
    w = 4.2
    u = 4
    s = bonjour
    \*-------------------------------------------------*/

}

