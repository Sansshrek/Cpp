#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

vector<int> vettore;

void random(){
    srand(time(0));
    int scelta,n;
    cout<<"\nInserire grandezza vector"<<endl;
    cin>>scelta;
    vettore.clear();
    for(int i=0;i<scelta;i++){
        n = rand()%50;
        vettore.push_back(n);
    }
    cout<<"\n\tInserimento Random completato"<<endl;
}

void print(){
    cout<<endl;
    if(vettore.empty())  //controlla se il vettore è vuoto
        cout<<"\nIl vector e' vuoto"<<endl;
    else{
        for(int i=0;i<vettore.size();i++){
            cout<<vettore[i]<<" ";
        }
    }
    cout<<endl;
}

void add(){
    int scelta, scelta_inserimento, n;
    cout<<"\nInserire quantita elementi da aggiungere"<<endl;
    cin>>scelta;
    cout<<"\nInserimento Random(1) o Manuale(2)"<<endl;
    cin>>scelta_inserimento;
    if(scelta_inserimento==1 || scelta_inserimento==2){
        for(int i=0;i<scelta;i++){
            if(scelta_inserimento==1){
                n = rand()%50;
                vettore.push_back(n);
            }
            else{
                cout<<"\nInserire elemento "<<i<<": ";
                cin>>n;
                vettore.push_back(n);
            }
        }
        cout<<"\n\tAggiunta completata"<<endl;
    }
    else
        cout<<"\nScelta inserimento inesistente"<<endl;
}

void information(){
    cout<<"\nsize= "<<vettore.size()<<endl;
    cout<<"capacity= "<<vettore.capacity()<<" (non ho idea a cosa serva)"<<endl;
    cout<<"maximum size= "<<vettore.max_size()<<endl;
}

void print_strange(){
    cout<<endl; 
    vector<int>::iterator it;  
    //.begin definisce l'index 0 del vector, .end definisce l'ultimo index del vector
    //creando un vettore it prendiamo i valori del vector da .begin fino a .end e aumentiamo l'index di it
    for(it=vettore.begin();it!=vettore.end();it++){
        cout<<*it<<" "; //stampa il puntatore di it che aumenta
    }
    /*si puo anche fare:
    int i;
    for(it=vettore.begin();it!=vettore.end();i++){
        cout<<it[i]<<" ";
    } */
    cout<<endl; 
}

void first_last(){
    cout<<"\nprimo elemento= "<<vettore.front()<<endl;
    cout<<"ultimo elemento (pos="<<vettore.size()-1<<")= "<<vettore.back()<<endl;
}

void delete_pos(){
    cout<<"ciao"<<endl;
    
    /*
    int scelta, n, n1;
    cout<<"\nQuanti elementi vuoi eliminare"<<endl;
    cin>>scelta;
    if(scelta==0) cout<<"cazzo vuoi allora"<<endl;
    else if(scelta==1){
        cout<<"\nInserire posizione da eliminare"<<endl;
        cin>>n;
        vettore.erase(n);
    }
    else{
        cout<<"\nInserire posizione 1 da cui partire"<<endl;
        cin>>n;
        cout<<"Inserire posizione 2 a cui arrivare"<<endl;
        cin>>n1;
        vettore.erase(n, n1);
    }
    */
} 

void print_pos(){
    int n;
    cout<<"\nInserire posizione"<<endl;
    cin>>n;
    if(n<vettore.size())
        cout<<"\npos "<<n<<": "<<vettore.at(n)<<endl;
    else
        cout<<"\nPosizione inesistente"<<endl;
}

void change_pos(){
    int n, n1;
    cout<<"\nInserire posizione da cambiare"<<endl;
    cin>>n;
    if(n<vettore.size()){
        cout<<"pos "<<n<<"= ";
        cin>>n1;
        vettore.at(n)=n1;  //si puo fare piu facilmente con vettore[n] = n1;
        cout<<"\nCambio valore completato"<<endl;
    }
    else
        cout<<"\nPosizione inesistente"<<endl;
}

