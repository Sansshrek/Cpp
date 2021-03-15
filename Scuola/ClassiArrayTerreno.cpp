#include <iostream>
#include <string.h>
#include <time.h>
using namespace std;

class dati {
    string codice;
    float ext, perc, rend;

public:
    void input(int i){
        bool check = false;
        int scelta;
        do{
            cout<<"\nInserimento terreno "<<i+1<<" random(1) o manuale(2)?"<<endl;
            cin>>scelta;
            if (scelta != 1 && scelta != 2)
                    cout << "\nScelta inesistente" << endl;
        }
        while (scelta != 1 && scelta != 2);
        if(scelta==1){
            int n = rand()%1000;
            codice = to_string(n);
            ext = rand()%1000;
            perc = rand()%100;
            rend = rand()%20;
        }
        else{
            cout << "\nInserire codice terreno" << endl;
            cin >> codice;
            cout << "Inserire estensione terreno (in mq)" << endl;
            cin >> ext;
            do {
                cout << "Inserire percentuale edificabile" << endl;
                cin >> perc;
                if (perc <= 100 && perc > 0) {
                    check=true;
                }
                else
                    cout<<"\nPercentuale impossibile"<<endl;
            } while (!check);
            cout << "Inserire costo rendita al mq" << endl;
            cin >> rend;
        }
    }
    void change(){
        bool check=false;
        int scelta;
        cout << "\nInserire valore per scegliere opzione" << endl
             << "1) Modifica codice terreno (" <<codice<<")"<< endl
             << "2) Modifica estensione terreno (" <<ext<<")" << endl
             << "3) Modifica percentuale edificabile (" <<perc<<")" << endl
             << "4) Modifica costo rendita (" <<rend<<")" << endl;
        cin >> scelta;
        switch (scelta) {
        case 1: {
            cout << "\nInserisci nuovo codice terreno" << endl;
            cin >> codice;
        } break;
        case 2: {
            cout << "\nInserisci nuova estensione terreno" << endl;
            cin >> ext;
        } break;
        case 3: {
            do {
                cout << "Inserire nuova percentuale edificabile" << endl;
                cin >> perc;
                if (perc <= 100 && perc > 0) {
                    check=true;
                }
                else
                    cout<<"\nPercentuale impossibile"<<endl;
            } while (!check);
        } break;
        case 4: {
            cout << "\nInserisci nuovo costo rendita" << endl;
            cin >> rend;
        } break;
        default:
            cout << "\nScelta inesistente" << endl;
        }
    }
    void print(){
        cout<<"\nDati terreno"<<endl
        <<"\tCodice: "<<codice<<endl
        <<"\tEstensione terreno: "<<ext<<endl
        <<"\tPercentuale terreno edificabile: "<<perc<<endl
        <<"\tCosto rendita: "<<rend<<"\u20AC"<<endl;
    }
    float get_rend(){ return rend*ext; }
    float get_edif(){ return (ext*perc)/100; }
    string get_codice(){ return codice; }
    float get_ext(){ return ext; }
    float get_cost(){ return rend; }
};

