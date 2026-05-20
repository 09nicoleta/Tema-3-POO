#ifndef MANAGERRESTAURANT_H
#define MANAGERRESTAURANT_H
#include<vector>
#include<string>
#include "Zi.h"

class ManagerRestaurant{
    ManagerRestaurant()=default;
    ManagerRestaurant(const ManagerRestaurant &mr)=delete;
    ManagerRestaurant & operator=(const ManagerRestaurant & mr)=delete;
    std::vector<std::string> zile_sapt={"luni","marti","miercuri","joi","vineri","sambata","duminica"};
    std::vector<Zi> saptamana;
    public:
    static ManagerRestaurant & getInstance();
    void input();
    void meniu();
};

#endif
