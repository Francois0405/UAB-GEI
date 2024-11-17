#include <iostream>

using namespace std;

int main()
{
	int n, fact_n=1; //jugadors que es té
	int m, fact_m=1; //formació de jugadors
	int k, fact_k=1; //diferencia de n i m. (n-m)
	int res;

	cout << "Quants jugadors té el entrenador? ";
	cin >> n;
	cout << "De quants jugadors és la formació? ";
	cin >> m;
	k = n - m;

	while (n > 0) {
		fact_n = fact_n * n;
		n = n - 1;
	}
	while (m > 0) {
		fact_m = fact_m * m;
		m = m - 1;
	}
	while (k > 0) {
		fact_k = fact_k * k;
		k = k - 1;
	}

	//Formula:		N! / (M! * (N-M)!)
	res = (fact_n / (fact_m * (fact_k)));
	
	cout << "El nombre d'equips que es poden formar es: " << res;
}