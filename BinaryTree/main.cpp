#include <iostream>
#include "Tree.h"
#include "ArrayList.h"
#include "Queue.h"
using namespace std;

///Dado un arbol binario de enteros devuelve la suma entre sus elementos.
int sumarT(Tree t){

    if(isEmptyT(t)){
        return 0;

    }else{
        return rootT(t) + sumarT(left(t)) + sumarT(right(t));
    }
}
/*-------------------------------------------------------------------------*/
///Dado un arbol binario devuelve su cantidad de elementos, es decir, el tam del arbol
int sizeT(Tree t){

    if(isEmptyT(t)){
        return 0;

    }else{
        return 1 + sizeT(left(t)) + sizeT(right(t));
    }
}
/*-------------------------------------------------------------------------*/
///Dados un elemento y un arbol binario devuelve True si existe un elemento igual a ese en el arbol.
bool perteneceT(int e, Tree t){

    if(isEmptyT(t)){
        return false;

    }else{
        return (rootT(t) == e) || perteneceT(e, left(t)) || perteneceT(e, right(t));
    }
}
/*-------------------------------------------------------------------------*/
int aparicionesEnRoot(int e, Tree t){

    if(e == rootT(t)){
        return 1;
    }
    else{
        return 0;
    }
}

///Dados un elemento e y un arbol binario devuelve la cantidad de elementos del arbol que son iguales a e.
int aparicionesT(int e, Tree t){

    if(isEmptyT(t)){
        return 0;

    }else{
        return aparicionesEnRoot(e,t) + aparicionesT(e, left(t)) + aparicionesT(e, right(t));
    }
}
/*-------------------------------------------------------------------------*/
///Dado un arbol devuelve su altura.
int heightT(Tree t){

    if(isEmptyT(t)){
        return 0;

    }else{
        return 1 + max( heightT(left(t)) , heightT(right(t)) );
    }
}
/*-------------------------------------------------------------------------*/
ArrayList append(ArrayList xs, ArrayList ys){

    ArrayList newAL = xs;
    for(int i=0; i<lengthAL(ys); i++){
        add(get(i,ys),newAL);
    }
    return newAL;
}

ArrayList toList(Tree t){

    ArrayList aList = newArrayList();

    if(isEmptyT(t)){
        return aList;

    }else{
        add(rootT(t),aList);
        return append(append(aList, toList(left(t))) , toList(right(t)));
        // append(arrayList, toLis(left(t)))
        // append (lista, lista)
    }
}
/*-------------------------------------------------------------------------*/
bool esHoja (Tree t){

    return isEmptyT(left(t)) && isEmptyT(right(t));
}

