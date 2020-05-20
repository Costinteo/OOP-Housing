#pragma once
#include <unordered_map>
#include "locuinta.h"
#include "casa.h"

template <class c_type>
class Gestiune {
public:
    std::unordered_map<int, c_type> s;
    static int idx;

    Gestiune(){}
    ~Gestiune(){}

    Gestiune<c_type> &operator+=(const c_type &obj);
    void print_Chirie(){
        std::cout << "Nu este casa";

    }

};

template <class c_type>
int Gestiune<c_type>::idx = 0;

template<class c_type>
Gestiune<c_type> &Gestiune<c_type>::operator+=(const c_type &obj) {
    Gestiune<c_type>::idx++;
    c_type nou = obj;
    this->s.insert(std::make_pair(Gestiune<c_type>::idx, nou));
    return *this;
}

template <> void Gestiune<Casa>::print_Chirie() {
    float total = 0;
    for (auto i : s){
        total += i.second.GetChirie();
    }

    std::cout << "Chiria totala este: " << total;
}

template<> Gestiune<Casa> &Gestiune<Casa>::operator+=(const Casa &obj) {
    Gestiune<Casa>::idx++;
    this->s.insert(std::make_pair(Gestiune<Casa>::idx, obj));

    return *this;
}
