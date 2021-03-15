/*classe conto corrente con codice conto, saldo, cognome, nome. codice univoco per conto con deposito minimo di 100 
euro. gestire un insieme di conti bancari prevedendo:
1)La creazione di un conto nuovo
2)Prelievo da un conto, fornendo il codice conto
3)Versamento su un conto, fornendo il codice conto
4)Stampa dei dati di un conto, fornendo il codice conto
5)Lo spostamento di denari da un conto all'altro, fornendo i codici conto
6)La lettura dei dati dei conti correnti con il massimo ed il minimo di saldo
7)La scrittura su un file dei codici dei conti aventi il saldo superiore alla media dei saldi di tutti i conti
8)La stampa dei saldi dei conti ordinati in ordine decrescente, dal piu grande al piu piccolo
9)La creazione di nuovi conti correnti leggendo i dati da un file  */
#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;

class dati{
    string codice, nome, cognome;
    float saldo;
public:
    void input(string cod, string nom, string cog, float s){
        codice = cod;
        nome = nom;
        cognome = cog;
        saldo = s;
    }
    void prelievo(float s){
        saldo -= s;
    }
    void versamento(float s){
        saldo += s;
    }
    void stampa(int user){
        cout<<"\nDati conto utente:"<<user<<endl
        <<"\tNome: "<<nome<<" "<<cognome<<endl
        <<"\tCodice: "<<codice<<endl
        <<"\tSaldo: "<<saldo<<endl;
    }
    string get_cod(){ return codice;}
    float get_saldo(){ return saldo;}
};

int main(){
    int nc, scelta;
    dati conto[100];
    cout<<"Inserire numero conti"<<endl;
    cin>>nc;
    int cont=0;
    for(int i=0;i<nc;i++){
        string cod, nom, cog;
        float s;
        bool check=false;
        do{
            cout<<"\nInserire codice utente "<<i+1<<endl;
            cin>>cod;
            for(int j=0;j<cont;j++){
                if(cod==conto[j].get_cod()){
                    check=true;
                    break;
                }
            }
            if(check)
                cout<<"\nERRORE: Codice gia esistente"<<endl;
        }
        while(check);
        cont++;
        cout<<"Inserire nome e cognome utente "<<i+1<<endl;
        cin>>nom;
        cin>>cog;
        do{
            cout<<"Inserire saldo utente "<<i+1<<" (minimo 100 euro)"<<endl;
            cin>>s;
            if(s<100)
                cout<<"\nERRORE: saldo immesso troppo basso (minimo 100 euro)"<<endl;
        }
        while(s<100);
        conto[i].input(cod, nom, cog, s);
    }
    do{
        cout<<"\nInserire valore per scegliere opzione"<<endl
        <<"Opzione 1: Crea nuovo conto"<<endl
        <<"Opzione 2: Prelievo da un conto, dato codice"<<endl
        <<"Opzione 3: Versamento su un conto, dato codice"<<endl
        <<"Opzione 4: Stampa di un conto, dato codice"<<endl
        <<"Opzione 5: Spostamento di denaro da due conti, dati codici"<<endl
        <<"Opzione 6: Stampa conto con saldo massimo e minimo"<<endl
        <<"Opzione 7: Inserire su file i conti con saldo maggiore alla media dei saldi"<<endl
        <<"Opzione 8: Stampa saldi ordinati in ordine decrescente"<<endl
        <<"Opzione 9: Crea nuovi conti da file"<<endl;
        cin>>scelta;
        switch(scelta){
            case 0:
            break;
            case 1:
            break;
            case 2:
            break;
            case 3:
            break;
            case 4:
            break;
            case 5:
            break;
            case 6:
            break;
            case 7:
            break;
            case 8:
            break;
            case 9:
            break;
            default:
                cout<<"\nScelta inesistente"<<endl;
        }
    }
    while(scelta!=0);
}