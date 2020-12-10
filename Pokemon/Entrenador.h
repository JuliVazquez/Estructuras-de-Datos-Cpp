#include "Pokemon.h"

struct EntrenadorSt;
typedef EntrenadorSt* Entrenador;

/*-------------------------------------------------------------------------*/
///Dado un nombre, una cantidad de pokemones, y un array de pokemones de ese tam,
///devuelve un entrenador.
Entrenador consEntrenador(string nombre, int cantidad, Pokemon* pokemones);

///Devuelve el nombre del entrenador.
string nombreDeEntrenador(Entrenador e);

///Devuelve la cantidad de pokemon que posee el entrenador.
int cantidadDePokemon(Entrenador e);

///Devuelve la cantidad de pokemon de determinado tipo que posee el entrenador.
int cantidadDePokemonDe(TipoDePokemon tipo, Entrenador e);

///Devuelve el pokemon número i de los pokemones del entrenador.
///Precondicion: existen al menos i − 1 pokemones.
Pokemon pokemonNro(int i, Entrenador e);

///Dados dos entrenadores, indica si, para cada pokemon del segundo entrenador, el primero
///posee al menos un pokemon que le gane.
bool leGanaATodos(Entrenador e1, Entrenador e2);
