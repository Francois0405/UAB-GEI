#include <iostream>

using namespace std;

int main()
{
	char N, C;
	int A;
	cout << "Introdueix la inicial del teu nom: ";
	cin >> N;
	cout << "Introdueix la inicial del teu cognom: ";
	cin >> C;
	cout << "Introdueix la teva edat: ";
	cin >> A;
	
	cout << "Hola " << N << "." << C << ". " << "Tens " << A << " anys!";
}