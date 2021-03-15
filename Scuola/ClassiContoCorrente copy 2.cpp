#include <iostream>
#include <string>
#include <time.h>
using namespace std;

string cognomiRandom[15] = { "Rossi", "Ferrari", "Bianchi", "Romano", "Gallo", "Costa", "Fontana", "Conti", "Esposito", "Bruno", "Rizzo", "Moretti", "Marino", "Barbieri", "Lombardi" };

struct Movimenti{
    string data;
    float importo;
    string tipo;
};
Movimenti Lista[100];
int cont=0;
int nc=0;

class CC{
    string correntista;
    string nomec;
    float saldo;
    float ti;
    public:
    
    CC(){
        saldo = 0;
        ti = 0;
    } 
    void prelievo (float a){
        if(saldo>a){
            saldo -= a;
            Lista[cont].importo = a;
            Lista[cont].tipo = "prelievo";
            cout<<"\nInserire data odierna"<<endl;
            cin>>Lista[cont].data;
            cont++;
            cout<<"\nil saldo attuale e' di euro "<<saldo<<endl;
        }
        else{
            cout<<"\nNon e' possibile effettuare il prelievo di una cifra superiore al saldo attuale che ammonta a euro "<<saldo<<endl;
        }
    }
    void versamento (float a){
        saldo += a;
        Lista[cont].importo = a;
        Lista[cont].tipo = "versamento";
        cout<<"\nInserire data odierna"<<endl;
        cin>>Lista[cont].data;
        cont++;
        cout<<"\nIl saldo attuale e' di euro "<<saldo<<endl;
    }
    void stampa(){
        cout<<"\nNumero conto: "<<nomec<<endl;
        cout<<"Correntista: "<<correntista<<endl;
        cout<<"Saldo: "<<saldo<<endl;
        cout<<"Tasso di interesse: "<<ti<<endl;
        cout<<"\nLista movimenti"<<endl;
        for(int i=0;i<cont;i++){
            cout<<"Data "<<Lista[i].data<<": "<<Lista[i].tipo<<" di "<<Lista[i].importo<<endl;
        }
    }
    void crea(float i){
        cout<<"\nInserire numero conto "<<i<<endl;
        cin>>nomec;
        cout<<"Inserire il cognome del correntista "<<i<<endl;
        cin>>correntista;
    }
    void random(){  //in costruzione
        srand(time(0));
        int indexCog;
        indexCog = rand() % 15;
        correntista = cognomiRandom[indexCog];
        indexCog = (rand()%9000)+1000;
        nomec = indexCog;
        cout<<"Correntista = "<<correntista<<" Nomec = "<<nomec<<endl;
    }
    void interesse(){
        cout<<"\nInserire valore Tasso interesse (es. 2 = 200 euro)"<<endl;
        cin>>ti;
        Lista[cont].importo = ti;
        Lista[cont].tipo = "tasso di interesse";
        cout<<"\nInserire data odierna"<<endl;
        cin>>Lista[cont].data;
        cont++;
        saldo += (ti/100)*saldo;
    }
    string Nome(){
        return correntista;
    }
    string Conto(){
        return nomec;
    }
};

int main(){
    CC User[100];
    bool check=false;
    int scelta=1, sceltaUtente=1, sceltaInserimento=0;
    float a;
    int userIndex;
    cout<<"Inserire valore Utenti"<<endl;
    cin>>nc;
    do{
        cout<<"Inserimento random o manuale? (1/2) (random in costruzione)"<<endl;
        cin>>sceltaInserimento;
        switch(sceltaInserimento){
            case 1:
                cout<<"\nRandom in costruzione"<<endl;
                /*
                for(int i=0;i<nc;i++){
                    User[i].random();
                }
                check=true;  */
            break;
            case 2:
                for(int i=0;i<nc;i++){
                    User[i].crea(i);
                }
                check=true;
            break;
            default:
                cout<<"Scelta inesistente"<<endl;
        }
    }
    while(!check);
    while(sceltaUtente!=0){
        cout<<"\nInserire valore per scegliere opzione"<<endl
        <<"Opzione 1: Scelta Utente"<<endl
        <<"Opzione 2: Stampa lista utenti"<<endl
        <<"Opzione 0: Esci dal programma"<<endl;
        cin>>sceltaUtente;
        switch(sceltaUtente){
            case 0:
                cout<<"\n---Uscendo dal programma---"<<endl;
            break;
            case 1:
                cout<<"\nInserire Numero Utente da controllare"<<endl;
                cin>>userIndex;
                if(userIndex>=0 && userIndex<nc){
                    scelta=1;
                    while(scelta!=0){
                        cout<<"\nInserire valore per scegliere opzione"<<endl
                        <<"Opzione 1: Prelievo"<<endl
                        <<"Opzione 2: Versamento"<<endl
                        <<"Opzione 3: Stampa dati conto"<<endl
                        <<"Opzione 4: Applica Tassa di interesse"<<endl
                        <<"Opzione 0: Esci dall'Utente"<<endl;
                        cin>>scelta;
                        switch(scelta){
                            case 0:
                                cout<<"\n---Uscendo dall'Utente ---"<<endl;
                            break;
                            case 1:
                                cout<<"\nInserire la cifra da prelevare"<<endl;
                                cin>>a;
                                User[userIndex].prelievo(a);
                            break;
                            case 2:
                                cout<<"\nInserire la cifra da versare"<<endl;
                                cin>>a;
                                User[userIndex].versamento(a);
                            break;
                            case 3:
                                User[userIndex].stampa();
                            break;
                            case 4:
                                User[userIndex].interesse();
                            break;
                            default:
                                cout<<"\nScelta inesistente"<<endl;
                        }
                    }
                }
                else
                    cout<<"\nUtente non esistente"<<endl;
            break;
            case 2:
                cout<<endl;
                for(int i=0;i<nc;i++){
                    string nome = User[i].Nome();
                    string conto = User[i].Conto();
                    cout<<"Utente "<<i<<": "<<nome<<" (numero conto: "<<conto<<")"<<endl;
                }
            break;
            default:
                cout<<"\nScelta inesistente"<<endl;
        }
    }
}