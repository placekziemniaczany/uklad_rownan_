#ifndef WEKTOR_HH
#define WEKTOR_HH
#include "rozmiar.hh"
#include <iostream>

class Wektor{
  double x,y,z;
public:
Wektor(){
    x = 0;
    y = 0;
    z = 0;
}
const Wektor operator + (const Wektor & W2)const;
const Wektor operator - (const Wektor & W2)const;
double operator * (const Wektor & W2)const; //skalarnie
const Wektor operator * (double l)const;
const Wektor  operator / (double l)const;
double dlugosc () const;
bool operator == (const Wektor & W2) const;
bool operator != (const Wektor & W2) const;
  double zwroc_x() const{
      return x;
  }
  double zwroc_y() const{
      return y;
  }
  double zwroc_z() const{
      return z;
  }
  void zmien_x(double nx){
      x = nx;
  }
  void zmien_y(double ny){
      y = ny;
  }
  void zmien_z(double nz){
      z = nz;
  }
};

std::istream& operator >> (std::istream &Strm, Wektor &Wek);
std::ostream& operator << (std::ostream &Strm, const Wektor &Wek);
Wektor operator *(double l, Wektor W2); // 3 * W3

#endif

