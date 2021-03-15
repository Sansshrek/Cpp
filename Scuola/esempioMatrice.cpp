#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;
float A[100][100];
void carica(int n,int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<"Inserire valore riga "<<i<<" colonna "<<j<<": ";
            cin>>A[i][j];
        }
    }
}
void stampa(int n,int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<A[i][j]<<"\t";
        }
        cout<<endl;
    }
}
void mediaCol(int n,int m){
    float media;
    int j;
    for(int i=0;i<m;i++){
        media=0;
        for(j=0;j<n;j++){
            media+=A[j][i];
        }
        media /= n;
        cout<<"Media colonna "<<i<<" = "<<media<<endl;
    }
}
void maxRiga(int n,int m){
    int max;
    for(int i=0;i<n;i++){
        max=0;
        for(int j=0;j<m;j++){
            if(A[i][j]>max){
                max=A[i][j];
            }
        }
        cout<<"Valore massimo riga "<<i<<" = "<<max<<endl;
    }
}
void random(int n,int m){
    srand(time(0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            A[i][j] = (rand()%10) + 1;
        }
    }
}
void minMatrix(int n,int m){
    int posi=0;
    int posj=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(A[i][j]<A[posi][posj]){
                posi=i;
                posj=j;
            }
        }
    }
    cout<<"Valore minimo della matrice = "<<A[posi][posj]<<" nella riga "<<posi<<" colonna "<<posj<<endl;
}
int main(){
    int n,m,scelta;
    cout<<"Inserire valore per le righe"<<endl;
    cin>>n;
    cout<<"Inserire valore per le colonne"<<endl;
    cin>>m;
    random(n,m);
    do{
        cout<<"\nInserire valore per scegliere opzione"<<endl;
        cout<<"Opzione 1: Carica Matrice"<<endl
        <<"Opzione 2: Randomizza valori matrice"<<endl
        <<"Opzione 3: Stampa matrice"<<endl
        <<"Opzione 4: Stampa massimo di ogni riga"<<endl
        <<"Opzione 5: Stampa media di ogni colonna"<<endl
        <<"Opzione 6: Stampa minimo di tutta la matrice"<<endl
        <<"Opzione 0: Esci dal programma"<<endl;
        cin>>scelta;
        cout<<endl;
        switch(scelta){
            case 0:
                cout<<"Uscendo dal programma"<<endl;
            break;
            case 1:
                carica(n,m);
            break;
            case 2:
                random(n,m);
            break;
            case 3:
                stampa(n,m);
            break;
            case 4:
                maxRiga(n,m);
            break;
            case 5:
                mediaCol(n,m);
            break;
            case 6:
                minMatrix(n,m);
            break;
            default:
                cout<<"Scelta inesistente"<<endl;
        }
    }
    while(scelta!=0);
}