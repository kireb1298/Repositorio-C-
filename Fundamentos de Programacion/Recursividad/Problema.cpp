#include <iostream>

void recursivo(int a, int b, int cont, int suma);

int main()
{
    int a, b, cont = 1, suma;
    std::cout << "Digite a: ";
    std::cin >> a;
    std::cout << "Digite b: ";
    std::cin >> b;
    suma = a+b;
    recursivo(a,b,cont,suma);
    system("pause");
    return 0;
}

void recursivo(int a, int b, int cont, int  suma)
{
    int aux = cont;
    if (aux <= 10)
    {
        std::cout << suma << "  ";
        aux++;
        recursivo(a, b, aux, suma+b);
    }
}