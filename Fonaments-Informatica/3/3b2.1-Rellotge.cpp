#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

int main()
{
    int s, m, h;
    s = 0;
    m = 0;
    h = 0;
    do
    {
        Sleep(1000);
        s = s + 1;
        cout << "Son les: " << h << ":" << m << ":" << s << endl;
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
    } while (!_kbhit()); 
}
