#pragma once
#include <string>
#include <iostream>
#define PRETPM 10   // pret etaj pe metru patrat
#define PRETCPM 20  // pret curte pe metru patrat

class Locuinta {
protected:
    std::string nume;
    int suprafata;
    float discount;
public:
    Locuinta(std::string nume = "DEFAULT", int suprafata = 0, float discount = 0);
    Locuinta(const Locuinta &obj);
    Locuinta &operator=(const Locuinta &obj);

    virtual float GetChirie();

    friend std::istream &operator>>(std::istream &is, Locuinta &obj);
    friend std::ostream &operator<<(std::ostream &os, const Locuinta &obj);

    virtual ~Locuinta(){}

    virtual void Afisare();
    //void setIndex(int x){this->index = x;}
    //int getIndex(){return index;}

};


