#include <iostream>
#include "LinkedList.h"
#include "Set.h"
using namespace std;

int main()
{
    Set s = emptyS();
    cout << "Esta Vacio?  " <<isEmptyS(s) << endl;
    addS(1,s);
    addS(2,s);
    addS(3,s);
    addS(4,s);
    mostrarSet(s);
    cout << "Pertenece el 2? "<<belongsS(2,s) << endl;
    cout << "Pertenece el 5? "<<belongsS(5,s) << endl;
    cout << "Eliminamos el elemnto 4 y el 89 (que no existe)" << endl;
    removeS(89,s);
    removeS(4,s);
    mostrarSet(s);
    cout << "-------------------------------------------" << endl;
    cout << "Pasamos este set : ";
    mostrarSet(s);
    LinkedList xs = setToList(s);
    cout << "A esta LinkedList : ";
    mostrarLinkedList(xs);

    cout << endl;
    cout << "DESTRUCCION! : " << endl;

    destroyS(s);
    mostrarSet(s);
    cout <<"SIZE:" <<sizeS(s) << endl;
    cout << "Esta Vacio?  " <<isEmptyS(s) << endl;

    addS(1,s);
    mostrarSet(s);
    cout << "Esta Vacio?  " <<isEmptyS(s) << endl;
    cout <<"SIZE:" <<sizeS(s) << endl;

    return 0;
}
