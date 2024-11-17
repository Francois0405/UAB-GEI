#include <iostream>
#include <windows.h>


using namespace std;

void incrementaHora(int &h, int &m, int &s)
{
    s++;
    if (s == 60)
    {
        m = m + 1;
        s = 0;
    }
    if (m == 60)
    {
        h = h + 1;
        m = 0;
    }
    if (h == 24)
    {
        h = 0;
    }
}

void mostrar_hora(int& h, int& m, int& s)
{
    if (h < 10)
        cout << "0";
    cout << h << ":";
    if (m < 10)
        cout << "0";
    cout << m << ":";
    if (s < 10)
        cout << "0";
    cout << s << endl;
}