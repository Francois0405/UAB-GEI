#include <iostream>

using namespace std;

int main()
{
	int num, suma;
	
	num = 0;
	suma = 0;

	do
	{
		suma = suma + num;
		num = num + 1;
	} while (num <=10);

	cout << suma;
}