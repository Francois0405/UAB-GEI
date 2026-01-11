#include <list>
#include <stack>
#include <string>

#include <iostream>
using namespace std;

bool cercaRecursiva(list<int>& l, list<int>::iterator& itL, int valor)
{
    if (itL == l.end())
        return false;
    else
    {
        if (*itL == valor)
            return true;
        if (itL == l.end())
            return false;
        itL++;
        cercaRecursiva(l, itL, valor);
    }
}

bool cerca(list<int>& l, int valor)
{
    list<int>::iterator itL = l.begin();
    return cercaRecursiva(l, itL, valor);
}

void escriuLlistaInversaRec(list<string>& l, list<string>::iterator& itL, list<string>& lRes)
{
    if (itL != l.end())
    {
        list<string>::iterator itAct = itL;
        escriuLlistaInversaRec(l, ++itL, lRes);
        cout << (*itAct) << ", ";
        lRes.push_back(*itAct);
    }

}
void escriuLlistaInversa(list<string>& l, list<string>& lRes)
{
    list<string>::iterator itL = l.begin();
    escriuLlistaInversaRec(l, itL, lRes);
    cout << endl;
}

void escriuLlistaInversaIt(list<string>& l, list<string>& lRes)
{
    stack<string> pila;
    for (string it : l)
    {
        pila.push(it);
    }
    int tamany = pila.size();
    for (int i = 0; i < tamany; i++)
    {
        cout << pila.top() << ", ";
        lRes.push_back(pila.top());
        pila.pop();
    }
}
