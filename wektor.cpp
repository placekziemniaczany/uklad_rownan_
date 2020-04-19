#include "wektor.hh"
#include <cmath>
#include <cstdlib>
using namespace std;
///Wczytywanie wartosci pod atrybuty danego obiektu typu 'Wektor'

istream& operator >> (istream &Strm, Wektor & Wek){
    double dana1, dana2, dana3;
    Strm>>dana1>>dana2>>dana3;
    Wek.zmien_x(dana1);
    Wek.zmien_y(dana2);
    Wek.zmien_z(dana3);
    return Strm;
}
ostream& operator << (ostream &Strm, const Wektor &Wek){
   Strm<<Wek.zwroc_x()<<" "<<Wek.zwroc_y()<<" "<<Wek.zwroc_z();
   return Strm;
}
const Wektor Wektor::operator+(const Wektor & W2)const{
    Wektor razem;
    double wynik_x, wynik_y, wynik_z;
    wynik_x= this->zwroc_x()+ W2.zwroc_x();
    razem.zmien_x(wynik_x);
    wynik_y= this->zwroc_y() + W2.zwroc_y();
    razem.zmien_y(wynik_y);
    wynik_z=this->zwroc_z() + W2.zwroc_z();
    razem.zmien_z(wynik_z);
    return razem;
}
const Wektor Wektor::operator-(const Wektor & W2)const{
    Wektor razem;
    double wynik_x, wynik_y, wynik_z;
    wynik_x= this->zwroc_x()- W2.zwroc_x();
    razem.zmien_x(wynik_x);
    wynik_y= this->zwroc_y() - W2.zwroc_y();
    razem.zmien_y(wynik_y);
    wynik_z=this->zwroc_z() - W2.zwroc_z();
    razem.zmien_z(wynik_z);
    return razem;
}
double Wektor::operator * (const Wektor & W2)const{
double wynik;
wynik = this->zwroc_x() * W2.zwroc_x() + this->zwroc_y() * W2.zwroc_y() + this->zwroc_z() * W2.zwroc_z();
return wynik;
}
const Wektor Wektor::operator*(double l)const{
    Wektor razem;
    double wynik_x, wynik_y, wynik_z;
    wynik_x= l * this->zwroc_x();
    razem.zmien_x(wynik_x);
    wynik_y= l * this->zwroc_y();
    razem.zmien_y(wynik_y);
    wynik_z= l * this->zwroc_z();
    razem.zmien_z(wynik_z);
    return razem;
}
const Wektor  Wektor::operator/(double l)const{
    Wektor razem;
    if (l==0){
            cerr<<"Proba dzielenia przez 0!"<<endl;
        exit(0);
    }
    double wynik_x, wynik_y, wynik_z;
    wynik_x= (1/l) * this->zwroc_x();
    razem.zmien_x(wynik_x);
    wynik_y= (1/l) * this->zwroc_y();
    razem.zmien_y(wynik_y);
    wynik_z= (1/l) * this->zwroc_z();
    razem.zmien_z(wynik_z);
    return razem;
}
double Wektor::dlugosc()const{
    double ax, ay, az;
    ax = this->zwroc_x();
    ay = this->zwroc_y();
    az = this->zwroc_z();
    return sqrt((ax*ax)+(ay*ay)+(az*az));
}
bool Wektor::operator==(const Wektor & W2)const{
    if (this->zwroc_x() == W2.zwroc_x() && this->zwroc_y() == W2.zwroc_y() && this->zwroc_z() == W2.zwroc_z()){
        return true;
    }
    else {
        return false;
    }
}
bool Wektor::operator!=(const Wektor & W2)const{
    if (this->zwroc_x() != W2.zwroc_x() || this->zwroc_y() != W2.zwroc_y() || this->zwroc_z() != W2.zwroc_z()){
        return true;
    }
    else {
        return false;
    }
}
Wektor operator *(double l, Wektor W2){
    Wektor razem;
    double wynik_x, wynik_y, wynik_z;
    wynik_x= l * W2.zwroc_x();
    razem.zmien_x(wynik_x);
    wynik_y= l * W2.zwroc_y();
    razem.zmien_y(wynik_y);
    wynik_z= l * W2.zwroc_z();
    razem.zmien_z(wynik_z);
    return razem;
}











