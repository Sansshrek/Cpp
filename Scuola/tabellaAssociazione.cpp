/* data una tabella contenente dati relativi agli iscritti ad una associazione. per ogni iscritto il record ha:
cognome, data_acconto, acconto, data_saldo. considerare le date come string di 6 caratteri (es. 120320 sarebbe 12
marzo 2020). considerare il saldo pari a 200 euro mentre l'acconto è inferiore a 200. usando un menu:
a) aggiornare la tabella quando viene effettuato un pagamento
b) stampi l'elenco degli iscritti che devono pagare ancora il saldo, con il relativo acconto   */
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
string cognomiRandom[15] = {"Rossi", "Ferrari", "Bianchi", "Romano", "Gallo", "Costa", "Fontana", "Conti", "Esposito", "Bruno", "Rizzo", "Moretti", "Marino", "Barbieri", "Lombardi"};

struct iscritto
{
    string cognome;
    string data_acconto;
    double acconto;
    string data_saldo;
    bool pagato = false;
};
const int maxStart = 20;
struct iscritto pers[maxStart];


void InserimentoRandom(int max)
{
    srand(time(0));
    int cogRandIndex;
    char gg[2], mm[2], yy[2];
    for (int i = 0; i < max; i++)
    {
        //inserimento cognome
        cogRandIndex = rand() % 15; //0-14
        pers[i].cognome = cognomiRandom[cogRandIndex];
        //inserimento data acconto
        //ho aggiunto +48 ad ogni rand poiche il char legge solo i numeri ascii e 48 in ascii è 0 percio parte da 48
        gg[0] = (rand() % 3) + 48;           //giorno 2x    0-2
        gg[1] = ((rand() % 9) + 48) + 1;     //giorno x6    0-9
        mm[0] = (rand() % 2) + 48;           //mese 1x    0-1
        if (mm[0] == 48)                     //48 in ascii è 0
            mm[1] = ((rand() % 9) + 48) + 1; //mese x6   1-9
        else
            mm[1] = (rand() % 3) + 48; //mese x2   0-2
        yy[0] = (rand() % 3) + 48;     //anno 1x    0-2
        if (yy[0] == 50)               //50 in ascii è 2
            yy[1] = 48;                //anno 20
        else
            yy[1] = (rand() % 10) + 48; //anno x4    0-9
        for (int j = 0; j < 2; j++)
        {
            pers[i].data_acconto[j] = gg[j];
            pers[i].data_acconto[j + 2] = mm[j];
            pers[i].data_acconto[j + 4] = yy[j];
        }
        //inserimento acconto
        pers[i].acconto = rand() % 200;
        //inserimento data saldo
        gg[0] = (rand() % 3) + 48;           //giorno 2x    0-2
        gg[1] = ((rand() % 9) + 48) + 1;     //giorno x6    0-9
        mm[0] = (rand() % 2) + 48;           //mese 1x    0-1
        if (mm[0] == 48)                     //48 in ascii è 0
            mm[1] = ((rand() % 9) + 48) + 1; //mese x6   1-9
        else
            mm[1] = (rand() % 3) + 48; //mese x2   0-2
        yy[0] = (rand() % 3) + 48;     //anno 1x    0-2
        if (yy[0] == 50)               //50 in ascii è 2
            yy[1] = 48;                //anno 20
        else
            yy[1] = (rand() % 10) + 48; //anno x4    0-9
        for (int j = 0; j < 2; j++)
        {
            pers[i].data_saldo[j] = gg[j];
            pers[i].data_saldo[j + 2] = mm[j];
            pers[i].data_saldo[j + 4] = yy[j];
        }
        //reset del pagamento
        pers[i].pagato = false;
    }
}

