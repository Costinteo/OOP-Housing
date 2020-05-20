#include "apartament.h"

Apartament::Apartament(std::string nume, int suprafata, float discount, int etaj) : Locuinta(nume, suprafata, discount) {
    this->etaj = etaj;
}

Apartament::Apartament(const Apartament &obj) {
    *this = obj;
}

Apartament &Apartament::operator=(const Apartament &obj) {
    this->etaj = obj.etaj;
    Locuinta::operator=(obj);
    return *this;
}

void Apartament::Afisare() {
        Locuinta::Afisare();
        std::cout << "Etaj: " << this->etaj << "\n";
}

std::istream &operator>>(std::istream &is, Apartament &obj) {
    is >> static_cast<Locuinta &>(obj);
    is >> obj.etaj;
    return is;
}

std::ostream &operator<<(std::ostream &os, const Apartament &obj) {
    os << static_cast<const Locuinta&> (obj);
    os << "Etaj: " << obj.etaj << "\n";
    return os;
}