void insert_pos(){
    cout<<"ciao"<<endl;
    /*
    int n, n1;
    cout<<"\nInserire posizione in cui inserire"<<endl;
    cin>>n;
    if(n<vettore.size()){
        cout<<"pos "<<n<<"= ";
        cin>>n1;
        vettore.insert(n, n1);  //oltre ad aggiungere il valore, il vettore sposta i valori successivi in avanti
        //aumentando la size del vettore automaticamente
        cout<<"\nInserimento valore completato"<<endl;
    }
    else
        cout<<"\nPosizione inesistente"<<endl;
    */
}

void clear(){
    vettore.clear();
    cout<<"\nEliminazione completata"<<endl;
}

void pop_back(){
    vettore.pop_back();
    cout<<"\nUltimo elemento eliminato correttamente"<<endl;
}

void swap(){
    int scelta, max;
    vector<int> test;
    cout<<"\nInserire grandezza secondo vector"<<endl;
    cin>>max;
    do{
        cout<<"\nInserimento random(1) o manuale(2)"<<endl;
        cin>>scelta;
    }
    while(scelta!=1 && scelta!=2);
    if(scelta==1){
        srand(time(0));
        for(int i=0;i<max;i++){
            int n;
            n = rand()%50;
            test.push_back(n);
        }
    }
    else{
        for(int i=0;i<max;i++){
            int n;
            cout<<"\nInserire valore pos "<<i<<endl;
            cin>>n;
            test.push_back(n);
        }
    }
    cout<<"\nVuoi stampare il vettore? (si=1/no=2)"<<endl;
    cin>>scelta;
    cout<<endl;
    if(scelta==1){
        for(int i=0;i<test.size();i++){
            cout<<test[i]<<" ";
        }
    }
    else if(scelta!=2)
        cout<<"\nScambio vettori in corso"<<endl;
    else 
        cout<<"\nScelta inesistente, scambio in corso"<<endl;
    vettore.swap(test);
    cout<<"\nScambio completato"<<endl;
}

int main(){
    int scelta;
    random();
    do{
        cout<<"\nInserire Scelta"<<endl
        <<"Opzione 0: Esci dal programma"<<endl
        <<"Opzione 1: Inserimento random"<<endl
        <<"Opzione 2: Stampa vector"<<endl
        <<"Opzione 3: Aggiungi elementi nel vettore      (.push_back)"<<endl
        <<"Opzione 4: Informazioni sul vector            (.size)"<<endl
        <<"Opzione 5: Stampa strana                      (.begin e .end)"<<endl
        <<"Opzione 6: Stampa primo e ultimo elemento     (.front e .back)"<<endl
        <<"Opzione 7: Elimina elemento/i     (non va)    (.erase)"<<endl
        <<"Opzione 8: Stampa elemento posizione          (.at)"<<endl
        <<"Opzione 9: Cambia elemento da posizione       (.at)"<<endl
        <<"Opzione 10: Aggiungi elemento da posizione    (.insert)"<<endl
        <<"Opzione 11: Elimina elementi del vettore      (.clear)"<<endl
        <<"Opzione 12: Elimina ultimo elemento           (.pop_back)"<<endl
        <<"Opzione 13: Scambia valori fra 2 vettori      (.swap)"<<endl
        <<"----------------------------------------"<<endl;
        cin>>scelta;
        switch(scelta){
            case 0:
                cout<<"\n---Uscendo dal programma---"<<endl;
            break;
            case 1:
                random();
            break;
            case 2:
                print();
            break;
            case 3:
                add();
            break;
            case 4:
                information();
            break;
            case 5:
                print_strange();
            break;
            case 6:
                first_last();
            break;
            case 7:
                delete_pos();
            break;
            case 8:
                print_pos();
            break;
            case 9:
                change_pos();
            break;
            case 10:
                insert_pos();
            break;
            case 11:
                clear();
            break;
            case 12:
                pop_back();
            break;
            case 13:
                swap();
            break;
            default:
                cout<<"\nScelta inesistente"<<endl;
        }
    }
    while(scelta!=0);
}