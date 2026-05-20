#include "Meniu.h"
#include<iostream>

std::ostream & operator<<(std::ostream &os, const Meniu & meniu){
    meniu.afisare(os);
    os<<"\n";
    return os;
}

float Meniu::total_plata() const{
    return total_plata_();
}
//Destructor pur virtual
Meniu::~Meniu(){}
