#ifndef ZI_H
#define ZI_H
#include<string>
#include<vector>
#include "MasaRestaurant.h"

class Zi{
    std::string zi;
    std::vector<MasaRestaurant>mese_ocupate;
    
    public:
    //Constructor cu un parametru
    Zi(const std::string &zi="null");
    void adaugare(const MasaRestaurant & m);
    friend std::ostream & operator<<(std::ostream & os, const Zi &zi);
     std::vector<int> rezumat_zi()const;
    std::string getZi() const;
};

#endif


