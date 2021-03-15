/*Inserire in una tabella i dati di un film, i dati sono composti da un titolo,
autore,incasso e nazionalità(italia,francia,...)
Scrivere un programma che esegui le seguenti funzionalita:
1) Inserire i dati dei film
2) Stampi l'incasso medio di un film di un determinato autore  
3) Dato il titolo di un film in input stampi i dati di quel film
4) Stampi i dati del film straniero con maggiore incasso
5) dato un incasso in input, stampi la lista dei titoli di film con incasso superiore all'incasso fornito in input*/
#include <iostream>
#include <iterator>
#include <math.h>
#include <string>
#include <time.h>
using namespace std;

string autoriRandom[15] = { "Fellini", "Kubrick", "Spielberg", "Tarantino", "Hitchcock", "Allen", "Polanski", "Leone", "Burton", "Lucas", "Cameron", "Jackson", "Kaufman", "Zemeckis", "Nolan" };
string titoliRandom[20] = { "Ghostbuster", "Jumanji", "Spiderman", "Shining", "Terminator", "Star Wars", "Matrix", "Hannibal", "Scarface", "Rambo", "Alien", "Avengers", "Interstellar", "Psyco", "Inception", "Rocky", "Esorcista", "Titanic", "Saw", "Batman" };
string nazionalitaRandom[10] = { "Italia", "Francia", "America", "Germania", "Spagna", "Canada", "Russia", "Egitto", "Inghilterra", "Brasile" };

struct DatiFilm {
    string titolo;
    string autore;
    float incasso;
    string nazione;
};
DatiFilm film[100];

void InserimentoRandom(int max)
{
    srand(time(0));
    int RandIndex;
    for (int i = 0; i < max; i++) {
        //inserimento autori
        RandIndex = rand() % 15;
        film[i].autore = autoriRandom[RandIndex];
        //inserimento titolo
        RandIndex = rand() % 20;
        film[i].titolo = titoliRandom[RandIndex];
        //inserimento nazionalità
        RandIndex = rand() % 10;
        film[i].nazione = nazionalitaRandom[RandIndex];
        //inserimento incasso
        film[i].incasso = (rand() % 10000000) + 500000;
    }
    cout << "\n\t-Randomizzazione Completata-" << endl;
}

int Inserimento()
{
    int max, scelta;
    cout << "\nInserire numero film da inserire" << endl;
    cin >> max;
    cout << "Vorresti inserire i valori manualmente o random?  (0/1)" << endl;
    cin >> scelta;
    if (scelta != 1) {
        for (int i = 0; i < max; i++) {
            cout << "Inserire titolo film " << i + 1 << endl;
            cin >> film[i].titolo;
            cout << "Inserire autore film " << i + 1 << endl;
            cin >> film[i].autore;
            cout << "Inserire nazionalita film " << i + 1 << endl;
            cin >> film[i].nazione;
            cout << "Inserire incasso film " << i + 1 << endl;
            cin >> film[i].incasso;
        }
        cout << "\n\t-Inserimento Completato-" << endl;
    } else
        InserimentoRandom(max);
    return max;
}

void Stampa(int max)
{
    if (max == 0)
        cout << "\nTabella vuota... Inserire prodotti" << endl;
    else {
        cout << "\nLista film:" << endl;
        for (int i = 0; i < max; i++) {
            cout << "\n- " << film[i].titolo << endl;
            cout << "\tFilm prodotto in " << film[i].nazione
                 << " dall'autore " << film[i].autore
                 << " con un incasso di " << film[i].incasso << "$" << endl;
        }
    }
}

void StampaTitoli(int max)
{
    cout << endl;
    for (int i = 0; i < max; i++) {
        cout << "-" << film[i].titolo << "  di " << film[i].autore << endl;
    }
    cout << endl;
}

