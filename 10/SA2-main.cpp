

#include "SA2-rectangle.h"
#include "SA2-triangle.h"
#include "SA2-circle.h"
#include <iostream>
#include <algorithm>
#include <vector>



using namespace std;

void deleteless25(Shape* &f) // input type is reference to a pointer
{
  if ( f->getArea() < 25) {

      cout << f->toString() << " has an area of less than 25."
                                                        << endl;
      delete f;
      f= nullptr;
  }
}

int main()
{
    vector<Shape*> v;
    v.push_back(new Triangle(2, 2, 2));
    v.push_back(new Circle(5,2,5));
    v.push_back(new Circle(3, 3, 7));
    v.push_back(new Rectangle(9, 5));
    v.push_back(new Circle(4, 6, 2));
    v.push_back(new Triangle(5, 4, 3, 5, 6));

    //Deleteless25 deleteless25;
    vector<Shape*>::iterator it = v.begin();

    cout << "The vector contains: " << endl;
    for (it = v.begin(); it != v.end(); it++) {
        cout << (*it)->toString() << endl;
    }
    cout << endl;

    for_each(v.begin(),v.end(), deleteless25);
    v.erase(remove(v.begin(),v.end(),
                            static_cast<Shape *>(0)), v.end() );

    // v.erase( v.begin() + 3 ); // Deleting the fourth element

    cout << endl;
    cout << "The vector now contains: " << endl;
    for (it = v.begin(); it != v.end(); it++) {
        cout << (*it)->toString() << endl;
    }
    cout << endl;
}

  /*--------------------- results -------------------------*\

The vector contains:
Triangle (2x2x2) Anchored to the point (0, 0)
Circle (5) Anchored to the point (5, 2)
Circle (7) Anchored to the point (3, 3)
Rectangle (5x9) Anchored to the point (0, 0)
Circle (2) Anchored to the point (4, 6)
Triangle (3x5x6) Anchored to the point (5, 4)

Triangle (2x2x2) Anchored to the point (0, 0) has an area of less than 25.
Circle (2) Anchored to the point (4, 6) has an area of less than 25.
Triangle (3x5x6) Anchored to the point (5, 4) has an area of less than 25.

The vector now contains:
Circle (5) Anchored to the point (5, 2)
Circle (7) Anchored to the point (3, 3)
Rectangle (5x9) Anchored to the point (0, 0)


 \*-------------------------------------------------------*/


