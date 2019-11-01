#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
using namespace std;

struct Dato
{
	char palabra[50];
	char significado[200];
};

struct NodoArbol
{
	Dato info;
	NodoArbol *hi;
	NodoArbol *hd;
};
typedef NodoArbol *arbol;

void menu();
void inserta(arbol &abb, Dato x);
bool empty(arbol abb);
void opcion3(arbol abb);
arbol opcion2(arbol abb, char x[]);
void opcion1(arbol &abb);
bool comprobar();
void guardarDatos(arbol abb, ofstream &save);
int size(arbol abb);

int main(int argc, char *argv[])
{
	arbol abb = NULL, aux;
	int opc = 1;
	char dato[50];
	Dato palabra, *temp;
	if (comprobar())
		cout << "No existe el archivo [data.dat] ";
	else
	{
		cout << "Si existe el archivo [data.dat]";
		ifstream leerArchivo("data.dat", ios::binary);
		leerArchivo.seekg(0, ios::beg);
		leerArchivo.read((char *)&palabra, sizeof(Dato));
		while (!leerArchivo.eof())
		{
			inserta(abb, palabra);
			leerArchivo.read((char *)&palabra, sizeof(Dato));
		}
		cout << "Se ha cargado con exito. ";
		leerArchivo.close();
	}

	cout << endl;
	system("pause");
	while (opc > 0 && opc < 5)
	{
		system("cls");
		menu();
		cout << endl;
		cout << "Ingrese una opcion: ";
		cin >> opc;
		switch (opc)
		{
		case 1:
			system("cls");
			opcion1(abb);
			system("pause");
			break;
		case 2:
			system("cls");
			aux = NULL;
			cin.ignore();
			cout << "Ingrese la palabra a buscar: ";
			cin.getline(dato, 50);
			aux = opcion2(abb, dato);
			if (aux != NULL)
				cout << aux->info.palabra << "	" << aux->info.significado << endl;
			else
				cout << "No se encuentra la palabra." << endl;
			system("pause");
			break;
		case 3:
			system("cls");
			opcion3(abb);
			system("pause");
			break;
		case 4:
			system("cls");
			ofstream save("temp.dat", ios::binary);
			guardarDatos(abb, save);
			save.close();
			cout << "Exito al guardar" << endl;
			remove("data.dat");
			rename("temp.dat", "data.dat");
			return 0;
			break;
		}
	}
	return 0;
}

void menu()
{
	cout << "		Menu de Quina\n"
		 << "	1.Ingresar palabra\n"
		 << "	2.Consultar palabra\n"
		 << "	3.Reportar\n"
		 << "	4.Guardar y Salir\n"
		 << "	5.Salir\n";
}

void inserta(arbol &abb, Dato x)
{
	if (empty(abb))
	{
		abb = new NodoArbol;
		abb->info = x;
		abb->hi = NULL;
		abb->hd = NULL;
	}
	else if (strcmp(x.palabra, abb->info.palabra) < 0)
		inserta(abb->hi, x);
	else if (strcmp(x.palabra, abb->info.palabra) > 0)
		inserta(abb->hd, x);
}

void opcion1(arbol &abb)
{
	Dato x;

	cin.ignore();
	cout << "Palabra: ";
	cin.getline(x.palabra, 50);
	cout << "Significado: ";
	cin.getline(x.significado, 200);
	inserta(abb, x);
}

arbol opcion2(arbol abb, char x[])
{
	if (!empty(abb))
	{
		if (strcmp(x, abb->info.palabra) == 0)
			return abb;
		else if (strcmp(x, abb->info.palabra) < 0)
			return opcion2(abb->hi, x);
		else
			return opcion2(abb->hd, x);
	}
	else
		return NULL;
}

void opcion3(arbol abb)
{
	if (!empty(abb))
	{
		opcion3(abb->hi);
		cout << abb->info.palabra << " " << abb->info.significado << endl;
		opcion3(abb->hd);
	}
}

bool empty(arbol abb)
{
	return (abb == NULL) ? true : false;
}

bool comprobar()
{
	ifstream comprobacion("data.dat", ios::binary);
	return (!comprobacion) ? true : false;
}

void guardarDatos(arbol abb, ofstream &save)
{
	if (!empty(abb))
	{
		save.write((char *)&abb->info, sizeof(Dato));
		guardarDatos(abb->hi, save);
		guardarDatos(abb->hd, save);
	}
}

int size(arbol abb)
{
	if (!empty(abb))
		return 1 + size(abb->hi) + size(abb->hd);
	else
		return 0;
}
