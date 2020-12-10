
#include <iostream>
using namespace std;

struct ArrayListSt;
typedef ArrayListSt* ArrayList;
/*-------------------------------------------------------------------------*/
///Imprime un arrayList
void imprimirArrayList (ArrayList xs);

///Crea una lista con 0 elementos.
///Nota: empezar el array list con capacidad 16.
ArrayList newArrayList();

///Crea una lista con 0 elementos y una capacidad dada por par�metro.
ArrayList newArrayListWith(int capacidad);

///Devuelve la cantidad de elementos existentes.
int lengthAL(ArrayList xs);

///Devuelve el i�simo elemento de la lista.
int get(int i, ArrayList xs);

///Reemplaza el i�simo elemento por otro dado.
int set(int i, int x, ArrayList xs);

///Decrementa o aumenta la capacidad del array.
///Nota: en caso de decrementarla, se pierden los elementos del final de la lista.
void resize(int capacidad, ArrayList xs);

///Agrega un elemento al final de la lista.
void add(int x, ArrayList xs);

///Borra el �ltimo elemento de la lista.
void remove(ArrayList xs);
