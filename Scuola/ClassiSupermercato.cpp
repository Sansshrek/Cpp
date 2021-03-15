#include <iostream>
#include <string.h>
#include <time.h>
#include <fstream>
using namespace std;

string prodotti[]={"Pane","Cereali","Latte","Mela","Biscotti","Olio","Banane","Pesce","Farina","Sale","Burro","Uova","Pasta"};

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
        cont=0;
        File.open("prodotti.txt", ios::in);
        if (File.is_open()){
            while(!File.eof()){
                File>>Prod[cont].codice>>Prod[cont].descrizione>>Prod[cont].quantita>>Prod[cont].prezzo;
                cont++;
            }
            File.close(); 
        }
        else{
            cout<<"\nfile 'prodotti.txt' non trovato nella directory del file"<<endl;
            cout<<"Passaggio al menu inserimento"<<endl;
            inputMenu();
        }
    }
    void inputRandom(){
        int length = (sizeof(prodotti)/sizeof(*prodotti)), index, n;
        cout<<"\nInserire quantita prodotti"<<endl;
        cin>>cont;
        srand(time(0));
        for(int i=0;i<cont;i++){
            n =  (rand()%9000)+1000;
            Prod[i].codice = to_string(n);
            index = rand()%length;
            Prod[i].descrizione = prodotti[index];
            Prod[i].quantita = rand()%50;
            Prod[i].prezzo = (rand()%50)+1;
        }
    }
    void inputMenu(){
        int scelta;
        do{
            cout<<"\nInserire Opzione"<<endl
            <<"Opzione 1: Inserimento Random"<<endl
            <<"Opzione 2: Inserimento manuale"<<endl
            <<"Opzione 3: Inserimento da file"<<endl;
            cin>>scelta;
            switch(scelta){
                case 1:
                    inputRandom();
                break;
                case 2:
                    input();
                break;
                case 3:
                    inputFile();
                break;
                default:
                    cout<<"\nOpzione inesistente"<<endl;
            }
        }
        while(scelta!=1 && scelta!=2 && scelta!=3);
    }
    void vendita(){
        bool check=false;
        int n;
        string cod;
        cout<<"\nInserire codice del prodotto da vendere"<<endl;
        cin>>cod;
        for(int i=0;i<cont;i++){
            if(Prod[i].codice==cod){
                check=true;
                cout<<"\nInserire quantita di "<<Prod[i].descrizione<<" venduto:"<<endl;
                cin>>n;
                if(Prod[i].quantita>=n)
                    Prod[i].quantita-=n;
                else
                    cout<<"\nIl numero inserito supera la quantita di "<<Prod[i].descrizione<<" disponibile ("<<Prod[i].quantita<<")"<<endl;
            }
        }
        if(!check){
            cout<<"\nCodice non trovato... ricerca della descrizione in corso"<<endl;
            for(int i=0;i<cont;i++){
                if(Prod[i].descrizione==cod){
                    check=true;
                    cout<<"\nInserire quantita di "<<Prod[i].descrizione<<" venduto:"<<endl;
                cin>>n;
                if(Prod[i].quantita>n)
                    Prod[i].quantita-=n;
                else
                    cout<<"\nIl numero inserito supera la quantita di "<<Prod[i].descrizione<<" disponibile ("<<Prod[i].quantita<<")"<<endl;
                }
            }
        }
        if(!check)
            cout<<"\nProdotto non trovato"<<endl;
    }
    void inserimento(){
        string cod;
        int n;
        bool check=false;
        cout<<"\nInserire codice del prodotto da inserire"<<endl;
        cin>>cod;
        for(int i=0;i<cont;i++){
            if(Prod[i].codice==cod){
                check=true;
                cout<<"\nInserire quantita di "<<Prod[i].descrizione<<" da inserire:"<<endl;
                cin>>n;
                Prod[i].quantita+=n;
            }
        }
        if(!check){
            cout<<"\nCodice non trovato... ricerca della descrizione in corso"<<endl;
            for(int i=0;i<cont;i++){
                if(Prod[i].descrizione==cod){
                    check=true;
                    cout<<"\nInserire quantita di "<<Prod[i].descrizione<<" da inserire:"<<endl;
                    cin>>n;
                    Prod[i].quantita+=n;
                }
            }
        }
        if(!check)
            cout<<"\nProdotto non trovato"<<endl;
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
    void aggiunta(){
        int n;
        cout<<"\nQuanti prodotti vuoi inserire?"<<endl;
        cin>>n;
        for(int i=0;i<n;i++){
            cout<<"\nInserire codice prodotto "<<i+1<<endl;
            cin>>Prod[cont].codice;
            cout<<"Inserire descrizione prodotto "<<i+1<<endl;
            cin>>Prod[cont].descrizione;
            cout<<"Inserire quantita prodotto "<<i+1<<endl;
            cin>>Prod[cont].quantita;
            cout<<"Inserire prezzo prodotto "<<i+1<<endl;
            cin>>Prod[cont].prezzo;
            cont++;
        }
    }
    void elimina(){
        string cod;
        bool check=false;
        int pos;
        cout<<"\nInserire codice del prodotto da inserire"<<endl;
        cin>>cod;
        for(int i=0;i<cont;i++){
            if(Prod[i].codice==cod){
                check=true;
                pos = i;
            }
        }
        if(!check){
            cout<<"\nCodice non trovato... ricerca della descrizione in corso"<<endl;
            for(int i=0;i<cont;i++){
                if(Prod[i].descrizione==cod){
                    check=true;
                    pos = i;
                }
            }
        }
        if(check){
            Dati tmp;
            for(int i=pos;i<cont;i++){
                tmp = Prod[i];
                Prod[i] = Prod[i+1];
                Prod[i+1]=tmp;
            }
            cont--;
            cout<<"\nEliminazione effettuata"<<endl;
        }
        else
            cout<<"\nProdotto non trovato"<<endl;
    }
};

int main(){
    Prodotti Super;
    int scelta;
    Super.inputMenu();
    do{
        cout<<"\nInserire opzione"<<endl
        <<"Opzione 1: Scelta inserimento prodotti"<<endl
        <<"Opzione 2: Vendita prodotto"<<endl
        <<"Opzione 3: Inserimento prodotto"<<endl
        <<"Opzione 4: Stampa prodotti"<<endl
        <<"Opzione 5: Aggiunta prodotti"<<endl
        <<"Opzione 6: Elimina prodotto"<<endl
        <<"Opzione 0: Esci dal programma"<<endl;
        cin>>scelta;
        switch(scelta){
            case 1:
                Super.inputMenu();
            break;
            case 2:
                Super.vendita();
            break;
            case 3:
                Super.inserimento();
            break;
            case 4:
                Super.stampa();
            break;
            case 5:
                Super.aggiunta();
            break;
            case 6:
                Super.elimina();
            break;
            default:
                cout<<"\nOpzione inesistente"<<endl;
        }
    }
    while(scelta!=0);
}