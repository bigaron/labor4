/**
 * \file potmeter.cpp
 * 
 * SimPoti osztály nem inline tagfüggvényei.
 *
 */

#include "potmeter.h"
#include "resistor.h"

// Itt valósítsa meg a SimPoti osztály tagfüggvényeit!
SimPoti::SimPoti(double r){
    this->R = r;
    this->pos = 50;
}

 int SimPoti::getPos() const{
     return this->pos;
 }

Resistor SimPoti::getRes() const{
    return Resistor(1 / ((1/(this->R * this->pos / 100)) + (1/(this->R*(100 - this->pos)/100))));
}

int SimPoti::operator++(){
    if(this->pos < 99) this->pos++;
    return pos;
}

int SimPoti::operator--(){
    if(this->pos > 1) this->pos--;
    return pos;
}