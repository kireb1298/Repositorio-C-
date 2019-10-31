/*
Muestre todas las hojas terminales (también llamados elementos de la frontera del árbol en un ABB, 
Sugerencia: recorra el árbol y cuando no tenga a donde ir (izquierda y derecha apuntan a NULL) imprima su valor.
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
bool empty(arbol abb);
void hojas(arbol abb);

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
    
    hojas(abb);
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

void hojas(arbol abb)
{
    if (!empty(abb))
    {
        if (abb->hi == NULL && abb->hd == NULL)
            cout << abb->info << "  ";
        hojas(abb->hi);
        hojas(abb->hd);
    }
}

bool empty(arbol abb)
{
    return (abb == NULL) ? true : false;
}