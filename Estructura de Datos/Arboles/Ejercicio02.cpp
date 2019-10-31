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

void inserta(arbol &abb, int x);
void preOrden(arbol abb, int dato);
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
    preOrden(abb, x);

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

void preOrden(arbol abb, int dato)
{
    if (!empty(abb))
    {
        if (abb->info == dato)
            exit(1);
        else if (dato < abb->info)
        {
            cout << abb->info << "  ";
            preOrden(abb->hi, dato);
        }
        else if (dato > abb->info)
        {
            cout << abb->info << "  ";
            preOrden(abb->hd, dato);
        }
    }
}

bool empty(arbol abb)
{
    return (abb == NULL) ? true : false;
}
