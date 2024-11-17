#include <iostream>

using namespace std;

int fibonacci(int a)
{
	// a1 = 0 + 1
	// a2 = 1 + 1
	// a3 = 2 + 1
	// a4 = 3 + 2
	// a5 = 5 + 3
	// a6 = 8 + 5
	// a7 = 13 + 8
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

int main()
{
	int a = 0, res;

	do {
		cout << "Introdueix un terme de fibonacci: " << endl;
		cin >> a;
		if (a < 0)
		{
			cout << "Error: el nombre no pot ser negatiu" << endl;
		}
	} while (a < 0);
	res = fibonacci(a);
	cout << "El terme " << a << " de la serie de Fibonacci es " << res;
}