/* Esercizio 19
Siano assegnati da tastiera due vettori di interi vett1 e vett2 (max 50
elementi). Si progetti una funzione ALTERNA che riceva in ingresso i due vettori
e restituisca un vettore vett3 costituito alternando gli elementi di vett1 e
vett2. La funzione ALTERNA deve anche restituire come valore di ritorno la somma
di tutti gli elementi del vettore vett3.  */
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
int vett3[100], vett1[50], vett2[50];

void Random(int max) {
    srand(time(0));
    cout << "\nVettore 1:" << endl;
    for (int i = 0; i < max; i++) {
        vett1[i] = (rand() % 30);
        cout << vett1[i] << " ";
    }
    cout << "\nvettore 2:" << endl;
    for (int i = 0; i < max; i++) {
        vett2[i] = (rand() % 30);
        cout << vett2[i] << " ";
    }
}

int Alterna(int max) {
    int j = 0;
    for (int i = 0; i < max; i++) {
        vett3[j] = vett1[i];
        j++;
        vett3[j] = vett2[i];
        j++;
    }
    int som = 0;
    cout << "\n\nVettore 3:" << endl;
    for (int i = 0; i < max * 2; i++) {
        som += vett3[i];
        cout << vett3[i] << " ";
    }
    cout << endl;
    return som;
}

int main() {
    int max;
    cout << "Inserire massima lunghezza dei vettori" << endl;
    cin >> max;
    Random(max);
    int som;
    som = Alterna(max);
    cout << "La somma dei valori di vett3 = " << som << endl;
    int scelta;
    do {
        cout << "\nVuoi continuare?" << endl << "si=1   no=0" << endl;
        cin >> scelta;
        if (scelta != 0 && scelta != 1)
            cout << "Reinserire valore scelta" << endl;
        else if (scelta == 1) {
            Random(max);
            som = Alterna(max);
            cout << "La somma dei valori di vett3 = " << som << endl;
        }
    } while (scelta != 0);
}