#include <iostream>
#include "wektor.hh"
#include "macierz.hh"
#include "uklad_rownan.hh"




/*
 * Tu definiujemy pozostale funkcje.
 * Lepiej jednak stworzyc dodatkowy modul
 * i tam je umiescic. Ten przyklad pokazuje
 * jedynie absolutne minimum.
 */


int main(){
UkladRownanLiniowych Ukl1;
Wektor A, B, C, D;
double x, a;
cin>>Ukl1;
cout<<Ukl1;
A = Ukl1.obliczuklad(Sarrus);
B = Ukl1.wekbl(Sarrus);
x = Ukl1.dlwekbl(Sarrus);
C = Ukl1.obliczuklad(Laplace);
D = Ukl1.wekbl(Laplace);
a = Ukl1.dlwekbl(Laplace);
cout<<endl<<"Dla metody Sarrusa: "<<endl;
wyswrozw(A, B, x);
cout<<endl<<"Dla metody Laplace'a: "<<endl;
wyswrozw(C, D, a);
}
