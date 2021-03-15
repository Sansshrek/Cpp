/*Dato un file di input contenente dei record con cognome, nome ed eta, caricare questi dati in una tabella
a)stampare media vendite superiori a dato fornito in input
b)trovare cliente con quantita massima e stampa del nome
c)dato nome cliente, stampare vendita o errore se non trovato
d)ordinare e stampare clienti in ordine alfabetico
*/
#include <fstream>
#include <iostream>
#include <math.h>
#include <string>
#include <time.h>
using namespace std;

string cognomiRandom[15] = { "Rossi", "Ferrari", "Bianchi", "Romano", "Gallo", "Costa", "Fontana", "Conti", "Esposito", "Bruno", "Rizzo", "Moretti", "Marino", "Barbieri", "Lombardi" };
string nomiRandom[15] = { "Carlo", "Luca", "Andrea", "Giorgio", "Nicola", "Alessio", "Simone", "Leonardo", "Francesco", "Mattia", "Gabriele", "Riccardo", "Edoardo", "Tommaso", "Alessandro" };
fstream File;

int nc = 0, eta;
string nome, cognome;

void Random()
{
    srand(time(0));
    File.open("tabella.txt", ios::out);
    int cogIndex;
    cout << "\nInserire massimo studenti" << endl;
    cin >> nc;
    srand(time(0));
    for (int i = 0; i < nc; i++) {
        cogIndex = rand() % 15;
        nome = nomiRandom[cogIndex];
        cogIndex = rand() % 15;
        cognome = cognomiRandom[cogIndex];
        eta = rand() % 50;
        File << nome << " " << cognome << " " << eta << "\n";
    }
    cout << "\n\t--Randomizzazione completata--" << endl;
    File.close();
}

void Inserimento()
{
    File.open("tabella.txt", ios::out);
    cout << "\nInserire massimo clienti" << endl;
    cin >> nc;
    for (int i = 0; i < nc; i++) {
        cout << "Inserire nome del cliente " << i + 1 << endl;
        cin >> nome;
        cout << "Inserire cognome del cliente " << i + 1 << endl;
        cin >> cognome;
        cout << "Inserire quantita etauta dal cliente " << i + 1 << endl;
        cin >> eta;
        File << nome << " " << cognome << " " << eta << "\n";
    }
    File.close();
}

void InserimentoFile()
{
    bool check = false;
    cout << "\nInserire il file 'tabella.txt' nella cartella del programma" << endl;
    File.open("tabella.txt", ios::in);
    if (File.is_open()) //check esistenza file
        check = true; //il file esiste
    if (!check)
        cout << "\nIl file non esiste" << endl;
    else {
        nc = 0;
        string x;
        File >> x;
        while (!File.eof()) {
            nc++;
        }
        cout << "Numero Clienti= " << nc << endl;
    }
    File.close();
}

void SceltaInsert()
{
    int scelta;
    cout << "\nInserire valore per scegliere opzione" << endl
         << "\n\tOpzione 1: Inserimento Random" << endl
         << "\n\tOpzione 2: Inserimento Manuale" << endl
         << "\n\tOpzione 3: Inserimento da File" << endl;
    cin >> scelta;
    switch (scelta) {
    case 1:
        Random();
        break;
    case 2:
        Inserimento();
        break;
    case 3:
        InserimentoFile();
        break;
    default:
        cout << "\nScelta inesistente" << endl;
    }
}

void Stampa()
{
    if (nc == 0)
        cout << "Non ci sono ancora persone nella lista" << endl;
    else {
        File.open("tabella.txt", ios::in);
        for (int i = 0; i < nc; i++) {
            File >> nome >> cognome >> eta;
            cout << "\nPersona " << i + 1 << ": " << nome << " " << cognome << " : " << eta << " anni" << endl;
        }
        File.close();
    }
}

void Maggiore18()
{
    if (nc == 0)
        cout << "\nNon ci sono ancora persone nella lista" << endl;
    else {
        cout << "\nLa lista di persone con l'eta maggiori di 18 anni e':" << endl;
        File.open("tabella.txt", ios::in);
        for (int i = 0; i < nc; i++) {
            File >> nome >> cognome >> eta;
            if (eta > 18)
                cout << "\nPersona " << i + 1 << ": " << nome << " " << cognome << " : " << eta << " anni" << endl;
        }
        File.close();
    }
}

