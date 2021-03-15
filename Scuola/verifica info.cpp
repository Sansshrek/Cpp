#include <iostream>
#include <string.h>
using namespace std;

struct telefoniaA{
    string cognome;
    string nome;
    int telefono;
    string fiscale;
    int scatti;
};
telefoniaA userA[100];
struct telefoniaB{
    int telefono;
    int scatti;
};
telefoniaB userB[100];
int nc=0;

void inserimentoA(){
    int max;
    cout<<"Inserire quanti utenti da inserire"<<endl;
    cin>>max;
    for(int i=nc;i<max;i++){
        cout<<"Inserire cognome e nome utente "<<i+1<<endl;
        cin>>userA[i].cognome;
        cin>>userA[i].nome;
        cout<<"Inserire numero di telefono utente "<<i+1<<endl;
        cin>>userA[i].telefono;
        userB[i].telefono = userA[i].telefono;
        cout<<"Inserire codice fiscale utente "<<i+1<<endl;
        cin>>userA[i].fiscale;
        cout<<"Inserire quantità scatti mesi precedenti utente "<<i+1<<endl;
        cin>>userA[i].scatti;
        nc++;
    }
    cout<<"\nInserimento completato"<<endl;
}

void inserimentoB(){
    int n_scatti;
    for(int i=0;i<nc;i++){
        cout<<"Inserire quantita di scatti mese attuale utente "<<i+1<<endl;
        cin>>n_scatti;
        userB[i].scatti += n_scatti;
        userA[i].scatti += n_scatti;
    }
}

void stampaBolletta(){
    int n_scatti;
    cout<<"Inserire costo scatto del mese attuale"<<endl;
    cin>>n_scatti;
    for(int i=0;i<nc;i++){
        cout<<"\n-"<<userA[i].cognome<<" "<<userA[i].nome<<" ("<<userA[i].fiscale<<
        ")\n\tHa utilizzato "<<userB[i].scatti<<
        " scatti questo mese\n\tDeve pagare "<<userB[i].scatti*n_scatti<<" sul numero "<<userB[i].telefono<<endl;
    }
}

void stampaMaggiore(){
    int max=0,pos;
    for(int i=0;i<nc;i++){
        if(userA[i].scatti>max){
            max=userA[i].scatti;
            pos=i;
        }
    }
    cout<<"\nL'utente con il maggior numero di scatti è: "<<endl
    <<"\t-"<<userA[pos].cognome<<" "<<userA[pos].nome<<" con "<<max<<" scatti"<<endl;
}

void ordinamento(){
    telefoniaA tmp;  //errore avevo messo tmp[100] al posto di tmp
    for(int i=0;i<nc;i++){
        if(userA[i].scatti>userA[i+1].scatti){
            tmp = userA[i];
            userA[i] = userA[i+1];
            userA[i+1] = tmp;
        }
    }
}

void sconto();
void cancellazione();  //errore codice non ho finito cancellazione()

int main(){
    int scelta=1;
    while(scelta!=0){
        cout<<"\nInserire valore per scegliare opzione"<<endl
        <<"Opzione 1: Aggiunta utenti"<<endl
        <<"Opzione 2: Aggiornamento scatti mensili"<<endl
        <<"Opzione 3: Stampa bollette utenti"<<endl
        <<"Opzione 4: Stampa utente con maggior numero di scatti"<<endl
        <<"Opzione 5: Ordinamento utenti in base agli scatti"<<endl
        <<"Opzione 6: Sconto del 10% sugli scatti"<<endl
        <<"Opzione 7: Cancellazione utente"<<endl
        <<"Opzione 0: Esci dal programma"<<endl;
        cin>>scelta;
        switch(scelta){
            case 0:
                cout<<"\n---Stai uscendo dal programma---"<<endl;
            break;
            case 1:
                inserimentoA();
            break;
            case 2:
                inserimentoB();
            break;
            case 3:
                stampaBolletta();
            break;
            case 4:
                stampaMaggiore();
            break;
            case 5:
                ordinamento();
            break;
            case 6:
                sconto();
            break;
            case 7:
                cancellazione();
            break;
            default:
                cout<<"Scelta inesistente"<<endl;
        }
    }
}

void sconto(){
    string nome[100],cognome[100];
    bool check=false;
    int n,scatti;
    cout<<"Quanti scatti vuoi inserire per lo sconto?"<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Inserire nome e cognome"<<endl;
        cin>>nome[i];
        cin>>cognome[i];
        for(int j=0;j<nc;j++){
            if(nome[i]==userA[j].nome && cognome[i]==userA[j].cognome)  //errore non avevo messo [i] a cognome
                check=true;
        }
        if(check==false)    
            cout<<"Utente non trovato"<<endl;
        else{
            scatti = userA[i].scatti;
            scatti*=10;
            scatti/=100;
            userA[i].scatti = scatti;  //errore codice non ho tolto lo sconto al prezzo
        }
    }
}