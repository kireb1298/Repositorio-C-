//En un árbol binario. ¿Cuantos nodos tienen un solo hijo?
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
int nodos(arbol abb);

int main()
{
    arbol abb = NULL, b;
    int n, x;

    cout << "Numero de elementos: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Elemento: ";
        cin >> x;
        inserta(abb, x);
    }
    
    cout << "El numero de nodos con un hijo es: " << nodos(abb) << endl;
    
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

int nodos(arbol abb)
{
    if (!empty(abb))
    {
        if((abb->hi == NULL && abb->hd != NULL) || (abb->hi != NULL && abb->hd == NULL))
            return 1 + nodos(abb->hi) + nodos(abb->hd);
        else
            return nodos(abb->hi) + nodos(abb->hd);
    }
    return 0;
}


bool empty(arbol abb)
{
    return (abb == NULL) ? true : false;
}