void StampaAutori(int max)
{
    cout << endl;
    string tmp[max];
    int cont = 0, FilmCont[max] = { 0 };
    bool check[max] = { false };

    for (int i = 0; i < max; i++) { //controllo array autore
        if (check[i] == false) { //se il check del nome del autore è falso
            tmp[cont] = film[i].autore; //tmp prende il valore dell'autore del for
            check[i] = true; //setta vero il numero messo nel tmp

            for (int j = 0; j < max; j++) { //controllo  dell'array per i doppi
                if (film[j].autore == film[i].autore) { //controllo se doppio
                    check[j] = true; //setta vero il doppio del numero controllato se è doppio
                    FilmCont[cont]++; //aumenta quante volte è il numero doppio
                }
            }
            cont++; //aumenta posizione tmp e film
        }
    }
    for (int i = 0; i < cont; i++)
        cout << "-" << tmp[i] << " con " << FilmCont[i] << " film" << endl;
    cout << endl;
}

void MediaAutore(int max)
{
    bool check = false;
    int cont = 0;
    float incasso = 0;
    string autore, scelta;
    cout << "\nVuoi sapere la lista degli autori? (si/no)" << endl;
    cin >> scelta;
    if (scelta == "si" || scelta == "s" || scelta == "y" || scelta == "yes") {
        StampaAutori(max);
    }
    cout << "\nInserire Autore di cui vuoi sapere la media degli incassi" << endl;
    cin >> autore;
    for (int i = 0; i < max; i++) {
        if (film[i].autore == autore) {
            check = true;
            cont++;
            incasso += film[i].incasso;
        }
    }
    incasso = incasso / cont;
    if (check == true) {
        cout << "\nLa media dei film di " << autore << " è di " << incasso << "$" << endl;
    } else {
        cout << "\nAutore non trovato" << endl;
    }
}

void StampaFilmDatoTitolo(int max)
{
    bool check = false;
    int pos;
    string titolo, scelta;
    cout << "\nVuoi sapere la lista dei titoli? (si/no)" << endl;
    cin >> scelta;
    if (scelta == "si" || scelta == "s" || scelta == "y" || scelta == "yes") {
        StampaTitoli(max);
    }
    cout << "\nInserire Titolo di cui vuoi sapere le informazioni" << endl;
    cin >> titolo;
    for (int i = 0; i < max; i++) {
        if (film[i].titolo == titolo) {
            check = true;
            pos = i;
            break;
        }
    }
    if (check == true) {
        cout << "\n- " << film[pos].titolo
             << "\n    Autore: " << film[pos].autore
             << "\n    Incasso: " << film[pos].incasso << "€"
             << "\n    Nazionalita': " << film[pos].nazione << endl;
    } else {
        cout << "\nTitolo non trovato" << endl;
    }
}

void FilmStraniero(int max)
{
    string nazione = "Italia", scelta;
    int pos;
    float incasso;
    cout << "\nIl paese di provenienza è settato come " << nazione << ". Lo vuoi modificare? (si/no)" << endl;
    cin >> scelta;
    if (scelta == "si" || scelta == "s" || scelta == "y" || scelta == "yes") {
        cout << "Gli altri paesi disponibili sono:" << endl;
        int len = sizeof(nazionalitaRandom) / sizeof(nazionalitaRandom[0]); //controlla lunghezza della lista delle nazioni
        for (int i = 1; i < len; i++) { //stampa lista delle nazioni
            cout << "-" << nazionalitaRandom[i] << endl;
        }
        cout << "\nPero puoi inserire altre nazioni" << endl
             << "Inserire nazione" << endl;
        cin >> nazione;
        cout << "\nIl paese di provenienza è stato settato come " << nazione << endl;
    } else if (scelta != "si")
        cout << "\nIl paese di provenienza rimarra " << nazione << endl;
    for (int i = 0; i < max; i++) {
        if (film[i].nazione != nazione) { //check diverso dalla nazione di provenienza
            if (film[i].incasso > incasso) { //check incasso maggiore
                incasso = film[i].incasso;
                pos = i;
            }
        }
    }
    cout << "\nIl film straniero con incasso maggiore è " << endl;
    cout << "\n- " << film[pos].titolo
         << "\n    Autore: " << film[pos].autore
         << "\n    Incasso: " << film[pos].incasso << "€"
         << "\n    Nazionalita': " << film[pos].nazione << endl;
}

