#include "Queue.h"

struct NodoQ {
Tree elem;           // valor del nodo
NodoQ* siguiente;   // puntero al siguiente nodo
};

struct QueueSt {
int cantidad; // cantidad de elementos
NodoQ* primero; // puntero al primer nodo
NodoQ* ultimo; // puntero al ultimo nodo
};

/*-------------------------------------------------------------------------*/
Queue emptyQ(){

    Queue q = new QueueSt;
    q->cantidad = 0;
    q->primero = NULL;
    q->ultimo = NULL;

    return q;
}
/*-------------------------------------------------------------------------*/
bool isEmptyQ(Queue q){

    return q->cantidad == 0;
}

/*-------------------------------------------------------------------------*/
Tree firstQ(Queue q){

    return q->primero->elem;
}
/*-------------------------------------------------------------------------*/
void enqueue(Tree x, Queue q){

    NodoQ* nuevoNodo = new NodoQ;
    nuevoNodo->elem = x;
    nuevoNodo->siguiente = NULL;

    if(isEmptyQ(q)){
        q->primero = nuevoNodo;
        q->ultimo = nuevoNodo;

    }

    q->ultimo->siguiente = nuevoNodo;
    q->ultimo = nuevoNodo;
    q->cantidad++;

}
/*-------------------------------------------------------------------------*/
void dequeue(Queue q){

    if(!isEmptyQ(q)){
        q->primero = q->primero->siguiente;

        if(q->cantidad == 1){
            q->ultimo = NULL;
        }
        q->cantidad--;
    }
}
/*-------------------------------------------------------------------------*/
int lengthQ(Queue q){

    return q->cantidad;
}
/*-------------------------------------------------------------------------*/
void mergeQ(Queue q1, Queue q2){

    NodoQ* nodoActual = q2->primero;
    while(!isEmptyQ(q2)){
        enqueue(nodoActual->elem, q1);
        dequeue(q2);
    }
}
/*-------------------------------------------------------------------------*/
void destroyQ(Queue q){

    while(!isEmptyQ(q)){
    dequeue(q);
    }
    delete q;
}
/*-------------------------------------------------------------------------*/
void mostrarQueue(Queue q){
    NodoQ* nodoActual = q->primero;
    cout << "[";
    while(nodoActual != NULL){
        cout << " " << nodoActual->elem;
        nodoActual = nodoActual->siguiente;
    }
    cout << " ]";
}
