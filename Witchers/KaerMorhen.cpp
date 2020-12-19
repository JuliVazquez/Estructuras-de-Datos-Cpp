#include "KaerMorhen.h"


struct KaerMorhenSt{
    ArrayList brujos;
};

/*-------------------------------------------------------------------------------*/
void mostrarKaerMorhen(KaerMorhen kaerMorhen){

    imprimirArrayList(kaerMorhen->brujos);
}
/*-------------------------------------------------------------------------------*/
KaerMorhen fundarKaerMorhen(){

    KaerMorhen km = new KaerMorhenSt;
    km->brujos = emptyAL();

    return km;
}
/*-------------------------------------------------------------------------------*/
void recibirBrujos(Witcher brujo, KaerMorhen kaerMorhen){

    add(brujo,kaerMorhen->brujos);
}
/*-------------------------------------------------------------------------------*/
ArrayList nombresDeBrujos(KaerMorhen kaerMorhen){

    ArrayList nombres = emptyAL();
    int i=0;
    while(isValidIndex(i,kaerMorhen->brujos)){
        Witcher brujo = get(i,kaerMorhen->brujos);
        add(brujo,nombres);                    // mi arrayList no es generico, solo es de brujos
        i++;
    }
    return nombres;
}
/*-------------------------------------------------------------------------------*/
int cantContratosResueltos(KaerMorhen kaerMorhen){

    int resultado = 0;
    int i=0;
    while(isValidIndex(i,kaerMorhen->brujos)){
        Witcher brujo = get(i,kaerMorhen->brujos);
        resultado = resultado + contratosResueltos(brujo);      // equivale a resultado += brujo->contratos;
        i++;
    }
    return resultado;

}
/*-------------------------------------------------------------------------------*/
bool fortalezaEscuela(KaerMorhen kaerMorhen){

    int i = 0;
    while(isValidIndex(i,kaerMorhen->brujos)){
        Witcher brujo = get(i,kaerMorhen->brujos);
        if(contratosResueltos(brujo) == 0){
            return true;
        }
        i++;
    }
    return false;
}
/*-------------------------------------------------------------------------------*/
bool esMaestroBrujo(string nombre, KaerMorhen kaerMorhen){

    int i = 0;
    while(isValidIndex(i,kaerMorhen->brujos)){
        Witcher brujo = get(i,kaerMorhen->brujos);
        if(nombreDeBrujo(brujo) == nombre){
            return contratosResueltos(brujo) > 350;
        }
        i++;
    }
    return false;

}
/*-------------------------------------------------------------------------------*/
ArrayList noviciosDeFortaleza(KaerMorhen kaerMorhen){

    int i = 0;
    ArrayList novicios = emptyAL();
    while(isValidIndex(i,kaerMorhen->brujos)){
        Witcher brujo = get(i, kaerMorhen->brujos);
        if(contratosResueltos(brujo) == 0 || escuelaDelBrujo(brujo) != "Lobo"){
            add(brujo, novicios);
        }
        i++;
    }
    return novicios;
}
/*-------------------------------------------------------------------------------*/
void ingresarBrujoLobuno(string nombre, KaerMorhen kaerMorhen){

    Witcher nuevoBrujo = consBrujo(nombre, "Lobo");
    add(nuevoBrujo,kaerMorhen->brujos);
}
/*-------------------------------------------------------------------------------*/
void ingresarContratoDeFortaleza(KaerMorhen kaerMorhen){

    int i = 0;
    while(isValidIndex(i,kaerMorhen->brujos)){
        Witcher brujo = get(i,kaerMorhen->brujos);
        if(contratosResueltos(brujo) > 0){
            agregarContratoResuelto(brujo);
        }
        i++;
    }
}


