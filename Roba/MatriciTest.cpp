#include <iostream>
#include <string.h>
#include <time.h>
using namespace std;
int M[100][100] = {0}, maxy=0, maxx=0;

void print(){
    if(maxy == 0 || maxx == 0)
        cout<<"\nMatrice vuota"<<endl;
    else{
        cout<<"\nRighe "<<maxy<<" - Colonne "<<maxx<<endl<<endl;
        for(int i=0;i<maxx;i++){
            cout<<"   "<<i;
        }
        cout<<endl;
        for(int i=0;i<maxy;i++){
            cout<<i<<" ";
            for(int j=0;j<maxx;j++){
                cout<<"["<<M[i][j]<<"]";
            }
            cout<<endl;
        }
    }
}

void print_pos(){
    if(maxy == 0 || maxx == 0)
        cout<<"\nMatrice vuota"<<endl;
    else{
        int y,x;
        do{
            cout<<"\nInserire posizione riga"<<endl;
            cin>>y;
            if(y<0 || y>=maxy)
                cout<<"\nLa posizione deve essere un numero tra 0 e "<<maxy-1<<endl;
        }while(y<0 || y>=maxy);
        do{
            cout<<"\nInserire posizione colonna"<<endl;
            cin>>x;
            if(x<0 || x>=maxx)
                cout<<"\nLa posizione deve essere un numero tra 0 e "<<maxx-1<<endl;
        }while(x<0 || x>=maxx);
        cout<<"\n\nRiga "<<y<<" - Colonna "<<x<<"\nValore = ["<<M[y][x]<<"]"<<endl;
    }
}

void insert(){
    do{
        cout<<"\nInserire grandezza righe"<<endl;
        cin>>maxy;
        if(maxy<0)
            cout<<"\nLa grandezza delle righe deve essere maggiore di 0"<<endl;
    }while(maxy<0);
    do{
        cout<<"\nInserire grandezza colonne"<<endl;
        cin>>maxx;
        if(maxx<0)
            cout<<"\nLa grandezza delle colonne deve essere maggiore di 0"<<endl;
    }while(maxx<0);
    srand(time(0));
    int scelta;
    do{
        cout<<"\nInserimento valori manuale(1) o random(2)?"<<endl;
        cin>>scelta;
        if(scelta!=1 && scelta!=2)
            cout<<"\nScelta insistente"<<endl;
    }while(scelta!=1 && scelta!=2);
    if(scelta==1){
        for(int i=0;i<maxy;i++){
            for(int j=0;j<maxx;j++){
                cout<<"\nInserire valore riga "<<i+1<<", col "<<j+1<<endl;
                cin>>M[i][j];
            }
        }
    }
    else{
        for(int i=0;i<maxy;i++){
            for(int j=0;j<maxx;j++){
                M[i][j] = (rand()%41)+10;                
            }
        }
    }
    cout<<"\nInserimento effettuato"<<endl;
}

void addRow(){
    string c;
    cout<<"\nVerra aggiunta la riga "<<maxy<<". Confermi (s/n)"<<endl;
    cin>>c;
    if(c=="s"){
        int scelta;
        do{
            cout<<"\nInserimento valori manuale(1) o random(2)?"<<endl;
            cin>>scelta;
            if(scelta!=1 && scelta!=2)
                cout<<"\nScelta insistente"<<endl;
        }while(scelta!=1 && scelta!=2);
        if(scelta==1){
            for(int i=0;i<maxx;i++){
                cout<<"\nInserire valore col "<<i+1<<endl;
                cin>>M[maxy][i];
            }
        }
        else{
            for(int i=0;i<maxx;i++){
                M[maxy][i] = (rand()%41)+10;
            }
        }
        cout<<"\nInserimento effettuato"<<endl;
        maxy++;
    }
}

void addCol(){
    string c;
    cout<<"\nVerra aggiunta la colonna "<<maxx<<". Confermi (s/n)"<<endl;
    cin>>c;
    if(c=="s"){
        int scelta;
        do{
            cout<<"\nInserimento valori manuale(1) o random(2)?"<<endl;
            cin>>scelta;
            if(scelta!=1 && scelta!=2)
                cout<<"\nScelta insistente"<<endl;
        }while(scelta!=1 && scelta!=2);
        if(scelta==1){
            for(int i=0;i<maxx;i++){
                cout<<"\nInserire valore riga "<<i+1<<endl;
                cin>>M[i][maxx];
            }
        }
        else{
            for(int i=0;i<maxx;i++){
                M[i][maxx] = (rand()%41)+10;
            }
        }
        cout<<"\nInserimento effettuato"<<endl;
        maxx++;
    }
}

void delRow(){
    string c;
    cout<<"\nVerra eliminata la riga "<<maxy-1<<". Confermi (s/n)"<<endl;
    cin>>c;
    if(c=="s"){
        maxy--;
    }
}

void delCol(){
    string c;
    cout<<"\nVerra eliminata la colonna "<<maxx-1<<". Confermi (s/n)"<<endl;
    cin>>c;
    if(c=="s"){
        maxx--;
    }
}

