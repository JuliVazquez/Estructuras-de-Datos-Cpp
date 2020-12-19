#include <iostream>
#include "Persona.h"
#include "ArrayList.h"
using namespace std;

struct InvestigacionSt;
typedef InvestigacionSt* Investigacion;
struct PersonaSt;
typedef PersonaSt* Persona;


///Prop�sito: crea una investigaci�n sin personas.
Investigacion comenzarInvestigacion();

///Prop�sito: devuelve los nombres de personas ingresadas.
///Nota: suponer que el ArrayList es de nombres.
ArrayList nombresIngresados(Investigacion investigacion);

///Prop�sito: devuelve la sumatoria de evidencia de las personas.
int cantEvidenciaDePersonas(Investigacion investigacion);

///Prop�sito: indica si la investigaci�n posee al menos una persona con al menos 5 evidencias en su contra.
bool casoCerrado(Investigacion investigacion);

///Prop�sito: indica si esa persona tiene al menos una evidencia en su contra.
///Nota: la persona puede no existir.
///Eficiencia: O(N)
bool esSospechosa(string nombre, Investigacion investigacion);

///Prop�sito: devuelve a las personas con cero evidencia en su contra.
///Nota: suponer que el ArrayList es de nombres.
ArrayList posiblesInocentes(Investigacion investigacion);

///Prop�sito: ingresa a personas nuevas a la investigaci�n (mediante sus nombres), sin evidencia en su contra.
///Nota: suponer que el ArrayList es de nombres.
///Precondici�n: las personas no existen en la investigaci�n y no hay nombres repetidos.
void ingresarPersonas(ArrayList nombres, Investigacion investigacion);

///Prop�sito: incrementa en uno la evidencia a una lista de personas.
///Precondici�n: la evidencia a�n no est� asociada a esa persona.
///Nota 1: la persona y la evidencia existen, pero NO est�n asociadas.
///Nota 2: suponer que el ArrayList es de nombres.
void ingresarUnaEvidencia(ArrayList nombres, Investigacion investigacion);
