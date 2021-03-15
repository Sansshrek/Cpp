#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;

struct Dati{
    string codice, descrizione;
    int quantita, prezzo;
};
Dati Prod[100];
int cont=0;

class Prodotti{
public:
    void input(){
        cout<<"\nInserire quantita prodotti"<<endl;
        cin>>cont;
        for(int i=0;i<cont;i++){
            cout<<"\nInserire codice prodotto "<<i+1<<endl;
            cin>>Prod[i].codice;
            cout<<"Inserire descrizione prodotto "<<i+1<<endl;
            cin>>Prod[i].descrizione;
            cout<<"Inserire quantita prodotto "<<i+1<<endl;
            cin>>Prod[i].quantita;
            cout<<"Inserire prezzo prodotto "<<i+1<<endl;
            cin>>Prod[i].prezzo;
        }
    }
    void inputFile(){
        fstream File;
        File.open("prodotti.txt", ios::in);
        while(!File.eof()){
            File>>Prod[cont].codice>>Prod[cont].descrizione>>Prod[cont].quantita>>Prod[cont].prezzo;
            cont++;
        }
        File.close(); 
    }
    void vendita(){
        string cod;
        int pos;
        bool check=false;
        cout<<"\nInserire codice del prodotto da vendere"<<endl;
        cin>>cod;
        for(int i=0;i<cont;i++){
            if(Prod[i].codice==cod){
                check=true;
                pos=i;
            }
        }
        if(check==true){
            int n;
            cout<<"\nInserire quantita di "<<Prod[pos].descrizione<<" venduto:"<<endl;
            cin>>n;
            Prod[pos].quantita=Prod[pos].quantita-n;
        }
        else{
            cout<<"\nProdotto non trovato"<<endl;
        }
    }
    void inserimento(){
        string cod;
        int pos;
        bool check=false;
        cout<<"\nInserire codice del prodotto da inserire"<<endl;
        cin>>cod;
        for(int i=0;i<cont;i++){
            if(Prod[i].codice==cod){
                check=true;
                pos=i;
            }
        }
        if(check==true){
            int n;
            cout<<"\nInserire quantita di "<<Prod[pos].descrizione<<" da inserire:"<<endl;
            cin>>n;
            Prod[pos].quantita=Prod[pos].quantita+n;
        }
        else{
            cout<<"\nProdotto non trovato"<<endl;
        }
    }
    void stampa(){
        for(int i=0;i<cont;i++){
            cout<<"\nProdotto "<<i<<endl;
            cout<<"\t-codice: "<<Prod[i].codice<<endl;
            cout<<"\t-descrizione: "<<Prod[i].descrizione<<endl;
            cout<<"\t-quantita: "<<Prod[i].quantita<<endl;
            cout<<"\t-prezzo: "<<Prod[i].prezzo<<endl;
        }
    }
};

int main(){
    Prodotti super;
    int scelta;
    do{
        cout<<"Vuoi inserire i prodotti manualmente(1) o da File(2)"<<endl;
        cin>>scelta;
        if(scelta!=1 && scelta!=2)
                cout<<"\nScelta inesistente"<<endl;
    }
    while(scelta!=1 && scelta!=2);
    if(scelta==1)
        super.input();
    else
        super.inputFile();
    do{
        cout<<"\nInserire opzione"<<endl
        <<"Opzione 1: Inserimento manuale"<<endl
        <<"Opzione 2: Inserimento da file"<<endl
        <<"Opzione 3: Vendita prodotto"<<endl
        <<"Opzione 4: Inserimento prodotto"<<endl
        <<"Opzione 5: Stampa prodotti"<<endl
        <<"Opzione 0: Esci dal programma"<<endl;
        cin>>scelta;
        switch(scelta){
            case 1:
                super.input();
            break;
            case 2:
                super.inputFile();
            break;
            case 3:
                super.vendita();
            break;
            case 4:
                super.inserimento();
            break;
            case 5:
                super.stampa();
            break;
            default:
                cout<<"\nopzione inesistente"<<endl;
        }
    }
    while(scelta!=0);
}