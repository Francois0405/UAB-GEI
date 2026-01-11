#pragma once
#include <iostream>

using namespace std;

template<class T1, class T2>
class Par {
public:
	Par(T1 a, T2 b): val1(a), val2(b) {}
	void mostrar();
private:
	T1 val1;
	T2 val2;
};

template<class T1, class T2>
void Par<T1, T2>::mostrar() {
	cout << val1 << ", " << val2;
}