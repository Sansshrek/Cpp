/*dato un supermercato, considerare prodotti con codice,descrizione,quantita,prezzo
P001, pane, 200, 2.   programma che:
1)Inserisca in modo massivo i prodotti nella classe leggendoli da un file
2)Un metodo descriverà la vendita di uno o piu prodotto
3)Un metodo gestirà l'inserimento di uno o piu prodotto da menu
4)Un metodo stamperà la lista dei prodotti, con codice, descrizione, quantita e prezzo */
#include <fstream>
#include <iostream>
#include <string.h>
#include <time.h>
using namespace std;

string prodotti[] = { "Pane", "Cereali", "Latte", "Mela", "Biscotti", "Olio", "Banane", "Pesce", "Farina", "Sale", "Burro", "Uova", "Pasta" };

int cont = 0;

void inputMenu();

class Prodotti {
    string codice, descrizione;
    int quantita, prezzo;

public:
    void input(string c, string d, int q, int p)
    {
        codice = c;
        descrizione = d;
        quantita = q;
        prezzo = p;
    }
    void vendita()
    {
        bool check = false;
        int n;
        string cod;
        cout << "\nInserire codice del prodotto da vendere" << endl;
        cin >> cod;
        for (int i = 0; i < cont; i++) {
            if (codice == cod) {
                check = true;
                cout << "\nInserire quantita di " << descrizione << " venduto:" << endl;
                cin >> n;
                if (quantita >= n)
                    quantita -= n;
                else
                    cout << "\nIl numero inserito supera la quantita di " << descrizione << " disponibile (" << quantita << ")" << endl;
            }
        }
        if (!check) {
            cout << "\nCodice non trovato... ricerca della descrizione in corso" << endl;
            for (int i = 0; i < cont; i++) {
                if (descrizione == cod) {
                    check = true;
                    cout << "\nInserire quantita di " << descrizione << " venduto:" << endl;
                    cin >> n;
                    if (quantita > n)
                        quantita -= n;
                    else
                        cout << "\nIl numero inserito supera la quantita di " << descrizione << " disponibile (" << quantita << ")" << endl;
                }
            }
        }
        if (!check)
            cout << "\nProdotto non trovato" << endl;
    }
    void inserimento()
    {
        string cod;
        int n;
        bool check = false;
        cout << "\nInserire codice del prodotto da inserire" << endl;
        cin >> cod;
        for (int i = 0; i < cont; i++) {
            if (codice == cod) {
                check = true;
                cout << "\nInserire quantita di " << descrizione << " da inserire:" << endl;
                cin >> n;
                quantita += n;
            }
        }
        if (!check) {
            cout << "\nCodice non trovato... ricerca della descrizione in corso" << endl;
            for (int i = 0; i < cont; i++) {
                if (descrizione == cod) {
                    check = true;
                    cout << "\nInserire quantita di " << descrizione << " da inserire:" << endl;
                    cin >> n;
                    quantita += n;
                }
            }
        }
        if (!check)
            cout << "\nProdotto non trovato" << endl;
    }
    void stampa(int i)
    {
        cout << "\nProdotto " << i << endl;
        cout << "\t-codice: " << codice << endl;
        cout << "\t-descrizione: " << descrizione << endl;
        cout << "\t-quantita: " << quantita << endl;
        cout << "\t-prezzo: " << prezzo << endl;
    }
    void aggiunta()
    {
        cout << "aggiunta" << endl;
        /*
        int n;
        cout<<"\nQuanti prodotti vuoi inserire?"<<endl;
        cin>>n;
        for(int i=0;i<n;i++){
            cout<<"\nInserire codice prodotto "<<i+1<<endl;
            cin>>Prod[cont].codice;
            cout<<"Inserire descrizione prodotto "<<i+1<<endl;
            cin>>Prod[cont].descrizione;
            cout<<"Inserire quantita prodotto "<<i+1<<endl;
            cin>>Prod[cont].quantita;
            cout<<"Inserire prezzo prodotto "<<i+1<<endl;
            cin>>Prod[cont].prezzo;
            cont++;
        }
        */
    }
    void elimina()
    {
        cout << "elimina" << endl;
        /*
        string cod;
        bool check=false;
        int pos;
        cout<<"\nInserire codice del prodotto da inserire"<<endl;
        cin>>cod;
        for(int i=0;i<cont;i++){
            if(codice==cod){
                check=true;
                pos = i;
            }
        }
        if(!check){
            cout<<"\nCodice non trovato... ricerca della descrizione in corso"<<endl;
            for(int i=0;i<cont;i++){
                if(descrizione==cod){
                    check=true;
                    pos = i;
                }
            }
        }
        if(check){
            Dati tmp;
            for(int i=pos;i<cont;i++){
                tmp = Prod[i];
                Prod[i] = Prod[i+1];
                Prod[i+1]=tmp;
            }
            cont--;
            cout<<"\nEliminazione effettuata"<<endl;
        }
        else
            cout<<"\nProdotto non trovato"<<endl;
    */
    }
};

