#include <iostream>
#include "LinkedList.h"
using namespace std;


void mostrarLinkedList(LinkedList xs){

    initialize(xs);
    cout << "[";
    while(!finished(xs)){
        cout << " " << current(xs);
        next(xs);
    }
    cout << " ]";
}

int main()
{
    LinkedList xs = nil();
    cons(4,xs);
    cons(3,xs);
    cons(2,xs);
    cons(1,xs);
    snoc(0,xs);

    mostrarLinkedList(xs);
    cout << endl;
    cout << "Esta vacia? = " <<isEmpty(xs) << endl;
    cout << "Head = " << head(xs) << endl;
    cout << "Tail: ";
    tail(xs);
    mostrarLinkedList(xs);
    cout << endl;
    cout << "Initialize = ";
    initialize(xs);
    cout << current(xs) << endl;

    return 0;
}
