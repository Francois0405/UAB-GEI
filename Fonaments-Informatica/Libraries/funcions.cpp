#include <iostream>
#include <cstdlib>
//#include <unistd.h>
#include <Windows.h>
#include <math.h>

using namespace std;

void swap(int& a, int& b)
{
	int aux;
	aux = a;
	a = b;
	b = aux;
}

int Aleatori(int min, int max)
{
	int al;

	al = (rand() % (max - min + 1)) + min;

	return al;
}

int alerta(int sec)
{

	if (sec > 0)
	{
		cout << "Alerta: Queden " << sec << " segons" << endl;
	}
	else
	{
		cout << "Alerta: S'ha acabat el temps" << endl;
	}
	return 0;
}

void duesXifres(int num)
{
	if (num < 10)
	{
		cout << "0";
	}
	cout << num;
}

int DivisioEnters(int dividend, int divisor, int& res)
{
	if (divisor != 0)
	{
		res = dividend / divisor;
		return(1);
	}
	else
	{
		return(0);
	}
}

void incrementaHora(int& h, int& m, int& s)
{
	s++;
	if (s == 60)
	{
		m = m + 1;
		s = 0;
	}
	if (m == 60)
	{
		h = h + 1;
		m = 0;
	}
	if (h == 24)
	{
		h = 0;
	}
}

void mostrar_hora(int& h, int& m, int& s)
{
	if (h < 10)
		cout << "0";
	cout << h << ":";
	if (m < 10)
		cout << "0";
	cout << m << ":";
	if (s < 10)
		cout << "0";
	cout << s << endl;
}

int centenes(int num)
{
	int cent;

	cent = (num / 100) % 10;

	return cent;
}

float potencia(int x, int n) // x^n
{
	float res;

	res = float(pow(x, n));
	return res;
}

float divisio(float a, float b)
{
	float div = 0;

	//div = a / b;
	bool negatiu = false;
	if ((a < 0 && b > 0) || (a > 0 && b < 0))
	{
		negatiu = true;
	}

	a = abs(a);
	b = abs(b);

	while (a >= b) {
		a = a - b; //a-=b;
		div++;
	}
	if (negatiu) {
		div = -div;
	}

	return div;
}

int fibonacci(int a)
{
	if (a == 0) {
		return 0;
	}
	else if (a == 1) {
		return 1;
	}
	else {
		return fibonacci(a - 1) + fibonacci(a - 2);
	}
}

void menucalc(void)
{
	cout << "/ x - + [CALCULADORA] + - x / " << endl
		<< "Selecciona una de les opcions" << endl <<
		"1.- Suma" << endl << "2.- Resta" << endl <<
		"3.- Producte" << endl << "4.- Divisio" << endl
		<< "5.- Sortir" << endl << endl;
}

float divisio_qr(int a, int b, int& div, int& residu)
{
	//div = a / b;
	bool negatiu = false;
	if (b != 0)
	{
		if ((a < 0 && b > 0) || (a > 0 && b < 0))
		{
			negatiu = true;
		}
		residu = a % b; // Calculem el residu de la divisio, el que resta.

		a = abs(a);
		b = abs(b);

		while (a >= b) {
			a = a - b; //a-=b;
			div++;
		}
		if (negatiu) {
			div = -div;
		}

		return 0;
	}
	else
	{
		return 1;
	}
}

int maxmin(float num, float& min, float& max)
{
	float quant;
	quant = 1;
	if (num == 0)
	{
		return 1;
	}
	else
	{
		max = num;
		min = num;
		while (quant <= 10 && num != 0)
		{
			cin >> num;
			quant = quant + 1;
			if (num != 0)
			{
				if (num > max)
				{
					max = num;
				}
				if (num < min)
				{
					min = num;
				}
			}
		}
		return 0;
	}
}

void polars(float x, float y, float& modul, float& angle)
{
	modul = sqrt(pow(x, 2) + pow(y, 2));
	angle = atan(y / x);
}

int equacio(int a, int b, int c, float& x1, float& x2)
{
	float discriminant;

	discriminant = (pow(b, 2) - (4 * a * c));
	if (discriminant < 0)
	{
		return 0;
	}
	else
	{
		if (discriminant == 0)
		{
			x1 = x2 = (((-b + sqrt(discriminant)) / (2 * a)));
			return 1;

		}
		else
		{
			x1 = (((-b + sqrt(discriminant)) / (2 * a)));

			x2 = (((-b - sqrt(discriminant)) / (2 * a)));
			return 2;

		}
	}
}

int AreaQuadrat(float costat, float& area)
{
	if (costat > 0)
	{
		area = costat * costat;
		return 0;
	}
	else
		return 1;
}

int AreaRectangle(float base, float altura, float& area)
{
	if ((base > 0) && (altura > 0))
	{
		area = base * altura;
		return 0;
	}
	else
		return 1;
}

int AreaTriangle(float base, float altura, float& area)
{
	if ((base > 0) && (altura > 0))
	{
		area = base * altura / 2;
		return 0;
	}
	else
		return 1;
}

// Moure punt
void moviment(int& x, int& y, int xmin, int xmax, int ymin, int ymax, int direccio)
{
	switch (direccio)
	{
	case 1: //esquerra
		if (x > xmin)
			x--;
		else
			cout << "No es pot moure a l'esquerra, esta en el limit." << endl;
		break;
	case 2: //dreta
		if (x < xmax)
			x++;
		else
			cout << "No es pot moure a la dreta, esta en el limit." << endl;
		break;
	case 3: //dalt
		if (y < ymax)
			y++;
		else
			cout << "No es pot moure a dalt, esta en el limit." << endl;
		break;
	case 4: //Baix
		if (y > ymin)
			y--;
		else
			cout << "No es pot moure a baix, esta en el limit." << endl;
		break;
	}
}

void menu(void)
{
	cout << "1: Esquerra" << endl;
	cout << "2: Dreta" << endl;
	cout << "3: Dalt" << endl;
	cout << "4: Baix" << endl;
	cout << "5: Sortir" << endl;
}