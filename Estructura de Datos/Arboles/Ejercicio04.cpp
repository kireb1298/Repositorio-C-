//¿Cuál es la diferencia entre el mayor y menor elemento de un árbol?
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
int menor(arbol abb);
int mayor(arbol abb);
int diferencia(arbol abb);

int main()
{
    arbol abb = NULL;
    int n, x;
    cout << "Numero de elementos del arbol: ";
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cout << "Ingrese numero :";
        cin >> x;
        inserta(abb, x);
    }

    cout << "La diferencia es: " << diferencia(abb) << endl;
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

bool empty(arbol abb)
{
    return (abb == NULL) ? true : false;
}

int mayor(arbol abb)
{
    if (abb->hd != NULL)
        return mayor(abb->hd);
    else
        return abb->info;
}

int menor(arbol abb)
{
    if (abb->hi != NULL)
        return menor(abb->hi);
    else
        return abb->info;
}

int diferencia(arbol abb)
{
    return mayor(abb) - menor(abb);
}