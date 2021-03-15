/*
Inserire in una cartella un file di testo contenente per ogni riga età e cognome di studenti. 
Supponiamo che abbia 10 righe. Scrivere un programma che legga il file e inserisca in un array le età degli studenti superiori alla media. 
Successivamente si legga tale array.
*/
#include <iostream>
#include <fstream>
#include <math.h>
#include <time.h>
#include <string.h>
using namespace std;

fstream File;

const int MAX=100; //massimo di studenti

struct dati{
    string cognome;
    int eta;
};
dati studente[MAX];

string cognomiRandom[15] = {"Rossi", "Ferrari", "Bianchi", "Romano", "Gallo", "Costa", "Fontana", "Conti", "Esposito", "Bruno", "Rizzo", "Moretti", "Marino", "Barbieri", "Lombardi"};

int Random(){
    srand(time(0));
    File.open("file.txt", ios::out);  //apri il file per inserire dati
    int eta, index, max;
    string cognome;
    cout<<"\nInserire massimo studenti"<<endl;
    cin>>max;
    for(int i=0;i<max;i++){
        index = rand()%15;
        cognome = cognomiRandom[index];
        eta = (rand()%25)+10;
        File<<cognome<<" "<<eta<<"\n";
    }
    cout<<"\nRandomizzazione completata"<<endl;
    File.close();
    return max;
}

int Inserimento(){
    int max,eta;
    File.open("file.txt", ios::out);  //apri il file per inserire dati
    cout<<"\nInserire massimo studenti"<<endl;
    cin>>max;
    string cognome;
    for(int i=0;i<max;i++){
        cout<<"\nInserire cognome e eta' studente "<<i+1<<endl;
        cin>>cognome;
        cin>>eta;
        File<<cognome<<" "<<eta<<"\n";
    }
    File.close();
    return max;
}

void Stampa(int max){
    if(max==0)
        cout<<"\nNon ci sono ancora studenti"<<endl;
    else{
        File.open("file.txt", ios::in);  //apri il file per prendere dati
        int eta;
        string cognome;
        for(int i=0;i<max;i++){
            File>>cognome>>eta;
            cout<<"\nStudente "<<i+1<<": "<<endl
            <<"\t-Cognome: "<<cognome<<endl
            <<"\t-eta': "<<eta<<endl;
        }
        File.close();
    }
}

bool InserimentoArray(int max, bool check){
    if(max==0)
        cout<<"\nNon ci sono ancora studenti"<<endl;
    else{
        File.open("file.txt", ios::in);  //apri il file per prendere dati
        for(int i=0;i<max;i++){
            File>>studente[i].cognome>>studente[i].eta;
        }
        cout<<"\nInserimento completato"<<endl;
        File.close();
        check=true;
    }
    return check;
}

void StampaArray(int max, bool check){
    if(max==0)
        cout<<"\nNon ci sono ancora studenti"<<endl;
    else if(check==false)
        cout<<"\nNon sono stati trasferiti valori nell'array"<<endl;
    else{
        for(int i=0;i<max;i++){
            cout<<"\nStudente "<<i+1<<": "<<endl
            <<"\t-Cognome: "<<studente[i].cognome<<endl
            <<"\t-eta': "<<studente[i].eta<<endl;
        }
    }
}

int Aggiunta(int max){
    if(max==0)
        cout<<"\nNon ci sono ancora studenti"<<endl;
    else{
        int n=-1, eta;
        string cognome;
        while(n<0){
            cout<<"\nQuanti studenti vuoi aggiungere?"<<endl;
            cin>>n;
            if(n<0)
                cout<<"\nValore impossibile. reinserire"<<endl;
        }
        File.open("file.txt", ios::in);  //apri il file per prendere dati
        for(int i=0;i<max;i++){
            File>>studente[i].cognome>>studente[i].eta;  //salva i valori nello struct studente 
        }
        File.close();
        File.open("file.txt", ios::out);  //apri il file per inserire dati
        for(int i=0;i<max+n;i++){
            if(i>=max){
                cout<<"\nInserire cognome e eta' studente "<<i+1<<endl;
                cin>>cognome;
                cin>>eta;
                File<<cognome<<" "<<eta<<"\n";
            }
            else{
                File<<studente[i].cognome<<" "<<studente[i].eta;
            }
        }
        File.close();
        cout<<"\nAggiunta completata"<<endl;
        max+=n;
    }
    return max;
}

int Elimina(int max){
    if(max==0)
        cout<<"\nNon ci sono ancora studenti"<<endl;
    else{
        int scelta, pos;
        string cog;
        cout<<"\nVuoi stampare i cognomi degli studenti con le posizioni? (si=1/no=0)"<<endl;
        cin>>scelta;
        if(scelta==1){
            File.open("file.txt", ios::in);  //apri il file per prendere dati
            string cognome;
            int eta;
            for(int i=0;i<max;i++){
                File>>cognome>>eta;
                cout<<"\nStudente "<<i+1<<": "<<cognome<<endl;
            }
            File.close();
        }
        cout<<"\nInserisci cognome da eliminare"<<endl;
        cin>>cog;
        bool check = false;
        File.open("file.txt", ios::in);
        for(int i=0;i<max;i++){
            File>>studente[i].cognome>>studente[i].eta;  //salva i valori nello struct studente 
            if(studente[i].cognome==cog){
                pos=i;
                check = true;
            }
        }
        File.close();
        if(check==false)
            cout<<"\nCognome inesistente"<<endl;
        else{
            for(int i=pos;i<max;i++){
                studente[i].cognome = studente[i+1].cognome;  //elimina il cognome inserito
                studente[i].eta = studente[i+1].eta;
            }
            File.open("file.txt", ios::out);
            for(int i=0;i<max;i++){
                File<<studente[i].cognome<<" "<<studente[i].eta<<"\n"; //reinserisce i dati con il cognome eliminato nel file
            }
            File.close();
            cout << "Studente eliminato correttamente." << endl;
            max--;
        }
    }
    return max;
}

int main(){
    int scelta=1, max=0;
    bool check = false;
    while(scelta!=0){
        cout<<"\nInserire valore per scegliere opzione"<<endl
        <<"Opzione 1: Inserire valori nel file"<<endl
        <<"Opzione 2: Randomizza i valori nel file"<<endl
        <<"Opzione 3: Stampare i valori del file"<<endl
        <<"Opzione 4: Inserire valori file negli array e stampa"<<endl
        <<"Opzione 5: Stampare valori array"<<endl
        <<"Opzione 6: Aggiunta studenti nel file"<<endl
        <<"Opzione 7: Elimina studenti dal file"<<endl
        <<"Opzione 0: Esci dal programma"<<endl;
        cin>>scelta;
        switch(scelta){
            case 0:     
                cout<<"\n---Chiusura e del programma---"<<endl;
            break;
            case 1:
                max = Inserimento();
            break;
            case 2:
                max = Random();
            break;
            case 3:
                Stampa(max);
            break;
            case 4:
                check = InserimentoArray(max, check);
            break;
            case 5:
                StampaArray(max, check);
            break;
            case 6:
                max = Aggiunta(max);
            break;
            case 7:
                max = Elimina(max);
            break;
            default:
                cout<<"\nScelta inesistente"<<endl;
        }
    }
    return 0;
}