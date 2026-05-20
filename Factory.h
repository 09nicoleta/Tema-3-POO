#ifndef FACTORY_H
#define FACTORY_H

#include "MeniuGeneric.h"
#include <memory>

class Factory{
    
    public:
    virtual std::shared_ptr<Meniu> creeazaMeniu()=0;
    Factory()=default;
    virtual ~Factory()=default;
    Factory(const Factory &f)=default;
    Factory & operator=(const Factory & f)=default;
};

class FactoryPreparatePrincipale:public Factory {

    public:
    std::shared_ptr<Meniu> creeazaMeniu() override {
        return std::make_shared<PreparatePrincipale>();
    }
};

class FactoryBauturi:public Factory {
    public:
    std::shared_ptr<Meniu> creeazaMeniu()override {
        return std::make_shared<Bauturi>();
    }
};

class FactoryMeniuSpecial:public Factory {
    public:
    std::shared_ptr<Meniu> creeazaMeniu() override {
        return std::make_shared<MeniuSpecial>();}
};

#endif
