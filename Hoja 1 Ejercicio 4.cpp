#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <time.h>

using namespace System;
using namespace std;


void GenerarValoresMatriz(int** Matriz, int& filas, int& columnas) {
	for (int fila = 0; fila < filas; fila++) {
		for (int columna = 0; columna < columnas; columna++) {
			Matriz[fila][columna] = rand() % 10 + 1;
		}
	}
}

void MostrarMes(int& mes) {
	switch (mes) {
	case 0:
		cout << "Enero";
		break;
	case 1:
		cout << "Febrero";
		break;
	case 2:
		cout << "Marzo";
		break;
	case 3:
		cout << "Abril";
		break;
	case 4:
		cout << "Mayo";
		break;
	case 5:
		cout << "Junio";
		break;
	case 6:
		cout << "Julio";
		break;
	case 7:
		cout << "Agosto";
		break;
	case 8:
		cout << "Septiem";
		break;
	case 9:
		cout << "Octubre";
		break;
	case 10:
		cout << "Noviem";
		break;
	case 11:
		cout << "Diciem";
		break;
	default:
		break;
	}
}

void MostrarMatriz(int** Matriz, int& filas, int& columnas) {
	cout << "\t\t";
	for (int columna = 0; columna < columnas; columna++) {
		cout << "Agencia " << columna + 1 << "\t\t";
	}
	cout << endl;

	for (int fila = 0; fila < filas; fila++) {
		MostrarMes(fila);
		cout << "\t\t";
		for (int columna = 0; columna < columnas; columna++) {
			cout << Matriz[fila][columna] << "\t\t\t";
		}
		cout << endl;
	}
}

int SumaTotalAgencia(int** Matriz, int& filas, int agencia) {
	int suma = 0;
	for (int fila = 0; fila < filas; fila++) {
		suma = suma + Matriz[fila][agencia - 1];
	}
	return suma;
}

float PromedioMensualAgencias(int **Matriz, int& columnas, int mes) {
	float promedio = 0.0;
	for (int columna = 0; columna < columnas; columna++) {
		promedio = promedio + Matriz[mes - 1][columna];
	}
	return promedio / columnas;
}

void IniciarArrayCeroInt(int* array, int tamaño) {
	for (int i = 0; i < tamaño; i++)
		array[i] = 0;
}

void VentasAgencia(int** Matriz, int& filas, int &columnas, int* ventasAgencias) {
	for (int columna = 0; columna < columnas; columna++) {
		for (int fila = 0; fila < filas; fila++) {
			ventasAgencias[columna] = ventasAgencias[columna] + Matriz[fila][columna];
		}
	}
}

int MayorArrayPos(int* ventasAgencias, int& columnas) {
	int agenciaMayor = -1;
	int mayor = -1;
	for (int i = 0; i < columnas;i++) {
		if (ventasAgencias[i] > mayor) {
			mayor = ventasAgencias[i];
			agenciaMayor = i;
		}
	}
	return agenciaMayor;
}

void VentasMensuales(int** Matriz, int& filas, int &columnas, int* ventasMensuales) {
	for (int fila = 0; fila < filas; fila++) {
		for (int columna = 0; columna < columnas; columna++) {
			ventasMensuales[fila] = ventasMensuales[fila] + Matriz[fila][columna];
		}
	}
}

int MenorArrayMes(int* ventasMensuales, int& filas) {
	int mesMenor = -1;
	int menor = 1000000;
	for (int fila = 0; fila < filas; fila++) {
		if (ventasMensuales[fila] < menor) {
			menor = ventasMensuales[fila];
			mesMenor = fila;
		}
	}
	return mesMenor;
}

int main()
{
	system("MODE 130,35");
	int** Matriz;
	int filas = 12;
	int columnas = 5;
	int *ventasAgencias;
	int *ventasMensuales;
	int menorMes = -1;

	Matriz = new int*[12];
	for (int fila = 0; fila < filas; fila++)
		Matriz[fila] = new int[columnas];

	ventasAgencias = new int[columnas];
	ventasMensuales = new int[filas];

	IniciarArrayCeroInt(ventasAgencias, columnas);
	IniciarArrayCeroInt(ventasMensuales, filas);



	GenerarValoresMatriz(Matriz, filas, columnas);

	MostrarMatriz(Matriz, filas, columnas);

	VentasAgencia(Matriz, filas, columnas, ventasAgencias);
	VentasMensuales(Matriz, filas, columnas, ventasMensuales);

	cout << "Las ventas anuales de la Agencia 3 es: " << SumaTotalAgencia(Matriz, filas, 3) << endl << endl;
	cout << "El promedio de ventas en el mes de Diciembre es: " << PromedioMensualAgencias(Matriz, columnas, 12) << endl << endl;
	cout << "La agencia con mayor valor de ventas es: " << MayorArrayPos(ventasAgencias, columnas) + 1 << endl << endl;
	cout << "Mes con menores ventas es: ";
	menorMes = MenorArrayMes(ventasMensuales, filas);
	MostrarMes(menorMes);
	cout << endl;

	_getch();
	return 0;
}