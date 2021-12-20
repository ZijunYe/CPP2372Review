

#include <iostream>

class Fraction {
    
  long num;
  long den;
  
  public:
  
    Fraction(long d=0, long n=1) : den(d), num(n) {} // note: conversion long->Fraction
  
    double getValue() { return static_cast<double>(num)/den; }
};