#include <iostream>
#include "ManagerRestaurant.h"

int main(){

    ManagerRestaurant::getInstance().input();
    ManagerRestaurant::getInstance().meniu();

    return 0;
}
