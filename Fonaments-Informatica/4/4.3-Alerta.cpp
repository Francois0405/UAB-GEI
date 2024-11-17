#include <iostream>
//#include <unistd.h>
#include <Windows.h>

using namespace std;

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

int main()
{
	int sec;
	int resultat;

	cout << "Introdueixi un temps en segons: " << endl;
	cin >> sec;

	do {
		resultat = alerta(sec);
		//sleep(1);
		Sleep(1000);
		sec--;
	} while (sec >= 0);
}