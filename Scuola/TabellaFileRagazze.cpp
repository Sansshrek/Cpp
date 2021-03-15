/*Inserire i dati in un file e caricare i dati da file su tabella
I campi del file sono:
cognome, localita di provenienza, eta, altezza */
#include <iostream>
#include <string.h>
#include <math.h>
#include <time.h>
#include <fstream>
using namespace std;

string cognomiRandom[15] = { "Rossi", "Ferrari", "Bianchi", "Romano", "Gallo", "Costa", "Fontana", "Conti", "Esposito", "Bruno", "Rizzo", "Moretti", "Marino", "Barbieri", "Lombardi" };
string cittaRandom[15] = {"Roma", "Napoli", "Venezia", "Catania", "Pisa", "Firenze", "Palermo", "Bologna", "Torino", "Verona", "Sassari", "Catania", "Bari", "Pescara", "Milano"};
fstream File;

int nc = 0;

string cognome, provenienza;
int eta, altezza;

void Random()
{
    srand(time(0));
    File.open("ragazze.txt", ios::out);
    int Index;
    cout << "\nInserire massimo studenti" << endl;
    cin >> nc;
    srand(time(0));
    for (int i = 0; i < nc; i++) {
        Index = rand() % 15;
        cognome = cognomiRandom[Index];
        Index = rand() %15;
        provenienza = cittaRandom[Index];
        eta = rand()%30;
        altezza = (rand()%60)+140;
        File << cognome << " " << provenienza << " " << eta << " "<< altezza<< "\n";
    }
    cout << "\n\t--Randomizzazione completata--" << endl;
    File.close();
}

void Inserimento()
{
    File.open("ragazze.txt", ios::out);
    cout << "\nInserire massimo clienti" << endl;
    cin >> nc;
    for (int i = 0; i < nc; i++) {
        cout << "Inserire cognome della ragazza " << i + 1 << endl;
        cin >> cognome;
        cout << "Inserire provenienza della ragazza " << i + 1 << endl;
        cin >> provenienza;
        cout << "Inserire quantita etauta dal cliente " << i + 1 << endl;
        cin >> eta;
        cout << "Inserire altezza della ragazza " << i + 1 << endl;
        cin >> altezza;
        File << cognome << " " << provenienza << " " << eta << " "<< altezza<< "\n";
    }
    File.close();
}

void InserimentoFile()
{
    bool check = false;
    cout << "\nInserire il file 'ragazze.txt' nella cartella del programma" << endl;
    File.open("ragazze.txt", ios::in);
    if (File.is_open()) //check esistenza file
        check = true; //il file esiste
    if (!check)
        cout << "\nIl file non esiste" << endl;
    else {
        File >> cognome >> provenienza >> eta >> altezza;
        nc++;
        while (!File.eof()) {
            File >> cognome >> provenienza >> eta >> altezza;
            nc++;
        }
        cout << "Numero Clienti= " << nc << endl;
    }
    File.close();
}

void SceltaCarica(){
    int scelta;
    cout<<"\nInserire Valore per scegliere opzione"<<endl
    <<"\n\tOpzione 1: Inserimento manuale"<<endl
    <<"\n\tOpzione 2: Inserimento random"<<endl
    <<"\n\tOpzione 3: Inserimento da file"<<endl;
    cin>>scelta;
    switch(scelta){
        case 1:
            Inserimento();
        break;
        case 2:
            Random();
        break;
        case 3:
            InserimentoFile();
        break;
        default:
            cout<<"\nOpzione inesistente"<<endl;
    }
}

void Stampa()
{
    if (nc == 0)
        cout << "Non ci sono ancora ragazze nella lista" << endl;
    else {
        File.open("ragazze.txt", ios::in);
        for (int i = 0; i < nc; i++) {
            File>>cognome>>provenienza>>eta>>altezza;
            cout << "\nRagazza " << i + 1 << ": " << cognome 
            << "\n\t" << "Citta: "<<provenienza
            << "\n\t" << "Eta: " << eta << " anni" 
            << "\n\t" << "Altezza: "<< altezza <<"cm"<< endl;
        }
        File.close();
    }
}

void MediaEta(){
    int cont = 0;
    float med = 0;
    File.open("ragazze.txt", ios::in);
    for(int i=0;i<nc;i++){
        File>>cognome>>provenienza>>eta>>altezza;
        cont++;
        med+=eta;
    }
    File.close();
    cout<<"\nLa media delle eta delle ragazze e': "<<med/cont<<endl;
}

