/*classe conto corrente con codice conto, saldo, cognome, nome. codice univoco
per conto con deposito minimo di 100 euro. gestire un insieme di conti bancari
prevedendo:
1)La creazione di un conto nuovo
2)Prelievo da un conto, fornendo il codice conto
3)Versamento su un conto, fornendo il codice conto
4)Stampa dei dati di un conto, fornendo il codice conto
5)Lo spostamento di denari da un conto all'altro, fornendo i codici conto
6)La lettura dei dati dei conti correnti con il massimo ed il minimo di saldo
7)La scrittura su un file dei codici dei conti aventi il saldo superiore alla media dei saldi di tutti i conti
8)La stampa dei saldi dei conti ordinati in ordine decrescente, dal piu grande al piu piccolo
9)La creazione di nuovi conti correnti leggendo i dati da un file  */
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string.h>
#include <time.h>
using namespace std;

string cognomiRandom[15] = {"Rossi", "Ferrari", "Bianchi", "Romano", "Gallo", "Costa", "Fontana", "Conti", "Esposito", "Bruno", "Rizzo", "Moretti", "Marino", "Barbieri", "Lombardi"};
string nomiRandom[15] = {"Carlo", "Luca", "Andrea", "Giorgio", "Nicola", "Alessio", "Simone", "Leonardo", "Francesco", "Mattia", "Gabriele", "Riccardo", "Edoardo", "Tommaso", "Alessandro"};

class dati {
    string codice, nome, cognome;
    float saldo;

  public:
    void input(string cod, string nom, string cog, float s) {
        codice = cod;
        nome = nom;
        cognome = cog;
        saldo = s;
    }
    void prelievo(float s) { saldo -= s; }
    void versamento(float s) { saldo += s; }
    void stampa(int user) {
        cout << "\nDati conto utente:" << user << endl;
        cout << "\tNome: " << nome << " " << cognome << endl;
        cout << "\tCodice: " << codice << endl;
        cout << "\tSaldo: " << saldo << "\u20AC" << endl;
    }
    string get_cod() { return codice; }
    string get_nom() { return nome; }
    string get_cog() { return cognome; }
    float get_saldo() { return saldo; }
};

