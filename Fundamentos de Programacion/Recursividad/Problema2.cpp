/*
Realizar un generador de codigo y decodificador, que consiste en indicar un numero clave (por ejemplo 3)
y cada letra recorrera 3 espacios en el abecedario esto realizarlo para una frase no mayor de 35 caracteres.
*/
#include <iostream>

std::string codificador(std::string frase);
std::string decodificador(std::string codificado);

int main()
{
    std::string frase;

    std::cout << "Ingrese una frase: ";
    std::getline(std::cin, frase);

    std::cout << "Frase Codificada: " << codificador(frase) << std::endl;
    std::cout << "Frase Decodificada: " << decodificador(codificador(frase)) << std::endl;
    system("pause");
    return 0;
}

std::string codificador(std::string frase)
{
    std::string aux = frase;
    for (int i = 0; i < frase.size(); i++)
    {
        if ((aux[i] > 64 && aux[i] < 88) || (aux[i] > 96 && aux[i] < 120))
            aux[i] += 3;
        else
        {
            switch (aux[i])
            {
            case 120:
                aux[i] = 97;
                break;
            case 88:
                aux[i] = 65;
                break;
            case 121:
                aux[i] = 98;
                break;
            case 89:
                aux[i] = 66;
                break;
            case 122:
                aux[i] = 99;
                break;
            case 90:
                aux[i] = 67;
                break;
            }
        }
    }
    return aux;
}

std::string decodificador(std::string codificado)
{
    std::string aux = codificado;
    for (int i = 0; i < codificado.size(); i++)
    {
        if ((aux[i] > 68 && aux[i] < 91) || (aux[i] > 99 && aux[i] < 123))
            aux[i] -= 3;

        else
        {
            switch (aux[i])
            {
            case 97:
                aux[i] = 120;
                break;
            case 65:
                aux[i] = 88;
                break;
            case 98:
                aux[i] = 121;
                break;
            case 66:
                aux[i] = 89;
                break;
            case 99:
                aux[i] = 122;
                break;
            case 67:
                aux[i] = 90;
                break;
            }
        }
    }
    return aux;
}