ArrayList leaves(Tree t){

    ArrayList aList = newArrayList();

    if(isEmptyT(t)){
        return aList;

    }else{
         if(esHoja(t)){

            add(rootT(t), aList);
            return append(append(aList, leaves(left(t))) , leaves(right(t)));

         }else{
             return append( leaves(left(t)) , leaves(right(t)) );
         }
    }
}
/*-------------------------------------------------------------------------*/
ArrayList levelN(int n, Tree t){

    ArrayList al = newArrayList();

    if(isEmptyT(t) && n >(heightT(t)-1)){
        return al;
    }
    else{
        if(n == 0){
            add(rootT(t),al);
            //return append(append(al, levelN(n-1,left(t))) , levelN(n-1,right(t)));
            return al;

        }else{
             return append( levelN(n-1,left(t)) , levelN(n-1,right(t)) );
        }
    }
}
/*-------------------------------------------------------------------------*/
// CON RECORRIDOS BFS
///Dado un arbol binario de enteros devuelve la suma entre sus elementos.
int sumarTBFS(Tree t){

    if(isEmptyT(t)){
        return 0;
    }
    else{
        int resultado = 0;                              // inicializo resultado
        Queue nodosPendientes = emptyQ();               // cola vacia, son los nodos pendientes
        Tree nodoActual = t;                            // nodoActual
        enqueue(nodoActual, nodosPendientes);

        while(!isEmptyQ(nodosPendientes)){                  // repito hasta que la cola este vacia

            nodoActual = firstQ(nodosPendientes);           // asigno nodo actual
            resultado = resultado + rootT(nodoActual);      // proceso del nodo
            dequeue(nodosPendientes);                       // lo procese, lo saco

            if(!isEmptyT(left(nodoActual))){                // agrego hijo izquierdo
                enqueue(left(nodoActual),nodosPendientes);
            }
             if(!isEmptyT(right(nodoActual))){              // agrego hijo derecho
                enqueue(right(nodoActual),nodosPendientes);
            }
        }
        return resultado;
    }
}
/*--------------------------------------------------------------------------------------------------------*/
///Dado un arbol binario devuelve su cantidad de elementos, es decir, el tamaño del árbol (size en inglés).
int sizeTBFS(Tree t){

    if(isEmptyT(t)){
        return 0;

    }else{
        int resultado = 0;
        Queue nodosPendiente = emptyQ();
        Tree nodoActual = t;
        enqueue(nodoActual,nodosPendiente);

        while(!isEmptyQ(nodosPendiente)){

            nodoActual = firstQ(nodosPendiente);
            resultado++;
            dequeue(nodosPendiente);

            if(!isEmptyT(left(nodoActual))){

                enqueue(left(nodoActual),nodosPendiente);
            }
             if(!isEmptyT(right(nodoActual))){

                enqueue(right(nodoActual),nodosPendiente);
            }

        }
        return resultado;
    }
}
/*--------------------------------------------------------------------------------------------------------*/
///Dados un elemento y un árbol binario devuelve True si existe un elemento igual a ese en el árbol.
bool perteneceTBFS(int e, Tree t){

    if(isEmptyT(t)){
        return false;
    }
    else{

        int pertenece = false;
        Queue nodosPendientes = emptyQ();
        Tree nodoActual = t;
        enqueue(nodoActual, nodosPendientes);

        while(!isEmptyQ(nodosPendientes)){

            nodoActual = firstQ(nodosPendientes);

            pertenece = pertenece || (rootT(nodoActual) == e);

            dequeue(nodosPendientes);

            if(!isEmptyT(left(nodoActual))){

                enqueue(left(nodoActual),nodosPendientes);
            }
             if(!isEmptyT(right(nodoActual))){

                enqueue(right(nodoActual),nodosPendientes);
            }

        }
        return pertenece;
    }
}

