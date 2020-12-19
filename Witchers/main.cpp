#include <iostream>
#include "Witcher.h"
#include "ArrayList.h"
#include "KaerMorhen.h"
using namespace std;

int cantidadDeNovicios(KaerMorhen kaerMorhen){

    int i = 0;
    ArrayList novicios = noviciosDeFortaleza(kaerMorhen);
    while(isValidIndex(i,novicios)){
        i++;
    }
    return i;
}
/*------------------------------------------------------------------*/


int main()
{
    Witcher ciri = consBrujo("Cirilla", "Lobo");
    //agregarContratoResuelto(ciri);
    //agregarContratoResuelto(ciri);
    //agregarContratoResuelto(ciri);
    Witcher geralt = consBrujoExperimentado("Geralt de Rivia", "Lobo", 652);
    Witcher vesemir = consBrujoExperimentado("Vesemir", "Lobo", 1024);
    Witcher eskel = consBrujoExperimentado("Eskel", "Lobo", 300);
    Witcher lambert = consBrujoExperimentado("Lambert", "Lobo", 211);
    Witcher letho = consBrujoExperimentado("Letho", "Manticora", 315);

/*
    mostrarBrujo(ciri);
    mostrarBrujo(vesemir);

    ArrayList brujos = emptyAL();
    imprimirArrayList(brujos);
    add(ciri, brujos);
    add(geralt, brujos);
    add(vesemir,brujos);
    imprimirArrayList(brujos);

    //set(2,eskel,brujos);
    //mostrarBrujo(get(2,brujos));

    //cout << "Es valido el 0    " << isValidIndex(0,brujos) << endl;
    //cout << "Es valido el 1    " << isValidIndex(1,brujos) << endl;
    //cout << "Es valido el 2    " << isValidIndex(2,brujos) << endl;
    //cout << "Es valido el 3    " << isValidIndex(3,brujos) << endl;
    //cout << "Es valido el 4    " << isValidIndex(4,brujos) << endl;

    cout << endl;
    //resize(2,brujos);
    add(eskel,brujos);
    add(lambert,brujos);
    add(letho,brujos);

    imprimirArrayList(brujos);

*/

    KaerMorhen km = fundarKaerMorhen();
    recibirBrujos(ciri,km);
    recibirBrujos(geralt,km);
    recibirBrujos(vesemir,km);
    recibirBrujos(eskel,km);
    recibirBrujos(lambert,km);
    recibirBrujos(letho,km);
    mostrarKaerMorhen(km);

    cout << endl;
    //cout << "Nombres: "<< endl;
    //imprimirArrayList(nombresDeBrujos(km));
    cout << "Contratos resueltos en Kaer Morhen: " << cantContratosResueltos(km) << endl;

    cout << endl;
    cout << "Kaer Morhen es escuela? : " << fortalezaEscuela(km) << endl;

    cout << endl;
    cout << "Eskel maestro? : " << esMaestroBrujo("Eskel",km) << endl;

    cout << endl;
    cout << "Geralt maestro? : " << esMaestroBrujo("Geralt de Rivia",km) << endl;

    cout << endl;
    cout << "Novicios de lobo" << endl;
    imprimirArrayList(noviciosDeFortaleza(km));

    cout << endl;
    ingresarBrujoLobuno("Jaskier",km);
    ingresarBrujoLobuno("Zoltan",km);
    mostrarKaerMorhen(km);

    cout << "Post contrato de fortaleza" << endl;
    ingresarContratoDeFortaleza(km);
    mostrarKaerMorhen(km);

    return 0;
}