int InserimentoIscritti(int max)
{
    string scelta;
    bool check_rand;
    cout << "\nVuoi modificare il numero massimo degli iscritti?  (si/no)" << endl;
    cin >> scelta;
    if (scelta == "si")
    {
        cout << "Inserire numero iscritti (max " << maxStart << ")" << endl;
        cin >> max;
    }
    else if (scelta == "no")
        cout << "Il numero massimo rimarra " << max << endl;
    else
        cout << "Scelta errata. Uscendo dall'opzione (il numero rimarra " << max << ")" << endl;
    cout << "Vuoi inserire gli iscritti in modo random?  (si/no)" << endl;
    cin >> scelta;
    if (scelta == "si"){
        InserimentoRandom(max);
        check_rand = true;
    }
    else if (scelta == "no")
        cout << "L'inserimento degli iscritti sara manuale" << endl;
    else
        cout << "Scelta errata. Inserimento manuale in corso" << endl;
    if(check_rand != true){
        bool check_data_acconto, check_acconto, check_data_saldo;
        for (int i = 0; i < max; i++)
        {
            cout << "\nInserire dati iscritto numero " << i + 1;
            cout << "\nCognome: ";
            cin >> pers[i].cognome;
            //controllo data acconto
            do
            {
                cout << "\nData dell'acconto (es inserimento: 230312): ";
                cin >> pers[i].data_acconto;
                //siccome pers[i].data_acconto è un char i valori numerici inseriti diventeranno valori ascii quindi
                //ho messo -48 davanti al valore di pers poiche 48 in ascii sarebbe 0 quindi farebbe un controllo dei
                //valori come se fossero interi senza bisogno di convertirli uno per uno
                if (pers[i].data_acconto[0] - 48 < 0 && pers[i].data_acconto[0] - 48 <= 0 ||
                    pers[i].data_acconto[0] - 48 > 2 ||
                    pers[i].data_acconto[0] - 48 == 0 && pers[i].data_acconto[1] - 48 == 0 ||
                    pers[i].data_acconto[2] - 48 > 1 ||
                    pers[i].data_acconto[2] - 48 == 0 && pers[i].data_acconto[3] - 48 == 0 ||
                    pers[i].data_acconto[2] - 48 == 1 && pers[i].data_acconto[3] - 48 > 2 ||
                    pers[i].data_acconto[4] - 48 > 2 ||
                    pers[i].data_acconto[4] - 48 == 2 && pers[i].data_acconto[5] - 48 > 0)
                    cout << "Valore impossibile. Reinserirlo" << endl;
                else
                    check_data_acconto = true;
            } while (check_data_acconto != true);
            //controllo valore acconto
            do
            {
                cout << "\nValore acconto: ";
                cin >> pers[i].acconto;
                if (pers[i].acconto >= 200)
                    cout << "\nIl valore dell'acconto supera il saldo da pagare. Reinserire il valore" << endl;
                else
                    check_acconto = true;
            } while (check_acconto != true);
            //controllo data saldo
            do
            {
                cout << "\nData scadenza saldo (es inserimento: 230312): ";
                cin >> pers[i].data_saldo;
                if (pers[i].data_saldo[0] - 48 < 0 && pers[i].data_saldo[0] - 48 <= 0 ||
                    pers[i].data_saldo[0] - 48 > 2 ||
                    pers[i].data_saldo[0] - 48 == 0 && pers[i].data_saldo[1] - 48 == 0 ||
                    pers[i].data_saldo[2] - 48 > 1 ||
                    pers[i].data_saldo[2] - 48 == 0 && pers[i].data_saldo[3] - 48 == 0 ||
                    pers[i].data_saldo[2] - 48 == 1 && pers[i].data_saldo[3] - 48 > 2 ||
                    pers[i].data_saldo[4] - 48 > 2 ||
                    pers[i].data_saldo[4] - 48 == 2 && pers[i].data_saldo[5] - 48 > 0)
                    cout << "Valore impossibile. Reinserirlo" << endl;
                else
                    check_data_saldo = true;
            } while (check_data_saldo != true);
        }
    }
    return max;
}

