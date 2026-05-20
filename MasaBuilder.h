#ifndef MASABUILDER_H
#define MASABUILDER_H

#include "MasaRestaurant.h"
#include "Exceptii.h"

class MasaBuilder{

    std::vector<std::shared_ptr<Meniu>> meniuri;
    int id=0;
    int timp=0;

    public:
    MasaBuilder & setId(int idNou){
        id=idNou;
        return *this;
    }

    MasaBuilder & setTimp(int timpNou){
        timp=timpNou;
        return *this;
    }

    MasaBuilder& adaugaMeniu(std::shared_ptr<Meniu> meniu) {
        meniuri.emplace_back(meniu->clone()); 
        return *this;
    }

    MasaRestaurant build(){
        verificaInterval<int>(timp, 0, 460);
        verificaInterval<int>(id, 0, 20);
        return MasaRestaurant{meniuri, id, timp};
    }
};

#endif