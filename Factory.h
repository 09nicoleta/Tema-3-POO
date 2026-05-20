#ifndef FACTORY_H
#define FACTORY_H

#include "MeniuGeneric.h"
#include <memory>

class Factory{
    
    public:
    virtual std::shared_ptr<Meniu> creeazaMeniu()=0;
    virtual int getNrElemente()const=0;
    virtual std::pair<std::string, float> creeazaElement(int ind) const=0;

    Factory()=default;
    virtual ~Factory()=default;
    Factory(const Factory &f)=default;
    Factory & operator=(const Factory & f)=default;
};

class FactoryPreparatePrincipale:public Factory {
    std::vector<std::pair<std::string, float>>preparate_princip={{"Burger",20},{"Paste",38},{"Pizza",35},{"Salata",20},
    {"Papanasi",20},{"Inghetata",10}};

    public:
    std::shared_ptr<Meniu> creeazaMeniu() override {
        return std::make_shared<PreparatePrincipale>();
    }

    int getNrElemente()const{
        return preparate_princip.size();
    }

    std::pair<std::string, float> creeazaElement(int ind) const{
        return preparate_princip[ind];
    }


};

class FactoryBauturi:public Factory {
    std::vector<std::pair<std::string, float>> bauturi={{"Limonada", 15},{"Pepsi",5}, {"Apa",3}, {"Cappuccino",15}, {"Ceai",10}};

    public:
    std::shared_ptr<Meniu> creeazaMeniu()override {
        return std::make_shared<Bauturi>();
    }

    int getNrElemente()const{
        return bauturi.size();
    }

    std::pair<std::string, float> creeazaElement(int ind) const{
        return bauturi[ind];
    }

};

class FactoryMeniuSpecial:public Factory {
    std::vector<std::pair<std::string, float>> men_sp={{"Business", 45},{"Family",70}, {"Fitness",55}};

    public:
    std::shared_ptr<Meniu> creeazaMeniu() override {
        return std::make_shared<MeniuSpecial>();
    }

    int getNrElemente()const{
        return men_sp.size();
    }

    std::pair<std::string, float> creeazaElement(int ind) const{
        return men_sp[ind];
    }

};

#endif
