
#include <iostream>

template <typename X, typename Y>
struct Promotion {
    typedef int Type; // default
};

// an operation with an int and a float
// produces a float
template<>
struct Promotion<int,float> {
    typedef float Type;
};
template<>
struct Promotion<float,int> {
    typedef float Type;
};


template <typename T>
class Mat3x3 {

    T m[3][3];

  public:

    Mat3x3() {
        for (int i=0; i<3; i++)
            for (int j=0; j<3; j++)
                m[i][j]= static_cast<T>(0);
    }

    T get(int i, int j) const { return m[i][j]; }
	
    const T* operator[](int i) const { return m[i];}
	
    T* operator[](int i) { return m[i];}
	
    const Mat3x3 operator+(const Mat3x3 &mat) {
        Mat3x3 result;
        for (int i=0; i<3; i++)
            for (int j=0; j<3; j++)
                result[i][j]= m[i][j]+mat[i][j];
        return result;
    }
	
    /* Solution 1: without mixed operations
    const Mat3x3 operator+(const Mat3x3 &mat) {
        Mat3x3 result;
        for (int i=0; i<3; i++)
            for (int j=0; j<3; j++)
                result[i][j]= m[i][j]+mat[i][j];
        return result;
    }
    */
};

/* Solution 2: define the mixed operands by position
template <typename X, typename Y>
const Mat3x3<X> operator+(const Mat3x3<X> &mat1, const Mat3x3<Y> &mat2) {
    Mat3x3<X> result;
    for (int i=0; i<3; i++)
        for (int j=0; j<3; j++)
            result[i][j]= mat1[i][j]+mat2[i][j];
    return result;
}
*/

// Solution 3: with type promotion
template <typename X, typename Y>
const  Mat3x3<typename Promotion<X,Y>::Type> 
       operator+(const Mat3x3<X> &mat1, const Mat3x3<Y> &mat2) {
    Mat3x3<typename Promotion<X,Y>::Type> result;
    for (int i=0; i<3; i++)
        for (int j=0; j<3; j++)
            result[i][j]= mat1[i][j]+mat2[i][j];
    return result;
}


int main()
{

    Mat3x3<float> matrix;
    Mat3x3<float> mat2;
    Mat3x3<float> mat3;

    std::cout << matrix.get(2,2) << std::endl;
    matrix[2][2]= 3.3;
    mat2[2][2]= 5.7;
    std::cout << matrix[2][2] << std::endl;

    mat3= mat2+matrix;
    std::cout << mat3[2][2] << std::endl;

    Mat3x3<int> matInt;
    matInt[2][2]=7;

    mat3= mat2+matInt;
    std::cout << mat3[2][2] << std::endl;

    mat3= matInt+mat2;
    std::cout << mat3[2][2] << std::endl;

    std::cout << "end" << std::endl;

    return 0;
}

/* Results:

0
3.3
9
12.7
12.7
end

*/
