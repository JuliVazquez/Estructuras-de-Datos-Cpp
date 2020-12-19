#include "ArrayList.h"

struct ArrayListSt{

    Witcher* brujos;
    int nextIndex;
    int capacidad;
};

ArrayList emptyAL(){

    ArrayList al = new ArrayListSt;

    al->brujos = new Witcher[0];
    al->nextIndex = 0;
    al->capacidad = 3;

    return al;
}

void imprimirArrayList (ArrayList xs){
    cout << "Capacidad AL: "<< xs->capacidad << endl;
    for(int i=0; i< xs->nextIndex; i++){

        cout <<"[" << i << "] : ";
        mostrarBrujo(xs->brujos[i]);
    }
}

void add(Witcher brujo, ArrayList xs){

    if(xs->capacidad == xs->nextIndex){
        resize(xs->capacidad+1,xs);
    }

    xs->brujos[xs->nextIndex] = brujo;
    xs->nextIndex++;
}

Witcher get(int i, ArrayList xs){

    return xs->brujos[i];

}


void set(int i, Witcher nuevoW, ArrayList xs){

    xs->brujos[i] = nuevoW;

}

bool isValidIndex(int i, ArrayList xs){

    return i< xs->nextIndex;
}

void resize(int capacidad, ArrayList xs){

    Witcher* arrayW = new Witcher[capacidad];

    if(capacidad > xs->capacidad){
        for(int i=0; i<xs->nextIndex; i++){
        arrayW[i] = xs->brujos[i];
        }
    }else{
        int contE = 0;
        while(contE <capacidad){
            arrayW[contE] = xs->brujos[contE];
            contE ++;
        }
        xs->nextIndex = contE;
    }

    delete[] xs->brujos;
    xs->brujos = arrayW;
    xs->capacidad = capacidad;

}