/*
|  cognomi  | data acc.|acconto| data saldo |pagato|
| zzzz      | 12/34/56 |  xxx  |  12/34/56  |  si  |
| bb        | 12/34/56 |  xxx  |  12/34/56  |  no  |
*/
void StampaIscritti(int max)
{
    int spazi_cognome, spazi_acconto, n;
    char acconto[3];
    cout << "\n|  cognomi  | data acc. |acconto| data saldo |pagato|" << endl;
    for (int i = 0; i < max; i++)
    {
        //stampa cognome
        cout << "| " << pers[i].cognome;
        //controllo quanti spazi mettere dopo il cognome
        spazi_cognome = 10 - pers[i].cognome.length();
        for (int j = 0; j < spazi_cognome; j++)
        {
            cout << " ";
        }
        cout << "| ";
        //stampa data acconto
        for (int j = 0; j < 6; j++)
        {
            cout << pers[i].data_acconto[j] << pers[i].data_acconto[j + 1];
            if (j < 4)
                cout << "/";
            j++;
        }
        //stampa acconto
        cout << "  |  " << pers[i].acconto;
        //controllo quanti spazi mettere dopo l'acconto
        //ho inserito il valore di pers in n poiche nella funzione sprintf non legge bene il valore dalla struct
        n = pers[i].acconto;
        spazi_acconto = 5 - sprintf(acconto, "%d", n);
        for (int j = 0; j < spazi_acconto; j++)
        {
            cout << " ";
        }
        cout << "|  ";
        //stampa data saldo
        for (int j = 0; j < 6; j++)
        {
            cout << pers[i].data_saldo[j] << pers[i].data_saldo[j + 1];
            if (j < 4)
                cout << "/";
            j++;
        }
        cout << "  |  ";
        if (pers[i].pagato == true)
            cout << "si  |" << endl;
        else
            cout << "no  |" << endl;
    }
}

void StampaPaganti(int max)
{
    cout << "\nDevono ancora pagare:" << endl;
    for (int i = 0; i < max; i++)
    {
        if (pers[i].pagato == false)
        {
            cout << "\n-" << pers[i].cognome
                 << ",  acconto: " << pers[i].acconto
                 << ",  data del saldo: ";
            for (int j = 0; j < 6; j++)
            {
                cout << pers[i].data_saldo[j] << pers[i].data_saldo[j + 1];
                if (j < 4)
                    cout << "/";
                j++;
            }
            cout << endl;
        }
    }
}

void Pagamento(int max)
{
    bool check = false;
    int index;
    string scelta;
    string cogRicerca;
    StampaPaganti(max);
    cout << "\nInserire cognome che ha pagato" << endl;
    cin >> cogRicerca;
    for (int i = 0; i < max; i++)
    {
        if (cogRicerca == pers[i].cognome)
        {
            check = true;
            index = i;
        }
    }
    if (check == false)
        cout << "Cognome non trovato - Controllare di aver inserito bene le maiuscole" << endl;
    else
    {
        cout << "Vuoi confermare il pagamento per il sig. " << cogRicerca << "?  (si/no)" << endl;
        cin >> scelta;
        if (scelta == "si")
        {
            pers[index].pagato = true;
            cout << "Pagamento completato" << endl;
        }
        else if (scelta == "no")
            cout << "Uscendo dall'opzione" << endl;
        else
            cout << "Scelta errata. Uscendo dall'opzione" << endl;
    }
}

