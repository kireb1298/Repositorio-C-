/*
Realizar una aplicacion que te permita generar 8 numeros aleatorios
diferentes, menores de 20 y que te indiquen cuantas iteraciones realizo para
que no se repita ninguno.
*/
#include <iostream>
#include <ctime>

bool verificacion(int n, int arreglo[]);
int main(int argc, char *argv[])
{
    srand(time(NULL));
    int arreglo[8], numeroR, contador = 0;
    for(int i = 0; i < 8; i++)
    {
        numeroR = 1 + rand() % (20 -1);
        while(verificacion(numeroR, arreglo))   // Si el numero existe se repite el bucle hasta que genere un aleatorio diferente
        {
            numeroR = 1 + rand() % (20 -1);
            contador++;
        }
        arreglo[i] = numeroR;
    }
    for(int i = 0; i < 8; i++)
    {
        std::cout << arreglo[i] << "    ";
    }
    std::cout << "\nSe hicieron " << contador << " iteraciones." << std::endl;
    system("pause");
    
    return 0;
}

bool verificacion(int n, int arreglo[])
{
    for(int i = 0; i < 8; i++) // Se crea un bucle para recorrer el arreglo
    {
        if(n == arreglo[i])   // Si ya existe un numero igual retorna true
            return true;
        return false;         // Si no retorna false
        
    }
}