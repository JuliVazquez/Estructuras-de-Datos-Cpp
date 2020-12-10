#include "LinkedList.h"

struct NodoL {
int elem; // valor del nodo
NodoL* siguiente; // puntero al siguiente nodo
};

struct LinkedListSt {
int cantidad; // cantidad de elementos
NodoL* primero; // puntero al primer nodo
NodoL* actual; // puntero al nodo actual (para recorridos)
};
/*-------------------------------------------------------------------------*/

LinkedList nil(){

    LinkedList xs = new LinkedListSt;
    xs->cantidad = 0;
    xs->primero = NULL;
    xs->actual = NULL;

    return xs;
}
/*-------------------------------------------------------------------------*/
bool isEmpty(LinkedList xs){

    return xs->cantidad == 0;
}
/*-------------------------------------------------------------------------*/
int head(LinkedList xs){

    return xs->primero->elem;
}
/*-------------------------------------------------------------------------*/
void cons(int x, LinkedList xs){

    NodoL* newNode = new NodoL;
    newNode->elem = x;
    newNode->siguiente = xs->primero;

    xs->primero = newNode;
    xs->cantidad++;
}
/*-------------------------------------------------------------------------*/
void tail(LinkedList xs){

    xs->cantidad--;
    xs->primero = xs->primero->siguiente;
}
/*-------------------------------------------------------------------------*/
int length(LinkedList xs){

    return xs->cantidad;
}
/*-------------------------------------------------------------------------*/
void snoc(int x, LinkedList xs){

    if(isEmpty (xs)){
        cons(x,xs);

    }else{

        NodoL* nodoActual = xs->primero;             // nodo a procesar
        NodoL* newNode = new NodoL;                  // nuevo nodo
        newNode->elem = x;
        newNode->siguiente = NULL;


        while(nodoActual->siguiente != NULL){       // si el siguiente es null es el ultimo
            nodoActual = nodoActual->siguiente;     // actualizo nodo actual
        }
        nodoActual->siguiente = newNode;            // le asigno un nodo siguiente al ultimo
    }
    xs->cantidad++;
}
/*-------------------------------------------------------------------------*/
void initialize(LinkedList xs){

    xs->actual = xs->primero;
}
/*-------------------------------------------------------------------------*/
int current(LinkedList xs){

    return xs->actual->elem;
}
/*-------------------------------------------------------------------------*/
void setCurrent(int x, LinkedList xs){

    xs->actual->elem = x;
}
/*-------------------------------------------------------------------------*/
void next(LinkedList xs){

    xs->actual = xs->actual->siguiente;

}
/*-------------------------------------------------------------------------*/
bool finished(LinkedList xs){

    return xs->actual == NULL;
}
/*-------------------------------------------------------------------------*/
void destroyL(LinkedList xs){

    while(!isEmpty(xs)){
        tail(xs);
    }
    delete xs;
}