int Aggiunta(int max)
{
    int nuovoMax;
    cout << "Quante persone vuoi aggiungere alla tabella? (massimo " << maxStart - max << ")" << endl;
    cin >> nuovoMax;
    cout << "Verranno aggiunte " << nuovoMax << " persona/e" << endl;
    int scelta;
    bool check_data_acconto, check_acconto, check_data_saldo;
    for (int i = 0; i < nuovoMax; i++)
    {
        cout << "\nInserire dati iscritto numero " << i + 1;
        cout << "\nCognome: ";
        cin >> pers[max + i].cognome;
        //controllo data acconto
        do
        {
            cout << "\nData dell'acconto (es inserimento: 230312): ";
            cin >> pers[max + i].data_acconto;
            if (pers[max + i].data_acconto[0] - 48 < 0 && pers[max + i].data_acconto[0] - 48 <= 0 ||
                pers[max + i].data_acconto[0] - 48 > 2 ||
                pers[max + i].data_acconto[0] - 48 == 0 && pers[max + i].data_acconto[1] - 48 == 0 ||
                pers[max + i].data_acconto[2] - 48 > 1 ||
                pers[max + i].data_acconto[2] - 48 == 0 && pers[max + i].data_acconto[3] - 48 == 0 ||
                pers[max + i].data_acconto[2] - 48 == 1 && pers[max + i].data_acconto[3] - 48 > 2 ||
                pers[max + i].data_acconto[4] - 48 > 2 ||
                pers[max + i].data_acconto[4] - 48 == 2 && pers[max + i].data_acconto[5] - 48 > 0)
                cout << "Valore impossibile. Reinserirlo" << endl;
            else
                check_data_acconto = true;
        } while (check_data_acconto != true);
        //controllo valore acconto
        do
        {
            cout << "\nValore acconto: ";
            cin >> pers[max + i].acconto;
            if (pers[max + i].acconto >= 200)
                cout << "\nIl valore dell'acconto supera il saldo da pagare. Reinserire il valore" << endl;
            else
                check_acconto = true;
        } while (check_acconto != true);
        //controllo data saldo
        do
        {
            cout << "\nData scadenza saldo (es inserimento: 230312): ";
            cin >> pers[max + i].data_saldo;
            if (pers[max + i].data_saldo[0] - 48 < 0 && pers[max + i].data_saldo[0] - 48 <= 0 ||
                pers[max + i].data_saldo[0] - 48 > 2 ||
                pers[max + i].data_saldo[0] - 48 == 0 && pers[max + i].data_saldo[1] - 48 == 0 ||
                pers[max + i].data_saldo[2] - 48 > 1 ||
                pers[max + i].data_saldo[2] - 48 == 0 && pers[max + i].data_saldo[3] - 48 == 0 ||
                pers[max + i].data_saldo[2] - 48 == 1 && pers[max + i].data_saldo[3] - 48 > 2 ||
                pers[max + i].data_saldo[4] - 48 > 2 ||
                pers[max + i].data_saldo[4] - 48 == 2 && pers[max + i].data_saldo[5] - 48 > 0)
                cout << "Valore impossibile. Reinserirlo" << endl;
            else
                check_data_saldo = true;
        } while (check_data_saldo != true);
    } 
    nuovoMax += max;
    return nuovoMax;
}

int EliminaIscritti(int max)
{
    int nuovoMax = max, pos;
    string cognome;
    bool check;
    cout << "Inserire cognome che si vuole eliminare" << endl;
    cin >> cognome;
    for (int i = 0; i < max; i++) {
        if (pers[i].cognome == cognome) {
            check = true;
            pos = i;
        }
    }
    if (check) {
        for (int j = pos; j <= max; j++) {
            pers[j].cognome = pers[j + 1].cognome;
            pers[j].data_acconto = pers[j + 1].data_acconto;
            pers[j].acconto = pers[j + 1].acconto;
            pers[j].data_saldo = pers[j + 1].data_saldo;
        }
        cout << "Iscritto eliminato correttamente." << endl;
        nuovoMax--;
    }
    return nuovoMax;
}

int main()
{
    int maxIscritti;
    cout << "Inserire numero iscritti (max " << maxStart << ")" << endl;
    cin >> maxIscritti;
    InserimentoRandom(maxIscritti);
    int scelta;
    do
    {
        cout << "\nInserire valore per scegliere opzione" << endl
             << "Opzione 1: Nuovo inserimento degli iscritti" << endl
             << "Opzione 2: Inserimento random degli iscritti" << endl
             << "Opzione 3: Stampa tabella iscritti con rispettivi acconti e saldi" << endl
             << "Opzione 4: Pagamento per cognome" << endl
             << "Opzione 5: Stampa elenco iscritti che devono ancora pagare e il relativo acconto" << endl
             << "Opzione 6: Aggiunta iscritto alla tabella" << endl
             << "Opzione 7: Elimina iscritto dalla tabella" << endl
             << "Opzione 0: Uscire dal programma" << endl;
        cin >> scelta;
        switch (scelta)
        {
        case 0:
            cout << "\n---Uscendo dal programma---";
            break;
        case 1:
            maxIscritti = InserimentoIscritti(maxIscritti);
            break;
        case 2:
            InserimentoRandom(maxIscritti);
            cout << "\nRandomizzazione completata" << endl;
            break;
        case 3:
            StampaIscritti(maxIscritti);
            break;
        case 4:
            Pagamento(maxIscritti);
            break;
        case 5:
            StampaPaganti(maxIscritti);
            break;
        case 6:
            maxIscritti = Aggiunta(maxIscritti);
            break;
        case 7:
            maxIscritti = EliminaIscritti(maxIscritti);
            break;
        default:
            cout << "Reinserire opzione" << endl;
        }
    } while (scelta != 0);
    return 0;
}