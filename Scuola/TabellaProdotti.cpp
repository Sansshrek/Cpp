#include <iostream>
#include <string.h>
#include <math.h>
#include <time.h>
using namespace std;

string cognomiRandom[15] = {"Rossi", "Ferrari", "Bianchi", "Romano", "Gallo", "Costa", "Fontana", "Conti", "Esposito", "Bruno", "Rizzo", "Moretti", "Marino", "Barbieri", "Lombardi"};

const int MAX = 100;
int nc = 0;

struct Dati{
    string nome;
    int vend;
};
Dati prodotto[MAX];

void Random(){
    int cogIndex;
    cout<<"\nInserire massimo studenti"<<endl;
    cin>>nc;
    srand(time(0));
    for(int i=0;i<nc;i++){
        cogIndex = rand()%15;
        prodotto[i].nome = cognomiRandom[cogIndex];
        prodotto[i].vend = rand()%20;
    }
    cout<<"\n\t--Randomizzazione completata--"<<endl;
}

void Inserimento(){
    int scelta;
    cout << "Vorresti inserire i valori manualmente o random?  (0/1)" << endl;
    cin >> scelta;
    if(scelta == 1)
        Random();
    else{
        cout<<"\nInserire massimo studenti"<<endl;
        cin>>nc;
        for(int i=0;i<nc;i++){
            cout<<"Inserire nome del cliente "<<i+1<<endl;
            cin>>prodotto[i].nome;
            cout<<"Inserire quantita venduta dal cliente "<<i+1<<endl;
            cin>>prodotto[i].vend;
        }
    }
}

void Stampa(){
    for(int i=0;i<nc;i++){
        cout<<"\nCliente "<<i+1<<" "<<prodotto[i].nome<<" ha venduto "<<prodotto[i].vend<<" prodotti"<<endl;
    }
}

void StampaMedia(){
    int n,som=0;
    float med;
    cout<<"\nInserire valore per controllare la media maggiore prodotti venduti al valore"<<endl;
    cin>>n;
    for(int i=0;i<nc;i++){
        if(prodotto[i].vend>n){
            som++;
            med+=prodotto[i].vend;
        }
    }
    med/=som;
    cout<<"\nLa media delle vendite superiore a "<<n<<" e': "<<med<<endl;
}

void StampaMaggiore(){
    int pos;
    int max=0;
    for(int i=0;i<nc;i++){
        if(prodotto[i].vend>max){
            max = prodotto[i].vend;
            pos = i;
        }
    }
    cout<<"\nIl cliente con la quantita piu alta di vendite e': "<<prodotto[pos].nome<<endl;
}

void StampaVendita(){
    bool checkNome = false, checkVend = false;
    string nome;
    int pos;
    cout<<"\nInserire nome per stampare la vendita"<<endl;
    cin>>nome;
    for(int i=0;i<nc;i++){
        if(nome == prodotto[i].nome){
            checkNome = true;
            pos = i;
            if(prodotto[i].vend>0)
                checkVend = true;
        }
    }
    if(!checkNome)
        cout<<"\nIl nome inserito non esiste nella lista"<<endl;
    else{
        if(!checkVend)
            cout<<"\n"<<nome<<" non ha venduto prodotti ancora"<<endl;
        else
            cout<<"\n"<<nome<<" ha venduto "<<prodotto[pos].vend<<" prodotti"<<endl;
    }
}

void OrdinamentoVend(){
    bool checkScambio;
    int scelta;
    Dati tmp;
    cout << "\nVuoi eseguire l'ordinamento:" << endl
         << "\tOpzione 0: dal piu grande al piu piccolo" << endl
         << "\tOpzione 1: dal piu piccolo al piu grande" << endl;
    cin >> scelta;
    if (scelta == 0 || scelta == 1) {
        for (int i = 0; i < nc; i++) {
            checkScambio = false;
            for (int j = 1; j < (nc - i); j++)
                if (scelta == 0) {
                    if (prodotto[j - 1].vend < prodotto[j].vend) {
                        tmp = prodotto[j - 1];
                        prodotto[j - 1] = prodotto[j];
                        prodotto[j] = tmp;
                        checkScambio = true;
                    }
                } else if (scelta == 1) {
                    if (prodotto[j - 1].vend > prodotto[j].vend) {
                        tmp = prodotto[j - 1];
                        prodotto[j - 1] = prodotto[j];
                        prodotto[j] = tmp;
                        checkScambio = true;
                    }
                }
            if (!checkScambio)
                break;
        }
    } else
        cout << "\nScelta inesistente" << endl;
}

void OrdinamentoNome(){
    Dati tmp;
    for(int i=0;i<nc-1;i++){
        for(int j=i+1;j<nc-1;j++){
            if(prodotto[i].nome > prodotto[i+1].nome){
                tmp = prodotto[i];
                prodotto[i] = prodotto[j];
                prodotto[j] = tmp;
            }
        }
    }
}

void Ordinamento()
{
    int scelta;
    bool check = true;
    cout << "\nIn che modo vuoi ordinare la tabella" << endl
         << "\tOpzione 1: Ordinamento in base alle vendite" << endl
         << "\tOpzione 2: Ordinamento in base al nome" << endl;
    cin >> scelta;
    switch (scelta) {
    case 1:
        OrdinamentoVend();
        break;
    case 2:
        OrdinamentoNome();
        break;
    default:
        cout << "\nScelta inesistente" << endl;
        check = false;
    }
    if(check)
        cout << "\n\t-Ordinamento Completato-" << endl;
        Stampa();
}

int main(){
    int scelta=1;
    Inserimento();
    while(scelta!=0){
        cout<<"\nInserire valore per scegliere opzione"<<endl
        <<"Opzione 1: Inserire nuovi clienti"<<endl
        <<"Opzione 2: Randomizza i clienti"<<endl
        <<"Opzione 3: Stampare lista clienti"<<endl
        <<"Opzione 4: Stampa media vendite maggiori a valore in input"<<endl
        <<"Opzione 5: Stampa cliente con maggiore vendita"<<endl
        <<"Opzione 6: Stampa vendita cliente dato"<<endl
        <<"Opzione 7: Ordinamento lista clienti"<<endl
        <<"Opzione 0: Esci dal programma"<<endl;
        cin>>scelta;
        switch(scelta){
            case 0:     
                cout<<"\n---Chiusura e del programma---"<<endl;
            break;
            case 1:
                Inserimento();
            break;
            case 2:
                Random();
            break;
            case 3: 
                Stampa();
            break;
            case 4:
                StampaMedia();
            break;
            case 5:
                StampaMaggiore();
            break;
            case 6:
                StampaVendita();
            break;
            case 7:
                Ordinamento();
            break;
            default:
                cout<<"\nScelta inesistente"<<endl;
        }
    }
}