void FilmSuperioriIncasso(int max)
{
    int incasso, scelta;
    cout << "\nInserire incasso da controllare" << endl;
    cin >> incasso;
    cout << "\nVuoi eseguire la stampa dei titoli dei film con incasso:" << endl
         << "\tOpzione 0: minore  di " << incasso << endl
         << "\tOpzione 1: superiore di " << incasso << endl;
    cin >> scelta;
    bool Check_exist = false;
    if (scelta == 0) {
        cout << "\nFilm con incasso minore a " << incasso << ":" << endl;
        for (int i = 0; i < max; i++) {
            if (film[i].incasso < incasso) {
                cout << "-" << film[i].titolo << endl;
                Check_exist = true;
            }
        }
        if (Check_exist == false)
            cout << "Non ci sono film con incasso minore a " << incasso << endl;
    } else if (scelta == 1) {
        cout << "\nFilm con incasso superiore a " << incasso << ":" << endl;
        for (int i = 0; i < max; i++) {
            if (film[i].incasso > incasso) {
                cout << "-" << film[i].titolo << endl;
                Check_exist = true;
            }
        }
        if (Check_exist == false)
            cout << "Non ci sono film con incasso minore a " << incasso << endl;
    } else
        cout << "Scelta inesistente" << endl;
}

int AggiuntaFilm(int max)
{
    int n, scelta;
    cout << "\nInserire numero di film da aggiungere" << endl;
    cin >> n;
    cout << "Vorresti inserire i valori manualmente o random?  (0/1)" << endl;
    cin >> scelta;
    if (scelta == 0) {
        for (int i = 0; i < n; i++) {
            cout << "Inserire titolo film " << i + 1 << endl;
            cin >> film[max + i].titolo;
            cout << "Inserire autore film " << i + 1 << endl;
            cin >> film[max + i].autore;
            cout << "Inserire nazionalita film " << i + 1 << endl;
            cin >> film[max + i].nazione;
            cout << "Inserire incasso film " << i + 1 << endl;
            cin >> film[max + i].incasso;
        }
    } else {
        DatiFilm tmp[100];
        for (int i = 0; i < max + n; i++) {
            tmp[i] = film[i];
        }
        for (int i = n; i < max + n; i++) {
            film[i] = tmp[i - n];
        }
        InserimentoRandom(n);
    }
    max += n;
    return max;
    cout << "\n\t-Aggiunta Completata-" << endl;
}

int EliminaFilm(int max)
{
    int n = max, pos;
    string titolo, scelta;
    bool check = false;
    cout << "\nVuoi sapere la lista degli autori? (si/no)" << endl;
    cin >> scelta;
    if (scelta == "si" || scelta == "s" || scelta == "y" || scelta == "yes") {
        StampaTitoli(max);
    }
    cout << "\nInserire nome film che si vuole eliminare" << endl;
    cin >> titolo;
    for (int i = 0; i < max; i++) {
        if (film[i].titolo == titolo) {
            check = true;
            pos = i;
            break;
        }
    }
    if (check == true) {
        for (int i = pos; i <= max; i++) {
            film[i].titolo = film[i + 1].titolo;
            film[i].autore = film[i + 1].autore;
            film[i].nazione = film[i + 1].nazione;
            film[i].incasso = film[i + 1].incasso;
        }
        cout << "\n\t-Eliminazione Completata-" << endl;
        n--;
    } else {
        cout << "\nFilm non trovato" << endl;
    }
    return n;
}

void OrdinamentoIncasso(int max)
{
    bool checkScambio;
    int scelta;
    DatiFilm tmp;
    cout << "\nVuoi eseguire l'ordinamento:" << endl
         << "\tOpzione 0: dal piu grande al piu piccolo" << endl
         << "\tOpzione 1: dal piu piccolo al piu grande" << endl;
    cin >> scelta;
    if (scelta == 0 || scelta == 1) {
        for (int i = 0; i < max; i++) {
            checkScambio = false;
            for (int j = 1; j < (max - i); j++)
                if (scelta == 0) {
                    if (film[j - 1].incasso < film[j].incasso) {
                        tmp = film[j - 1];
                        film[j - 1] = film[j];
                        film[j] = tmp;
                        checkScambio = true;
                    }
                } else if (scelta == 1) {
                    if (film[j - 1].incasso > film[j].incasso) {
                        tmp = film[j - 1];
                        film[j - 1] = film[j];
                        film[j] = tmp;
                        checkScambio = true;
                    }
                }
            if (!checkScambio)
                break;
        }
        cout << "\n\t-Ordinamento Completato-" << endl;
    } else
        cout << "\nScelta inesistente" << endl;
    Stampa(max);
}

