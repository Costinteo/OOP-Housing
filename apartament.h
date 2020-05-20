#pragma once
#include "locuinta.h"

class Apartament : public Locuinta {
protected:
    int etaj;
public:
    Apartament(std::string nume = "DEFAULT", int suprafata = 0, float discount = 0, int etaj = 0);
    Apartament(const Apartament &obj);
    Apartament &operator=(const Apartament &obj);

    friend std::istream &operator>>(std::istream &is, Apartament &obj);
    friend std::ostream &operator<<(std::ostream &os, const Apartament &obj);

    ~Apartament(){}

    void Afisare() override;
};

