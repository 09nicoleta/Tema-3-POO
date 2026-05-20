#ifndef SIMULATORRESTAURANT_H
#define SIMULATORRESTAURANT_H
#include "MasaRestaurant.h"
#include "Zi.h"

#include<random>
#include<string>

class SimulatorRestaurant{
    std::mt19937 rng;

public:
    std::shared_ptr<Meniu> genereazaMeniu();
    MasaRestaurant genereazaMasa(int id);
    Zi genereazaZi(const std::string& nume);
};
#endif