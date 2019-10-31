#include <iostream>
using namespace std;

struct NodoArbol
{
    int info;
    struct NodoArbol *hi;
    struct NodoArbol *hd;
};

typedef NodoArbol *arbol;

void inserta(arbol &, int);
void enOrden(arbol);
void preOrden(arbol);
void postOrden(arbol);
int eliminaMenor(arbol &);
void elimina(arbol &, int x);

int main(int argc, char *argv[])
{

    arbol abb = NULL;
    int n, i, x;

    cout << "Cantidad de elementos del arbol : ";
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        cout << "Ingrese nodo numero" << i << ":";
        cin >> x;
        inserta(abb, x);
    }
    cout << "En Orden" << endl;
    enOrden(abb);
    cout << endl;
    cout << "dATO A ELIMINAR : ";
    cin >> x;
    elimina(abb, x);
    cout << "En Orden" << endl;
    enOrden(abb);
    cout << endl;
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
        cout << abb->info << "  ";
        preOrden(abb->hi);
        preOrden(abb->hd);
    }
}

void enOrden(arbol abb)
{
    if (abb != NULL)
    {
        enOrden(abb->hi);
        cout << abb->info << "  ";
        enOrden(abb->hd);
    }
}

void postOrden(arbol abb)
{
    if (abb != NULL)
    {
        postOrden(abb->hi);
        postOrden(abb->hd);
        cout << abb->info << "  ";
    }
}

int eliminaMenor(arbol &abb)
{
    if (abb->hi != NULL)
        return eliminaMenor(abb->hi);
    else
    {
        int x = abb->info;
        arbol temp;
        temp = abb;
        abb = abb->hd;
        delete temp;
        return x;
    }
}

void elimina(arbol &abb, int x)
{
    arbol temp;
    if (abb != NULL)
    {
        if (x < abb->info)
            elimina(abb->hi, x);
        else if (x > abb->info)
            elimina(abb->hd, x);
        else if (abb->hi != NULL && abb->hd != NULL)
        {
            int x = eliminaMenor(abb->hd);
            abb->info = x;
        }
        else if (abb->hi != NULL)
        {
            temp = abb;
            abb = abb->hi;
            delete temp;
        }
        else if (abb->hd != NULL)
        {
            temp = abb;
            abb = abb->hd;
            delete temp;
        }
    }
}