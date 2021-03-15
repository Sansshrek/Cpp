/*Ospedale che registri i ricoveri dei pazienti per cognome,nome,data di accettazione, data di dimissione
1)Stampa elenco pazienti dimessi in una determinata data fornita in input
2)Registra dimissione avendo in input il cognome da dimettere e la data attuale. se non presente segnala errore
3)Registra accettazione paziente con immissione dei dati nella prima posizione vuota */

#include <iostream>
#include <string.h>
using namespace std;

const int MAX=100;
struct DatiPaziente{
    string cognome;
    string nome;
    string accettazione;
    string dimissione;
};
DatiPaziente paziente[MAX];

int nc=0;
void Inserimento(){
    int max;
    cout<<"\nInserire numero pazienti"<<endl;
    cin>>max;
    for(int i=0;i<max;i++){
        cout<<"Inserire cognome paziente "<<nc+1<<endl;
        cin>>paziente[i].cognome;
        cout<<"Inserire nome paziente "<<nc+1<<endl;
        cin>>paziente[i].nome;
        cout<<"Inserire data accettazione paziente (es. 123456)"<<nc+1<<endl;
        cin>>paziente[i].accettazione;
        cout<<"Inserire data dimissione paziente (es. 123456)"<<nc+1<<endl;
        cin>>paziente[i].dimissione;
        nc++;
    }
}

void StampaLista(){
    cout<<"\nLista pazienti:"<<endl;
    for(int i=0;i<nc;i++){
        cout<<"\n-"<<paziente[i].cognome<<" "<<paziente[i].nome
        <<"\n\tdata accettazione: "<<paziente[i].accettazione<<" | data dimissione: "<<paziente[i].dimissione<<endl;
    }
}

void StampaDimessi(){
    string data;
    cout<<"Inserire data da controllare"<<endl;
    cin>>data;
    bool check=false;
    for(int i=0;i<nc;i++){
        if(paziente[i].dimissione==data){
            check=true;
        }
    }
    if(check==true){
        cout<<"\nLista pazienti dimessi il "<<data<<":"<<endl;
        for(int i=0;i<nc;i++){
            if(paziente[i].dimissione==data){
                cout<<"\n-"<<paziente[i].cognome<<" "<<paziente[i].nome<<endl;
            }
        }
    }
    else
        cout<<"Non ci sono pazienti dimessi il "<<data<<endl;
}

void RegistraDimissione(){
    string cognome,data;
    bool check=false;
    int pos;
    cout<<"Inserire cognome da dimettere"<<endl;
    cin>>cognome;
    cout<<"Inserire data attuale"<<endl;
    cin>>data;
    for(int i=0;i<nc;i++){
        if(paziente[i].cognome==cognome){
            check=true;
            pos=i;
        }
    }
    if(check==true){
        paziente[pos].dimissione=data;
    }
    else
        cout<<"Non esiste il paziente "<<cognome<<" nella lista"<<endl;
}

void RegistraAccettazione(){
    int data, dimissione, data_vuota;
    bool check=false;
    cout<<"Inserire data attuale"<<endl;
    cin>>data;
    for(int i=0;i<nc;i++){
        dimissione = stoi(paziente[i].dimissione);
        if(dimissione<data){
            data_vuota=i;
            check=true;
            break;
        }
    }
    if(check==false){
        data_vuota=nc+1;
    }
    cout<<"\nInserire cognome paziente "<<nc+1<<endl;
    cin>>paziente[data_vuota].cognome;
    cout<<"Inserire nome paziente "<<nc+1<<endl;
    cin>>paziente[data_vuota].nome;
    cout<<"Inserire data accettazione paziente "<<nc+1<<" (es. 123456)"<<endl;
    cin>>paziente[data_vuota].accettazione;
    cout<<"Inserire data dimissione paziente "<<nc+1<<" (es. 123456)"<<endl;
    cin>>paziente[data_vuota].dimissione;
    nc++;
}

int main(){
    int scelta=1;
    Inserimento();
    while(scelta!=0){
        cout<<"\nInserisci valore per scegliere opzione"<<endl
        <<"Opzione 1: Inserimento dei pazienti"<<endl
        <<"Opzione 2: Stampa lista dei pazienti con relativa data"<<endl
        <<"Opzione 3: Stampa elenco pazienti dimessi in una determinata data"<<endl
        <<"Opzione 4: Registra dimissione"<<endl
        <<"Opzione 5: Registra accettazione paziente nella prima posizione vuota"<<endl
        <<"Opzione 0: Esci dal programma"<<endl;
        cin>>scelta;
        switch(scelta){
            case 0:
                cout<<"\n---Stai uscendo dal programma---"<<endl;
            break;
            case 1:
                Inserimento();
            break;
            case 2:
                StampaLista();
            break;
            case 3:
                StampaDimessi();
            break;
            case 4:
                RegistraDimissione();
            break;
            case 5:
                RegistraAccettazione();
            break;
            default:
                cout<<"Scelta non esistente"<<endl;
        }
    }
}