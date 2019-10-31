/*
En un ABB, busque un valor y diga cuantos elementos se recorrieron para llegar a dicho valor. 
Este valor es conocido como longitud del camino.
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
int camino(arbol abb, int dato);
bool empty(arbol abb);

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

    cout << "Ingrese un elemento: ";
    cin >> x;

    cout << "La longitud del camino es: " << camino(abb, x) << endl;

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

int camino(arbol abb, int dato)
{
    if (!empty(abb))
    {
        if (abb->info == dato)
            return 0;
        else if (dato < abb->info)
            return 1 + camino(abb->hi, dato);
        else if (dato > abb->info)
            return 1 + camino(abb->hd, dato);
    }
}

bool empty(arbol abb)
{
    return (abb == NULL) ? true : false;
}