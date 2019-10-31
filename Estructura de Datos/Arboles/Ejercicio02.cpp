//En un ABB muestre el camino que se debe seguir para llegar a un nodo determinado.
#include <iostream>
using namespace std;

struct NodoArbol
{
    int info;
    NodoArbol *hi;
    NodoArbol *hd;
};
typedef NodoArbol *arbol;

