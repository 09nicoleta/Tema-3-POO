#ifndef MASABUILDER_H
#define MASABUILDER_H
#include<memory>
#include<vector>
#include "MasaRestaurant.h"
class MasaBuilder{

    std::vector<std::shared_ptr<Meniu>> meniuri;
    int id,timp;

    public:
    MasaBuilder & setId(int idNou);
    MasaBuilder & setTimp(int timpNou);
    MasaBuilder& adaugaMeniu(std::shared_ptr<Meniu> meniu);
    MasaRestaurant build()const;
};

#endif
