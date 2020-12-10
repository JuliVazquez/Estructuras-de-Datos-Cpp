
#include <iostream>
using namespace std;

struct LinkedListSt;
typedef LinkedListSt* LinkedList;

/*-------------------------------------------------------------------------*/
///Crea una lista vacía.
LinkedList nil();

///Indica si la lista está vacía.
bool isEmpty(LinkedList xs);

///Devuelve el primer elemento.
int head(LinkedList xs);

///Agrega un elemento al principio de la lista.
void cons(int x, LinkedList xs);

///Quita el primer elemento.
void tail(LinkedList xs);

///Devuelve la cantidad de elementos.
int length(LinkedList xs);

///Devuelve la cantidad de elementos.
void snoc(int x, LinkedList xs);

///Apunta el recorrido al primer elemento.
void initialize(LinkedList xs);

///Devuelve el elemento actual en el recorrido.
int current(LinkedList xs);

///Reemplaza el elemento actual por otro elemento.
void setCurrent(int x, LinkedList xs);

///Pasa al siguiente elemento.
void next(LinkedList xs);

///Indica si el recorrido ha terminado.
bool finished(LinkedList xs);

///Libera la memoria ocupada por la lista.
void destroyL(LinkedList xs);

void mostrarLinkedList(LinkedList xs);
