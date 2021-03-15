#include <iostream>
using namespace std;
float A[100][100];
int n,m;

void inserimento(),stampa(),maxriga(),minimo(),medcol();
int main(){
    int scelta;
    bool check;
    do{
    	cout<<endl;
    	cout<<"Inserire valore per scegliere opzione"<<endl;
    	cout<<"Opzione 1: inserimento"<<endl;
    	cout<<"Opzione 2: stampa"<<endl;
    	cout<<"Opzione 3: Controllo massimo di ogni riga"<<endl;
    	cout<<"Opzione 4: Controllo minimo della matrice"<<endl;
    	cout<<"Opzione 5: Controllo media di ogni colonna"<<endl;
    	cout<<"Opzione 0 per uscire dal programma"<<endl;
    	cin>>scelta;
    	switch(scelta){
    		case 0:
    			cout<<"\n--- Uscendo dal programma--- "<<endl;
    		break;
    		case 1:
    			check=true;
    		    inserimento();
    		break;
    		case 2:
    			if(check==false)
    				cout<<"\nScegliere prima opzione 1 per inserire valori nella matrice\n"<<endl;
    			else
    				stampa();
    		break;
    		case 3:
    			if(check==false)
    				cout<<"\nScegliere prima pzione 1 per inserire valori nella matrice\n"<<endl;
    			else
    				maxriga();
    		break;
    		case 4:
    			if(check==false)
    				cout<<"\nScegliere prima opzione 1 per inserire valori nella matrice\n"<<endl;
    			else
    				minimo();
    		break;
    		case 5:
    			if(check==false)
    				cout<<"\nScegliere prima opzione 1 per inserire valori nella matrice\n"<<endl;
    			else
    				medcol();
    		break;
    		default:
    			if(scelta!=0)
    				cout<<"\nScelta inesistente... riprova\n"<<endl;
		}
	}
	while(scelta !=0);
}

void inserimento(){
	cout<<endl;
	cout<<"Inserire grandezza righe matrice"<<endl;
	cin>>n;
	cout<<"Inserire grandezza colonne matrice"<<endl;
	cin>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<"Inserire valore riga "<<i+1<<" colonna "<<j+1<<endl;
			cin>>A[i][j];
		}
	}
}

void stampa(){
	cout<<endl;
	for(int i=0;i<n;i++){
    	for(int j=0;j<m;j++){
            cout<<A[i][j]<<"   ";
        }
    	cout<<endl;
    }
	cout<<endl;
}

void maxriga(){
	cout<<endl;
	for(int i=0;i<n;i++){
		int posj=0;
		for(int j=0;j<m;j++){
			if(A[i][j]>A[i][posj])
				posj=j;
		}
		cout<<"Valore massimo riga "<<i+1<<" = "<<A[i][posj]<<endl;
	}
}

void minimo(){
	cout<<endl;
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
	cout<<"Valore minimo della matrice = "<<A[posi][posj]<<" (riga "<<posi+1<<" ,colonna "<<posj+1<<")"<<endl;
}

void medcol(){
	cout<<endl;
	for(int i=0;i<m;i++){
		float medc=0;
		for(int j=0;j<n;j++){
			medc=medc+A[j][i];
		}
		medc=medc/n;
		cout<<"Media colonna "<<i+1<<" = "<<medc<<endl;
	}
}

