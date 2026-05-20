#include<iostream>
#include "MasaBuilder.h"
#include "Meniu.h"
#include "Exceptii.h"
#include<memory>
#include "MasaRestaurant.h"
#include<vector>

MasaBuilder & MasaBuilder::setId(int idNou){
    id=idNou;
    return *this;
}

MasaBuilder & MasaBuilder::setTimp(int timpNou){
    timp=timpNou;
    return *this;
}

MasaBuilder& MasaBuilder::adaugaMeniu(std::shared_ptr<Meniu> meniu) {
    meniuri.emplace_back(meniu->clone()); 
    return *this;
}

MasaRestaurant MasaBuilder::build()const{
    verificaInterval<int>(timp, 0, 460);
    verificaInterval<int>(id, 0, 20);
    return MasaRestaurant{meniuri, id, timp};
}