int main() {
    srand(time(0));
    int nc, scelta;
    dati conto[100];
    do {
        cout << "Inserire numero conti" << endl;
        cin >> nc;
        if (nc < 0)
            cout << "\nScelta numero impossibile" << endl;
    } while (nc < 0);
    int cont = 0;
    int sceltaInsert;
    do {
        cout << "\nInserire valore in modo casuale(1) o manuale(2)" << endl;
        cin >> sceltaInsert;
        if (sceltaInsert != 1 && sceltaInsert != 2)
            cout << "\nScelta inesistente" << endl;
    } while (sceltaInsert != 1 && sceltaInsert != 2);
    for (int i = 0; i < nc; i++) {
        string cod, nom, cog;
        float s;
        bool check = false;
        if (sceltaInsert == 1) {
            cod = to_string(rand() % 1000);
            int len_nom = (sizeof(nomiRandom) / sizeof(*nomiRandom));
            int len_cog = (sizeof(cognomiRandom) / sizeof(*cognomiRandom));
            int index = rand() % len_nom;
            nom = nomiRandom[index];
            index = rand() % len_cog;
            cog = cognomiRandom[index];
            s = (rand() % 900) + 100;
        } else if (sceltaInsert == 2) {
            do {
                cout << "\nInserire codice utente " << i + 1 << endl;
                cin >> cod;
                for (int j = 0; j < cont; j++) {
                    if (cod == conto[j].get_cod()) {
                        check = true;
                        break;
                    }
                }
                if (check)
                    cout << "\nERRORE: Codice gia esistente" << endl;
            } while (check);
            cont++;
            cout << "Inserire nome e cognome utente " << i + 1 << endl;
            cin >> nom;
            cin >> cog;
            do {
                cout << "Inserire saldo utente " << i + 1 << " (minimo 100 euro)" << endl;
                cin >> s;
                if (s < 100)
                    cout << "\nERRORE: saldo immesso troppo basso (minimo 100 euro)" << endl;
            } while (s < 100);
        }
        conto[i].input(cod, nom, cog, s);
    }
    do {
        cout << "\nInserire valore per scegliere opzione" << endl;
        cout << "Opzione 1: Crea nuovo conto" << endl;
        cout << "Opzione 2: Stampa lista conti" << endl;
        cout << "Opzione 3: Scelta conto corrente" << endl;
        cout << "Opzione 4: Versamento su un conto, dato codice" << endl;
        cout << "Opzione 5: Prelievo da un conto, dato codice" << endl;
        cout << "Opzione 6: Stampa di un conto, dato codice" << endl;
        cout << "Opzione 7: Spostamento di denaro da due conti, dati codici" << endl;
        cout << "Opzione 8: Stampa conto con saldo massimo e minimo" << endl;
        cout << "Opzione 9: Inserire su file i conti con saldo maggiore alla media dei saldi" << endl;
        cout << "Opzione 10: Stampa saldi ordinati in ordine decrescente" << endl;
        cout << "Opzione 11: Crea nuovi conti da file" << endl;
        cout << "Opzione 12: Elimina conto, dato codice" << endl;
        cout << "Opzione 0: Esci dal programma" << endl;
        cin >> scelta;
        switch (scelta) {
        case 0:
            cout << "\n--Uscendo dal programma--" << endl;
            break;
        case 1: {
            string cod, nom, cog;
            float s;
            bool check = false;
            int sceltaInsert;
            cout << "\nInserire valore in modo casuale(1) o manuale(2)" << endl;
            cin >> sceltaInsert;
            if (sceltaInsert == 1) {
                cod = to_string(rand() % 1000);
                int len_nom = (sizeof(nomiRandom) / sizeof(*nomiRandom));
                int len_cog = (sizeof(cognomiRandom) / sizeof(*cognomiRandom));
                int index = rand() % len_nom;
                nom = nomiRandom[index];
                index = rand() % len_cog;
                cog = cognomiRandom[index];
                s = (rand() % 900) + 100;
            } else if (sceltaInsert == 2) {
                do {
                    cout << "\nInserire codice utente " << nc << endl;
                    cin >> cod;
                    for (int j = 0; j < cont; j++) {
                        if (cod == conto[j].get_cod()) {
                            check = true;
                            break;
                        }
                    }
                    if (check)
                        cout << "\nERRORE: Codice gia esistente" << endl;
                } while (check);
                cont++;
                cout << "Inserire nome e cognome utente " << nc << endl;
                cin >> nom;
                cin >> cog;
                do {
                    cout << "Inserire saldo utente " << nc << " (minimo 100 euro)" << endl;
                    cin >> s;
                    if (s < 100)
                        cout << "\nERRORE: saldo immesso troppo basso (minimo 100 "
                                "euro)"
                             << endl;
                } while (s < 100);
            }
            conto[nc].input(cod, nom, cog, s);
            nc++;
        } break;
        case 2: {
            cout << endl;
            for (int i = 0; i < nc; i++) {
                cout << i + 1 << ")Conto: " << conto[i].get_cod() << ", " << conto[i].get_nom() << " " << conto[i].get_cog() << ", " << conto[i].get_saldo() << "\u20AC" << endl;
            }
        } break;
        case 3: {
            int indexConto, sceltaConto;
            cout << "\nInserire indice conto corrente" << endl;
            cin >> indexConto;
            indexConto--;
            if (indexConto >= 0 && indexConto < nc) {
                do {
                    cout << "\nInserire valore per scegliere opzione" << endl;
                    cout << "Opzione 1: Stampa dati Conto" << endl;
                    cout << "Opzione 2: Versamento su conto" << endl;
                    cout << "Opzione 3: Prelievo da conto" << endl;
                    cout << "Opzione 0: Esci dal conto corrente" << endl;
                    cin >> sceltaConto;
                    switch (sceltaConto) {
                    case 0:
                        cout << "\n--Uscendo dal conto corrente--" << endl;
                        break;
                    case 1:
                        conto[indexConto].stampa(indexConto);
                        break;
                    case 2: {
                        float n;
                        cout << "\nInserire quantita da versare" << endl;
                        cin >> n;
                        conto[indexConto].versamento(n);
                    } break;
                    case 3: {
                        float n;
                        cout << "\nInserire quantita da prelevare" << endl;
                        cin >> n;
                        if (n < conto[indexConto].get_saldo())
                            conto[indexConto].prelievo(n);
                        else
                            cout << "\nQuantita da prelevare maggiore di quella disponibilie (" << conto[indexConto].get_saldo() << ")" << endl;
                    } break;
                    default:
                        cout << "\nScelta inesistente" << endl;
                    }
                } while (sceltaConto != 0);
            } else
                cout << "\nConto corrente inesistente" << endl;
        } break;
        case 4: {
            string cod;
            int pos;
            float n;
            bool check = false;
            cout << "\nInserire codice da versare" << endl;
            cin >> cod;
            for (int i = 0; i < nc; i++) {
                if (conto[i].get_cod() == cod) {
                    pos = i;
                    check = true;
                    cout << "\nCodice trovato" << endl;
                    break;
                }
            }
            if (!check) {
                cout << "\nCodice non trovato... ricerca in base a nome" << endl;
                for (int i = 0; i < nc; i++) {
                    if (conto[i].get_nom() == cod) {
                        pos = i;
                        check = true;
                        cout << "\nNome trovato";
                        break;
                    }
                }
                if (!check) {
                    cout << "\nNome non trovato... ricerca in base a cognome" << endl;
                    for (int i = 0; i < nc; i++) {
                        if (conto[i].get_cog() == cod) {
                            pos = i;
                            check = true;
                            cout << "\nCognome trovato";
                            break;
                        }
                    }
                }
            }
            if (check) {
                cout << "\nInserire quantita da versare" << endl;
                cin >> n;
                conto[pos].versamento(n);
            } else
                cout << "\nCodice non trovato" << endl;
        } break;
        case 5: {
            string cod;
            int pos;
            float n;
            bool check = false;
            cout << "\nInserire codice da prelevare" << endl;
            cin >> cod;
            for (int i = 0; i < nc; i++) {
                if (conto[i].get_cod() == cod) {
                    pos = i;
                    check = true;
                    cout << "\nCodice trovato";
                    break;
                }
            }
            if (!check) {
                cout << "\nCodice non trovato... ricerca in base a nome" << endl;
                for (int i = 0; i < nc; i++) {
                    if (conto[i].get_nom() == cod) {
                        pos = i;
                        check = true;
                        cout << "\nNome trovato";
                        break;
                    }
                }
                if (!check) {
                    cout << "\nNome non trovato... ricerca in base a cognome" << endl;
                    for (int i = 0; i < nc; i++) {
                        if (conto[i].get_cog() == cod) {
                            pos = i;
                            check = true;
                            cout << "\nCognome trovato";
                            break;
                        }
                    }
                }
            }
            if (check) {
                cout << "\nInserire quantita da prelevare" << endl;
                cin >> n;
                if (n < conto[pos].get_saldo())
                    conto[pos].prelievo(n);
                else
                    cout << "\nQuantita da prelevare maggiore di quella disponibilie (" << conto[pos].get_saldo() << ")" << endl;
            } else
                cout << "\nCodice non trovato" << endl;
        } break;
        case 6: {
            string cod;
            int pos;
            bool check = false;
            cout << "\nInserire codice da stampare" << endl;
            cin >> cod;
            for (int i = 0; i < nc; i++) {
                if (conto[i].get_cod() == cod) {
                    pos = i;
                    check = true;
                    cout << "\nCodice trovato";
                    break;
                }
            }
            if (!check) {
                cout << "\nCodice non trovato... ricerca in base a nome" << endl;
                for (int i = 0; i < nc; i++) {
                    if (conto[i].get_nom() == cod) {
                        pos = i;
                        check = true;
                        cout << "\nNome trovato";
                        break;
                    }
                }
                if (!check) {
                    cout << "\nNome non trovato... ricerca in base a cognome" << endl;
                    for (int i = 0; i < nc; i++) {
                        if (conto[i].get_cog() == cod) {
                            pos = i;
                            check = true;
                            cout << "\nCognome trovato";
                            break;
                        }
                    }
                }
            }
            if (check)
                conto[pos].stampa(pos);
            else
                cout << "\nCodice non trovato" << endl;
        } break;
        case 7: {
            string cod1, cod2;
            int pos1, pos2;
            bool check = false;
            cout << "\nInserire primo codice da controllare" << endl;
            cin >> cod1;
            for (int i = 0; i < nc; i++) {
                if (conto[i].get_cod() == cod1) {
                    pos1 = i;
                    check = true;
                }
            }
            if (!check) {
                cout << "\nCodice non trovato... ricerca in base a nome" << endl;
                for (int i = 0; i < nc; i++) {
                    if (conto[i].get_nom() == cod1) {
                        pos1 = i;
                        check = true;
                    }
                }
                if (!check) {
                    cout << "\nNome non trovato... ricerca in base a cognome" << endl;
                    for (int i = 0; i < nc; i++) {
                        if (conto[i].get_cog() == cod1) {
                            pos1 = i;
                            check = true;
                        }
                    }
                }
            }
            if (check) {
                do {
                    check = false;
                    cout << "\nInserire secondo codice da controllare" << endl;
                    cin >> cod2;
                    for (int i = 0; i < nc; i++) {
                        if (conto[i].get_cod() == cod2) {
                            pos2 = i;
                            check = true;
                        }
                    }
                    if (!check) {
                        cout << "\nCodice non trovato... ricerca in base a nome" << endl;
                        for (int i = 0; i < nc; i++) {
                            if (conto[i].get_nom() == cod2) {
                                pos2 = i;
                                check = true;
                            }
                        }
                        if (!check) {
                            cout << "\nNome non trovato... ricerca in base a cognome" << endl;
                            for (int i = 0; i < nc; i++) {
                                if (conto[i].get_cog() == cod2) {
                                    pos2 = i;
                                    check = true;
                                }
                            }
                        }
                    }
                    if (pos2 == pos1)
                        cout << "\nIl codice immesso e' uguale al primo" << endl;
                } while (pos2 == pos1);
                if (check) {
                    float n;
                    int scelta;
                    bool swapped = false;
                    do {
                        cout << "\nScelta trasferimento" << endl;
                        cout << "\t1) Dal primo conto al secondo" << endl;
                        cout << "\t2) Dal secondo conto al primo" << endl;
                        cin >> scelta;
                        if (scelta == 1) {
                            do {
                                cout << "\nInserire quantita da trasferire" << endl;
                                cin >> n;
                                if (n < conto[pos1].get_saldo()) {
                                    swapped = true;
                                    conto[pos1].prelievo(n);
                                    conto[pos2].versamento(n);
                                } else
                                    cout << "\nQuantita da prelevare maggiore di quella disponibilie (" << conto[pos1].get_saldo() << ")" << endl;
                            } while (!swapped);
                        } else if (scelta == 2) {
                            do {
                                cout << "\nInserire quantita da trasferire" << endl;
                                cin >> n;
                                if (n < conto[pos2].get_saldo()) {
                                    swapped = true;
                                    conto[pos1].versamento(n);
                                    conto[pos2].prelievo(n);
                                } else
                                    cout << "\nQuantita da prelevare maggiore di quella disponibilie (" << conto[pos2].get_saldo() << ")" << endl;
                            } while (!swapped);
                        } else
                            cout << "\nScelta inesistente" << endl;
                    } while (!swapped);
                } else
                    cout << "\nSecondo codice non trovato" << endl;
            } else
                cout << "\nPrimo codice non trovato" << endl;
        } break;
        case 8: {
            int max = 0, min = conto[0].get_saldo(), pos_max, pos_min = 0;
            for (int i = 0; i < nc; i++) {
                if (conto[i].get_saldo() > max) {
                    max = conto[i].get_saldo();
                    pos_max = i;
                }
                if (conto[i].get_saldo() < min) {
                    min = conto[i].get_saldo();
                    pos_min = i;
                }
            }
            cout << "\nConto con saldo maggiore: " << endl;
            cout << "\nConto con saldo minore: " << endl;
        } break;
        case 9: {
            fstream File;
            File.open("media.txt", ios::out);
            float med = 0;
            for (int i = 0; i < nc; i++) {
                med += conto[i].get_saldo();
            }
            med /= nc;
            cout << "\nMedia = " << med << endl;
            for (int i = 0; i < nc; i++) {
                if (conto[i].get_saldo() > med)
                    File << conto[i].get_cod() << " " << conto[i].get_nom() << " " << conto[i].get_cog() << " " << conto[i].get_saldo() << "\n";
            }
            File.close();
        } break;
        case 10: {
            dati Copia[nc], tmp;
            for (int i = 0; i < nc; i++) {
                Copia[i] = conto[i];
            }
            int sceltaOrd1, sceltaOrd2;
            do {
                cout << "\nScelta tipo ordinamento" << endl;
                cout << "\t1) Ordinamento in base al codice" << endl;
                cout << "\t2) Ordinamento in base al nome" << endl;
                cout << "\t3) Ordinamento in base al cognome" << endl;
                cout << "\t4) Ordinamento in base al saldo" << endl;
                cin >> sceltaOrd1;
                if (sceltaOrd1 != 1 && sceltaOrd1 != 2 && sceltaOrd1 != 3 && sceltaOrd1 != 4)
                    cout << "\nScelta inesistente" << endl;
            } while (sceltaOrd1 != 1 && sceltaOrd1 != 2 && sceltaOrd1 != 3 && sceltaOrd1 != 4);
            do {
                cout << "\nVuoi eseguire l'ordinamento:" << endl << "\t1) Dal piu grande al piu piccolo" << endl << "\t2) Dal piu piccolo al piu grande" << endl;
                cin >> sceltaOrd2;
                if (sceltaOrd2 != 1 && sceltaOrd2 != 2)
                    cout << "\nScelta inesistente" << endl;
            } while (sceltaOrd2 != 1 && sceltaOrd2 != 2);
            switch (sceltaOrd1) {
            case 1: {
                for (int i = 0; i < nc; i++) {
                    for (int j = i + 1; j < nc; j++) {
                        if (sceltaOrd2 == 1) {
                            if (Copia[j].get_cod() > Copia[i].get_cod()) {
                                tmp = Copia[i];
                                Copia[i] = Copia[j];
                                Copia[j] = tmp;
                            }
                        } else if (sceltaOrd2 == 2) {
                            if (Copia[j].get_cod() < Copia[i].get_cod()) {
                                tmp = Copia[i];
                                Copia[i] = Copia[j];
                                Copia[j] = tmp;
                            }
                        }
                    }
                }
            } break;
            case 2: {
                for (int i = 0; i < nc; i++) {
                    for (int j = i + 1; j < nc; j++) {
                        if (sceltaOrd2 == 1) {
                            if (Copia[j].get_nom() > Copia[i].get_nom()) {
                                tmp = Copia[i];
                                Copia[i] = Copia[j];
                                Copia[j] = tmp;
                            }
                        } else if (sceltaOrd2 == 2) {
                            if (Copia[j].get_nom() < Copia[i].get_nom()) {
                                tmp = Copia[i];
                                Copia[i] = Copia[j];
                                Copia[j] = tmp;
                            }
                        }
                    }
                }
            } break;
            case 3: {
                for (int i = 0; i < nc; i++) {
                    for (int j = i + 1; j < nc; j++) {
                        if (sceltaOrd2 == 1) {
                            if (Copia[j].get_cog() > Copia[i].get_cog()) {
                                tmp = Copia[i];
                                Copia[i] = Copia[j];
                                Copia[j] = tmp;
                            }
                        } else if (sceltaOrd2 == 2) {
                            if (Copia[j].get_cog() < Copia[i].get_cog()) {
                                tmp = Copia[i];
                                Copia[i] = Copia[j];
                                Copia[j] = tmp;
                            }
                        }
                    }
                }
            } break;
            case 4: {
                for (int i = 0; i < nc; i++) {
                    for (int j = i + 1; j < nc; j++) {
                        if (sceltaOrd2 == 1) {
                            if (Copia[j].get_saldo() > Copia[i].get_saldo()) {
                                tmp = Copia[i];
                                Copia[i] = Copia[j];
                                Copia[j] = tmp;
                            }
                        } else if (sceltaOrd2 == 2) {
                            if (Copia[j].get_saldo() < Copia[i].get_saldo()) {
                                tmp = Copia[i];
                                Copia[i] = Copia[j];
                                Copia[j] = tmp;
                            }
                        }
                    }
                }
            } break;
            default:
                cout << "\nScelta inesistente" << endl;
            }
            for (int i = 0; i < nc; i++) {
                Copia[i].stampa(i);
            }
        } break;
        case 11: {
            bool check = false;
            fstream File;
            cout << "\nInserire il file 'input.txt' nella cartella del programma" << endl;
            cout << "Formato file: codice, nome, cognome, saldo" << endl;
            File.open("input.txt", ios::in);
            if (File.is_open()) { // check esistenza file
                check = true;     // il file esiste
                int sal;
                string cod, nom, cog;
                do {
                    File >> cod >> nom >> cog >> sal;
                    conto[nc].input(cod, nom, cog, sal);
                    nc++;
                } while (!File.eof());
            }
            if (!check)
                cout << "\nIl file non esiste" << endl;
        } break;
        case 12: {
            string cod;
            int pos;
            bool check = false;
            cout << "\nVuoi stampare i conti delle persone con le posizioni? (si=1/no=0)" << endl;
            cin >> scelta;
            if (scelta == 1) {
                for (int i = 0; i < nc; i++) {
                    conto[i].stampa(i);
                }
            }
            cout << "\nInserisci codice da eliminare" << endl;
            cin >> cod;
            for (int i = 0; i < nc; i++) {
                if (conto[i].get_cod() == cod) {
                    pos = i;
                    check = true;
                    cout << "\nCodice trovato";
                    break;
                }
            }
            if (!check) {
                cout << "\nCodice non trovato... ricerca in base a nome" << endl;
                for (int i = 0; i < nc; i++) {
                    if (conto[i].get_nom() == cod) {
                        pos = i;
                        check = true;
                        cout << "\nNome trovato";
                        break;
                    }
                }
                if (!check) {
                    cout << "\nNome non trovato... ricerca in base a cognome" << endl;
                    for (int i = 0; i < nc; i++) {
                        if (conto[i].get_cog() == cod) {
                            pos = i;
                            check = true;
                            cout << "\nCognome trovato";
                            break;
                        }
                    }
                }
            }
            if (!check)
                cout << "\nCodice non trovato" << endl;
            else {
                if (pos != nc - 1) {
                    for (int i = pos; i < nc; i++) {
                        conto[i] = conto[i + 1];
                    }
                    nc--;
                } else
                    nc--;
                cout << "\nPersona eliminata correttamente." << endl;
            }
        } break;
        default:
            cout << "\nScelta inesistente" << endl;
        }
    } while (scelta != 0);
}