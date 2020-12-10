
#include <iostream>
using namespace std;

struct NodeT;
typedef NodeT* Tree;

/*--------------------------------------------------------------------*/
///Retorna un arbol vacio
Tree emptyT();

///Crea un nodo para un arbol
Tree nodeT(int elem, Tree left, Tree right);

///Describe si el arbol esta vacio
bool isEmptyT(Tree t);

///Retorna el valor del root del arbol
int rootT(Tree t);

///Retorna la rama derecha del arbol
Tree left(Tree t);

///Retorna la rama izquierda del arbol
Tree right(Tree t);
