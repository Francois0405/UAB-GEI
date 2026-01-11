#include <string>
#include <iostream>
#include "Caja.h"
#include "Par.h"
#include "VectorSimple.h"

using namespace std;

template<class T1>
T1 maximo(T1 a, T1 b) {
	if (a > b)
		return a;
	else
		return b;
}

template<class T1>
void intercambiar(T1 &a, T1 &b) {
	T1 c = a;
	a = b;
	b = c;
}

template <typename T, int N>
T multiplicar(T valor)
{
	return (valor * N);
}

int main()
{
	cout << maximo(3, 5);        // 5
	cout << maximo(2.5, 1.1);    // 2.5
	cout << maximo('a', 'z');    // z

	int a = 10, b = 20;
	intercambiar(a, b);

	Caja<int> c1(7);
	c1.mostrar();   // Valor: 7

	Caja<string> c2("hola");
	c2.mostrar();   // Valor: hola

	Par<int, string> p(10, "hola");
	p.mostrar();   // (10, hola)
	
	cout << multiplicar<int, 3>(5);  // 15

	VectorSimple<int, 3> v;
	v.set(0, 10);
	v.set(1, 20);
	cout << v.get(1); // 20

	return 0;
}