void OrdinamentoEta()
{
    bool checkScambio;
    int eta1[nc], scelta, tmpInt;
    string nomi[nc], cognomi[nc], tmpStr;
    File.open("tabella.txt", ios::in);
    for (int i = 0; i < nc; i++) {
        File >> nomi[i] >> cognomi[i] >> eta1[i];
    }
    File.close();
    cout << "\nVuoi eseguire l'ordinamento:" << endl
         << "\tOpzione 0: dal piu grande al piu piccolo" << endl
         << "\tOpzione 1: dal piu piccolo al piu grande" << endl;
    cin >> scelta;
    if (scelta == 0 || scelta == 1) {
        for (int i = 0; i < nc; i++) {
            for (int j = i + 1; j < nc; j++) {
                if (scelta == 0) {
                    if (eta1[i] < eta1[j]) {
                        tmpStr = nomi[i]; //scambio nomi
                        nomi[i] = nomi[j];
                        nomi[j] = tmpStr;
                        tmpStr = cognomi[i]; //scambio cognomi
                        cognomi[i] = cognomi[j];
                        cognomi[j] = tmpStr;
                        tmpInt = eta1[i]; //scambio vendite
                        eta1[i] = eta1[j];
                        eta1[j] = tmpInt;
                    }
                } else if (scelta == 1) {
                    if (eta1[i] > eta1[j]) {
                        tmpStr = nomi[i]; //scambio nomi
                        nomi[i] = nomi[j];
                        nomi[j] = tmpStr;
                        tmpStr = cognomi[i]; //scambio cognomi
                        cognomi[i] = cognomi[j];
                        cognomi[j] = tmpStr;
                        tmpInt = eta1[i]; //scambio vendite
                        eta1[i] = eta1[j];
                        eta1[j] = tmpInt;
                    }
                }
            }
        }
    } else
        cout << "\nScelta inesistente" << endl;
    File.open("tabella.txt", ios::out);
    for (int i = 0; i < nc; i++) {
        File << nomi[i] << " " << cognomi[i] << " " << eta1[i] << "\n";
    }
    File.close();
}

void OrdinamentoNome()
{
    int eta1[nc], scelta, tmpInt;
    string nomi[nc], cognomi[nc], tmpStr;
    File.open("tabella.txt", ios::in);
    for (int i = 0; i < nc; i++) {
        File >> nomi[i] >> cognomi[i] >> eta1[i];
    }
    File.close();
    for (int i = 0; i < nc; i++) {
        for (int j = i + 1; j < nc; j++) {
            if (nomi[i] > nomi[j]) {
                tmpStr = nomi[i]; //scambio nomi
                nomi[i] = nomi[j];
                nomi[j] = tmpStr;
                tmpStr = cognomi[i]; //scambio cognomi
                cognomi[i] = cognomi[j];
                cognomi[j] = tmpStr;
                tmpInt = eta1[i]; //scambio vendite
                eta1[i] = eta1[j];
                eta1[j] = tmpInt;
            }
        }
    }
    File.open("tabella.txt", ios::out);
    for (int i = 0; i < nc; i++) {
        File << nomi[i] << " " << cognomi[i] << " " << eta1[i] << "\n";
    }
    File.close();
}

void OrdinamentoCognome()
{
    int eta1[nc], scelta, tmpInt, j;
    string nomi[nc], cognomi[nc], tmpStr;
    File.open("tabella.txt", ios::in);
    for (int i = 0; i < nc; i++) {
        File >> nomi[i] >> cognomi[i] >> eta1[i];
    }
    File.close();
    for (int i = 0; i < nc; i++) {
        for (int j = i + 1; j < nc; j++) {
            if (cognomi[i] > cognomi[j]) {
                tmpStr = nomi[i]; //scambio nomi
                nomi[i] = nomi[j];
                nomi[j] = tmpStr;
                tmpStr = cognomi[i]; //scambio cognomi
                cognomi[i] = cognomi[j];
                cognomi[j] = tmpStr;
                tmpInt = eta1[i]; //scambio vendite
                eta1[i] = eta1[j];
                eta1[j] = tmpInt;
            }
        }
    }
    File.open("tabella.txt", ios::out);
    for (int i = 0; i < nc; i++) {
        File << nomi[i] << " " << cognomi[i] << " " << eta1[i] << "\n";
    }
    File.close();
}
void Ordinamento()
{
    int scelta;
    bool check = true;
    cout << "\nIn che modo vuoi ordinare la tabella" << endl
         << "\tOpzione 1: Ordinamento in base all' eta" << endl
         << "\tOpzione 2: Ordinamento in base al nome" << endl
         << "\tOpzione 3: Ordinamento in base al cognome" << endl;
    cin >> scelta;
    switch (scelta) {
    case 1:
        OrdinamentoEta();
        break;
    case 2:
        OrdinamentoNome();
        break;
    case 3:
        OrdinamentoCognome();
        break;
    default:
        cout << "\nScelta inesistente" << endl;
        check = false;
    }
    if (check)
        cout << "\n\t-Ordinamento Completato-" << endl;
    Stampa();
}