void StampaInput(){
    string cog;
    bool check = false;
    File.open("ragazze.txt", ios::out);
    cout<<"\nInserire cognome da stampare"<<endl;
    cin>>cog;
    for(int i=0;i<nc;i++){
        File>>cognome>>provenienza>>eta>>altezza;
        if(cognome==cog){
            cout << "\nRagazza " << i + 1 << ": " << cognome 
            << "\n\t" << "Citta: "<<provenienza
            << "\n\t" << "Eta: " << eta << " anni" 
            << "\n\t" << "Altezza: "<< altezza <<"cm"<< endl;
            check = true;
        }
    }
    if(!check)
        cout<<"Cognome inesistente"<<endl;
    File.close();
}

void OrdinamentoEta()
{
    bool checkScambio;
    int eta1[nc], altezza1[nc], scelta, tmpInt;
    string provenienza1[nc], cognome1[nc], tmpStr;
    File.open("ragazze.txt", ios::in);
    for (int i = 0; i < nc; i++) {
        File>>cognome1[i]>>provenienza1[i]>>eta1[i]>>altezza1[i];
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
                        tmpStr = cognome1[i]; //scambio cognomi
                        cognome1[i] = cognome1[j];
                        cognome1[j] = tmpStr;
                        tmpStr = provenienza1[i]; //scambio provenienza
                        provenienza1[i] = provenienza1[j];
                        provenienza1[j] = tmpStr;
                        tmpInt = eta1[i]; //scambio vendite
                        eta1[i] = eta1[j];
                        eta1[j] = tmpInt;
                        tmpInt = altezza1[i];  //scambio altezze
                        altezza1[i] = altezza1[j];
                        altezza1[j] = tmpInt;
                    }
                } else if (scelta == 1) {
                    if (eta1[i] > eta1[j]) {
                        tmpStr = cognome1[i]; //scambio cognomi
                        cognome1[i] = cognome1[j];
                        cognome1[j] = tmpStr;
                        tmpStr = provenienza1[i]; //scambio provenienza
                        provenienza1[i] = provenienza1[j];
                        provenienza1[j] = tmpStr;
                        tmpInt = eta1[i]; //scambio vendite
                        eta1[i] = eta1[j];
                        eta1[j] = tmpInt;
                        tmpInt = altezza1[i];  //scambio altezze
                        altezza1[i] = altezza1[j];
                        altezza1[j] = tmpInt;
                    }
                }
            }
        }
    } else
        cout << "\nScelta inesistente" << endl;
    File.open("ragazze.txt", ios::out);
    for (int i = 0; i < nc; i++) {
        File << cognome << " " << provenienza << " " << eta << " "<< altezza<< "\n";
    }
    File.close();
}

void OrdinamentoCognome()
{
    int eta1[nc], altezza1[nc], tmpInt;
    string provenienza1[nc], cognome1[nc], tmpStr;
    File.open("ragazze.txt", ios::in);
    for (int i = 0; i < nc; i++) {
        File>>cognome1[i]>>provenienza1[i]>>eta1[i]>>altezza1[i];
    }
    File.close();
    for (int i = 0; i < nc; i++) {
        for (int j = i + 1; j < nc; j++) {
            if (cognome1[i] > cognome1[j]) {
                tmpStr = cognome1[i]; //scambio cognomi
                cognome1[i] = cognome1[j];
                cognome1[j] = tmpStr;
                tmpStr = provenienza1[i]; //scambio provenienza
                provenienza1[i] = provenienza1[j];
                provenienza1[j] = tmpStr;
                tmpInt = eta1[i]; //scambio vendite
                eta1[i] = eta1[j];
                eta1[j] = tmpInt;
                tmpInt = altezza1[i];  //scambio altezze
                altezza1[i] = altezza1[j];
                altezza1[j] = tmpInt;
            }
        }
    }
    File.open("ragazze.txt", ios::out);
    for (int i = 0; i < nc; i++) {
        File << cognome << " " << provenienza << " " << eta << " "<< altezza<< "\n";
    }
    File.close();
}

