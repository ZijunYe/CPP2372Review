
#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "SA2-shape.h"
#include <iostream>



using namespace std;

class Rectangle: public Shape {
    double width;
    double height;

public:
    Rectangle(double x, double y, double width, double height) :
            Shape(x, y), width(width), height(height) { }

    Rectangle(double width, double height):
            Shape(), width(width), height(height) { }

    Rectangle(const Rectangle &r) {
        setAnchor(r.getAnchor());
        width = r.width, height = r.height;
    }

    double getPerimetre() const override {
        return 2*(width+ height);
    }

    double getArea() const override {
        return width*height;
    }

    virtual void getLimites(Point2D &p1, Point2D &p2) override {
        p1 = getAnchor();
        p2.setX(p1.getX() + width);
        p2.setY(p1.getY() + height);
    }

    double getHeight() const {
        return height;
    }

    void setHeight(double height) {
        this->height = height;
    }

    double getWidth() const {
        return width;
    }

    void setWidth(double width) {
        this->width = width;
    }

  virtual  string toString() override { // overriding
        std::stringstream ss;
        ss << "Rectangle (" << height << "x" << width << ")";
        return ss.str() + Shape::toString();
    }


};

#endif // RECTANGLE_H