#include <iostream>
#include <math.h>
#include <stdio.h>
#include <cmath>

using namespace std;

int main()
{
    double x0, y0, xmax, n, x, ye, yd,blad, krok, wart_funkc, deltaY, c;
    //int i;
    cout << "Podaj warunek poczatkowy na x, x0= "  ;
    cin >> x0;
    cout << "Podaj warunek poczatkowy na y, y0= ";
    cin >> y0;
    cout << "podaj wartosc koncowa x, xmax= " ;
    cin >> xmax;
    cout << "liczbe punktow równo roz³o¿onych pomiêdzy x0 a xmax, w których bêdzie wyznaczane rozwi¹zanie.";
    cin >> n;
    krok = (xmax - x0) / (n+1);
    ye = y0;
    for (x = x0; x <= xmax; x = x+krok)
    {
        cout << "x=" << x << endl;
        cout << "y=" << ye << endl;
        wart_funkc = 0.1 * x * ye;
        deltaY = wart_funkc * krok;
        c = ye / exp( 0.05 * pow(x , 2.0));
        yd = c * exp(0.05 * pow(x , 2.0));
        cout << "yd=" << yd << endl;
           
        blad = ye - yd;
        cout << "blad=" << blad << endl;
        cout << "NASTEPNA ITERACJA@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
        ye = ye + deltaY;

    }

    system("pause");
    return 0;
}
