#include "Investigacion.h"
struct PersonaSt {
string nombre;
int evidencia;
};

struct InvestigacionSt {
ArrayList sospechosos; // lista de Persona
};

/*----------------------------------------------------------------------------------*/

Investigacion comenzarInvestigacion(){

    Investigacion investigacion = new InvestigacionSt;
    investigacion->sospechosos = emptyAL();

    return investigacion;
}
/*----------------------------------------------------------------------------------*/
ArrayList nombresIngresados(Investigacion investigacion){

    int i = 0;
    ArrayList nombres = emptyAL();
    while(isValidIndex(i,investigacion->sospechosos)){
        Persona pActual = get(i,investigacion->sospechosos);
        add(pActual->nombre, nombres);
        i++;
    }
    return nombres;
}
/*----------------------------------------------------------------------------------*/
int cantEvidenciaDePersonas(Investigacion investigacion){

    int contador = 0;
    int i = 0;
    while(isValidIndex(i,investigacion->sospechosos)){
        Persona pActual = get(i,investigacion->sospechosos);
        contador = contador + pActual->evidencia;
        i++;
    }
    return contador;
}
/*----------------------------------------------------------------------------------*/
bool casoCerrado(Investigacion investigacion){

    int i = 0;
    while(isValidIndex(i,investigacion->sospechosos)){
        Persona pActual = get(i,investigacion->sospechosos);
        if(pActual->evidencias >=5){
            return true;
        }
        i++;
    }
    return false;
}

/*----------------------------------------------------------------------------------*/
bool esSospechosa(string nombre, Investigacion investigacion){

    int i = 0;
    while(isValidIndex(i,investigacion->sospechosos)){
        Persona pActual = get(i,investigacion->sospechosos);
        if(pActual->nombre == nombre){
            return pActual->evidencias > 0;
        }
        i++;
    }
    return false;
}
/*----------------------------------------------------------------------------------*/
ArrayList posiblesInocentes(Investigacion investigacion){

    ArrayList inocentes = emptyAL();
    int i = 0;
    while(isValidIndex(i,investigacion->sospechosos)){
        Persona pActual = get(i,investigacion->sospechosos);
        if(pActual->evidencias == 0){
            add(pActual->nombre, inocentes);
        }
    }
    return inocentes;
}
/*----------------------------------------------------------------------------------*/
void ingresarPersonas(ArrayList nombres, Investigacion investigacion){

    int i = 0;
    while(isValidIndex(i,nombres)){
        Persona pNueva = new PersonaSt;
        pNueva->nombre = get(i,nombres);
        pNueva->evidencias = 0;
        add(pNueva,investigacion->sospechosos);
        i++;
    }
}
/*----------------------------------------------------------------------------------*/
bool perteneceANombresAL (string nombre, ArrayList nombres){

    int i = 0;
    while(isValidIndex(i,nombres)){
        string nombreActual = get(i,nombres);
        if(nombreActual == nombre){
            return true;
        }
        i++;
    }
    return false;
}

void ingresarUnaEvidencia(ArrayList nombres, Investigacion investigacion){

    int i = 0;
    while(isValidIndex(i,investigacion->sospechosos)){
        Persona pActual = get(i, investigacion->sospechosos);
        if(perteneceANombresAL (pActual->nombre, nombres)){
            pActual->evidencias ++;
        }
        i++;
    }
}
