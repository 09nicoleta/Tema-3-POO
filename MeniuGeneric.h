#ifndef MENIUGENERIC_H
#define MENIUGENERIC_H

#include "Meniu.h"
#include "Exceptii.h"
#include <vector>
#include <utility>
#include <string>
#include<iostream>
#include<memory>

struct TagPreparatePrincipale{
    std::string getnume()const{return "Meniu Principal";}
};
struct TagMeniuSpecial{
     std::string getnume()const {return "Meniu Special";}
};

struct TagBauturi{
    std::string getnume()const{return "Bauturi";}
};

template <typename T>
class MeniuGeneric:public Meniu{

    std::vector<std::pair<std::string, float>> comanda;
    T tip;

    void afisare(std::ostream &os) const override{
        if(!comanda.empty()){
            os<<"\n<"<<tip.getnume()<<">\n";
            for(const auto&com:comanda)
                os<<" - "<<com.first<<"\n"; 
        }
        afiseaza_nr(os,*this);
    }
    
    float total_plata_()const override{
        float plata=0;
        for(const auto&com:comanda)
            plata+=com.second;
        return plata;
    }

    public:
    MeniuGeneric()=default;
    MeniuGeneric(const std::vector<std::pair<std::string, float>>& com) : Meniu(),comanda{com} {}
    MeniuGeneric(std::initializer_list<std::pair<std::string, float>> com) :Meniu(), comanda{com} {}

    std::shared_ptr<Meniu> clone() const override {
    return std::make_shared<MeniuGeneric<T>>(*this);
    }

    std::string TipMeniu() const {
        return tip.getnume();
    }

    void citire(std::istream & in){
    int n;
    in>>n;
    for(int i =0;i<n;i++) {
        std::string nume;
        float pret;
        in>>nume>>pret;
        verificaInterval<float>(pret, 3.f, 400.f);

        comanda.emplace_back(nume, pret);
    }
}
    template<typename U>
    friend void afiseaza_nr(std::ostream &os, const MeniuGeneric<U> &m);
};

template<typename U>
void afiseaza_nr(std::ostream &os , const MeniuGeneric<U> &m){
    os<<m.tip.getnume()<<" are "<<m.comanda.size()<<" elemente\n";
}

using PreparatePrincipale=MeniuGeneric<TagPreparatePrincipale>;
using MeniuSpecial=MeniuGeneric<TagMeniuSpecial>;
using Bauturi=MeniuGeneric<TagBauturi>;

#endif
