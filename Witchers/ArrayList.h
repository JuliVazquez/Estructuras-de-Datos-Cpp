#include <iostream>
#include "Witcher.h"
using namespace std;

struct ArrayListSt;
typedef ArrayListSt* ArrayList;

ArrayList emptyAL();

void imprimirArrayList (ArrayList xs);

void add(Witcher brujo, ArrayList xs);

Witcher get(int i, ArrayList xs);

void set(int i, Witcher nuevoW, ArrayList xs);

bool isValidIndex(int i, ArrayList xs);

void resize(int capacidad, ArrayList xs);
