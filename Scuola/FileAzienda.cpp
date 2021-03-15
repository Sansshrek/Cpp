/*Dato un file in input f1 contenente i seguenti dati dei dipententi di un azienda: cognome,nome,anzianita,stipendio scrivi un programma che:
1) carichi i dati del file in una tabella
2) crei un nuovo file contenente il nome e cognome dei dipendenti con stipendio<1500 euro
3) dato un anzianita in input, stampare i cognomi e i nomi dei dipententi aventi tale anzianita*/
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

fstream File1;
fstream File2;

struct dati{
    string nome;
    string cognome;
    int anzianita;
    int stipendio;
};
dati Dipendente[100];
int nc=0;

void Caricamento(){
    File1.open("dati.txt", ios::in);
    while (!File1.eof()) {
        cout<<"nice"<<endl;
        File1 >> Dipendente[nc].nome >> Dipendente[nc].cognome >> Dipendente[nc].anzianita >> Dipendente[nc].stipendio;
        nc++;
    }
    File1.close();
}

void Stampa(){
    for(int i=0;i<nc;i++){
        cout<<"-Dipendente "<<i+1<<":"<<endl
        <<"\tNome: "<<Dipendente[nc].nome<<endl
        <<"\tCognome: "<<Dipendente[nc].cognome<<endl
        <<"\tAnzianita: "<<Dipendente[nc].anzianita<<endl
        <<"\tStipendio: "<<Dipendente[nc].stipendio<<endl;
    }
}

void StipendioMin(){
    File2.open("Minore.txt", ios::out);
    for(int i=0;i<nc;i++){
        if(Dipendente[i].anzianita<1500){
            File2 << Dipendente[nc].nome << " " << Dipendente[nc].cognome << " " << Dipendente[nc].anzianita << " " << Dipendente[nc].stipendio << "\n";
        }
    }
    File2.close();
}


void StampaAnzianita(){
    int eta;
    cout<<"\nInserire eta da controllare"<<endl;
    cin>>eta;
    for(int i=0;i<nc;i++){
        if(Dipendente[nc].anzianita == eta){
            cout<<"-Dipendente "<<i+1<<":"<<endl
            <<"\tNome: "<<Dipendente[nc].nome<<endl
            <<"\tCognome: "<<Dipendente[nc].cognome<<endl
            <<"\tAnzianita: "<<Dipendente[nc].anzianita<<endl
            <<"\tStipendio: "<<Dipendente[nc].stipendio<<endl;
        }
    }
}

int main(){
    Caricamento();
    int scelta = 1;
    while(scelta!=0){
        cout<<"\nInserire valore per scegliere opzione"<<endl
        <<"Opzione 1: Caricamento valori dal file"<<endl
        <<"Opzione 2: Stampa tabella"<<endl
        <<"Opzione 3: Inserimento dati stipendio<1500€"<<endl
        <<"Opzione 4: Stampa dipendenti dato anzianita"<<endl;
        cin>>scelta;
        switch(scelta){
            case 0:     
                cout<<"\n---Chiusura e del programma---"<<endl;
            break;
            case 1:
                Caricamento();
            break;
            case 2:
                Stampa();
            break;
            case 3:
                StipendioMin();
            break;
            case 4:
                StampaAnzianita();
            break;
            default:
                cout<<"\nScelta inesistente"<<endl;
        }
    }
}