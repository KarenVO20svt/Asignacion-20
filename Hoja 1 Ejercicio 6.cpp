#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <time.h>
using namespace System;
using namespace std;

void GenerarValoresMatriz(int** Matriz, int& filas, int& columnas) {
	srand(time(NULL));
	for (int fila = 0; fila < filas; fila++) {
		for (int columna = 0; columna < columnas; columna++) {
			Matriz[fila][columna] = rand() % 10 + 1;
		}
	}
}

void MostrarMatriz(int** Matriz, int& filas, int& columnas) {

	for (int fila = 0; fila < filas; fila++) {
		for (int columna = 0; columna < columnas; columna++) {
			if (Matriz[fila][columna] < 10)
			{
				cout << Matriz[fila][columna] << "  ";
			}
			else
			{
				cout << Matriz[fila][columna] << " ";
			}
		}
		cout << endl;
	}
}

void IniciarMatrizCeroInt(int** Matriz, int& filas, int&columnas) {
	for (int fila = 0; fila < filas; fila++) {
		for (int columna = 0; columna < columnas; columna++) {
			Matriz[fila][columna] = 0;
		}
	}
}

void GenerarTrianguloIngerior(int** Matriz, int& filas, int& columnas, int** trianguloInferior) {
	for (int fila = 1; fila < filas; fila++) {
		for (int columna = 0; columna < fila; columna++) {
			trianguloInferior[fila][columna] = Matriz[fila][columna] + Matriz[columna][fila];
		}
	}
}

int main()
{
	int** Matriz;
	int** trinaguloInferior;
	int n;
	do
	{
		cout << "Ingrese el valor de n: ";
		cin >> n;
	} while (n < 2 || n>50);
	cout << endl;
	int filas = n;
	int columnas = n;
	Matriz = new int*[filas];
	for (int fila = 0; fila < filas; fila++)
		Matriz[fila] = new int[columnas];

	trinaguloInferior = new int*[filas];
	for (int fila = 0; fila < filas; fila++)
		trinaguloInferior[fila] = new int[columnas];


	GenerarValoresMatriz(Matriz, filas, columnas);
	cout << "Matriz inicial: " << endl << endl;
	MostrarMatriz(Matriz, filas, columnas);

	IniciarMatrizCeroInt(trinaguloInferior, filas, columnas);

	GenerarTrianguloIngerior(Matriz, filas, columnas, trinaguloInferior);

	cout << endl;
	cout << "Matriz resultante: " << endl << endl;
	MostrarMatriz(trinaguloInferior, filas, columnas);

	_getch();
	return 0;
}