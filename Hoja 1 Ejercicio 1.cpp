#include <iostream>
#include <stdio.h>
#include <conio.h>
using namespace System;
using namespace std;

void HacerMatriz(int **Matriz, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << " Ingrese el valor de la matriz en la fila " << i + 1 << " ,columna " << j + 1 << " : ";
			cin >> Matriz[i][j];

		}

	}

	cout << endl;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 1; j++)
		{
			cout << "  ";

		}

		for (int j = 0; j < m; j++)
		{
			if (Matriz[i][j] < 10)
			{
				cout << Matriz[i][j] << "  ";
			}
			else
			{
				cout << Matriz[i][j] << " ";
			}

		}

		cout << endl;

	}

	cout << endl;

}

void SumaFilas(int **Matriz, int n, int m)
{
	int *MenorValor = new int[n];
	int sumafilas;

	cout << "--------------------------------";
	cout << endl;

	for (int i = 0; i < n; i++)
	{
		MenorValor[i] = Matriz[i][0];
		sumafilas = 0;

		for (int j = 0; j < m; j++)
		{
			sumafilas += Matriz[i][j];

			if (Matriz[i][j] < MenorValor[i])
			{
				MenorValor[i] = Matriz[i][j];
			}


		}

		cout << " La suma de la fila " << i + 1 << " es : " << sumafilas << endl;
		cout << " El menor valor de la fila " << i + 1 << " es : " << MenorValor[i] << endl;
		cout << endl;

	}

}

void SumaColumnas(int **Matriz, int n, int m)
{
	int *MayorValor = new int[n];
	double sumacolumnas;
	double promedio;

	cout << "------------------------------ ";
	cout << endl;

	for (int j = 0; j < m; j++)
	{
		MayorValor[j] = Matriz[0][j];
		sumacolumnas = 0.0;
		promedio = 0.0;

		for (int i = 0; i < n; i++)
		{
			sumacolumnas += Matriz[i][j];

			if (Matriz[i][j] > MayorValor[j])
			{
				MayorValor[i] = Matriz[i][j];
			}

			promedio = sumacolumnas / m;
		}

		cout << " El promedio de la columna " << j + 1 << " es : " << promedio << endl;
		cout << " El mayor valor de la columna " << j + 1 << " es : " << MayorValor[j] << endl;
		cout << endl;

	}

}

void MayorValor(int **Matriz, int n, int m)
{
	int MayorValor = Matriz[0][0];
	int posf;
	int posc;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (Matriz[i][j] > MayorValor)
			{
				MayorValor = Matriz[i][j];
				posf = i;
				posc = j;
			}

		}
	}

	cout << " ------------------------------ " << endl;
	cout << " El mayor valor de la matriz es " << MayorValor << " y se encuentra en la fila " << posf + 1 << " , columna " << posc + 1 << endl;

}

int main()
{
	int n, m;
	int **Matriz;

	cout << endl;
	do
	{
		cout << " Ingrese el n° de filas de la matriz: ";
		cin >> n;

	} while (n <= 0 || n > 10);

	do
	{
		cout << " Ingrese el n° de columnas de la matriz: ";
		cin >> m;

	} while (m <= 0 || m > 10);

	Matriz = new int*[n];
	for (int i = 0; i < n; i++)
	{
		Matriz[i] = new int[m];
	}


	HacerMatriz(Matriz, n, m);
	SumaFilas(Matriz, n, m);
	SumaColumnas(Matriz, n, m);
	MayorValor(Matriz, n, m);


	for (int i = 0; i < n; i++)
	{
		delete[] Matriz[i];
	}

	delete[] Matriz;


	cout << endl;
	cout << " ";

	_getch();
}