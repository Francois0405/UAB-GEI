#include "Aleatori.h"

//Copiar programa aqui
#include <iostream>
#include <time.h>

using namespace std;

#define SUMA 0
#define RESTA 1
#define MULTIPLICACIO 2
#define DIVISIO 3
#define FACIL 1
#define MIG 2
#define DIFICIL 3

int main()
{
    int opcio;
    int op1, op2, min = 0, max, operacio, x, punts = 0, punts_tot = 0, punts_tot_final, coef, res1;
    float res = 0, res_usuari;
    bool correcta, escorrecte;
    //srand( (unsigned)time(NULL) );

    cout << "Benvinguts al Brain Training Game! ";
    cout << "Si us plau, selecciona una dificultat : " << endl;
    cout << "1 - Facil" << endl;
    cout << "2 - Mig" << endl;
    cout << "3 - Dificil" << endl;



    do {
        correcta = true;
        cin >> opcio;
        switch (opcio)
        {
        case FACIL:
            max = 9;
            x = 2;
            coef = 8;
            break;

        case MIG:
            max = 99;
            x = 2;
            coef = 10;
            break;

        case DIFICIL:
            max = 999;
            x = 3;
            coef = 12;
            break;

        default:
            cout << "Seleccio incorrecta. Si us plau, selecciona una dificultat: ";
            correcta = false;
        }
    } while (correcta == false);

    do
    {
        escorrecte = true;
        operacio = Aleatori(0, x); // x és el nombre d'operacions que hi han al modo dificil hi han 4 tmb el :
        switch (operacio)
        {
        case SUMA:
            op1 = Aleatori(min, max);
            op2 = Aleatori(min, max);
            res = float(op1) + op2;
            cout << op1 << " + " << op2 << " = ";
            punts = 1;
            break;
        case RESTA:
            op1 = Aleatori(min, max);
            op2 = Aleatori(min, max);
            res = float(op1) - op2;
            cout << op1 << " - " << op2 << " = ";
            punts = 1;
            break;
        case MULTIPLICACIO:
            op1 = Aleatori(min, max);
            op2 = Aleatori(min, max);
            res = float(op1) * op2;
            cout << op1 << " x " << op2 << " = ";
            punts = 2;
            break;
        case DIVISIO:
            op1 = Aleatori(min, max);
            do {
                op2 = Aleatori(min, max);
            } while (op2 == 0);
            res = float(op1) / op2;
            res1 = res * 10;
            res = float(res1) / 10;
            cout << op1 << " : " << op2 << " = ";
            punts = 3;
            break;
        }
        cin >> res_usuari;

        if (res_usuari == res)
        {
            escorrecte = true;
            punts_tot = punts + punts_tot;
        }
        else
        {
            escorrecte = false;
            punts_tot_final = punts_tot * coef;
            cout << "Has aconseguit encadenar " << punts_tot << " respostes correctes amb una puntuacio final de: " << punts_tot_final << " punts.";
        }

    } while (escorrecte == true);
}