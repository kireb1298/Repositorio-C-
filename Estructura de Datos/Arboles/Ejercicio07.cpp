//Lea 2 árboles ¿Que elementos del primer árbol no se encuentran en el segundo árbol?
#include <iostream>
using namespace std;

struct NodoArbol
{
    int info;
    NodoArbol *hd;
    NodoArbol *hi;
};
typedef NodoArbol *arbol;

void inserta(arbol &abb, int x);
bool empty(arbol abb);
void comparar(arbol a, int x);
void preOrden(arbol a, arbol b);

int main()
{
    int n1, n2, x;
    arbol abb1, abb2;
    abb1 = NULL;
    abb2 = NULL;
    cout << "Numero de elementos arbol 1: ";
    cin >> n1;
    cout << "Numero de elementos arbol 2: ";
    cin >> n2;
    cout << endl;
    cout << "Elementos del arbol 1: " << endl;
    for (int i = 0; i < n1; i++)
    {
        cout << "Numero: ";
        cin >> x;
        inserta(abb1, x);
    }

    cout << "Elementos del arbol 2: " << endl;
    for (int i = 0; i < n2; i++)
    {
        cout << "Numero: ";
        cin >> x;
        inserta(abb2, x);
    }
    cout << "Los elementos faltantes son: " << endl;
    preOrden(abb1, abb2);

    system("pause");
    return 0;
}

bool empty(arbol abb)
{
    return (abb == NULL) ? true : false;
}

void inserta(arbol &abb, int x)
{
    if (empty(abb))
    {
        abb = new NodoArbol;
        abb->info = x;
        abb->hd = NULL;
        abb->hi = NULL;
    }
    else if (x < abb->info)
        inserta(abb->hi, x);
    else if (x < abb->info)
        inserta(abb->hd, x);
}

void preOrden(arbol a, arbol b)
{
    comparar(b, a->info);
    preOrden(a->hi, b);
    preOrden(a->hd, b);
}

void comparar(arbol a, int x)
{
    if (x == a->info)
    {
        comparar(a->hi, x);
        comparar(a->hd, x);
    }
    else
       cout << x << "   "; 
}