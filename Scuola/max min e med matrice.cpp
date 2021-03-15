#include <iostream>
using namespace std;

int main(){
    int n,m,i,j,posi=0,posj=0;
	cout<<"Inserire grandezza righe matrice"<<endl;
	cin>>n;
	cout<<"Inserire grandezza colonne matrice"<<endl;
	cin>>m;
	float A[n][m], medc;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			cout<<"Inserire valore riga "<<i+1<<" colonna "<<j+1<<endl;
			cin>>A[i][j];
		}
	}
	cout<<endl;
	//stampa tutti elementi
	for(i=0;i<n;i++){
    	for(j=0;j<m;j++){
            cout<<A[i][j]<<"   ";
        }
    	cout<<endl;
    }
	cout<<endl;
	//controllo valore massimo di ogni riga
	for(i=0;i<n;i++){
		posj=0;
		for(j=0;j<m;j++){
			if(A[i][j]>A[i][posj])
				posj=j;
		}
		cout<<"Valore massimo riga "<<i+1<<" = "<<A[i][posj]<<endl;
	}
	cout<<endl;
	//controllo valore minimo di tutti gli elementi della matrice
	posi=0;
	posj=0;
	for(i=0;i<n;i++){
		for(j=1;j<m;j++){
			if(A[i][j]<A[posi][posj]){
				posi=i;
				posj=j;
			}
		}
	}
	cout<<"Valore minimo della matrice = "<<A[posi][posj]<<" (riga "<<posi+1<<" ,colonna "<<posj+1<<")"<<endl;
	cout<<endl;
	//controllo media di ciascuna colonna
	for(i=0;i<m;i++){
		medc=0;
		for(j=0;j<n;j++){
			medc=medc+A[j][i];
		}
		medc=medc/n;
		cout<<"Media colonna "<<i+1<<" = "<<medc<<endl;
	}
	return 0;
}
