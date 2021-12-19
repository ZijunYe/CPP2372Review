
#ifndef TRIANGLE_H // if TRIANGLE_H is not defined
#define TRIANGLE_H // define TRIANGLE_H

#include "SA2-shape.h"
#include <math.h>




class Triangle : public Shape{
private:
    double base, side1, side2;

public:
    Triangle(double x, double y, double base,
             double side1, double side2) :
                Shape(x, y), base(base), side1(side1),
                side2(side2) {  }

    Triangle(double base, double side1, double side2) :
                Shape(), base(base), side1(side1), side2(side2) { }

    Triangle(const Triangle &t) {
        setAnchor(t.getAnchor());
        base = t.base, side1 = t.side1, side2 = t.side2;
    }

    double getBase() const {
        return base;
    }

    void setBase(double base) {
        this->base = base;
    }

    double getSide1() const {
        return side1;
    }

    void setSide1(double side1) {
        this->side1 = side1;
    }

    double getSide2() const {
        return side2;
    }

    void setSide2(double side2) {
        this->side2 = side2;
    }

    double getPerimetre() const {
        return base+ side1+side2;
    }

     // assuming that no triangle has an angle > 90
    double getArea() const {
        double p = getPerimetre();
        double area = 1/4*sqrt(p*(p-2*base)*(p-2*side1)
                                                    *(p-2*side2));
        return area;
    }

    virtual void getLimites(Point2D &p1, Point2D &p2) {
        p1 = getAnchor();
        p2.setX(p1.getX() + base);
        p2.setY(p1.getY() + 2*getArea()/base);
    }

  virtual  string toString() override { // overriding
        std::stringstream ss;
        ss << "Triangle (" << base << "x"
                << side1 << "x" << side2 << ")";
        return ss.str() + Shape::toString();
    }
};

#endif // TRIANGLE_H