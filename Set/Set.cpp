#include "Set.h"

struct NodoS {
int elem; // valor del nodo
NodoS* siguiente; // puntero al siguiente nodo
};

struct SetSt {
int cantidad; // cantidad de elementos diferentes
NodoS* primero; // puntero al primer nodo
};

/*-------------------------------------------------------------------------*/
Set emptyS(){

    Set s = new SetSt;
    s->cantidad = 0;
    s->primero = NULL;

    return s;
}
/*-------------------------------------------------------------------------*/
bool isEmptyS(Set s){

    return s->cantidad == 0;
}
/*-------------------------------------------------------------------------*/
bool belongsS(int x, Set s){

    if(s->cantidad>0){

        int cant = s->cantidad;
        NodoS* nodoActal = s->primero;
        while(cant > 0 && nodoActal->elem != x){
            nodoActal = nodoActal->siguiente;
            cant--;
        }

        return cant > 0 && nodoActal->elem == x;
    }
    else{
        return false;
    }
}
/*-------------------------------------------------------------------------*/
void addS(int x, Set s){

    if(!belongsS(x,s)){

        NodoS* newNode = new NodoS;
        newNode->elem = x;
        newNode->siguiente = s->primero;

        s->primero = newNode;
        s->cantidad ++;
    }
}
/*-------------------------------------------------------------------------*/
void removeS(int x, Set s){

    if(belongsS(x,s)){

        if(s->primero->elem == x){

                s->primero = s->primero->siguiente;
                s->cantidad--;

        }else{
                NodoS* nodoActual = s->primero;         // al prinipio ambos son primero y previo
                NodoS* nodoPrevio = s->primero;

                while(nodoActual->elem != x){
                    nodoPrevio = nodoActual;
                    nodoActual = nodoActual->siguiente;
                }
                nodoPrevio->siguiente = nodoActual->siguiente;  // el siguiente del anterior es el siguiente del que no va
                s->cantidad--;
                delete nodoActual;
        }
    }
}
/*-------------------------------------------------------------------------*/
int sizeS(Set s){

    return s->cantidad;
}
/*-------------------------------------------------------------------------*/
LinkedList setToList(Set s){

    LinkedList xs = nil();
    NodoS* nodoActual = s->primero;

    for(int i=0; i<s->cantidad; i++){
        cons(nodoActual->elem, xs);
        nodoActual = nodoActual->siguiente;
    }
    return xs;
}
/*-------------------------------------------------------------------------*/
void destroyS(Set s){

    NodoS* nodoActual = s->primero;

    while(s->primero!= NULL){
        removeS(nodoActual->elem, s);
        nodoActual = nodoActual->siguiente;
    }
    delete nodoActual;
}
/*-------------------------------------------------------------------------*/
void mostrarSet(Set s){

    NodoS* nActual = s->primero;
    cout <<"[";
    for(int i=0; i< s->cantidad; i++){
       cout <<" "<< nActual->elem;
       nActual = nActual->siguiente;
    }
    cout << " ]" << endl;
}
