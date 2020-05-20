#pragma once
#include "locuinta.h"
#include <vector>

class Casa : public Locuinta{
protected:
    int curte;
    int nr_etaje;
public:
    std::vector<int> etaje;
    Casa(std::string nume = "DEFAULT", int suprafata = 0, float discount = 0, int curte = 0, int nr_etaje = 1);
    Casa(const Casa &obj);
    Casa &operator=(const Casa &obj);

    float GetChirie() override;

    friend std::istream &operator>>(std::istream &is, Casa &obj);
    friend std::ostream &operator<<(std::ostream &os, const Casa &obj);

    ~Casa(){}

    void Afisare() override;

};