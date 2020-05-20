#include <fstream>
#include "locuinta.h"
#include "casa.h"
#include "apartament.h"
#include "gestiune.h"

int main() {
    std::ifstream f("data.in");
    Gestiune<Apartament> ApartLista;
    Gestiune<Casa> CasaLista;
    int n;
    f >> n;
    for (int i = 0; i < n; i++) {
        std::string tip;
        Locuinta loc;
        Apartament ap;
        Casa c;
        f >> tip;
        if (tip == "Locuinta"){
            f >> loc;
            std::cout << loc << "\n";
        }
        else if (tip == "Apartament") {
            f >> ap;
            ApartLista += ap;
        }
        else if (tip == "Casa"){
            f >> c;
            CasaLista += c;
        }

    }

    for (auto i : ApartLista.s)
        std::cout << i.second << "Chirie: " << i.second.GetChirie() << "\n\n";
    for (auto i : CasaLista.s)
        std::cout << i.second << "Chirie: " << i.second.GetChirie() << "\n\n";
    CasaLista.print_Chirie();

    return 0;
}
