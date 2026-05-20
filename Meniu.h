#ifndef MENIU_H
#define MENIU_H
#include<memory>

class Meniu{
    
    virtual float total_plata_()const =0;
    virtual void afisare(std::ostream&) const=0;
    protected:
    public:
    //Constructor
    Meniu()=default;
    //Constructor de copiere
    Meniu(const Meniu & meniu)=default;
    virtual void citire(std::istream &in)=0;
    Meniu & operator=(const Meniu & meniu)=default; 
    //Destructor
    virtual ~Meniu()=0;
    friend std::ostream &operator<<(std::ostream & os, const Meniu & meniu);
    float total_plata() const; 
    virtual std::shared_ptr<Meniu> clone() const = 0;

};

#endif