
#ifndef SHAPE_H
#define SHAPE_H

#include<sstream>
#include<string>

using namespace std;

class Point2D {
    double x;
    double y;

public:
   Point2D(double x=0, double y=0): x(x), y(y) {}

   void setX(double x) { this->x = x; }

   double getX() const { return x; }

   void setY(double y) { this->y = y; }

   double getY() const { return y; }

};

class Shape { // abstract class
    Point2D p2d;

public:
    Shape(double x=0, double y=0) {
        p2d.setX(x);
        p2d.setY(y);
    }

    void translate(double dx, double dy) {
        p2d.setX(p2d.getX() + dx);
        p2d.setY(p2d.getY() + dy);
    }

    virtual void getLimites(Point2D &p1, Point2D &p2) {
        p1 = p2d;
        p2 = p2d;
    }

     // the next two methods are pure virtual methods
    // pure virtual methods
    virtual double getPerimetre() const = 0;
    virtual double getArea() const = 0;

    Point2D getAnchor() const {
        return p2d;
    }

    void setAnchor(Point2D p1) {
        p2d = p1;
    }

  virtual  string toString() { 
        std:: stringstream ss;
        ss << " Anchored to the point (" << p2d.getX()
                << ", " << p2d.getY() << ")";
        return ss.str();
    }

};

#endif // SHAPE_H