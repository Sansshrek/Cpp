//dati due interi n e m letti in input, considerare una matrice A[n][m]
//utilizzare procedure e funzione
//1) inserire i valori nella matrice in modo random, i valori sono compresi tra 1 e 10
//2) dato un intero x in input stampare la somma della riga x
//3) per ogni riga stampa la somma dei numeri superiori alla media
#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;
int A[100][100];
void random(int n,int m){
    srand(time(0));
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            A[i][j]=((rand()%10)+1);
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cout<<A[i][j]<<"\t";
        }
        cout<<endl;
    }
}

void stampaX(int m){
    int riga,somma;
    cout<<"Inserire valore della riga da stampare"<<endl;
    cin>>riga;
    for(int i=0;i<m;i++){
        somma=somma+A[riga][i];
    }
    cout<<"Somma riga "<<riga<<" = "<<somma<<endl;
}

void stampaMedia(int n, int m){
    int cont=0,i,j;
    float media=0,somma;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            media=media+A[i][j];
            cont++;
        }
    }
    media=media/cont;
    cout<<"Media = "<<media<<endl;
    for(i=0;i<n;i++){
        somma=0;
        for(j=0;j<m;j++){
            if(A[i][j]>media){
                somma=somma+A[i][j];
            }
        }
        cout<<"Somma riga "<<i<<" = "<<somma<<endl;
    }
}

int main(){
    int n,m;
    cout<<"Inserire grandezza righe"<<endl;
    cin>>n;
    cout<<"Inserire grandezza colonne"<<endl;
    cin>>m;
    int scelta;
    random(n,m);
    do{
        cout<<"Opzione 1: randomizzare valori matrice"<<endl;
        cout<<"Opzione 2: stampare riga x"<<endl;
        cout<<"Opzione 3: stampa somma elementi maggiori della media per ogni riga"<<endl;
        cout<<"Opzione 0: uscire dal programma"<<endl;
        cin>>scelta;
        switch(scelta){
            case 0:
                cout<<"Uscendo dal programma"<<endl;
            break;
            case 1:
                random(n,m);
            break;
            case 2:
                stampaX(m);
            break;
            case 3:
                stampaMedia(n,m);
            break;
            default:
                cout<<"Scelta inesistente"<<endl;
        }
    }
    while(scelta!=0);
}