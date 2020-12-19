#include "Witcher.h"
#include "ArrayList.h"
#include <iostream>
using namespace std;
struct KaerMorhenSt;
typedef KaerMorhenSt* KaerMorhen;

///Funda la fortaleza de KaerMorhen
KaerMorhen fundarKaerMorhen();

///Ingresa un brujo a KaerMorhen
void recibirBrujos(Witcher brujo, KaerMorhen kaerMorhen);

void mostrarKaerMorhen(KaerMorhen kaerMorhen);

///Devuelve los nombres de los brujos de KaerMorhen
ArrayList nombresDeBrujos(KaerMorhen kaerMorhen);

///Devuelve el total de contratos resuletos por los brujos de KaerMorhen
int cantContratosResueltos(KaerMorhen kaerMorhen);

///Describe si KaerMorhen es una escuela, es decir, si tiene al menos un brujo sin contratos resueltos.
bool fortalezaEscuela(KaerMorhen kaerMorhen);

///Describe si el brujo es un maestro, o sea, tiene mas de 350 contratos resueltos
bool esMaestroBrujo(string nombre, KaerMorhen kaerMorhen);

///Devuelve los nombres de los novicios de KaerMorhen. Aquellos que no son de la escuela del lobo o
/// que no tienen contratos resueltos.
ArrayList noviciosDeFortaleza(KaerMorhen kaerMorhen);

///Ingresa un brujo nuevos a KaerMorhen.
void ingresarBrujoLobuno(string nombre, KaerMorhen kaerMorhen);

///Incrementa en 1 la cantidad de contratos resueltos de todos los brujos de KaerMorhen a excepcion de los
///iniciados (aquellos que no resolvieron ningun contrato)
void ingresarContratoDeFortaleza(KaerMorhen kaerMorhen);


