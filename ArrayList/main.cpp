#include <iostream>
#include "ArrayList.h"
using namespace std;

///Devuelve la suma de todos los elementos.
int sumatoria(ArrayList xs){

    int sumatoria = 0;
    for(int i=0; i<lengthAL(xs); i++){
        sumatoria = sumatoria + get(i,xs);
    }
    return sumatoria;
}
/*-------------------------------------------------------------------------*/
///Incrementa en uno todos los elementos.
void sucesores(ArrayList xs){

    for(int i=0; i<lengthAL(xs); i++){
        set(i, get(i,xs)+1, xs );
    }
}
/*-------------------------------------------------------------------------*/
///Indica si el elemento pertenece a la lista.
bool pertenece(int x, ArrayList xs){

    int i = 0;
    while(i<lengthAL(xs) && get(i,xs) != x){
        i++;
    }
    return get(i,xs) == x;
}
/*-------------------------------------------------------------------------*/
///Indica la cantidad de elementos iguales a x
int apariciones(int x, ArrayList xs){

    int contador = 0;
    for(int i=0; i<lengthAL(xs); i++){

        if(get(i,xs) == x){
            contador++;
        }
    }
    return contador;
}
/*-------------------------------------------------------------------------*/
ArrayList append(ArrayList xs, ArrayList ys){

    ArrayList newAL = xs;
    for(int i=0; i<lengthAL(ys); i++){
        add(get(i,ys),newAL);
    }
    return newAL;

}
/*-------------------------------------------------------------------------*/
///Devuelve el elemento más chico de la lista.
int minimo(ArrayList xs){

    int minActual = get(1,xs);
    for(int i=0; i<lengthAL(xs); i++){
        minActual = min(minActual, get(i,xs));
    }
    return minActual;
}
/*-------------------------------------------------------------------------*/

int main()
{

    cout << "Probando arrayList :" << endl;

    ArrayList aList = newArrayListWith(4);

    add(1, aList);
    add(2, aList);
    add(3, aList);
    add(4, aList);

    imprimirArrayList(aList);

    remove(aList);
    add(5,aList);
    imprimirArrayList(aList);


    cout << "Resize:" << endl;
    resize(2,aList);
    imprimirArrayList(aList);
    cout << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "USUARIO:" << endl;
    ArrayList aList1 = newArrayListWith(4);
    ArrayList aList2 = newArrayListWith(3);
    add(8, aList1);
    add(3, aList1);
    add(4, aList1);
    add(3, aList1);
    add(1, aList2);
    add(2, aList2);
    add(3, aList2);

    imprimirArrayList(aList1);
    imprimirArrayList(aList2);

    cout << endl;
    cout << "SUMATORIA = " << sumatoria(aList1) << endl;
    cout << "SUMATORIA = " << sumatoria(aList2) << endl;
    cout << endl;
    cout << "SUCESORES AL1 = " << endl;
    sucesores(aList1);
    sucesores(aList2);
    imprimirArrayList(aList1);
    cout << endl;
    cout << "SUCESORES AL2 = " << endl;
    imprimirArrayList(aList2);
    cout << endl;
    cout << "PERTENECE = " << pertenece(9,aList1) << endl;
    cout << "PERTENECE = " << pertenece(4,aList1) << endl;
    cout << "PERTENECE = " << pertenece(99,aList1) << endl;
    cout << endl;
    cout << "APARICIONES = " << apariciones(4,aList1) << endl;
    cout << "APARICIONES = " << apariciones(86,aList1) << endl;

    ArrayList alAppend = append(aList1, aList2);
    imprimirArrayList(alAppend);
    cout <<endl;
    cout << "COPIA" <<endl;
    ArrayList copia = aList1;
    imprimirArrayList(copia);
    cout << endl;
    cout << "MINIMO = " << minimo(alAppend) << endl;




    return 0;
}
