//Ordinamento record
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <time.h>
using namespace std;

string cognomiRandom[15] = { "Rossi", "Ferrari", "Bianchi", "Romano", "Gallo", "Costa", "Fontana", "Conti", "Esposito", "Bruno", "Rizzo", "Moretti", "Marino", "Barbieri", "Lombardi" };

struct prodotto {
    int cod;
    string nome;
    int costo;
};

struct prodotto prod[100];

void InserimentoRandom(int max)
{
    srand(time(0));
    int cogRandIndex;
    for (int i = 0; i < max; i++) {
        //inserimento codice
        prod[i].cod = rand() % 1000;
        //inserimento cognome
        cogRandIndex = rand() % 15;
        prod[i].nome = cognomiRandom[cogRandIndex];
        //inserimento costo
        prod[i].costo = rand() % 100;
    }
    cout << "\n\t-Randomizzazione Completata-" << endl;
}

int Inserimento()
{
    int max, scelta;
    cout << "Inserire numero prodotti da inserire" << endl;
    cin >> max;
    cout << "Vorresti inserire i valori manualmente o random?  (0/1)" << endl;
    cin >> scelta;
    if (scelta != 1) {
        for (int i = 0; i < max; i++) {
            cout << "Inserire codice prodotto " << i + 1 << endl;
            cin >> prod[i].cod;
            cout << "Inserire nome prodotto " << i + 1 << endl;
            cin >> prod[i].nome;
            cout << "Inserire costo prodotto " << i + 1 << endl;
            cin >> prod[i].costo;
        }
        cout << "\n\t-Inserimento Completato-" << endl;
    } else
        InserimentoRandom(max);
    return max;
}

int CheckLength(int cod)
{
    int i = 0, n = cod;
    do {
        n /= 10;
        i++;
    } while (n > 0);
    return i;
}

void Stampa(int max)
{
    int som, SpaziCodice, SpaziNome;
    if (max == 0)
        cout << "\nTabella vuota... Inserire prodotti" << endl;
    else {
        cout << "\n  codici     nomi       costo" << endl;
        for (int i = 0; i < max; i++) {
            //stampa codice
            cout << "| " << prod[i].cod;
            //controllo quanti spazi mettere dopo il codice
            SpaziCodice = 5 - CheckLength(prod[i].cod);
            for (int j = 0; j < SpaziCodice; j++) {
                cout << " ";
            }
            //stampa nome
            cout << "  | " << prod[i].nome;
            //controllo quanti spazi mettere dopo il nome
            SpaziNome = 10 - prod[i].nome.length();
            for (int j = 0; j < SpaziNome; j++) {
                cout << " ";
            }
            //stampa costo
            cout << " |  " << prod[i].costo << "$\t|" << endl;
        }
    }
}

void OrdinamentoCod(int max)
{
    bool checkScambio;
    prodotto tmp;
    int scelta;
    cout << "\nVuoi eseguire l'ordinamento:" << endl
         << "\tOpzione 0: dal piu grande al piu piccolo" << endl
         << "\tOpzione 1: dal piu piccolo al piu grande" << endl;
    cin >> scelta;
    if (scelta == 0 || scelta == 1) {
        for (int i = 0; i < max; i++) {
            checkScambio = false;
            for (int j = 1; j < (max - i); j++)
                if (scelta == 0) {
                    if (prod[j - 1].cod < prod[j].cod) {
                        tmp = prod[j - 1];
                        prod[j - 1] = prod[j];
                        prod[j] = tmp;
                        checkScambio = true;
                    }
                } else if (scelta == 1) {
                    if (prod[j - 1].cod > prod[j].cod) {
                        tmp = prod[j - 1];
                        prod[j - 1] = prod[j];
                        prod[j] = tmp;
                        checkScambio = true;
                    }
                }
            if (!checkScambio)
                break;
        }
    } else
        cout << "\nScelta inesistente" << endl;
    Stampa(max);
}

void OrdinamentoNome(int max)
{
    int Arrayint[100], tmp1;
    char Arraychar[100];
    prodotto tmp;
    bool checkScambio;
    for (int i = 0; i < max; i++) {
        Arraychar[i] = prod[i].nome[0];  //inserisce la prima lettera del nome nell'array
        Arrayint[i] = (int)Arraychar[i];  //trasforma i valori dell'array in interi
    }
    for (int i = 0; i < max; i++) {
        checkScambio = false;
        for (int j = 1; j < (max - i); j++)
            if (Arrayint[j - 1] > Arrayint[j]) {  //controllo valori array per ordinamento
                tmp1 = Arrayint[j - 1]; //scambio valori array int
                Arrayint[j - 1] = Arrayint[j];
                Arrayint[j] = tmp1;
                tmp = prod[j - 1];
                prod[j - 1] = prod[j];
                prod[j] = tmp;
                checkScambio = true;
            }
        if (!checkScambio)  //esce dal programma se non ci sono stati scambi
            break;
    }
    Stampa(max);  //era la procedura della stampa mia levala pure
}

