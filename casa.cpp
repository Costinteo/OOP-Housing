#include "casa.h"

Casa::Casa(std::string nume, int suprafata, float discount, int curte, int nr_etaje) : Locuinta(nume, 0, discount) {
    this->curte = curte;
    this->nr_etaje = nr_etaje;
}

Casa::Casa(const Casa &obj) {
    *this = obj;
}

Casa &Casa::operator=(const Casa &obj) {
    this->curte = obj.curte;
    this->nr_etaje = obj.nr_etaje;
    this->etaje = obj.etaje;
    Locuinta::operator=(obj);
    return *this;
}

std::istream &operator>>(std::istream &is, Casa &obj) {
    is >> static_cast<Locuinta &>(obj);
    is >> obj.curte;
    is >> obj.nr_etaje;
    for (int i = 0; i < obj.nr_etaje; i++){
        int etaj;
        is >> etaj;
        obj.etaje.push_back(etaj);
        obj.suprafata += etaj;
    }

    return is;
}

void Casa::Afisare() {
    Locuinta::Afisare();
    std::cout << "Suprafata utila curte: " << this->curte << "\n";
    std::cout << "Numar etaje: " << this->nr_etaje << "\n";
    for (int i = 0; i < this->nr_etaje; i++)
        std::cout << "Suprafata utila etaj " << i + 1 << ": " << this->etaje[i] << "\n";
}

float Casa::GetChirie() {
    return PRETCPM * this->curte + Locuinta::GetChirie();
}

std::ostream &operator<<(std::ostream &os, const Casa &obj) {
    os << static_cast<const Locuinta&> (obj);
    os << "Suprafata utila curte: " << obj.curte << "\n";
    os << "Numar etaje: " << obj.nr_etaje << "\n";
    for (int i = 0; i < obj.nr_etaje; i++)
        os << "Suprafata utila etaj " << i + 1 << ": " << obj.etaje[i] << "\n";
    return os;
}




