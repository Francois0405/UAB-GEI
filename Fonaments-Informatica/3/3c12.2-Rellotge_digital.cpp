#include <iostream>
#include <unistd.h>

using namespace std;
int main()
{
    int s, m, h, contar;
    char sep;
    contar = 1;
    cout << "Introdueix una hora (HH:MM:SS): ";
    cin >> s >> sep >> m >> sep >> h;
    do
    {
        sleep(1);
        contar = contar + 1;
        s = s + 1;
        cout << h << ":" << m << ":" << s << endl;
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
            m = 0;
            s = 0;
        }
    } while (contar <= 5);
}
