#include <iostream>

using namespace std;

int main()
{
	int num;
	cout << "introdueix un numero enter: ";
	cin >> num;

	if (num > 0)
	{
		cout << "Positiu";
	}
	else
	{
		if (num == 0)
		{
			cout << "Zero";
		}
		else
			if (num < 0)
			{
				cout << "Negatiu";
			}
	}
}