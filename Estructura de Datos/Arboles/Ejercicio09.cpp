/*
Encuentre el mayor elemento de un ABB por los 2 métodos siguientes:
Buscando el mayor iterativamente solamente por el lado correcto, 
buscando el mayor recursivamente solo por el lado correcto.
*/
#include <iostream>
using namespace std;

struct NodoArbol
{
    int info;
    NodoArbol *hi;
    NodoArbol *hd;
};
typedef NodoArbol *arbol;

void inserta(arbol &abb, int x);
bool empty(arbol abb);
int mayorR(arbol abb);
int mayorI(arbol abb);

int main()
{
    arbol abb = NULL;
    int n, x;

    cout << "Numero de elementos: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Elemento: ";
        cin >> x;
        inserta(abb, x);
    }

    cout << "El mayor Recursivamente: " << mayorR(abb) << endl;
    cout << "El mayor Iterativamente: " << mayorI(abb) << endl;

    system("pause");
    return 0;
}

void inserta(arbol &abb, int x)
{
    if (empty(abb))
    {
        abb = new NodoArbol;
        abb->info = x;
        abb->hi = NULL;
        abb->hd = NULL;
    }
    else if (x < abb->info)
        inserta(abb->hi, x);
    else if (x > abb->info)
        inserta(abb->hd, x);
}

int mayorR(arbol abb)
{
    if (!empty(abb->hd))
        return mayorR(abb->hd);
    else
        return abb->info;
}

bool empty(arbol abb)
{
    return (abb == NULL) ? true : false;
}

int mayorI(arbol abb)
{
    arbol aux = abb;

    while (!empty(aux))
    {
        if (aux->hd == NULL)
            return aux->info;
        aux = aux->hd;
    }
}