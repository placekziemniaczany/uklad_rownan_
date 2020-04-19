#include "macierz.hh"

using namespace std;
istream& operator >> (istream &Strm, MacierzKw &M1){
    Wektor W;
    for(int i = 0; i<ROZMIAR; ++i) {
        Strm >> W;
        M1.zamien_w(W,i);
    }
    return Strm;
}
ostream& operator << (ostream &Strm, const MacierzKw &M){
    Strm<<endl;
    for(int i=0; i<ROZMIAR; ++i){
        Strm<<M.zwroc_w(i)<<endl;
    }
    return Strm;
}
double MacierzKw::Wyznacznik_Sarrus(){
    double a, b;
    MacierzKw M = (*this);
   a = M[0].zwroc_x()*M[1].zwroc_y()*M[2].zwroc_z()+M[0].zwroc_y()*M[1].zwroc_z()*M[2].zwroc_x()+M[0].zwroc_z()*M[1].zwroc_x()*M[2].zwroc_y();
   b = M[2].zwroc_x()*M[1].zwroc_y()*M[0].zwroc_z()+M[2].zwroc_y()*M[1].zwroc_z()*M[0].zwroc_x()+M[2].zwroc_z()*M[1].zwroc_x()*M[0].zwroc_y();
return a-b;
}
double MacierzKw::Wyznacznik_Laplace(){
    MacierzKw M = (*this);
   double m1 = M[1].zwroc_y()*M[2].zwroc_z()-(M[2].zwroc_y()*M[1].zwroc_z());
   double m2 = M[1].zwroc_x()*M[2].zwroc_z()-(M[2].zwroc_x()*M[1].zwroc_z());
   double m3 = M[1].zwroc_x()*M[2].zwroc_y()-(M[2].zwroc_x()*M[1].zwroc_y());
return m1*M[0].zwroc_x() - m2*M[0].zwroc_y() + m3*M[0].zwroc_z();
}
const MacierzKw MacierzKw::operator*(const MacierzKw & M2)const{
MacierzKw nowa;
MacierzKw M1 = (*this);
double a, b, c;
Wektor W;
for (int i = 0; i<ROZMIAR; i++){
    a = M1[i].zwroc_x()*M2[0].zwroc_x()+M1[i].zwroc_y()*M2[1].zwroc_x()+M1[i].zwroc_z()*M2[2].zwroc_x();
    W.zmien_x(a);
    b = M1[i].zwroc_x()*M2[0].zwroc_y()+M1[i].zwroc_y()*M2[1].zwroc_y()+M1[i].zwroc_z()*M2[2].zwroc_y();
    W.zmien_y(b);
    c = M1[i].zwroc_x()*M2[0].zwroc_z()+M1[i].zwroc_y()*M2[1].zwroc_z()+M1[i].zwroc_z()*M2[2].zwroc_z();
    W.zmien_z(c);
    nowa.zamien_w(W, i);
}
return nowa;
}
const MacierzKw MacierzKw::operator + (const MacierzKw & M2)const{
    double a, b, c;
    Wektor W;
    MacierzKw nowa, M1;
    M1 = (*this);
    for (int i = 0; i<ROZMIAR; i++){
       a = M1[i].zwroc_x()+M2[i].zwroc_x();
       W.zmien_x(a);
       b = M1[i].zwroc_y()+M2[i].zwroc_y();
       W.zmien_y(b);
       c = M1[i].zwroc_z()+M2[i].zwroc_z();
       W.zmien_z(c);
       nowa.zamien_w(W, i);
    }
    return nowa;
}
const MacierzKw MacierzKw::operator - (const MacierzKw & M2)const{
    double a, b, c;
    Wektor W;
    MacierzKw nowa, M1;
    M1=(*this);
    for (int i = 0; i<ROZMIAR; i++){
       a = M1[i].zwroc_x()-M2[i].zwroc_x();
       W.zmien_x(a);
       b = M1[i].zwroc_y()-M2[i].zwroc_y();
       W.zmien_y(b);
       c = M1[i].zwroc_z()-M2[i].zwroc_z();
       W.zmien_z(c);
       nowa.zamien_w(W, i);
    }
    return nowa;
}
const MacierzKw MacierzKw::operator*(const double l)const{
    double a, b, c;
    Wektor W;
    MacierzKw nowa, M;
    M = (*this);
    for (int i = 0; i<ROZMIAR; i++){
        a = M[i].zwroc_x() * l;
    W.zmien_x(a);
    b = M[i].zwroc_y() * l;
    W.zmien_y(b);
    c = M[i].zwroc_z() * l;
    W.zmien_z(c);
    nowa.zamien_w(W, i);
    }
    return nowa;
}
const Wektor MacierzKw::operator*(const Wektor & W)const{
Wektor wynik;
MacierzKw M = (*this);
double a, b, c;
    a = M[0].zwroc_x()*W.zwroc_x()+M[0].zwroc_y()*W.zwroc_y()+M[0].zwroc_z()*W.zwroc_z();
    wynik.zmien_x(a);
    b = M[1].zwroc_x()*W.zwroc_x()+M[1].zwroc_y()*W.zwroc_y()+M[1].zwroc_z()*W.zwroc_z();
    wynik.zmien_y(b);
    c = M[2].zwroc_x()*W.zwroc_x()+M[2].zwroc_y()*W.zwroc_y()+M[2].zwroc_z()*W.zwroc_z();
    wynik.zmien_z(c);
return wynik;
}
const MacierzKw MacierzKw::transponuj(){
    MacierzKw nowa;
    MacierzKw M = (*this);
double a, b, c, d, e, f, g, h, i;
a = M[0].zwroc_x();
nowa[0].zmien_x(a);
e = M[1].zwroc_y();
nowa[1].zmien_y(e);
i = M[2].zwroc_z();
nowa[2].zmien_z(i);
b = M[1].zwroc_x();
nowa[0].zmien_y(b);
c = M[2].zwroc_x();
nowa[0].zmien_z(c);
d = M[0].zwroc_y();
nowa[1].zmien_x(d);
f = M[2].zwroc_y();
nowa[1].zmien_z(f);
g = M[0].zwroc_z();
nowa[2].zmien_x(g);
h = M[1].zwroc_z();
nowa[2].zmien_y(h);
return nowa;
}
const MacierzKw operator * (const double l, const MacierzKw & M){
    double a, b, c;
    Wektor W;
    MacierzKw nowa;
    for (int i = 0; i<ROZMIAR; i++){
        a = M[i].zwroc_x() * l;
    W.zmien_x(a);
    b = M[i].zwroc_y() * l;
    W.zmien_y(b);
    c = M[i].zwroc_z() * l;
    W.zmien_z(c);
    nowa.zamien_w(W, i);
    }
    return nowa;
}
const Wektor MacierzKw::zwroc_kolumne(int index)const{
    MacierzKw M =(*this);
    Wektor nowy;
    double a,b,c;
switch(index){
case 0:
        a = M[0].zwroc_x();
        nowy.zmien_x(a);
        b = M[1].zwroc_x();
        nowy.zmien_y(b);
        c = M[2].zwroc_x();
        nowy.zmien_z(c);
    break;
case 1:
        a = M[0].zwroc_y();
        nowy.zmien_x(a);
        b = M[1].zwroc_y();
        nowy.zmien_y(b);
        c = M[2].zwroc_y();
        nowy.zmien_z(c);
    break;
case 2:
        a = M[0].zwroc_z();
        nowy.zmien_x(a);
        b = M[1].zwroc_z();
        nowy.zmien_y(b);
        c = M[2].zwroc_z();
        nowy.zmien_z(c);
    break;
    }
return nowy;
}
