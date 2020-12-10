#include "Entrenador.h"

struct EntrenadorSt {
string nombre;
Pokemon* pokemon;
int cantPokemon;
};

/*-------------------------------------------------------------------------*/
Entrenador consEntrenador(string nombre, int cantidad, Pokemon* pokemones){

    Entrenador e = new EntrenadorSt;
    e->nombre = nombre;
    e->cantPokemon = cantidad;
    e->pokemon = pokemones;
    return e;
}
/*-------------------------------------------------------------------------*/
string nombreDeEntrenador(Entrenador e){

    return e->nombre;
}
/*-------------------------------------------------------------------------*/
int cantidadDePokemon(Entrenador e){

    return e->cantPokemon;
}
/*-------------------------------------------------------------------------*/

int cantidadDePokemonDe(TipoDePokemon tipo, Entrenador e){

    int cantDelTipo = 0;

    if(e->cantPokemon == 0){
        return cantDelTipo;
    }
    else{
        for(int i; i< e->cantPokemon; i++){

            if(tipoDePokemon(e->pokemon[i]) == tipo){
                cantDelTipo ++;
            }
        }
        return cantDelTipo;
    }
}
/*-------------------------------------------------------------------------*/
Pokemon pokemonNro(int i, Entrenador e){

    return e->pokemon[i];
}
/*-------------------------------------------------------------------------*/
bool elPokemonLeGanaATodosDe(Pokemon poke, Entrenador ent){

    bool victoria = true;
    for(int i=0; i<ent->cantPokemon; i++){

        victoria = victoria && superaA(poke, ent->pokemon[i]);
    }
    return victoria;
}

bool leGanaATodos(Entrenador e1, Entrenador e2){

    int i=0;
    while(!elPokemonLeGanaATodosDe(e1->pokemon[i], e2) && i<e2->cantPokemon){
        i++;
    }
    return elPokemonLeGanaATodosDe(e1->pokemon[i], e2);
}





