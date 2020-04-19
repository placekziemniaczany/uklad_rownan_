#ifndef MACIERZ_HH
#define MACIERZ_HH
#include <cstdlib>
#include "rozmiar.hh"
#include "wektor.hh"
#include <iostream>
using namespace std;

enum metoda{
    Sarrus, Laplace
};

class MacierzKw {
  Wektor tab[ROZMIAR];
  public:
  MacierzKw(){
    for (int i; i<ROZMIAR; i++){
       tab[i].zmien_x(0);
       tab[i].zmien_y(0);
       tab[i].zmien_z(0);
    }
  }
double Wyznacznik_Sarrus();
double Wyznacznik_Laplace();
const MacierzKw transponuj();
const Wektor operator * (const Wektor & W)const;
const MacierzKw operator * (const MacierzKw & M2)const;
const MacierzKw operator + (const MacierzKw & M2)const;
const MacierzKw operator - (const MacierzKw & M2)const;
const MacierzKw operator * (const double l)const;
const Wektor zwroc_kolumne(int ind)const;
Wektor zwroc_w(int i) const {
          return tab[i];
      }
void zamien_w(Wektor C, int i){
          tab[i] = C;
      }
const Wektor & operator [] (unsigned int ind) const{
    if (ind < 0 || ind > ROZMIAR) {
      cerr << "indeks poza zakresem" << endl;
      exit(1);
    }
    else return tab[ind];
  }
Wektor & operator [] (unsigned int ind){
   if (ind < 0 || ind > ROZMIAR) {
      cerr << "indeks poza zakresem" << endl;
      exit(1);
    }
    else return tab[ind];
  }

};


istream& operator >> (istream &Strm, MacierzKw &M1);
ostream& operator << (ostream &Strm, const MacierzKw &M1);
const MacierzKw operator * (const double l, const MacierzKw & M);




#endif

