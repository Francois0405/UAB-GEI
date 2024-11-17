#include <iostream>

using namespace std;

int main()
{
	//VAR
	int hh, mm, ss;
	char c;

	//INP
	cout << "Introdueix una hora format (hh:mm:ss): ";
	cin >> hh >> c >> mm >> c >> ss;

	//PRO
	ss = ss + 1;
	if (ss == 60)
	{
		ss = 0;
		mm = mm + 1;
	}
	if (mm == 60)
	{
		mm = 0;
		hh = hh + 1;
	}
	if (hh == 24)
	{
		hh = 0;

	}

	//OUT
	if (hh < 10)
	{
		cout << 0;
	}
	cout << hh << c;
	if (mm < 10)
	{
		cout << 0;
	}
	cout << mm << c;
	if (ss < 10)
	{
		cout << 0;
	}
	cout << ss << endl;
}