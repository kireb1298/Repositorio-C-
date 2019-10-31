//Contar el numero de hojas tiene un árbol binario de búsqueda.
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
int hojas(arbol abb);

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
    
    cout << "El numero de hojas es: " << hojas(abb) << endl;
    
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

int hojas(arbol abb)
{
    if (!empty(abb))
    {
        if(abb->hi == NULL && abb->hd == NULL)
            return 1 + hojas(abb->hi) + hojas(abb->hd);
        else
            return hojas(abb->hi) + hojas(abb->hd);
    }
    return 0;
}

bool empty(arbol abb)
{
    return (abb == NULL) ? true : false;
}