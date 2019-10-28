
//Crear una función que devuelva el número de elementos de un árbol binario.
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
int size(arbol abb);

int main()
{
    arbol abb = NULL;
    int n, x, dato;
    cout << "Numero de elementos del arbol: ";
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cout << "Ingrese numero :";
        cin >> x;
        inserta(abb, x);
    }
    std::cout << "El numero de elementos en el arbol es: " << size(abb) << std::endl;

    system("pause");
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

int size(arbol abb)
{
    if (!empty(abb))
        return 1 + size(abb->hi) + size(abb->hd);
    else
        return 0;
}

bool empty(arbol abb)
{
    return (abb == NULL) ? true : false;
}