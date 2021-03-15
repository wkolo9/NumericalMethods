#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;
double delta[100][100] = { 0 }, pochodna, pochodna2, ww[100] = { 0 }; //wartosci operatorow nie sa zapisane w tablicy dynamicznej, poniewaz tak jest latwiej wyzerowac tablice
int main()
{
	int iteracja = 0;
	double a, b, ksi, eps, fxi,fs,x;
	cout << "Podaj dolna granice: ";
	cin >> a;
	cout << "Podaj gorna granice: ";
	cin >>b;
	cout << "Podaj dokladnosc ";
	cin >> eps;
	ksi = b;
	//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
	
	double  h=0.001;
	int n = 8;
	cout << endl;
	double* fx = new double[n + 1]; //tablice dynamiczne dla wartosci funkcji, wspolczynnikow
	double* w = new double[n + 1];
	for (int i = 0; i <= n; i++)
	{
		fx[i] = pow((ksi + i * h), 4.0) -625 ; //wyliczanie kolejnych wartosci funkcji (w tym przypadku jest to funkcja x^4-625)
		
	}
	cout << endl;
	for (int i = 1; i <= n; i++) //kolejna potega operatora
	{
		for (int j = n + 1 - i; j > 0; j--) //kolejna roznica liczona od ostatniej
		{
			if (i == 1)
				delta[i][j] = fx[j] - fx[j - 1]; //liczenie operatorow rzedu pierwszego
			else
				delta[i][j] = delta[i - 1][j + 1] - delta[i - 1][j]; //liczenie operatorow pozostalych rzedow
		}
	}
	for (int i = 1; i <= n; i++)
	{
		w[i] = pow((-1.0), i + 1) / i;//wspolczynnik przy kazdym operatorze w ostatecznym wzorze (sumie operatorów) na pochodna
			pochodna += w[i] * delta[i][1];
	}
	pochodna = pochodna / h;
	cout << endl << "pochodna 1 stopnia z funkcji x^4 w punkcie " << ksi << ": " << pochodna << endl << endl;
	cout << endl;
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (k + 1 == j + i)
				{
					ww[k] += w[i] * w[j]; //wyliczanie wspolczynnikow przy operatorach we wzorze na druga pochodna
				}
			}
		}
	}
	for (int k = 1; k < n; k++)
	{
		
		pochodna2 += ww[k] * delta[k + 1][1]; //liczenie pochodnej ze wzoru Taylora (przed podzieleniem przez h^2)
	}
	pochodna2 = pochodna2 / (h * h);
	cout << endl << "pochodna 2 stopnia z funkcji x^4 w punkcie " << ksi << ": " << pochodna2 << endl;
	delete fx, w; //usuwanie tablic dynamicznych
	//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@




	//f(x)=x^4 - 625, 
	if ((pow(ksi,4) - 625) * pochodna2 < 0)  //sprawdzenie czy b moze byc punktem stalym dla metody siecznych
	{
		ksi = a;
		
		//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
		double* fx = new double[n + 1]; //tablice dynamiczne dla wartosci funkcji, wspolczynnikow
		double* w = new double[n + 1];
		for (int i = 0; i <= n; i++)
		{
			fx[i] = pow((ksi + i * h), 4.0) -625 ; //wyliczanie kolejnych wartosci funkcji (w tym przypadku jest to funkcja x^4-625)
			cout << "wartosc funkcji w punkcie x=" << ksi + i * h << " wynosi: " << fx[i] << endl;
		}
		cout << endl;
		for (int i = 1; i <= n; i++) //kolejna potega operatora
		{
			for (int j = n + 1 - i; j > 0; j--) //kolejna roznica liczona od ostatniej
			{
				if (i == 1)
					delta[i][j] = fx[j] - fx[j - 1]; //liczenie operatorow rzedu pierwszego
				else
					delta[i][j] = delta[i - 1][j + 1] - delta[i - 1][j]; //liczenie operatorow pozostalych rzedow
			}
		}
		for (int i = 1; i <= n; i++)
		{
			w[i] = pow((-1.0), i + 1) / i;//wspolczynnik przy kazdym operatorze w ostatecznym wzorze (sumie operatorów) na pochodna
			pochodna += w[i] * delta[i][1];
		}
		pochodna = pochodna / h;
		cout << endl << "pochodna 1 stopnia z funkcji x^4 w punkcie " << ksi << ": " << pochodna << endl << endl;
		cout << endl;
		for (int k = 1; k <= n; k++)
		{
			for (int i = 1; i <= n; i++)
			{
				for (int j = 1; j <= n; j++)
				{
					if (k + 1 == j + i)
					{
						ww[k] += w[i] * w[j]; //wyliczanie wspolczynnikow przy operatorach we wzorze na druga pochodna
					}
				}
			}
		}
		for (int k = 1; k < n; k++)
		{
			
			pochodna2 += ww[k] * delta[k + 1][1]; //liczenie pochodnej ze wzoru Taylora (przed podzieleniem przez h^2)
		}
		pochodna2 = pochodna2 / (h * h);
		cout << endl << "pochodna 2 stopnia z funkcji x^4 w punkcie " << ksi << ": " << pochodna2 << endl;
		delete fx, w; //usuwanie tablic dynamicznych
		//@@@@@@@@@@@@@@@@@@@@@@metoda siecznych@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
	}
	//metoda siecznych
	cout << "METODA SIECZNYCH "<<endl;

	cout << "Punktem stalym jest " << ksi << endl;

	if(ksi==b)
	{
		fs = pow(ksi, 4.0) - 625;
		do
		{
			if (iteracja == 0) {
				fxi = pow(a, 4.0) - 625; //dla iteracji 0 fxi = f(a)
				x = a - (fxi / (fs - fxi)) * (ksi - a);
				iteracja++;
				cout << "x1= "<<x<<endl;
			}
			if (iteracja != 0) {
				fxi = pow(x, 4.0) - 625;
				cout << "f(x " << iteracja << ")=" << fxi << endl;
				x = x - (fxi / (fs - fxi)) * (ksi - x);
				iteracja++;
				cout << "x " << iteracja << "=" << x << endl;
			}
		} while (abs(fxi) > eps);
		cout << "osagnieto wynikik w iteracji " << iteracja << "i jest równy" << fxi << endl;
	}
	

	if (ksi == a)
	{
		fs = pow(ksi, 4.0) - 625;
		do
		{
			if (iteracja == 0) {
				fxi = pow(b, 4.0) - 625; //dla iteracji 0 fxi = f(b)
				x = a - (fs / (fxi - fs)) * (ksi - a);
				iteracja++;
				cout << "x1= " << x << endl;
			}
			if (iteracja != 0) {
				fxi = pow(x, 4.0) - 625;
				cout << "f(x " << iteracja << ")=" << fxi << endl;
				x = a - (fs / (fxi - fs)) * (x - a);
				iteracja++;
				cout << "x " << iteracja << "=" << x << endl;
			}
		} while (abs(fxi) > eps);
		cout << "osagnieto wynikik w iteracji " << iteracja << "i jest równy" << fxi << endl;
	}
	
	iteracja = 0;x = 0; fxi = 0;
	// METODA STYCZNYCH #########################################################################################
	cout << "METODA STYCZNYCH " << endl;

	cout << "Poczatkowym puntkem jest  " << ksi << endl;
	do
	{

		if (iteracja == 0) {
			iteracja++;
			x = ksi - (pow(ksi, 4.0) - 625) / pochodna;
			fxi = pow(x, 4.0) - 625;
			cout << "x1= " << x << endl;
			cout << "fx1= " << fxi << endl;
			
		}


		if (iteracja != 0) {
			for (int i = 0; i <= n; i++)
			{
				fx[i] = pow((x + i * h), 4.0) - 625; //wyliczanie kolejnych wartosci funkcji (w tym przypadku jest to funkcja x^4-625)

			}
			cout << endl;
			for (int i = 1; i <= n; i++) //kolejna potega operatora
			{
				for (int j = n + 1 - i; j > 0; j--) //kolejna roznica liczona od ostatniej
				{
					if (i == 1)
						delta[i][j] = fx[j] - fx[j - 1]; //liczenie operatorow rzedu pierwszego
					else
						delta[i][j] = delta[i - 1][j + 1] - delta[i - 1][j]; //liczenie operatorow pozostalych rzedow
				}
			}
			for (int i = 1; i <= n; i++)
			{
				w[i] = pow((-1.0), i + 1) / i;//wspolczynnik przy kazdym operatorze w ostatecznym wzorze (sumie operatorów) na pochodna
				pochodna += w[i] * delta[i][1];
			}
			pochodna = pochodna / h;
			iteracja++;
			x = x - (pow(x, 4.0) - 625) / pochodna;
			fxi = pow(x, 4.0) - 625;

		cout << "x " << iteracja << "=" << x << endl;
		cout << "f(x " << iteracja << ")=" << fxi << endl;
		pochodna = 0;
		}
	} while (abs(fxi) > eps);
	cout << "osagnieto wynikik w iteracji " << iteracja << "i jest równy" << fxi << endl;
	system("pause");
	return 0;
}