void OrdinamentoTitolo(int max)
{
    int Arrayint[100], tmp1;
    char Arraychar[100];
    DatiFilm tmp;
    bool checkScambio;
    for (int i = 0; i < max; i++) {
        Arraychar[i] = film[i].titolo[0];
        Arrayint[i] = (int)Arraychar[i];
    }
    for (int i = 0; i < max; i++) {
        checkScambio = false;
        for (int j = 1; j < (max - i); j++)
            if (Arrayint[j - 1] > Arrayint[j]) {
                tmp1 = Arrayint[j - 1]; //scambio valori array int
                Arrayint[j - 1] = Arrayint[j];
                Arrayint[j] = tmp1;
                tmp = film[j - 1];
                film[j - 1] = film[j];
                film[j] = tmp;
                checkScambio = true;
            }
        if (!checkScambio)
            break;
    }
    cout << "\n\t-Ordinamento Completato-" << endl;
    Stampa(max);
}

void OrdinamentoAutore(int max)
{
    int Arrayint[100], tmp1;
    char Arraychar[100];
    DatiFilm tmp;
    bool checkScambio;
    for (int i = 0; i < max; i++) {
        Arraychar[i] = film[i].autore[0];
        Arrayint[i] = (int)Arraychar[i];
    }
    for (int i = 0; i < max; i++) {
        checkScambio = false;
        for (int j = 1; j < (max - i); j++)
            if (Arrayint[j - 1] > Arrayint[j]) {
                tmp1 = Arrayint[j - 1]; //scambio valori array int
                Arrayint[j - 1] = Arrayint[j];
                Arrayint[j] = tmp1;
                tmp = film[j - 1];
                film[j - 1] = film[j];
                film[j] = tmp;
                checkScambio = true;
            }
        if (!checkScambio)
            break;
    }
    cout << "\n\t-Ordinamento Completato-" << endl;
    Stampa(max);
}

void Ordinamento(int max)
{
    int scelta;
    cout << "\nIn che modo vuoi ordinare la tabella" << endl
         << "\tOpzione 1: Ordinamento in base agli Incassi" << endl
         << "\tOpzione 2: Ordinamento in base al Titolo" << endl
         << "\tOpzione 3: Ordinamento in base all' Autore" << endl;
    cin >> scelta;
    switch (scelta) {
    case 1:
        OrdinamentoIncasso(max);
        break;
    case 2:
        OrdinamentoTitolo(max);
        break;
    case 3:
        OrdinamentoAutore(max);
        break;
    default:
        cout << "\nScelta inesistente" << endl;
    }
}

int main()
{
    int max, scelta;
    max = Inserimento();
    do {
        cout << "\nInserire numero per scegliere opzione" << endl
             << "Opzione 0: Uscire dal programma" << endl
             << "Opzione 1: Inserimento film" << endl
             << "Opzione 2: Inserimento film Random" << endl
             << "Opzione 3: Stampa lista film" << endl
             << "Opzione 4: Stampa Incasso medio dei film di un determinato autore" << endl
             << "Opzione 5: Stampa dati film dato il titolo" << endl
             << "Opzione 6: Stampa dati del film straniero con maggiore incasso" << endl
             << "Opzione 7: Stampa lista film con incasso superiore/minore all'incasso inserito" << endl
             << "Opzione 8: Ordinamento film" << endl
             << "Opzione 9: Aggiunta film" << endl
             << "Opzione 10: Elimina film" << endl;
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
            MediaAutore(max);
            break;
        case 5:
            StampaFilmDatoTitolo(max);
            break;
        case 6:
            FilmStraniero(max);
            break;
        case 7:
            FilmSuperioriIncasso(max);
            break;
        case 8:
            Ordinamento(max);
            break;
        case 9:
            max = AggiuntaFilm(max);
            break;
        case 10:
            max = EliminaFilm(max);
            break;
        default:
            cout << "\nScelta inesistente" << endl;
        }
    } while (scelta != 0);
}