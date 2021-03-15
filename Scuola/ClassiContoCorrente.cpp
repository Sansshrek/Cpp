#include <iostream>
#include <string>
using namespace std;

struct Movimenti{
    string data;
    string dd;
    string mm;
    string yy;
    float importo;
    string tipo;
};
Movimenti Lista[100];
int cont=0;

void Data();
void ordinamento();

class CC{
    string correntista;
    string nc;
    float saldo;
    private:
        float ti;
    public:
    CC(float a){
        saldo = a;
        ti = 0;
    }
    void prelievo (float a){
        if(saldo>a){
            saldo -= a;
            Lista[cont].importo = a;
            Lista[cont].tipo = "prelievo";
            cout<<"\nInserire data odierna (dd-mm-yy)"<<endl;
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
        cout<<"\nInserire data odierna (dd-mm-yy)"<<endl;
        cin>>Lista[cont].data;
        cont++;
        cout<<"\nIl saldo attuale e' di euro "<<saldo<<endl;
    }
    void stampa(){
        cout<<"\nNumero conto: "<<nc<<endl;
        cout<<"Correntista: "<<correntista<<endl;
        cout<<"Saldo: "<<saldo<<endl;
        cout<<"Tasso di interesse: "<<ti<<endl;
        stampaMovimenti();
    }
    void stampaMovimenti(){
        cout<<"\nLista movimenti"<<endl;
        for(int i=0;i<cont;i++){
            cout<<"Data "<<Lista[i].data<<": "<<Lista[i].tipo<<" di "<<Lista[i].importo<<endl;
        }
    }
    void crea(){
        cout<<"\nInserire numero conto "<<endl;
        cin>>nc;
        cout<<"Inserire il cognome del correntista "<<endl;
        cin>>correntista;
    }
    void interesse(){
        cout<<"\nInserire valore Tasso interesse (es. 2 = 200 euro)"<<endl;
        cin>>ti;
        saldo += (ti/100)*saldo;
    }
};

int main(){
    int scelta=1;
    float a;
    CC conto(0);
    conto.crea();
    while(scelta!=0){
        cout<<"\nInserire valore per scegliere opzione"<<endl
        <<"Opzione 1: Prelievo"<<endl
        <<"Opzione 2: Versamento"<<endl
        <<"Opzione 3: Stampa dati conto"<<endl
        <<"Opzione 4: Applica Tassa di interesse"<<endl
        <<"Opzione 5: Ordinamento Lista movimenti"<<endl
        <<"Opzione 0: Esci"<<endl;
        cin>>scelta;
        switch(scelta){
            case 0:
                cout<<"\n---Uscendo dal programma---"<<endl;
            break;
            case 1:
                cout<<"\nInserire la cifra da prelevare"<<endl;
                cin>>a;
                conto.prelievo(a);
            break;
            case 2:
                cout<<"\nInserire la cifra da versare"<<endl;
                cin>>a;
                conto.versamento(a);
            break;
            case 3:
                conto.stampa();
            break;
            case 4:
                conto.interesse();
            break;
            case 5:
                Data();
                ordinamento();
                conto.stampaMovimenti();
            break;
            default:
                cout<<"\nScelta inesistente"<<endl;
        }
    }
}

void Data(){
    string n1, n2;
    for(int i=0;i<cont;i++){
        n1 = Lista[i].data[0];
        n2 = Lista[i].data[1];
        Lista[i].dd = n1 + n2;
        n1 = Lista[i].data[4];
        n2 = Lista[i].data[5];
        Lista[i].mm = n1 + n2;
        n1 = Lista[i].data[7];
        n2 = Lista[i].data[8];
        Lista[i].yy = n1 + n2;
    }
} 

void ordinamento(){
    int scelta, tmpInt;
    string Sort[100];
    Movimenti tmp;
    bool check = false, checkScambio;
    cout << "\nIn che modo vuoi ordinare la tabella" << endl
         << "\tOpzione 1: Ordinamento in base al giorno" << endl
         << "\tOpzione 2: Ordinamento in base al mese" << endl
         << "\tOpzione 3: Ordinamento in base all'anno" << endl;
    cin >> scelta;
    switch (scelta) {
    case 1:
        for (int i = 0; i < cont; i++) {
            checkScambio = false;
            for (int j = 1; j < (cont - i); j++){
                if (Lista[j - 1].dd > Lista[j].dd) {
                    tmp = Lista[j - 1];
                    Lista[j - 1] = Lista[j];
                    Lista[j] = tmp;
                    checkScambio = true;
                }
            }
            if (!checkScambio)
                break;
        }
        cout << "\n\t-Ordinamento Completato-" << endl;
        break;
    case 2:
        for (int i = 0; i < cont; i++) {
            checkScambio = false;
            for (int j = 1; j < (cont - i); j++)
                if (Lista[j - 1].mm > Lista[j].mm) {
                    tmp = Lista[j - 1];
                    Lista[j - 1] = Lista[j];
                    Lista[j] = tmp;
                    checkScambio = true;
                }
            if (!checkScambio)
                break;
        }
        cout << "\n\t-Ordinamento Completato-" << endl;
        break;
    case 3:
        for (int i = 0; i < cont; i++) {
            checkScambio = false;
            for (int j = 1; j < (cont - i); j++)
                if (Lista[j - 1].yy > Lista[j].yy) {
                    tmp = Lista[j - 1];
                    Lista[j - 1] = Lista[j];
                    Lista[j] = tmp;
                    checkScambio = true;
                }
            if (!checkScambio)
                break;
        }
        cout << "\n\t-Ordinamento Completato-" << endl;
        break;
    default:
        cout << "\nScelta inesistente" << endl;
        check = true;
    }
}