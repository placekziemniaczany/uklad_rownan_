#ifndef UKLADROWNANLINIOWYCH_HH
#define UKLADROWNANLINIOWYCH_HH
#include "macierz.hh"
#include <iostream>
using namespace std;

/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
class UkladRownanLiniowych {
  MacierzKw M;
  Wektor W;
public:
    UkladRownanLiniowych() {
        W.zmien_x(0);
        W.zmien_y(0);
        W.zmien_z(0);
        for (int i; i<ROZMIAR; i++){
            M.zamien_w(W, i);
        }
    }
void wczytaj_wektor(const Wektor C, int i){
    M.zamien_w(C, i);
}
void wcztaj_wyraz1(double a){
    W.zmien_x(a);
}
void wcztaj_wyraz2(double a){
    W.zmien_y(a);
}
void wcztaj_wyraz3(double a){
    W.zmien_z(a);
}
const double zwroc_w1()const{
 return W.zwroc_x();
}
const double zwroc_w2()const{
return W.zwroc_y();
}
const double zwroc_w3()const{
return W.zwroc_z();
}
MacierzKw zwroc_macierz()const{
  return M;
}
const Wektor daj_wektor(int i)const{
   return M.zwroc_w(i);
}
const Wektor zwroc_wolny()const{
    return W;
}
Wektor obliczuklad(metoda met); //Metoda obliczajaca uklad rownan
Wektor wekbl(metoda met);
double dlwekbl(metoda met);
};



istream& operator >> (istream &Strm, UkladRownanLiniowych &UklRown);
std::ostream& operator << (std::ostream &Strm, UkladRownanLiniowych &UklRown);
void wyswrozw(Wektor C, Wektor B, double x);
#endif