/*--------------------------------------------------------------------------------------------------------*/
///Dados un elemento e y un árbol binario devuelve la cantidad de elementos del árbol que son iguales a e.
int aparicionesTBFS(int e, Tree t){

    if(isEmptyT(t)){
        return 0;
    }
    else{
        int vecesVisto = 0;
        Queue nodosPendientes = emptyQ();
        Tree nodoActual = t;
        enqueue(nodoActual, nodosPendientes);

        while(!isEmptyQ(nodosPendientes)){

            nodoActual = firstQ(nodosPendientes);
            if(rootT(nodoActual) == e){
                vecesVisto++;
            }

            dequeue(nodosPendientes);

            if(!isEmptyT(left(nodoActual))){

                enqueue(left(nodoActual),nodosPendientes);
            }
             if(!isEmptyT(right(nodoActual))){

                enqueue(right(nodoActual),nodosPendientes);
            }
        }
        return(vecesVisto);
    }
}
/*--------------------------------------------------------------------------------------------------------*/
///Dado un árbol devuelve una lista con todos sus elementos
ArrayList toListBFS(Tree t){

    ArrayList al = newArrayList();

    if(isEmptyT(t)){
        return al;
    }
    else{
        Queue nodosPendientes = emptyQ();
        Tree nodoActual = t;
        enqueue(nodoActual, nodosPendientes);

        while(!isEmptyQ(nodosPendientes)){

            nodoActual = firstQ(nodosPendientes);
            add(rootT(nodoActual),al);
            dequeue(nodosPendientes);

            if(!isEmptyT(left(nodoActual))){

                enqueue(left(nodoActual),nodosPendientes);
            }
             if(!isEmptyT(right(nodoActual))){

                enqueue(right(nodoActual),nodosPendientes);
            }
        }
        return al;
    }
}
/*--------------------------------------------------------------------------------------------------------*/
int main()
{
    Tree t1 = nodeT(1,
                    (nodeT(5,
                           emptyT(),
                           emptyT())),
                    (nodeT(4,
                           emptyT(),
                           emptyT()
                           ))
                    );

    Tree t2 = nodeT(7,
                (nodeT(5,
                       emptyT(),
                       emptyT())),
                (nodeT(4,
                       nodeT(7,
                             emptyT(),
                             emptyT()),
                       emptyT()
                       ))
                );


    cout << "SUMAR T1 = " << sumarT(t1) << endl;
    cout << "SUMAR T2 = " << sumarT(t2) << endl;
    cout << endl;
    cout << "SIZE T1 = " << sizeT(t1) << endl;
    cout << "SIZE T2 = " << sizeT(t2) << endl;
    cout << endl;
    cout << "PERTENECE 7 T2 = " << perteneceT(7,t2) << endl;
    cout << "PERTENECE 8 T2 = " << perteneceT(8,t2) << endl;
    cout << endl;
    cout << "APARCIONES 7 T2 = " << aparicionesT(7,t2) << endl;
    cout << "APARCIONES 9 T2 = " << aparicionesT(9,t2) << endl;
    cout << endl;
    cout << "HEIGHT T1 = " << heightT(t1) << endl;
    cout << "HEIGHT T2 = " << heightT(t2) << endl;
    cout << endl;
    cout << "ToList" << endl;
    ArrayList aList = toList(t2);
    imprimirArrayList(aList);
    cout << endl;
    cout << "Leaves" << endl;
    ArrayList alLeave = leaves(t2);
    imprimirArrayList(alLeave);

    cout << endl;
    cout << "Lvl 1" << endl;
    //ArrayList alLvl1 = levelN(1,t2);
    //imprimirArrayList(levelN(1,t2));
    ArrayList alLvl1 = levelN(1,t2);
    imprimirArrayList(alLvl1);

    cout << endl;
    cout << "Lvl 0" << endl;
    //ArrayList alLvl0 = levelN(0,t2);
    //imprimirArrayList(levelN(0,t2));
    ArrayList alLvl0 = levelN(0,t2);
    imprimirArrayList(alLvl0);

    cout <<"--------------------------------------------------------------------------"<< endl;
    cout << endl;
    cout << "RECORRIDOS BFS" << endl;
    Tree t3 = nodeT(7,
                (nodeT(5,
                       emptyT(),
                       emptyT())),
                (nodeT(4,
                       nodeT(7,
                             emptyT(),
                             emptyT()),
                       emptyT()
                       ))
                );

    cout << "sumarTBFS = " << sumarTBFS(t3) << endl;
    cout << "sizeTBFS = " << sizeTBFS(t3) << endl;
    cout << "Pertenece el 5 ? " << perteneceTBFS(5,t3) << endl;
    cout << "Pertenece el 7 ? " << perteneceTBFS(7,t3) << endl;
    cout << "Pertenece el 89 ? " << perteneceTBFS(89,t3) << endl;
    cout << endl;
    cout << endl;
    cout << "Apariciones de 7 " << aparicionesTBFS(7, t3) << endl;
    cout << "Apariciones de 99 " << aparicionesTBFS(99, t3) << endl;
    cout << endl;
    cout << "ArrayListBFS:" << endl;
    imprimirArrayList(toListBFS(t3));

    cout << endl;
    cout <<"EXITO";

    return 0;
}
