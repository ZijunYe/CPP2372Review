
#include <iostream>
#include <fstream>
#include<iterator>
#include<string>
#include <list>

class Point2D {
 public:
    int x, y;

    Point2D(int x, int y): x(x), y(y) { }
    bool operator<(const Point2D &pt) const {
        if (x == pt.x)
            return y < pt.y;
        else
            return x < pt.x;
    }
};

    inline std::ostream&
operator<<(std::ostream &left, const Point2D &pt) { 

    left << "(" << pt.x << "," << pt.y << ")";
    return left;
}

bool compare(const Point2D &p1, const Point2D &p2) {
    if (p1.y == p2.y)
        return p1.x < p2.x;
    else
        return p1.y < p2.y;
}

bool compareAbs(int a, int b) {
 return abs(a) < abs(b);
}

int main()
{
   std::list<int> liste;

   // Insert an element at the end
   liste.push_back(0);
   liste.push_back(5);
   liste.push_back(6);

   // Insert an element at the beginning
   liste.push_front(1);

   for(auto i=liste.begin(); i != liste.end(); ++i) std::cout << *i << " ";
   std::cout << std::endl;

   liste.insert(++liste.begin(),2);

   for(auto i=liste.begin(); i != liste.end(); ++i) std::cout << *i << " ";
   std::cout << std::endl;

   std::list<Point2D> lpt;
   lpt.push_back(Point2D(3,8));
   lpt.push_back(Point2D(6,9));
   lpt.push_back(Point2D(4,2));
   lpt.push_back(Point2D(6,7));
   
   lpt.sort();
   for(auto i=lpt.begin(); i != lpt.end(); ++i) std::cout << *i << " ";
   std::cout << std::endl;
   
   lpt.sort(compare);
   for(auto i=lpt.begin(); i != lpt.end(); ++i) std::cout << *i << " ";
   std::cout << std::endl;
   
   liste.push_back(-8);
   liste.push_back(-1);
   liste.push_back(-5);
   liste.push_back(-3);
   
   liste.sort(compareAbs);
   for(auto i=liste.begin(); i != liste.end(); ++i) std::cout << *i << " ";
   std::cout << std::endl;
   
   std::ifstream is("2-firstname.txt");
   std::istream_iterator<std::string> ii(is);
   std::istream_iterator<std::string> eof;
   std::list<std::string> names(ii, eof);
    // all words are sorted in alphabetical order
   names.sort();

   std::ostream_iterator<std::string> oo(std::cout, ";\n");
   std::copy(names.begin(), names.end(), oo);

   return 0;
}

 /*------------------ results ------------------------*\
    1 0 5 6 
    1 2 0 5 6 
    (3,8) (4,2) (6,7) (6,9) 
    (4,2) (6,7) (3,8) (6,9) 
    0 1 -1 2 -3 5 -5 6 -8 
    ALICE;
    BEATRICE;
    CHARLIE;
    CHARLOTTE;
    EDOUARD;
    EMMA;
    FELIX;
    FLORENCE;
    LEA;
    LEO;
    LIAM;
    LIVIA;
    LOGAN;
    NATHAN;
    NOAH;
    OLIVIA;
    RAPHAEL;
    ROSALIE;
    THOMAS;
    WILLIAM;
 \*----------------------------------------------------*/


