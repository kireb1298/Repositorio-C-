//Dado un ABB, cree una copia de él.

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
void preOrden(arbol abb, arbol &b);
void preOrden(arbol abb);
bool empty(arbol abb);

int main()
{
    arbol a = NULL, b = NULL;
    int x, n;

    cout << "Cantidad de elementos: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Elemento: ";
        cin >> x;
        inserta(a, x);
    }

    cout << "Elementos que seran copiados: " << endl;
    preOrden(a, b);
    cout << endl;

    cout << "Elementos del nuevo arbol: " << endl;
    preOrden(b);
    cout << endl;

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

void preOrden(arbol abb, arbol &b)
{
    if (!empty(abb))
    {
        cout << abb->info << " ";
        inserta(b, abb->info);
        preOrden(abb->hi, b);
        preOrden(abb->hd, b);
    }
}

void preOrden(arbol abb)
{
    if (!empty(abb))
    {
        cout << abb->info << " ";
        preOrden(abb->hi);
        preOrden(abb->hd);
    }
}

bool empty(arbol abb)
{
    return (abb == NULL) ? true : false;
}