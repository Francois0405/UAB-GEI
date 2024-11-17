#include <iostream>

using namespace std;

int main()
{
    char lletra;

    cout << "Introdueixi una lletra vocal a traduir: ";
    cin >> lletra;

    switch (lletra)
    {
    case 'A':
    case 'a': cout << "Vocal: " << lletra << " - Codi Morse : .-";
        break;
    case 'E':
    case 'e': cout << "Vocal: " << lletra << " - Codi Morse : .";
        break;
    case 'I':
    case 'i': cout << "Vocal: " << lletra << " - Codi Morse : ..";
        break;
    case 'O':
    case 'o': cout << "Vocal: " << lletra << " - Codi Morse : ---";
        break;
    case 'U':
    case 'u': cout << "Vocal: " << lletra << " - Codi Morse : ..-";
        break;
    default: cout << "Error: El caracter introduit no es una vocal";
        break;
    }

}
