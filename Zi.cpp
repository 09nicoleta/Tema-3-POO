#include "Zi.h"
#include<iostream>

//Constructor
Zi::Zi(const std::string & zi):zi{zi}{}

void Zi::adaugare(const MasaRestaurant &m){
    mese_ocupate.emplace_back(m);
}

std::ostream &operator<<(std::ostream & os, const Zi & z){
    os<<"Activitatea restaurantului in ziua de "<<z.zi<<'\n';
    for(const auto &activitate: z.mese_ocupate){
        os<<activitate;
    }
    return os;
} 
std::vector<int> Zi::rezumat_zi(){
    std::vector<int> nr_men_com(3, 0);

    for( auto& masa:mese_ocupate){
        auto r = masa.rezumat_comanda();

        for(int i=0; i<3; ++i){
            nr_men_com[i] += r[i];
        }
    }

    std::cout<<"In ziua de "<<zi<<" s-au comandat:\n";
    std::cout<<"Meniu Preparate principale -> " <<nr_men_com[0]<<"\n";
    std::cout<<"Meniu Special -> " <<nr_men_com[1]<<"\n";
    std::cout<<"Meniu Bauturi -> " <<nr_men_com[2]<<"\n";

    return nr_men_com;
}

std::string Zi::getZi() const{return zi;}


