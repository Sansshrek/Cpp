#include <iostream>
#include <string.h>
#include <time.h>
using namespace std;
string reparti[] = { "Frutta", "Verdura", "Salumi", "Formaggi", "Carne", "Pesce", "Surgelati", "Pasta", "Latte", "Bevande", "Pasticceria" };
int nc;

class Market {
    string nome, rep[100];
    int num_rep, inc[100];

public:
    void input()
    {
        int scelta;
        cout << "\nInserire Nome Supermercato" << endl;
        cin >> nome;
        cout << "Inserire numero reparti" << endl;
        cin >> num_rep;
        do {
            cout << "\nVuoi inserire i reparti in modo random(1) o manuale(2)" << endl;
            cin >> scelta;
            if (scelta != 1 && scelta != 2)
                cout << "\nScelta inesistente" << endl;
        } while (scelta != 1 && scelta != 2);
        if (scelta == 1) {
            srand(time(0));
            int length = (sizeof(reparti) / sizeof(*reparti)), n;
            for (int i = 0; i < num_rep; i++) {
                n = rand() % length;
                rep[i] = reparti[n];
                inc[i] = rand() % 1000;
            }
        } else {
            for (int i = 0; i < num_rep; i++) {
                cout << "\nInserire nome reparto " << i + 1 << ": " << endl;
                cin >> rep[i];
                cout << "Inserire incasso reparto " << rep[i] << endl;
                cin >> inc[i];
            }
        }
    }
    float rendita()
    {
        int tot = 0;
        for (int i = 0; i < num_rep; i++) {
            tot += inc[i];
        }
        return tot;
    }
    void print()
    {
        cout << "\nDati Supermercato:" << endl
             << "\t-Nome: " << nome << endl
             << "\t-Numero Reparti: " << num_rep << endl
             << "Dati Reparti:" << endl;
        for (int i = 0; i < num_rep; i++) {
            cout << "\t-" << rep[i] << ", incasso= " << inc[i] <<"\u20AC"<< endl;
        }
    }
    float incassorep(string r)
    {
        int pos;
        bool check = false;
        for (int i = 0; i < num_rep; i++) {
            if (rep[i] == r) {
                pos = i;
                check = true;
                break;
            }
        }
        if (check)
            return inc[pos];
        else {
            return 0;
        }
    }
    string returnnome() { return nome; }
    int returnnum_rep() { return num_rep; }
};

int main()
{
    Market Super[100];
    int scelta, sceltaSuper, userIndex;
    cout << "Inserire numero Supermercati" << endl;
    cin >> nc;
    for (int i = 0; i < nc; i++) {
        Super[i].input();
    }
    do {
        cout << "\nInserire valore per scegliere opzione" << endl
             << "Opzione 1: Scelta Supermercato" << endl
             << "Opzione 2: Stampa lista supermercati" << endl
             << "Opzione 3: Stampa totale incasso di ciascun supermercato" << endl
             << "Opzione 4: Stampa totale incassi per reparto dato di ciascun supermercato" << endl
             << "Opzione 5: Stampa dati del supermercato con piu incasso" << endl
             << "Opzione 6: Aggiungi supermercato" << endl
             << "Opzione 0: Esci dal programma" << endl;
        cin >> sceltaSuper;
        switch (sceltaSuper) {
        case 0:
            cout << "\n---Uscendo dal programma---" << endl;
            break;
        case 1:
            cout << "\nInserire Numero Supermercato da controllare" << endl;
            cin >> userIndex;
            userIndex--;
            if (userIndex >= 0 && userIndex < nc) {
                
                scelta;
                do {
                    cout << "\nInserire valore per scegliere opzione" << endl
                         << "Opzione 1: Re-inserimento valori supermercato" << endl
                         << "Opzione 2: Stampa incasso totale del supermercato" << endl
                         << "Opzione 3: Stampa dati del supermercato" << endl
                         << "Opzione 4: Stampa incasso reparto dato" << endl
                         << "Opzione 0: Esci dai Dati supermercato" << endl;
                    cin >> scelta;
                    switch (scelta) {
                    case 0:
                        cout << "\n---Uscendo dai dati supermercato---" << endl;
                        break;
                    case 1:
                        Super[userIndex].input();
                        break;
                    case 2:
                        cout << "\nIncasso totale: " << Super[userIndex].rendita() <<"\u20AC"<< endl;
                        break;
                    case 3:
                        Super[userIndex].print();
                        break;
                    case 4: {
                        string r;
                        cout << "\nInserire nome reparto da controllare" << endl;
                        cin >> r;
                        cout << "\nIncasso reparto " << r << ": " << Super[userIndex].incassorep(r) <<"\u20AC"<< endl;
                    } break;
                    default:
                        cout << "\nScelta inesistente" << endl;
                    }
                } while (scelta != 0);
            } else
                cout << "\nSupermercato non esistente" << endl;
            break;
        case 2: {
            cout << endl;
            for (int i = 0; i < nc; i++) {
                cout << "\t"<<i+1<<")-" << Super[i].returnnome() << " numero reparti: " << Super[i].returnnum_rep() << endl;
            }
        } break;
        case 3: {
            for (int i = 0; i < nc; i++) {
                cout << "\t-" << Super[i].returnnome() << " totale incasso: " << Super[i].rendita() <<"\u20AC"<< endl;
            }
        } break;
        case 4: {
            string r;
            cout << "\nInserire nome reparto da controllare" << endl;
            cin >> r;
            for (int i = 0; i < nc; i++) {
                cout << "\t-" << Super[i].returnnome() << " incasso reparto " << r << " : " << Super[i].incassorep(r)<<"\u20AC" << endl;
            }
        } break;
        case 5: {
            int pos, max, n;
            max = Super[0].rendita();
            for (int i = 0; i < nc; i++) {
                n = Super[i].rendita();
                if (n > max) {
                    max = n;
                    pos = i;
                }
            }
            cout << "\nDati supermercato con maggiore incasso" << endl;
            Super[pos].print();
        } break;
        case 6: {
            Super[nc].input();
            nc++;
        } break;
        default:
            cout << "\nScelta inesistente" << endl;
        }
    } while (sceltaSuper != 0);
}