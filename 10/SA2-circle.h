
#ifndef CIRCLE_H
#define CIRCLE_H

#define PI 3.1415926535897932384626433832795

#include "SA2-shape.h"

#include <iostream>
#include <math.h>

using namespace std;

class Circle: public Shape {
    double radius;

public:
    Circle(double x, double y, double radius):
            Shape(x, y), radius(radius) { }

    Circle(double radius): Shape(), radius(radius) { }

    Circle(const Circle &c) {
        setAnchor(c.getAnchor()), radius = c.radius;
    }

    double getPerimetre() const {
        return 2*PI*radius;
    }

    double getArea() const {
        return PI*pow(radius, 2);
    }

    double getRadius() const {
        return radius;
    }

    void setRadius(double radius) {
        this->radius = radius;
    }

    virtual void getLimites(Point2D &p1, Point2D &p2) {
        p1.setX(getAnchor().getX() - radius);
        p1.setY(getAnchor().getY() - radius);
        p2.setX(getAnchor().getX() + radius);
        p2.setY(getAnchor().getY() + radius);
    }


  virtual  string toString() override { // overriding
        std::stringstream ss;
        ss << "Circle (" << radius << ")";
        return ss.str() + Shape::toString();
    }

};

#endif // CIRCLE_H