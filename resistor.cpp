/**
 * \file resistor.cpp
 *   (UTF-8 kodolasu fajl. Allitsa at a megjenetes kodolasat,
 *    ha a tovabbi kommentek nem olvashatok helyesen!)
 *
 * Ohmikus ellenállást modellező osztály megvalósítása
 */

/**
 * Itt kell megvalósítani a resistor.h-ban deklarált nem inline függvényeket.
 * A Jportára ezt a fájlt kell feltölteni.
 */

#include "resistor.h"
#include "gtest_lite.h"

double Resistor::defR = 9;

Resistor::Resistor(){
    this->R = defR;
    //Pr("ctor0");
}

Resistor::Resistor(double r){
    this->R = r;
    // Pr("ctor1");
}

void Resistor::setDef(double r) {defR = r;}

Resistor Resistor::operator+(const Resistor &r) const{
    return this->getR() + r.getR();
}

Resistor Resistor::operator%(const Resistor &r) const{
    return 1/(1/(this->R) + 1/r.getR());
}

Resistor operator*(int n, const Resistor &r){
    if(n <= 0) throw("GIS2YB");
    else return r.getR() * n; 
}

Resistor::Resistor(const Resistor& rhs){
    *this = rhs;
    //Pr("copy");
}

Resistor& Resistor::operator=(const Resistor& rhs){
    //Pr("Assign");
    this->R = rhs.getR();
    return *this;
}

double Resistor::getI(double u) const{
    return u / this->R;
}

double Resistor::getU(double i) const{
    return i * this->R;
}


bool Resistor::operator==(const Resistor& r) const{
    return gtest_lite::almostEQ(this->R, r.getR());
}

Resistor::~Resistor(){
    //Pr("dtor");
}
