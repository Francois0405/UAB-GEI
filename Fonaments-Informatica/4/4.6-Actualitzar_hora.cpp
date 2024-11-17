#include <iostream>
#include "funcions.h"
#include <windows.h>

using namespace std;
int main()
{
    int s, m, h, contar;
    char sep;
    contar = 1;
    cout << "Introdueix una hora (HH:MM:SS): ";
    cin >> h >> sep >> m >> sep >> s;
    do
    {
        Sleep(1);
        incrementaHora(h, m, s);
        mostrar_hora(h, m, s);
    } while (contar <= 100);
}
