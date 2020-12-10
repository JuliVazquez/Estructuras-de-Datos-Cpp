#include "ArrayList.h"

struct ArrayListSt {
int cantidad;           // cantidad de elementos
int* elementos;         // array de elementos
int capacidad;          // tamaño del array
};

/*-------------------------------------------------------------------------*/

void imprimirArrayList (ArrayList xs){

    cout << "Arraylist de capacidad: " << xs->capacidad << endl;
    for(int i=0; i< xs->cantidad; i++){

        cout <<"[" << i << "] : " << xs->elementos[i] << endl;
    }
}

ArrayList newArrayList(){

    ArrayList al = new ArrayListSt;
    al->cantidad = 0;
    al->capacidad = 16;
    al->elementos = new int[0];
    return al;
}

ArrayList newArrayListWith(int capacidad){

    ArrayList al = new ArrayListSt;
    al->cantidad = 0;
    al->capacidad = capacidad;
    al->elementos = new int[capacidad];
    return al;
}

int lengthAL(ArrayList xs){

    return xs->cantidad;
}

int get(int i, ArrayList xs){

    return xs->elementos[i];
}


int set(int i, int x, ArrayList xs){

    return xs->elementos[i] = x;
}

void resize(int capacidad, ArrayList xs){

    int* newArray = new int[capacidad];

    if(capacidad < xs->capacidad){
        int contElem = 0;
        for(int i=0; i<capacidad; i++){
            newArray[i] = xs->elementos[i];
            contElem++;
        }
        xs->cantidad = contElem;

    }else{
        for(int i=0; i<xs->cantidad; i++){
            newArray[i] = xs->elementos[i];
        }
    }
    delete[] xs->elementos;
    xs->elementos = newArray;
    xs->capacidad = capacidad;
}

void add(int x, ArrayList xs){

    if(xs->cantidad == xs->capacidad){
        resize(xs->capacidad +1, xs);
    }
    xs->elementos[xs->cantidad] = x;
    xs->cantidad ++;
}

void remove(ArrayList xs){

    xs->cantidad--;
}






