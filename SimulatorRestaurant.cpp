#include "MeniuGeneric.h"
#include "SimulatorRestaurant.h"
#include "MasaRestaurant.h"
#include "MasaBuilder.h"
#include "Factory.h"
#include<memory>

std::shared_ptr<Meniu> SimulatorRestaurant::genereazaMeniu() {
    std::uniform_int_distribution<int> tipDist(0, 2);
    int tip=tipDist(rng);

    std::vector<std::pair<std::string, float>>com_meniu;

    if(tip==0){ 

    FactoryPreparatePrincipale fact;
    int nr_el=std::uniform_int_distribution<int>(1,2)(rng);
    std::uniform_int_distribution<int>ind(0, fact.getNrElemente()-1);
    int ind_rand;
    for(int i=1;i<=nr_el;++i){
        ind_rand=ind(rng);
        com_meniu.emplace_back(fact.creeazaElement(ind_rand));
    }

    return std::make_shared<PreparatePrincipale>(com_meniu);
    }
    
    else if(tip==1){ 
    FactoryMeniuSpecial fact;
    int nr_el=std::uniform_int_distribution<int>(1,2)(rng);
    std::uniform_int_distribution<int>ind(0, fact.getNrElemente()-1);
    int ind_rand;
    for(int i=1;i<=nr_el;++i){
        ind_rand=ind(rng);
        com_meniu.emplace_back(fact.creeazaElement(ind_rand));
    }
    
    return std::make_shared<MeniuSpecial>(com_meniu);

    }
    else{
    FactoryBauturi fact;
    int nr_el=std::uniform_int_distribution<int>(1,2)(rng);
    std::uniform_int_distribution<int>ind(0, fact.getNrElemente()-1);
    int ind_rand;
    for(int i=1;i<=nr_el;++i){
        ind_rand=ind(rng);
        com_meniu.emplace_back(fact.creeazaElement(ind_rand));
    }
    
    return std::make_shared<Bauturi>(com_meniu);

    }
}

MasaRestaurant SimulatorRestaurant::genereazaMasa(int id) {
    MasaBuilder builder;

    int n=std::uniform_int_distribution<int>(1,3)(rng);

    for(int i=0;i<n;i++)
        builder.adaugaMeniu(genereazaMeniu());

    int timp=std::uniform_int_distribution<int>(0,460)(rng);

    return builder.setId(id).setTimp(timp).build();
}

Zi SimulatorRestaurant::genereazaZi(const std::string& nume_zi){
    Zi zi{nume_zi};
    int n_clienti=std::uniform_int_distribution<int>(1,5)(rng);
    for(int i=0; i<n_clienti; i++)
        zi.adaugare(genereazaMasa(i+1));

    return zi;
}