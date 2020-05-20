#include "locuinta.h"

Locuinta::Locuinta(std::string nume, int suprafata, float discount) {
    this->nume = nume;
    this->suprafata = suprafata;
    this->discount = discount;
}

Locuinta::Locuinta(const Locuinta &obj) {
    *this = obj;

}

Locuinta &Locuinta::operator=(const Locuinta &obj) {
    this->nume = obj.nume;
    this->suprafata = obj.suprafata;
    this->discount = obj.discount;
    return *this;
}

std::istream &operator>>(std::istream &is, Locuinta &obj) {
    is >> obj.nume;
    is >> obj.suprafata;
    is >> obj.discount;
    return is;
}

void Locuinta::Afisare() {

    std::cout << "Nume detinator: " << this->nume << "\n";
    std::cout << "Suprafata utila: " << this->suprafata << "\n";
    std::cout << "Discount: " << this->discount*100 << "%\n";

}

float Locuinta::GetChirie() {
    return this->suprafata * PRETPM * (1 - this->discount);
}

std::ostream &operator<<(std::ostream &os, const Locuinta &obj) {
    os << "Nume detinator: " << obj.nume << "\n";
    os << "Suprafata utila: " << obj.suprafata << "\n";
    os << "Discount: " << obj.discount*100 << "%\n";
    return os;
}