void OrdinamentoAltezza()
{
    bool checkScambio;
    int eta1[nc], altezza1[nc], scelta, tmpInt;
    string provenienza1[nc], cognome1[nc], tmpStr;
    File.open("ragazze.txt", ios::in);
    for (int i = 0; i < nc; i++) {
        File>>cognome1[i]>>provenienza1[i]>>eta1[i]>>altezza1[i];
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
                    if (altezza1[i] < altezza1[j]) {
                        tmpStr = cognome1[i]; //scambio cognomi
                        cognome1[i] = cognome1[j];
                        cognome1[j] = tmpStr;
                        tmpStr = provenienza1[i]; //scambio provenienza
                        provenienza1[i] = provenienza1[j];
                        provenienza1[j] = tmpStr;
                        tmpInt = eta1[i]; //scambio vendite
                        eta1[i] = eta1[j];
                        eta1[j] = tmpInt;
                        tmpInt = altezza1[i];  //scambio altezze
                        altezza1[i] = altezza1[j];
                        altezza1[j] = tmpInt;
                    }
                } else if (scelta == 1) {
                    if (altezza1[i] > altezza1[j]) {
                        tmpStr = cognome1[i]; //scambio cognomi
                        cognome1[i] = cognome1[j];
                        cognome1[j] = tmpStr;
                        tmpStr = provenienza1[i]; //scambio provenienza
                        provenienza1[i] = provenienza1[j];
                        provenienza1[j] = tmpStr;
                        tmpInt = eta1[i]; //scambio vendite
                        eta1[i] = eta1[j];
                        eta1[j] = tmpInt;
                        tmpInt = altezza1[i];  //scambio altezze
                        altezza1[i] = altezza1[j];
                        altezza1[j] = tmpInt;
                    }
                }
            }
        }
    } else
        cout << "\nScelta inesistente" << endl;
    File.open("ragazze.txt", ios::out);
    for (int i = 0; i < nc; i++) {
        File << cognome << " " << provenienza << " " << eta << " "<< altezza<< "\n";
    }
    File.close();
}

void OrdinamentoProvenienza()
{
    int eta1[nc], altezza1[nc], tmpInt;
    string provenienza1[nc], cognome1[nc], tmpStr;
    File.open("ragazze.txt", ios::in);
    for (int i = 0; i < nc; i++) {
        File>>cognome1[i]>>provenienza1[i]>>eta1[i]>>altezza1[i];
    }
    File.close();
    for (int i = 0; i < nc; i++) {
        for (int j = i + 1; j < nc; j++) {
            if (provenienza1[i] > provenienza1[j]) {
                tmpStr = cognome1[i]; //scambio cognomi
                cognome1[i] = cognome1[j];
                cognome1[j] = tmpStr;
                tmpStr = provenienza1[i]; //scambio provenienza
                provenienza1[i] = provenienza1[j];
                provenienza1[j] = tmpStr;
                tmpInt = eta1[i]; //scambio vendite
                eta1[i] = eta1[j];
                eta1[j] = tmpInt;
                tmpInt = altezza1[i];  //scambio altezze
                altezza1[i] = altezza1[j];
                altezza1[j] = tmpInt;
            }
        }
    }
    File.open("ragazze.txt", ios::out);
    for (int i = 0; i < nc; i++) {
        File << cognome << " " << provenienza << " " << eta << " "<< altezza<< "\n";
    }
    File.close();
}

void Ordinamento()
{
    int scelta;
    bool check = true;
    cout << "\nIn che modo vuoi ordinare la tabella" << endl
         << "\tOpzione 1: Ordinamento in base all' eta" << endl
         << "\tOpzione 2: Ordinamento in base al cognome" << endl
         <<"\tOpzione 3: Ordinamento in base all'altezza"<<endl
         << "\tOpzione 4: Ordinamento in base al provenienza" << endl;
    cin >> scelta;
    switch (scelta) {
    case 1:
        OrdinamentoEta();
        break;
    case 2:
        OrdinamentoCognome();
        break;
    case 3:
        OrdinamentoAltezza();
        break;
    case 4:
        OrdinamentoProvenienza();
    break;
    default:
        cout << "\nScelta inesistente" << endl;
        check = false;
    }
    if (check)
        cout << "\n\t-Ordinamento Completato-" << endl;
    Stampa();
}

void DiffAltezza(){
    int delta, h, cont=0, index[nc];
    bool check=false;
    cout<<"\nInserire altezza da controllare"<<endl;
    cin>>h;
    cout<<"\nInserire delta per differenza"<<endl;
    cin>>delta;
    File.open("ragazze.txt", ios::in);
    for(int i=0;i<nc;i++){
        File>>cognome>>provenienza>>eta>>altezza;
        if(altezza>h+delta || altezza<h-delta){
            cont++;
            check = true;
        }
    }
    File.close();
    if(check)
        cout<<"\nCi sono "<<cont<<" ragazze con altezza maggiore di "<<h+delta<<" o minori di "<<h-delta<<" cm"<<endl;
    else
        cout<<"\nNon ci sono ragazze con altezza maggiore di "<<h+delta<<" o minori di "<<h-delta<<" cm"<<endl;
}

