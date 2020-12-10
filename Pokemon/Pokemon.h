#include <iostream>
using namespace std;

struct PokemonSt;
typedef string TipoDePokemon;
typedef PokemonSt*Pokemon;

/*-------------------------------------------------------------------------*/
///Muestra un pokemon completo
void mostrarPokemon (Pokemon p);

///Dado un tipo devuelve un pok�mon con 100 % de energ�a.
Pokemon consPokemon(string nombre ,TipoDePokemon tipo);

///Devuelve el tipo de un pokemon.
TipoDePokemon tipoDePokemon(Pokemon p);

///Devuelve el porcentaje de energ�a.
int energia(Pokemon p);

///Le resta energ�a al pok�mon.
void perderEnergia(int energia, Pokemon p);

///Dados dos pok�mon indica si el primero, en base al tipo, es superior al segundo. Agua supera
///a fuego, fuego a planta y planta a agua. Y cualquier otro caso es falso.
bool superaA(Pokemon p1, Pokemon p2);

