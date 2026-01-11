#pragma once
#include <iostream>

using namespace std;

template<class T1>
class Caja {
public:
	Caja(T1 v) : val(v) {}
	void mostrar();

private:
	T1 val;
};

template<>
void Caja<string>::mostrar() {
	cout << "Cadena detectada: " << val;
}

template<class T1>
void Caja<T1>::mostrar() {
	cout << val;
}