void OrdinamentoCosto(int max)
{
    bool checkScambio;
    int scelta;
    prodotto tmp;
    cout << "\nVuoi eseguire l'ordinamento:" << endl
         << "\tOpzione 0: dal piu grande al piu piccolo" << endl
         << "\tOpzione 1: dal piu piccolo al piu grande" << endl;
    cin >> scelta;
    if (scelta == 0 || scelta == 1) {
        for (int i = 0; i < max; i++) {
            checkScambio = false;
            for (int j = 1; j < (max - i); j++)
                if (scelta == 0) {
                    if (prod[j - 1].costo < prod[j].costo) {
                        tmp = prod[j - 1];
                        prod[j - 1] = prod[j];
                        prod[j] = tmp;
                        checkScambio = true;
                    }
                } else if (scelta == 1) {
                    if (prod[j - 1].costo > prod[j].costo) {
                        tmp = prod[j - 1];
                        prod[j - 1] = prod[j];
                        prod[j] = tmp;
                        checkScambio = true;
                    }
                }
            if (!checkScambio)
                break;
        }
    } else
        cout << "\nScelta inesistente" << endl;
    Stampa(max);
}

void Ordinamento(int max)
{
    int scelta;
    cout << "\nIn che modo vuoi ordinare la tabella" << endl
         << "\tOpzione 1: Ordinamento in base al codice" << endl
         << "\tOpzione 2: Ordinamento in base al nome" << endl
         << "\tOpzione 3: Ordinamento in base al costo" << endl;
    cin >> scelta;
    switch (scelta) {
    case 1:
        OrdinamentoCod(max);
        break;
    case 2:
        OrdinamentoNome(max);
        break;
    case 3:
        OrdinamentoCosto(max);
        break;
    default:
        cout << "\nScelta inesistente" << endl;
    }
    cout << "\n\t-Ordinamento Completato-" << endl;
}

int AggiuntaProdotto(int max)
{
    int n;
    cout << "\nInserire numero di prodotti da aggiungere" << endl;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Inserire codice prodotto " << max + i + 1 << endl;
        cin >> prod[max + i].cod;
        cout << "Inserire nome prodotto " << max + i + 1 << endl;
        cin >> prod[max + i].nome;
        cout << "Inserire costo prodotto " << max + i + 1 << endl;
        cin >> prod[max + i].costo;
    }
    max += n;
    return max;
    cout << "\n\t-Aggiunta Completata-" << endl;
}

int EliminaProdotto(int max)
{
    int n = max, pos;
    string nome;
    bool check = false;
    cout << "\nInserire nome prodotto che si vuole eliminare" << endl;
    cin >> nome;
    for (int i = 0; i < max; i++) {
        if (prod[i].nome == nome) {
            check = true;
            pos = i;
            break;
        }
    }
    if (check == true) {
        for (int i = pos; i <= max; i++) {
            prod[i].cod = prod[i + 1].cod;
            prod[i].nome = prod[i + 1].nome;
            prod[i].costo = prod[i + 1].costo;
        }
        cout << "\n\t-Eliminazione Completata-" << endl;
        n--;
    } else {
        cout << "\nProdotto non trovato" << endl;
    }
    return n;
}

int main()
{
    int max, scelta;
    max = Inserimento();
    do {
        cout << "\nInserire numero per scegliere opzione" << endl
             << "Opzione 0: Uscire dal programma" << endl
             << "Opzione 1: Inserimento prodotti" << endl
             << "Opzione 2: Inserimento Random" << endl
             << "Opzione 3: Stampa prodotti" << endl
             << "Opzione 4: Ordinamento prodotti" << endl
             << "Opzione 5: Aggiunta prodotti" << endl
             << "Opzione 6: Elimina prodotto" << endl;
        cin >> scelta;
        switch (scelta) {
        case 0:
            cout << "\nUscendo dal programma..." << endl;
            break;
        case 1:
            max = Inserimento();
            break;
        case 2:
            InserimentoRandom(max);
            break;
        case 3:
            Stampa(max);
            break;
        case 4:
            Ordinamento(max);
            break;
        case 5:
            max = AggiuntaProdotto(max);
            break;
        case 6:
            max = EliminaProdotto(max);
            break;
        default:
            cout << "\nScelta inesistente" << endl;
        }
    } while (scelta != 0);
}