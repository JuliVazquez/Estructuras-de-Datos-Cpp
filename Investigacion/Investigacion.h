#include <iostream>
#include "Persona.h"
#include "ArrayList.h"
using namespace std;

struct InvestigacionSt;
typedef InvestigacionSt* Investigacion;
struct PersonaSt;
typedef PersonaSt* Persona;


///Propósito: crea una investigación sin personas.
Investigacion comenzarInvestigacion();

///Propósito: devuelve los nombres de personas ingresadas.
///Nota: suponer que el ArrayList es de nombres.
ArrayList nombresIngresados(Investigacion investigacion);

///Propósito: devuelve la sumatoria de evidencia de las personas.
int cantEvidenciaDePersonas(Investigacion investigacion);

///Propósito: indica si la investigación posee al menos una persona con al menos 5 evidencias en su contra.
bool casoCerrado(Investigacion investigacion);

///Propósito: indica si esa persona tiene al menos una evidencia en su contra.
///Nota: la persona puede no existir.
///Eficiencia: O(N)
bool esSospechosa(string nombre, Investigacion investigacion);

///Propósito: devuelve a las personas con cero evidencia en su contra.
///Nota: suponer que el ArrayList es de nombres.
ArrayList posiblesInocentes(Investigacion investigacion);

///Propósito: ingresa a personas nuevas a la investigación (mediante sus nombres), sin evidencia en su contra.
///Nota: suponer que el ArrayList es de nombres.
///Precondición: las personas no existen en la investigación y no hay nombres repetidos.
void ingresarPersonas(ArrayList nombres, Investigacion investigacion);

///Propósito: incrementa en uno la evidencia a una lista de personas.
///Precondición: la evidencia aún no está asociada a esa persona.
///Nota 1: la persona y la evidencia existen, pero NO están asociadas.
///Nota 2: suponer que el ArrayList es de nombres.
void ingresarUnaEvidencia(ArrayList nombres, Investigacion investigacion);
