#include <iostream>
using namespace std;

struct WitcherSt;
typedef WitcherSt* Witcher;

Witcher consBrujo(string nombre, string escuela);

Witcher consBrujoExperimentado(string nombre, string escuela, int contratos);

string nombreDeBrujo(Witcher brujo);

string escuelaDelBrujo(Witcher brujo);

int contratosResueltos(Witcher brujo);

void agregarContratoResuelto(Witcher brujo);

void mostrarBrujo(Witcher x);


