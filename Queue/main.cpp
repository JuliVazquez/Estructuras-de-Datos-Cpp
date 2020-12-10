#include <iostream>
#include "Queue.h"
using namespace std;


int main()
{
    Queue q = emptyQ();
    enqueue(1,q);
    enqueue(2,q);
    enqueue(3,q);
    mostrarQueue(q);

    //Queue q5 = emptyQ();
    //cout<< firstQ(q5);

    //mostrarQueue(q);
    cout << endl;

    cout << "Dequeue: ";
    dequeue(q);
    mostrarQueue(q);
    cout << endl;

    cout << "LengthQ: " << lengthQ(q) << endl;

    cout << "MergeQ: ";
    Queue q1 = emptyQ();
    enqueue(1,q1);
    enqueue(2,q1);
    enqueue(3,q1);

    Queue q2 = emptyQ();
    enqueue(4,q2);
    enqueue(5,q2);
    enqueue(6,q2);
    mergeQ(q1,q2);

    mostrarQueue(q1);
    cout << endl;

    destroyQ(q);

    cout << endl;
    cout << "Dequeue de vacia" << endl;
    Queue q3 = emptyQ();
    dequeue(q3);
    mostrarQueue(q3);

    return 0;
}
