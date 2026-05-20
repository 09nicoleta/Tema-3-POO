#ifndef EXCEPTII_H
#define EXCEPTII_H
#include <exception>
#include <string>


class InputInvalid : public std::exception {
    std::string mesaj;
public:
    InputInvalid(const std::string& mesaj):mesaj(mesaj){}

    const char* what() const noexcept override{return mesaj.c_str();}
};


class EroareFisier:public std::exception{
    std::string mesaj;
    public:
    EroareFisier(const std::string &mesaj="Fisierul nu se poate deschide"): mesaj{mesaj}{}

    const char* what() const noexcept override{
        return mesaj.c_str();
    }
};

class EroareMeniu: public std::exception{
    std::string mesaj;
    public:
    EroareMeniu(const std::string &msj):mesaj{msj}{}
    const char* what() const noexcept override{
        return mesaj.c_str();
    }
};

template <typename T>
void verificaInterval(T valoare, T minim, T maxim){
    if(valoare<minim)
        throw InputInvalid("Valoare prea mica"); 
    if(valoare>maxim)
        throw InputInvalid("Valoare prea mare");
}

#endif