void Aggiunta()
{
    int n = -1, eta1[nc];
    string nomi[nc], cognomi[nc];
    while (n < 0) {
        cout << "\nQuanti studenti vuoi aggiungere?" << endl;
        cin >> n;
        if (n < 0)
            cout << "\nValore impossibile. reinserire" << endl;
    }
    File.open("tabella.txt", ios::in); //apri il file per prendere dati
    for (int i = 0; i < nc; i++) {
        File >> nomi[i] >> cognomi[i] >> eta1[i]; //salva i valori negli array
    }
    File.close();
    File.open("tabella.txt", ios::out); //apri il file per inserire dati
    for (int i = 0; i < nc + n; i++) {
        if (i >= nc) {
            cout << "\nInserire nome, cognome e eta' persona " << i + 1 << endl;
            cin >> nome;
            cin >> cognome;
            cin >> eta;
            File << nome << " " << cognome << " " << eta << "\n";
        } else {
            File << nomi[i] << " " << cognomi[i] << " " << eta1[i];
        }
    }
    File.close();
    cout << "\nAggiunta completata" << endl;
    nc += n;
}

void Elimina()
{
    int scelta, pos, eta1[nc];
    string cog, nomi[nc], cognomi[nc];
    cout << "\nVuoi stampare i cognomi delle persone con le posizioni? (si=1/no=0)" << endl;
    cin >> scelta;
    if (scelta == 1) {
        File.open("tabella.txt", ios::in);
        for (int i = 0; i < nc; i++) {
            File >> nome >> cognome >> eta;
            cout << "\nPersona " << i + 1 << ": " << cognome << endl;
        }
        File.close();
    }
    cout << "\nInserisci cognome da eliminare" << endl;
    cin >> cog;
    bool check = false;
    File.open("tabella.txt", ios::in);
    for (int i = 0; i < nc; i++) {
        File >> nomi[i] >> cognomi[i] >> eta1[i]; //salva i valori negli array
        if (cognomi[i] == cog) {
            pos = i;
            check = true;
        }
    }
    File.close();
    if (check == false)
        cout << "\nCognome inesistente" << endl;
    else {
        if (pos != nc - 1) {
            for (int i = pos; i < nc; i++) {
                nomi[i] = nomi[i + 1]; //elimina il cognome inserito
                cognomi[i] = cognomi[i + 1];
                eta1[i] = eta1[i + 1];
            }
            nc--;

        } else
            nc--;
        File.open("tabella.txt", ios::out);
        for (int i = 0; i < nc; i++) {
            File << nomi[i] << " " << cognomi[i] << " " << eta1[i] << "\n"; //reinserisce i dati con il cognome eliminato nel file
        }
        File.close();
        cout << "Persona eliminata correttamente." << endl;
    }
}

int main()
{
    int scelta = 1;
    SceltaInsert();
    while (scelta != 0) {
        cout << "\nInserire valore per scegliere opzione" << endl
             << "Opzione 1: Inserire o randomizzare nuovi clienti" << endl
             << "Opzione 2: Stampare lista clienti" << endl
             << "Opzione 3: Inserire su file le persone aventi eta>18 anni" << endl
             << "Opzione 4: Ordinamento lista clienti" << endl
             << "Opzione 5: Aggiungi delle persone al file" << endl
             << "Opzione 6: Elimina persona dal file" << endl
             << "Opzione 0: Esci dal programma" << endl;
        cin >> scelta;
        switch (scelta) {
        case 0:
            cout << "\n---Chiusura e del programma---" << endl;
            break;
        case 1:
            SceltaInsert();
            break;
        case 2:
            Stampa();
            break;
        case 3:
            Maggiore18();
            break;
        case 4:
            Ordinamento();
            break;
        case 5:
            Aggiunta();
            break;
        case 6:
            Elimina();
            break;
        default:
            cout << "\nScelta inesistente" << endl;
        }
    }
}