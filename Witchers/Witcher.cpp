#include "Witcher.h"

struct WitcherSt{
    string nombre;
    string escuela;
    int contratos;
};

Witcher consBrujo(string nombre, string escuela){

    Witcher brujo = new WitcherSt;
    brujo->nombre = nombre;
    brujo->escuela = escuela;
    brujo->contratos = 0;

    return brujo;
}

Witcher consBrujoExperimentado(string nombre, string escuela, int contratos){

    Witcher brujo = new WitcherSt;
    brujo->nombre = nombre;
    brujo->escuela = escuela;
    brujo->contratos = contratos;

    return brujo;
}

string nombreDeBrujo(Witcher brujo){

    return brujo->nombre;
}

string escuelaDelBrujo(Witcher brujo){

    return brujo->escuela;
}

int contratosResueltos(Witcher brujo){

    return brujo->contratos;
}

void agregarContratoResuelto(Witcher brujo){

    brujo->contratos++;
}

void mostrarBrujo(Witcher brujo){

    cout << "Brujo ---------------------- " << endl;
    cout << "Nombre: " << brujo->nombre << endl;
    cout << "Escuela del " << brujo->escuela << endl;
    cout << "Cantidad de contratos resueltos : " << brujo->contratos << endl;
    cout << "--------------------------------------" << endl;
    cout << endl;
}