void Aggiunta()
{
    int eta1[nc], altezza1[nc], n=-1;
    string provenienza1[nc], cognome1[nc];
    while (n < 0) {
        cout << "\nQuanti studenti vuoi aggiungere?" << endl;
        cin >> n;
        if (n < 0)
            cout << "\nValore impossibile. reinserire" << endl;
    }
    File.open("ragazze.txt", ios::in); //apri il file per prendere dati
    for (int i = 0; i < nc; i++) {
        File>>cognome1[i]>>provenienza1[i]>>eta1[i]>>altezza1[i]; //salva i valori negli array
    }
    File.close();
    File.open("ragazze.txt", ios::out); //apri il file per inserire dati
    for (int i = 0; i < nc + n; i++) {
        if (i >= nc) {
            cout << "\nInserire cognome ragazza " << i + 1 << endl;
            cin >> cognome;
            cout << "\nInserire provenienza ragazza " << i + 1 << endl;
            cin >> provenienza;
            cout << "\nInserire eta ragazza " << i + 1 << endl;
            cin >> eta;
            cout << "\nInserire altezza ragazza " << i + 1 << endl;
            cin>>altezza;
            File << cognome << " " << provenienza << " " << eta << " "<< altezza<< "\n";
        } else {
            File << cognome1[i] << " " << provenienza1[i] << " " << eta1[i] << " "<< altezza1[i]<< "\n";
        }
    }
    File.close();
    cout << "\nAggiunta completata" << endl;
    nc += n;
}

void Elimina()
{
    int scelta, pos, eta1[nc], altezza1[nc];
    string cog, provenienza1[nc], cognome1[nc];
    cout << "\nVuoi stampare i cognomi delle persone con le posizioni? (si=1/no=0)" << endl;
    cin >> scelta;
    if (scelta == 1) {
        File.open("ragazze.txt", ios::in);
        for (int i = 0; i < nc; i++) {
            File>>cognome>>provenienza>>eta>>altezza;
            cout << "\nPersona " << i + 1 << ": " << cognome << endl;
        }
        File.close();
    }
    cout << "\nInserisci cognome da eliminare" << endl;
    cin >> cog;
    bool check = false;
    File.open("ragazze.txt", ios::in);
    for (int i = 0; i < nc; i++) {
        File>>cognome1[i]>>provenienza1[i]>>eta1[i]>>altezza1[i]; //salva i valori negli array
        if (cognome1[i] == cog) {
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
                cognome1[i] = cognome1[i + 1]; //elimina il cognome inserito
                provenienza1[i] = provenienza1[i + 1];
                eta1[i] = eta1[i + 1];
                altezza1[i] = altezza1[i + 1];
            }
            nc--;
        } else
            nc--;
        File.open("ragazze.txt", ios::out);
        for (int i = 0; i < nc; i++) {
            File << cognome1[i] << " " << provenienza1[i] << " " << eta1[i] << " "<< altezza1[i]<< "\n"; //reinserisce i dati con il cognome eliminato nel file
        }
        File.close();
        cout << "Persona eliminata correttamente." << endl;
    }
}

int main()
{
    int scelta = 1;
    SceltaCarica();
    while (scelta != 0) {
        cout << "\nInserire valore per scegliere opzione" << endl
             << "Opzione 1: Inserire o randomizzare nuovi ragazze" << endl
             << "Opzione 2: Stampare lista ragazze" << endl
             << "Opzione 3: Stampa la media dell'eta delle ragazze" << endl
             << "Opzione 4: Stampa ragazza da cognome dato"<<endl
             << "Opzione 5: Ordinamento lista ragazze" << endl
             << "Opzione 6: Aggiungi delle ragazze al file" << endl
             << "Opzione 7: Elimina ragazze dal file" << endl
             << "Opzione 0: Esci dal programma" << endl;
        cin >> scelta;
        switch (scelta) {
        case 0:
            cout << "\n---Chiusura e del programma---" << endl;
            break;
        case 1:
            SceltaCarica();
            break;
        case 2:
            Stampa();
            break;
        case 3:
            MediaEta();
            break;
        case 4:
            StampaInput();
            break;
        case 5:
            Ordinamento();
        break;
        case 6:
            Aggiunta();
            break;
        case 7:
            Elimina();
            break;
        default:
            cout << "\nScelta inesistente" << endl;
        }
    }
}