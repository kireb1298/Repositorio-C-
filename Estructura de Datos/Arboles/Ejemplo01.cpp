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
void preOrden(arbol abb);
void enOrden(arbol abb);
void postOrden(arbol abb);
void descendente(arbol abb);
int menor(arbol abb);
int mayor(arbol abb);
arbol buscar(arbol abb, int x);

int main(int argc, char *argv[])
{
    arbol abb = NULL;
    int n, x, i, dato;
    cout << "Numero de elementos del arbol: ";
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        cout << "Ingrese numero :";
        cin >> x;
        inserta(abb, x);
    }
    cout << "\n Pre Orden " << endl;
    preOrden(abb);
    cout << "\n En Orden " << endl;
    enOrden(abb);
    cout << "\n Post Orden " << endl;
    postOrden(abb);
    cout << "\n Orden Descendente " << endl;
    descendente(abb);
    cout << "\n El mayor es : " << mayor(abb) << endl;
    cout << "\n El menor es : " << menor(abb) << endl;
    arbol p;
    cout << "Dato a buscar : ";
    cin >> dato;
    p = buscar(abb, dato);
    if (p != NULL)
        cout << "Dato se encuentra en el arbol " << endl;
    else
        cout << "Dato no se encuentra en el arbol " << endl;

    return 0;
}

void inserta(arbol &abb, int x)
{
    if (abb == NULL)
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

void preOrden(arbol abb)
{
    if (abb != NULL)
    {
        cout << abb->info << " ";
        preOrden(abb->hi);
        preOrden(abb->hd);
    }
}

void enOrden(arbol abb)
{
    if (abb != NULL)
    {
        enOrden(abb->hi);
        cout << abb->info << " ";
        enOrden(abb->hd);
    }
}

void postOrden(arbol abb)
{
    if (abb != NULL)
    {
        postOrden(abb->hi);
        postOrden(abb->hd);
        cout << abb->info << " ";
    }
}

void descendente(arbol abb)
{
    if (abb != NULL)
    {
        descendente(abb->hd);
        cout << abb->info << " ";
        descendente(abb->hi);
    }
}

int menor(arbol abb)
{
    if (abb->hi != NULL)
        return menor(abb->hi);
    else
        return abb->info;
}

int mayor(arbol abb)
{
    if (abb->hd != NULL)
        return mayor(abb->hd);
    else
        return abb->info;
}

arbol buscar(arbol abb, int x)
{
    if (abb != NULL)
    {
        if (x == abb->info)
            return abb;
        else if (x < abb->info)
            return buscar(abb->hi, x);
        else
            return buscar(abb->hd, x);
    }
    else
        return NULL;
}