int main(){
    srand(time(0));
    dati terr[100];
    int nc,scelta,index,sceltaUser;
    cout<<"Inserire numero terreni"<<endl;
    cin>>nc;
    for (int i = 0; i < nc; i++) {
        terr[i].input(i);
    }
    do {
        cout << "\nInserire valore per scegliere opzione" << endl
             << "Opzione 1: Scelta Terreno" << endl
             << "Opzione 2: Stampa lista Terreni" << endl
             << "Opzione 3: Stampa Terreno con piu metri edificabili"<<endl
             << "Opzione 4: Stampa rendita media dei Terreni"<<endl
             << "Opzione 5: Dato codice Terreno stampa metri edificabili e rendita totale"<<endl
             << "Opzione 6: Aggiungi Terreno" << endl
             << "Opzione 7: Elimina Terreno" << endl
             << "Opzione 8: Ordinamento Terreno" << endl
             << "Opzione 0: Esci dal programma" << endl;
        cin >> scelta;
        switch (scelta) {
        case 0:
            cout << "\n---Uscendo dal programma---" << endl;
            break;
        case 1: {
            cout << "\nInserire Numero Terreno da controllare" << endl;
            cin >> index;
            index--;
            if (index >= 0 && index < nc) {
                do {
                    cout << "\nInserire valore per scegliere opzione" << endl
                         << "Opzione 1: Re-inserimento valori Terreno" << endl
                         << "Opzione 2: Cambia valori Terreno" << endl
                         << "Opzione 3: Stampa dati del Terreno" << endl
                         << "Opzione 4: Stampa rendita totale del Terreno" << endl
                         << "Opzione 5: Stampa metri edificabili del Terreno" << endl
                         << "Opzione 0: Esci dai Dati Terreno" << endl;
                    cin >> sceltaUser;
                    switch (sceltaUser) {
                    case 0:
                        cout << "\n---Uscendo dai dati Terreno---" << endl;
                    break;
                    case 1:
                        terr[index].input(index);
                    break;
                    case 2:
                        terr[index].change();
                    break;
                    case 3:
                        terr[index].print();
                    break;
                    case 4:
                        cout << "\nRendita totale: " << terr[index].get_rend() <<"\u20AC"<< endl;
                    break;
                    case 5:
                        cout << "\nMetri edificabili: " << terr[index].get_edif() << endl;
                    break;
                    default:
                        cout << "\nScelta inesistente" << endl;
                    }
                } while (sceltaUser != 0);
            } else
                cout << "\nTerreno non esistente" << endl;
        }break;
        case 2: {
            cout<<endl;
            for(int i=0;i<nc;i++){
                cout<< "\t"<<i+1<<")-" <<"Terreno: "<<terr[i].get_codice()<<", estensione terreno: "<<terr[i].get_ext()<<", costo rendita: "<<terr[i].get_cost()<<"\u20AC"<<endl;
            }
        } break;
        case 3: {
            float max=0;
            int pos;
            for(int i=0;i<nc;i++){
                if(terr[i].get_edif()>max){
                    max=terr[i].get_edif();
                    pos=i;
                }
            }
            cout<<"\nIl terreno con piu metri edificabili e' "<<terr[pos].get_codice()<<", con "<<terr[pos].get_edif()<<" metri edificabili"<<endl;
        } break;
        case 4: {
            float med=0;
            for(int i=0;i<nc;i++){
                med+=terr[i].get_rend();
            }
            med/=nc;
            cout<<"\nLa media della rendita e': "<<med<<endl;
        } break;
        case 5: {
            string s;
            bool check=false;
            int pos;
            cout<<"\nInserire codice da controllare"<<endl;
            cin>>s;
            for(int i=0;i<nc;i++){
                if(s==terr[i].get_codice()){
                    pos=i;
                    check=true;
                    break;
                }
            }
            if(check){
                cout<<"\nTrovato Terreno "<<s<<endl
                <<"\tMetri edificabili: "<<terr[pos].get_edif()<<endl
                <<"\tRendita totale: "<<terr[pos].get_rend()<<endl;
            }
            else{
                cout<<"\nTerreno non trovato"<<endl;
            }
        } break;
        case 6: {
            terr[nc].input(nc);
            cout<<"\nAggiunta Completata"<<endl;
            nc++;
        } break;
        case 7: {
            string s;
            bool check=false;
            int pos;
            cout<<"\nInserire codice Terreno da eliminare"<<endl;
            cin>>s;
            for(int i=0;i<nc;i++){
                if(s==terr[i].get_codice()){
                    pos=i;
                    check=true;
                    break;
                }
            }
            if(!check){
                cout<<"\nCodice Terreno non trovato... Ricerca sulla posizione"<<endl;
                int n = stoi(s);
                if(n>0 && n<=nc){
                    pos = n-1;
                    check=true;
                }
            }
            if(check){
                for(int i=pos;i<nc;i++){
                    terr[i] = terr[i+1];
                }
                cout<<"\nEliminazione Completata"<<endl;
                nc--;
            }
            else{
                cout<<"\nTerreno non trovato"<<endl;
            }
        }break;
        case 8: {
            dati tmp;
            int sceltaOrd1, sceltaOrd2;
            float swap[nc];
            do{
                cout<<"\nInserire scelta ordinamento"<<endl
                <<"\t1) Ordinamento in base all'estensione del terreno"<<endl
                <<"\t2) Ordinamento in base al costo della rendita"<<endl;
                cin>>sceltaOrd1;
                if(sceltaOrd1!=1 && sceltaOrd1!=2)
                    cout<<"\nScelta inesistente"<<endl;
            }
            while(sceltaOrd1!=1 && sceltaOrd1!=2);
            do{
                cout << "\nVuoi eseguire l'ordinamento:" << endl
                << "\t1) Dal piu grande al piu piccolo" << endl
                << "\t2) Dal piu piccolo al piu grande" << endl;
                cin>>sceltaOrd2;
                if(sceltaOrd2!=1 && sceltaOrd2!=2)
                    cout<<"\nScelta inesistente"<<endl;
            }
            while(sceltaOrd2!=1 && sceltaOrd2!=2);
            for(int i=0;i<nc;i++){
                for(int j=i+1;j<nc;j++){
                    if(sceltaOrd1==1){
                        if(sceltaOrd2==1){
                            if(terr[j].get_ext()>terr[i].get_ext()){
                                tmp = terr[i];
                                terr[i] = terr[j];
                                terr[j] = tmp;
                            }
                        }
                        else{
                            if(terr[j].get_ext()<terr[i].get_ext()){
                                tmp = terr[i];
                                terr[i] = terr[j];
                                terr[j] = tmp;
                            }
                        }
                    }
                    else{
                        if(sceltaOrd2==1){
                            if(terr[j].get_cost()>terr[i].get_cost()){
                                tmp = terr[i];
                                terr[i] = terr[j];
                                terr[j] = tmp;
                            }
                        }
                        else{
                            if(terr[j].get_cost()<terr[i].get_cost()){
                                tmp = terr[i];
                                terr[i] = terr[j];
                                terr[j] = tmp;
                            }
                        }
                    }
                }
            }
            cout<<"\nOrdinamento completato"<<endl;
        }break;
        default:
            cout << "\nScelta inesistente" << endl;
        }
    } while (scelta != 0);
}