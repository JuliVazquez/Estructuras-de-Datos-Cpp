#include "Pokemon.h"

struct PokemonSt {
string nombre;
TipoDePokemon tipo;
int vida;
};
/*-------------------------------------------------------------------------*/
void mostrarPokemon (Pokemon p){
    cout << "Pokemon: " << endl;
    cout << "     name:  "<< p->nombre<< endl;
    cout << "     tipo:  "<< p->tipo<< endl;
    cout << "     vida:  "<< p->vida<< endl;
}

Pokemon consPokemon(string nombre, TipoDePokemon tipo){

    Pokemon poke = new PokemonSt;
    poke->nombre = nombre;
    poke->tipo = tipo;
    poke->vida = 100;
    return poke;
}

TipoDePokemon tipoDePokemon(Pokemon p){

    return p->tipo;
}

int energia(Pokemon p){

    return p->vida;
}

void perderEnergia(int energia, Pokemon p){

    if(energia >= p->vida){
        p->vida = 0;
    }
    else{
        p->vida = p->vida-energia;
    }
}

bool superaA(Pokemon p1, Pokemon p2){

    if(p1->tipo == "Fuego"){
        return p2->tipo == "Planta";
    }
    if(p1->tipo == "Agua"){
        return p2->tipo == "Fuego";
    }
    if(p1->tipo == "Planta"){
        return p2->tipo == "Agua";
    }
}