int main()
{
    Prodotti Super[100];
    cout << "\nInserire numero prodotti" << endl;
    cin >> cont;
    int scelta, sceltaProd, index;
    inputMenu();
    do {
        cout << "\nInserire opzione" << endl
             << "Opzione 1: Scelta prodotto" << endl
             << "Opzione 2: Stampa lista prodotti" << endl
             << "Opzione 0: Esci dal programma" << endl;
        cin >> sceltaProd;
        switch (sceltaProd) {
        case 0:
            cout << "\n---Uscendo dal programma---" << endl;
            break;
        case 1: {
            cout << "\nInserire numero prodotto da controllare" << endl;
            cin >> index;
            if (index >= 0 && index < cont) {
                do {
                    cout << "\nInserire opzione" << endl
                         << "Opzione 1: Scelta inserimento prodotti" << endl
                         << "Opzione 2: Vendita prodotto" << endl
                         << "Opzione 3: Inserimento prodotto" << endl
                         << "Opzione 4: Stampa prodotti" << endl
                         << "Opzione 5: Aggiunta prodotti" << endl
                         << "Opzione 6: Elimina prodotto" << endl
                         << "Opzione 0: Esci dal programma" << endl;
                    cin >> scelta;
                    switch (scelta) {
                    case 1:{
                        int scelta, prezzo, quantita;
                        string codice, descrizione;
                        do {
                            cout << "\nInserire Opzione" << endl
                                    << "Opzione 1: Inserimento Random" << endl
                                    << "Opzione 2: Inserimento manuale" << endl
                                    << "Opzione 3: Inserimento da file" << endl;
                            cin >> scelta;
                            switch (scelta) {
                            case 1: {
                                int length = (sizeof(prodotti) / sizeof(*prodotti)), index, n;
                                cout << "\nInserire quantita prodotti" << endl;
                                cin >> cont;
                                srand(time(0));
                                for (int i = 0; i < cont; i++) {
                                    n = (rand() % 9000) + 1000;
                                    codice = to_string(n);
                                    index = rand() % length;
                                    descrizione = prodotti[index];
                                    quantita = rand() % 50;
                                    prezzo = (rand() % 50) + 1;
                                    Super[i].input(codice, descrizione, quantita, prezzo);
                                }
                            } break;
                            case 2: {
                                cout << "\nInserire quantita prodotti" << endl;
                                cin >> cont;
                                for (int i = 0; i < cont; i++) {
                                    cout << "\nInserire codice prodotto " << i + 1 << endl;
                                    cin >> codice;
                                    cout << "Inserire descrizione prodotto " << i + 1 << endl;
                                    cin >> descrizione;
                                    cout << "Inserire quantita prodotto " << i + 1 << endl;
                                    cin >> quantita;
                                    cout << "Inserire prezzo prodotto " << i + 1 << endl;
                                    cin >> prezzo;
                                    Super[i].input(codice, descrizione, quantita, prezzo);
                                }
                            } break;
                            case 3: {
                                fstream File;
                                cont = 0;
                                File.open("prodotti.txt", ios::in);
                                if (File.is_open()) {
                                    while (!File.eof()) {
                                        File >> codice >> descrizione >> quantita >> prezzo;
                                        Super[cont].input(codice, descrizione, quantita, prezzo);
                                        cont++;
                                    }
                                    File.close();
                                } else {
                                    cout << "\nfile 'prodotti.txt' non trovato nella directory del file" << endl;
                                    cout << "Passaggio al menu inserimento" << endl;
                                    inputMenu();
                                }
                            } break;
                            default:
                                cout << "\nOpzione inesistente" << endl;
                            }
                        } while (scelta != 1 && scelta != 2 && scelta != 3);
                    }
                        break;
                    case 2:
                        Super[index].vendita();
                        break;
                    case 3:
                        Super[index].inserimento();
                        break;
                    case 4:
                        Super[index].stampa(index);
                        break;
                    case 5:
                        Super[index].aggiunta();
                        break;
                    case 6:
                        Super[index].elimina();
                        break;
                    default:
                        cout << "\nOpzione inesistente" << endl;
                    }
                } while (scelta != 0);
            } else
                cout << "\nProdotto non esistente" << endl;
        } break;
        case 2:
            cout << endl;
            for (int i = 0; i < cont; i++) {
                Super[i].stampa(i);
            }
            break;
        default:
            cout << "\nOpzione inesistente" << endl;
        }
    } while (sceltaProd != 0);
    return 0;
}