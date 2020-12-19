#include <iostream>
#include "Investigacion.h"

using namespace std;

int cantidadDeInocentes(Investigacion investigacion){

    int i = 0;
    ArrayList inocentes = posiblesInocentes(investigacion);
    while(isValidIndex(i,inocentes)){
        i++;
    }
    return i;
}
/*-------------------------------------------------------------------------------------*/
bool seCierraSiSeAñadenEstasEvidencias(int evidencias, Investigacion investigacion){

    int i = 0;
    while(i<evidencias){
        ingresarUnaEvidencia(nombresIngresados(investigacion), investigacion);
        i++;
    }
    return casoCerrado;
}
/*-------------------------------------------------------------------------------------*/
bool todasInocentes(Investigacion investigacion){

    return cantEvidenciaDePersonas(investigacion) == 0;
}
/*-------------------------------------------------------------------------------------*/


int main()
{

    return 0;
}
