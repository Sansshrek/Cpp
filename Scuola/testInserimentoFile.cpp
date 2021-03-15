#include <fstream>
#include <iostream>
#include <string.h>
using namespace std;

fstream File;
int nc = 0;
int main()
{
    bool check = false;
    string cognome, provenienza;
    int eta, altezza;
    cout << "nice" << endl;
    File.open("test.txt", ios::in);
    if (File.is_open()) //check esistenza file
        check = true; //il file esiste
    if (!check)
        cout << "\nIl file non esiste" << endl;
    else {
        File >> cognome >> provenienza >> eta >> altezza;
        cout << "\n"<< cognome << " " << provenienza << " " << eta << " " << altezza << endl;
        nc++;
        while (!File.eof()) {
            File >> cognome >> provenienza >> eta >> altezza;
            nc++;
            cout << "\n"<< cognome << " " << provenienza << " " << eta << " " << altezza << endl;
        }
        cout << "Numero Clienti= " << nc << endl;
    }
    File.close();
}