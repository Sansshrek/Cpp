//Caricamento di una matrice random con valori compresi tra 1 e 10, in input n righe e m colonne.
/*
Menu con prima opzione: stampa A + stampa trasposta TA
*/



#include <iostream>
#include <time.h>
#include <cstdlib>
using namespace std;

int A[100][100];

void trasposta(int n, int m){
    int TA[m][n];
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            TA[i][j] = A[j][i];
        }
    }
    cout<<"Matrice trasposta: "<<endl;
    for(int i=0; i<m;i++){
        for(int j=0;j<n;j++){
            cout<<TA[i][j] <<"\t";
        }
        cout<<endl;
    }
}

void sommacol(int n, int m){
	for(int i=0; i<m; i++){
		int somma=0;
		for(int j=0; j<n; j++){
			somma += A[j][i];
		}
		cout<<"La somma per la colonna" <<i+1 <<" e': " <<somma <<endl;
	}
}

float media(int n, int m){
	float media=0;
	int valori = n*m;
	for(int i=0; i<n;i++){
		for(int j=0; j<m;j++){
			media += A[i][j];
		}
	}
	media /= valori;
	return media;
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
            A[i][j] = (rand() % 10) + 1;
        }
    }
    cout<<"Matrice generata: "<<endl;
    for(int i=0; i<n;i++){
        for(int j=0;j<m;j++){
            cout<<A[i][j] <<"\t";
        }
        cout<<endl;
    }
    int scelta=-1;
    while(scelta!=0){
        cout<<"Selezionare l'opzione desiderata: " <<endl
        <<"- 0: Chiudi il programma" <<endl
        <<"- 1: Trasposta della matrice generata"<<endl
        <<"- 2: Somma per colonna"<<endl
        <<"- 3: Media della matrice"<<endl;
        cin>>scelta;
        switch(scelta){
            case 0:
                break;
            case 1:
                trasposta(n, m);
                break;
            case 2:
            	sommacol(n, m);
            	break;
            case 3:
            	cout<<"Il valore della media e': " <<media(n, m)<<endl;
            	break;
        }
    }
    return 0;
}