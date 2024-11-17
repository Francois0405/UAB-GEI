#include <iostream>

using namespace std;

int main()
{
    char bondia[9] = "Bon dia "; 
    char nom[15];            
    char concat[30];         

    cout << "Introdueix el teu nom: ";
    cin >> nom;

    int i = 0;
    while (bondia[i] != '\0')
    {
        concat[i] = bondia[i];
        i++;
    }
    int j = 0;
    while (nom[j] != '\0') 
    {
        concat[i] = nom[j];
        i++;
        j++;
    }

    concat[i] = '\0';

    cout << concat << endl;
    return 0;
}
