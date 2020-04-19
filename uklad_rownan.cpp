#include "uklad_rownan.hh"
#include "wektor.hh"
#include "macierz.hh"
#include "rozmiar.hh"
#include <cmath>
using namespace std;
istream& operator >> (istream &Strm, UkladRownanLiniowych &UklRown){
Wektor wek;
    for(int i=0; i<ROZMIAR; ++i){
    Strm>>wek;
    UklRown.wczytaj_wektor(wek, i);
}
double dana1, dana2, dana3;
Strm>>dana1;
UklRown.wcztaj_wyraz1(dana1);
Strm>>dana2;
UklRown.wcztaj_wyraz2(dana2);
Strm>>dana3;
UklRown.wcztaj_wyraz3(dana3);
return Strm;
}
ostream& operator << (ostream &Strm, UkladRownanLiniowych &UklRown){
    Strm << endl << "Uklad rownan do rozwiazania: " << endl << endl;
Strm << "\t|" <<UklRown.zwroc_macierz().zwroc_kolumne(0)<<  "| | x_1" << " |   |"<<UklRown.zwroc_w1()<<"|"<<endl;
Strm << "\t|" <<UklRown.zwroc_macierz().zwroc_kolumne(1)<<  "| | x_2" << " | = |"<<UklRown.zwroc_w2()<<"|"<<endl;
Strm << "\t|" <<UklRown.zwroc_macierz().zwroc_kolumne(2)<<  "| | x_3" << " |   |"<<UklRown.zwroc_w3()<<"|"<<endl<<endl;
return Strm;
}
Wektor UkladRownanLiniowych::obliczuklad(metoda met){
    Wektor wynik;
    MacierzKw pomocnicza1, pomocnicza2, pomocnicza3;
    this->zwroc_macierz().transponuj();
    Wektor zmienny = this->zwroc_wolny();
    double Wyznacznik_glowny, Wx1, Wx2, Wx3;
    switch(met){
    case Sarrus:
Wyznacznik_glowny = this->zwroc_macierz().Wyznacznik_Sarrus();
pomocnicza1 = this->zwroc_macierz();
pomocnicza1.zamien_w(zmienny, 0);
Wx1 = pomocnicza1.Wyznacznik_Sarrus();
pomocnicza2 = this->zwroc_macierz();
pomocnicza2.zamien_w(zmienny, 1);
Wx2 = pomocnicza2.Wyznacznik_Sarrus();
pomocnicza3 = this->zwroc_macierz();
pomocnicza3.zamien_w(zmienny, 2);
Wx3 = pomocnicza3.Wyznacznik_Sarrus();
wynik.zmien_x(Wx1/Wyznacznik_glowny);
wynik.zmien_y(Wx2/Wyznacznik_glowny);
wynik.zmien_z(Wx3/Wyznacznik_glowny);
break;
case Laplace:
Wyznacznik_glowny = this->zwroc_macierz().Wyznacznik_Laplace();
pomocnicza1 = this->zwroc_macierz();
pomocnicza1.zamien_w(zmienny, 0);
Wx1 = pomocnicza1.Wyznacznik_Sarrus();
pomocnicza2 = this->zwroc_macierz();
pomocnicza2.zamien_w(zmienny, 1);
Wx2 = pomocnicza2.Wyznacznik_Sarrus();
pomocnicza3 = this->zwroc_macierz();
pomocnicza3.zamien_w(zmienny, 2);
Wx3 = pomocnicza3.Wyznacznik_Sarrus();
wynik.zmien_x(Wx1/Wyznacznik_glowny);
wynik.zmien_y(Wx2/Wyznacznik_glowny);
wynik.zmien_z(Wx3/Wyznacznik_glowny);
}
return wynik;
}
void wyswrozw(Wektor C, Wektor B, double x){
cout << "Wektor rozwiazan:" <<endl  << endl << "\t" << C << endl << endl;
cout << "Wektor bledu:" << endl << endl << "\tAx-b  =  (" << B << ")" << endl << endl;
cout << "Dlugosc wektora bledu:" << endl << endl << "\t||Ax-b||  =  " << x << endl << endl;
}
Wektor UkladRownanLiniowych::wekbl(metoda met){
Wektor wyniki, blad;
MacierzKw pom = this->zwroc_macierz();
Wektor wolny = this->zwroc_wolny();
switch(met){
case Sarrus:
wyniki = this->obliczuklad(Sarrus);
blad = (pom*wyniki) - wolny;
break;
case Laplace:
wyniki = this->obliczuklad(Laplace);
blad = (pom*wyniki) - wolny;
break;
}
return blad;
}
double UkladRownanLiniowych::dlwekbl(metoda met){
    Wektor pom;
    double dl;
    pom = this->wekbl(met);
    dl = sqrt(pom*pom);
return dl;
}
