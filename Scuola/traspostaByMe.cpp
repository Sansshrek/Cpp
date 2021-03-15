//Caricamento di una matrice random con valori compresi tra 1 e 10, in input n righe e m colonne.
/*
Menu con prima opzione: stampa A + stampa trasposta TA
*/

#include <iostream>
#include <time.h>
#include <cstdlib>
using namespace std;

int A[100][100];

void stampa(int n, int m){
    cout<<"\nMatrice A:"<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<A[i][j]<<"\t";
        }
        cout<<endl;
    }
}

void randomizza(int n, int m){
    srand(time(0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            A[i][j] = (rand()%10) + 1;
        }
    }
    stampa(n, m);
}

void trasposta(int n, int m){
    int TA[m][n];
    cout<<"\nMatrice trasposta TA:"<<endl;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            TA[i][j] = A[j][i];
        }
    }
    for(int i=0; i<m;i++){
        for(int j=0;j<n;j++){
            cout<<TA[i][j] <<"\t";
        }
        cout<<endl;
    }
}

int main(){
    int n, m;
    cout<<"Inserire il numero di righe: ";
    cin>>n;
    cout<<"Inserire il numero di colonne: ";
    cin>>m;
    srand(time(0));
    for(int i=0; i<n;i++){
        for(int j=0;j<m;j++){
            A[i][j] =   (rand() % 10) + 1;
        }
    }
    int scelta;
    do{
        cout<<"\nSelezionare una opzione: "<<endl
        <<"- 1: Stampa matrice A"<<endl
        <<"- 2: Stampa trasposta TA"<<endl
        <<"- 3: Randomizza Matrice A"<<endl
        <<"- 0: Esci dal programma"<<endl;
        cin>>scelta;
        switch(scelta){
            case 0:
                cout<<"\n Uscendo dal programma";
            break;
            case 1:
                stampa(n, m);
            break;
            case 2:
                trasposta(n, m);
            break;
            case 3:
                randomizza(n, m);
            break;
            default:
                cout<<"Scelta inesistente"<<endl;
        }
    }
    while(scelta!=0);
    return 0;
}