#include <iostream>
#include "Menu.h"
#include "Funcions.h"

using namespace std;

int main()
{
    int opcio;
    float area, base, altura, res;
    bool sortir = false;

    do
    {
        MenuSeleccio();
        cin >> opcio;
    
        switch (opcio)
        {
            case 1: //quadrat
                cout << "Introdueix el costat del quadrat: ";
                cin >> base;
                res = AreaQuadrat(base, area);
                break;
            case 2: //rectangle
                cout << "Introdueix la base del rectangle i la seva altura: " << endl;
                cin >> base >> altura;
                res = AreaRectangle(base, altura, area);
                break;
            case 3: //triangle
                cout << "Introdueix la base del triangle i la seva altura: " << endl;
                cin >> base >> altura;
                res = AreaTriangle(base, altura, area);
                break;
            case 4: //sortir
                sortir = true;
                break;
        }
    
        if (res == 0)
        {
            cout << "Area: " << area << endl << endl;
        }
        else
        {
            cout << "Error: Dimensions incorrectes" << endl << endl;
        }
    } while (sortir == false);
 
    return 0;
}