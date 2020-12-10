#include <iostream>
#include "Pokemon.h"
#include "Entrenador.h"
using namespace std;

int main()
{
    Pokemon p1 = consPokemon("Charmander","Fuego");
    Pokemon p2 = consPokemon("Squirtle","Agua");
    Pokemon p3 = consPokemon("Bulbasaur","Planta");
    mostrarPokemon(p1);
    mostrarPokemon(p2);
    mostrarPokemon(p3);
    cout << "---------------------------------" << endl;
    cout << "Modificaciones" << endl;
    cout << tipoDePokemon(p1) << endl;
    perderEnergia(55,p1);
    cout << energia(p1) << endl;
    cout << endl;
    cout << "Charmander le gana a Squirtle: " << superaA(p1,p2) << endl;
    cout << "Squirtle le gana a Bulbasaur: " << superaA(p2,p3) << endl;
    cout << "Charmander le gana a Bulbasaur: " << superaA(p1,p3) << endl;
    cout << "---------------------------------" << endl;

    Pokemon* team1 = new Pokemon[3];
    team1[1] = consPokemon("Charmander","Fuego");
    team1[2] = consPokemon("Squirtle","Agua");
    team1[3] = consPokemon("Cyndaquill","Fuego");

    Entrenador ash = consEntrenador("Ash",3,team1);

    Pokemon* team2 = new Pokemon[3];
    team2[1] = consPokemon("Entei","Fuego");
    team2[2] = consPokemon("Chimchar","Fuego");
    team2[3] = consPokemon("Talonflame","Fuego");

    Entrenador gary = consEntrenador("Gary",3,team2);

    cout << "Pokemon 2 de Ash " << endl;
    mostrarPokemon(pokemonNro(2,ash));
    cout << "Pokemon 3 de Gary "<< endl;
    mostrarPokemon(pokemonNro(2,gary));

     cout << "---------------------------------" << endl;

     cout << "Ash le gana a Gary? " << leGanaATodos(ash,gary) << endl;

    return 0;
}
