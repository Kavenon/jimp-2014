#include "aghInclude.h"
// -------------------------------------------------------------

aghComplex::aghComplex(){

    re = 0;
    im = 0;

}
// -------------------------------------------------------------

aghComplex::aghComplex(double _re, double _im){

    re = _re;
    im = _im;

}
// -------------------------------------------------------------

aghComplex aghComplex::operator+(aghComplex const & c){

    aghComplex result;
    result.re = re + c.re;
    result.im = im + c.im;
    return result;

}
// -------------------------------------------------------------

aghComplex aghComplex::operator*(aghComplex const & c){

    aghComplex result;
    result.re = re * c.re - im * c.im;
    result.im = re * c.im + im * c.re;
    return result;

}
// -------------------------------------------------------------

bool aghComplex::operator==(aghComplex const & c){

    if(re == c.re && im == c.im){
        return true;
    }
    else {
        return false;
    }

}
// -------------------------------------------------------------

bool aghComplex::operator!=(aghComplex const & c){

    return !operator==(c);

}
// -------------------------------------------------------------

std::ostream& operator<<(std::ostream& out, const aghComplex& c){
    return out << "(" << c.re << "+" << c.im << "i)" << endl;
}
// -------------------------------------------------------------
