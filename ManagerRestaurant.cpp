#include<iostream>
#include<fstream>
#include "Meniu.h"
#include "MeniuGeneric.h"
#include "MasaRestaurant.h"
#include "Zi.h"
#include "SimulatorRestaurant.h"
#include "Exceptii.h"
#include "ManagerRestaurant.h"

ManagerRestaurant & ManagerRestaurant::getInstance(){
     static ManagerRestaurant mg;
     return mg;
}

void ManagerRestaurant::input(){
    bool loop=true;

    std::ifstream f("tastatura.in");
    int op;
    std::cout<<" Alegeti datele pe care le prelucrati:\n Tastati 1 --> date fisier\n         2 --> simuleaza activitatea restaurantului\n";
    std::cin>>op;
       
    if(op!=1 && op!=2)
        throw InputInvalid("Trebuie sa tastati 1 sau 2");

    if(op==1){
    if(!f.is_open())
        throw EroareFisier();
    else{
    int x,i,n;
        try{
        while(f>>x){
        Zi zi{zile_sapt[x-1]}; 

        f>>n;
        for(i=0;i<n;i++){
            MasaRestaurant masa;
            f>>masa;
            zi.adaugare(masa);
        }

        saptamana.emplace_back(zi);
    }

    }catch(const std::exception& err){
        std::cout<<"Eroare"<<err.what();
    }
    f.close();
}

}   
    else if(op==2){
    SimulatorRestaurant sim;
    try{
    for(const auto& z : zile_sapt)
        saptamana.emplace_back(sim.genereazaZi(z));

    }catch(std::exception &err){
        std::cout<<"Eroare: "<<err.what()<<'\n';
        std::cin.clear(); 
        loop=true;
    }
    }
std::string input;
}

void ManagerRestaurant::meniu(){
    bool loop=true;
    std::string input;
    int op;
    while(loop){
std::cout << R"(
-------------------------------------------------       ⣠⣾⣿⣿⣿⣷⣄
|                    MENIU                      |       ⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣰⣶⣆
------------------------------------------------|       ⢿⣿⣿⣿⣿⣿⡿⠀⠀⠀⠀⠀⠀⠀⠀⣴⣿⣿⣿⣿⣿⣦
| 1 - Afiseaza datele inregistrate              |       ⠀⠙⠛⠛⠛⠋⠀⠀⠀⠀⠀⠀⠀⢠⣤⣿⣿⣿⣿⣿⣿⣿⣤⡄
| 2 - Rezumatul activitatii                     |      ⢠⣤⣶⠀⠀⠀⠀⠀⣶⣶⣤⣤⡀ ⠸⠿⠿⠿⠿⠿⠿⠿⠿⠿⠇
| 3 - Iesire                                    |      ⢸⣿⣿⡇⠀⠀⠀⢸⣿⣿⣿⣿⣷⡄⠀⠀⠀⣤⣤⣤⣤⣤⣤⠄
-------------------------------------------------      ⢸⣿⣿⣿⡀⠀⠀⣾⣿⣿⣿⣿⣿⣿⣆⠀⣼⣿⣿⠛⠉⠉
Alegeti optiunea:                                      ⢸⣿⣿⣿⡇⠀⢰⣿⣿⣿⣿⡿⢿⣿⣿⣿⣿⡿⠁
)";

    std::cin>>input;
    try{

        try{
        op=std::stoi(input);
        }catch(const std::exception& e){
        std::cout<<"Date de intrare invalide - introduceti un numar intre 1 si 3"; 
        std::cin.clear();
        continue;
        }
        
        switch(op){

        case 1:
        for(const auto& zi:saptamana)
            std::cout<<zi;
        break;

        case 2:{
        std::string zi_max;
        std::vector<int> rez(3);
        int maxim=-1,suma_zi;

        int men_sp=0,men_b=0,men_pp=0;
        for(auto & zi: saptamana){
            rez=zi.rezumat_zi();
            men_pp+=rez[0];
            men_sp+=rez[1];
            men_b+=rez[2];
            suma_zi=rez[0]+rez[1]+rez[2];
            if(suma_zi>maxim){
                maxim=suma_zi;
                zi_max=zi.getZi();
            }
        }
    std::cout<<"\nIn saptamana inregistrata s-au comandat:\n"<<men_pp<<" Comenzi din Preparate Principale\n"<<men_sp<<" Comenzi din Meniuri Speciale\n"<<men_b<<" Comenzi din Bauturi\n";
    std::cout<<"Ziua cu cele mai multe comenzi a fost "<<zi_max<<"\n";
        break;
        }
    
        case 3:
        loop=false;
        break;
        
        default:
        std::cout<<"\nInput invalid.";
        break;
}

}catch(const std::exception& e){
                std::cout<<"Eroare: "<<e.what()<<'\n';
                std::cin.clear();
}
       
}
}