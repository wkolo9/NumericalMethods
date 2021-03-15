#include <stdio.h>
#include <iostream>
#include <math.h>
 
using namespace std;
 
int main()
{
   	double a, b, h, n, x, f;
   	double w_t, w_kt, w_S; //wyniki dla t - trapez, S - Simpson, k - kwadratura zlozona
   	double reszta_t, reszta_t_dokl, reszta_kt, reszta_kt_dokl,  reszta_S, reszta_S_dokl, reszta_kS, reszta_kS_dokl, w_kS, w_dokladny;
 
   	cout << "Podaj dolna granice calkowania (a): ";
   	cin >> a;
   	cout << "Podaj gorna granice calkowania (b): ";
   	cin >> b;
   	cout << "Podaj liczbe podprzedzialow (n), na ktore dzieli sie przedial calkowania: "; //im wieksze n tym lepsza dokladnosc wyniku z zadania drugiego
   	cin >> n;
   	w_dokladny = exp(b) - exp(a);
 
   	cout << "Dokladna wartosc calki oznaczonej z funkcji e^x dla granic calkowania " << a << " i " << b << " wynosi: " << w_dokladny << endl << endl;
   	cout << "                           	zad1" << endl;
 //zad1
   	//METODA TRAPEZOW
   	w_t = (exp(a) + exp(b)) * (b - a) / 2.0; //zakladamy ze n=1 we wzorze trapezów
   	reszta_t = -1.0 / 12.0 * pow((b - a), 3) * exp(b); //<-w ostatniej eksponencie dalismy b, aby reszta byla jak najwieksza (mozna tak robic dla funkcji exp)
   	reszta_t_dokl = w_dokladny - w_t;
   	cout << "Wartosc calki oznaczonej policzonej metoda trapezow: " << w_t << endl;
   	cout << "Reszta z metody trapezow policzona wzorem: " << reszta_t << "" << endl << "Dokladna reszta: " << reszta_t_dokl << "" << endl << endl;
 
   	// METODA SIMPSONA
   	w_S = (exp(a) + 4 * exp((b + a) / 2.0) + exp(b)) * (b - a) / 6.0; //zakladamy ze n=2 we wzorze Simpsona
   	reszta_S = -1.0 / 90.0 * pow((b - a)/2, 5) * exp(b); //<-w ostatniej eksponencie dalismy b, aby reszta byla jak najwieksza (mozna tak robic dla funkcji exp)
   	reszta_S_dokl =  w_dokladny- w_S;
   	cout << "Wartosc calki oznaczonej policzonej metoda Simpsona: " << w_S << endl;
   	cout << "Reszta z metody Simpsona policzona wzorem: " << reszta_S << "" << endl << "Dokladna reszta: " << reszta_S_dokl << "" << endl << endl << endl;
 
   	cout << "                           	zad2" << endl;
 //zad2
   	//Kwadratura zlozona trapezów
   	h = (b - a) / n;
   	f = exp(a);     	//pierwszy i ostatni skladnik sumy nie ma wspolczynnika 2
   	x = a; //x0 - dolna granica calkowania, kazdy kolejny x jest rownoodlegly o h (wzor: x=a+(i*h))
   	for (int i = 0; i < n - 1; i++)
   	{
         	x += h;         	
         	f += 2 * exp(x);
   	}
   	f += exp(b);
   	w_kt = (b - a) / (2 * n) * f;
   	reszta_kt = -1.0 / 12.0 * n * pow(h, 3) * exp(b); //<- tym razem liczba w eksponencie nalezy do przedzialu domknietego [a;b]
   	reszta_kt_dokl = w_dokladny - w_kt;
   	cout << "Wartosc calki oznaczonej policzonej z zastosowaniem kwadratury zlozonej trapezow: " << w_kt << endl;
   	cout << "Reszta z kwadratury zlozonej trapezow policzona wzorem: " << reszta_kt << "" << endl << "Dokladna reszta: " << reszta_kt_dokl << "" << endl << endl;
 
   	//Kwadratura zlozona Simpsona
   	h = (b - a) / (2 * n);
   	f = exp(a);	//pierwszy i ostatni skladnik sumy nie ma wspolczynnika 2
   	x = a;   //x0 - dolna granica calkowania, kazdy kolejny x jest rownoodlegly o h (wzor: x=a+(i*h))
   	for (int i = 0; i < 2 * n - 1; i++)
   	{
         	x += h;
         	if (i % 2 == 1)
                	f += 2 * exp(x);
         	else                          	//wspolczynnik przy skladnikach sumy jest rowny odpowednio 4, 2, 4, 2,...
                	f += 4 * exp(x);
   	}
   	f += exp(b);
   	w_kS = h / 3 * f;
   	reszta_kS = -1.0 / 90.0 * n * pow(h, 5) * exp(b); //<- tym razem liczba w eksponencie nalezy do przedzialu domknietego [a;b]
   	reszta_kS_dokl= w_dokladny - w_kS;
 
   	cout << "Wartosc calki oznaczonej policzonej z zastosowaniem kwadratury zlozonej Simpsona: " << w_kS << endl;
   	cout << "Reszta z kwadratury zlozonej Simpsona policzona wzorem: " << reszta_kS << "" << endl << "Dokladna reszta: " << reszta_kS_dokl << "" << endl;
 
   	system("pause");
   	return 0;
}