void matrix(){
    bool check;
    int scelta, scelta_insert, mx, my;
    do{
        cout<<"\nInserire grandezza righe"<<endl;
        cin>>my;
        if(my<0)
            cout<<"\nLa grandezza delle righe deve essere maggiore di 0"<<endl;
    }while(my<0);
    do{
        cout<<"\nInserire grandezza colonne"<<endl;
        cin>>mx;
        if(mx<0)
            cout<<"\nLa grandezza delle colonne deve essere maggiore di 0"<<endl;
    }while(mx<0);
    int matrix[my][mx];
    do{
        cout<<"\nInserimento valori manuale(1) o random(2)?"<<endl;
        cin>>scelta_insert;
        if(scelta_insert!=1 && scelta_insert!=2)
            cout<<"\nscelta_insert insistente"<<endl;
    }while(scelta_insert!=1 && scelta_insert!=2);
    if(scelta_insert==1){
        for(int i=0;i<my;i++){
            for(int j=0;j<mx;j++){
                cout<<"\nInserire valore riga "<<i+1<<", col "<<j+1<<endl;
                cin>>matrix[i][j];
            }
        }
    }
    else{
        for(int i=0;i<my;i++){
            for(int j=0;j<mx;j++){
                matrix[i][j] = (rand()%41)+10;                
            }
        }
    }
    cout<<"\nInserimento effettuato"<<endl;
    do{
        cout<<"\nInserire valore per scegliere opzione"<<endl;
        cout<<"Opzione 1: Inserimento valori"<<endl;
        cout<<"Opzione 2: Stampa matrice"<<endl;
        cout<<"Opzione 3: Stampa valore data posizione"<<endl;
        cout<<"Opzione 0: Esci dalla matrice"<<endl;
        cin>>scelta;
        switch(scelta){
            case 0:
                cout<<"\n---Uscendo dalla matrice---"<<endl;
            break;
            case 1:{
                do{
                    cout<<"\nInserimento valori manuale(1) o random(2)?"<<endl;
                    cin>>scelta_insert;
                    if(scelta_insert!=1 && scelta_insert!=2)
                        cout<<"\nscelta_insert insistente"<<endl;
                }while(scelta_insert!=1 && scelta_insert!=2);
                if(scelta_insert==1){
                    for(int i=0;i<my;i++){
                        for(int j=0;j<mx;j++){
                            cout<<"\nInserire valore riga "<<i+1<<", col "<<j+1<<endl;
                            cin>>matrix[i][j];
                        }
                    }
                }
                else{
                    for(int i=0;i<my;i++){
                        for(int j=0;j<mx;j++){
                            matrix[i][j] = (rand()%41)+10;                
                        }
                    }
                }
                cout<<"\nInserimento effettuato"<<endl;
            }break;
            case 2:{
                cout<<"\nRighe "<<my<<" - Colonne "<<mx<<endl<<endl;
                for(int i=0;i<mx;i++){
                    cout<<"   "<<i;
                }
                cout<<endl;
                for(int i=0;i<my;i++){
                    cout<<i<<" ";
                    for(int j=0;j<mx;j++){
                        cout<<"["<<matrix[i][j]<<"]";
                    }
                    cout<<endl;
                }
            }break;
            case 3:{
                int x,y;
                cout<<"\nInserire posizione riga"<<endl;
                cin>>y;
                cout<<"\nInserire posizione colonna"<<endl;
                cin>>x;
                cout<<"\n\nRiga "<<y<<" - Colonna "<<x<<"\nValore = ["<<matrix[y][x]<<"]"<<endl;
            }break;
            default:
                cout<<"\nScelta inesistente"<<endl;
        }
    }while(scelta!=0);
}

int main(){
    int scelta;
    do{
        cout<<"\nInserire valore per scegliere opzione"<<endl;
        cout<<"Opzione 1: Inserimento valori"<<endl;
        cout<<"Opzione 2: Stampa matrice"<<endl;
        cout<<"Opzione 3: Stampa valore data posizione"<<endl;
        cout<<"Opzione 4: Aggiungi riga"<<endl;
        cout<<"Opzione 5: Aggiungi colonna"<<endl;
        cout<<"Opzione 6: Elimina riga"<<endl;
        cout<<"Opzione 7: Elimina colonna"<<endl;
        cout<<"Opzione 8: Testa totalmente una matrice nuova"<<endl;
        cout<<"Opzione 0: Esci dal programma"<<endl;
        cin>>scelta;
        switch(scelta){
            case 0:
                cout<<"\n---Uscendo dal programma---"<<endl;
            break;
            case 1:
                insert();
            break;
            case 2:
                print();
            break;
            case 3:
                print_pos();
            break;
            case 4:
                addRow();
            break;
            case 5:
                addCol();
            break;
            case 6:
                delRow();
            break;
            case 7:
                delCol();
            break;
            case 8:
                matrix();
            break;
            default:
                cout<<"\nScelta inesistente"<<endl;
        }
    }while(scelta!=0);
}