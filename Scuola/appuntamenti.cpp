#include <iostream>
#include <string>
using namespace std;
const int MAXC=6, MAXR=25;
string app[MAXR][MAXC];
void inserimento(),stampa_giorno(),stampa_cognome();

int main(){
	int scelta;
	//inserimento giorni nella riga 0
	app[0][0]="Lunedi";
	app[0][1]="Martedi";
	app[0][2]="Mercoledi";
	app[0][3]="Giovedi";
	app[0][4]="Venerdi";
	app[0][5]="Sabato";
	do{
		cout<<"\n--------------------------------"<<endl;
		cout<<"Opzione 1: Inserire appuntamento"<<endl;
		cout<<"Opzione 2: Stampa appuntamenti in base al giorno"<<endl;
		cout<<"Opzione 3: Stampa appuntamento in base al cognome"<<endl;
		cout<<"--------------------------------"<<endl;
		cout<<"Inserire valore per scegliere un opzione"<<endl;
		cout<<"Inserire 0 per uscire dal programma\n"<<endl;
		cin>>scelta;
		switch(scelta){
			case 0:
				cout<<"\nUscendo dal programma"<<endl;
			break;
			case 1:
				inserimento();
			break;
			case 2:
				stampa_giorno();
			break;
			case 3:
				stampa_cognome();
			break;
			default:
				cout<<"\nScelta inesistente riprovare"<<endl;
		}
	}
	while(scelta!=0);
	return 0;
}

void inserimento(){
	int o,g;
	cout<<"\n Inserire ora e giorno(da 1 a 6) dell'appuntamento"<<endl;
	cin>>o>>g;
	if(o<0 || o>MAXR || g<1 || g>MAXC)
		cout<<"scelta errata"<<endl;
	else{
		g--;o++;
		cout<<"Inserire Nome per il giorno:"<<app[0][g]<<" ora:"<<o-1<<endl;
		cin>>app[o][g];
	}
}

void stampa_giorno(){
	int g;
	cout<<"\nInserire giorno da stampare(da 1 a 6)"<<endl;
	cin>>g;
	if(g<1 || g>MAXC)
		cout<<"scelta errata"<<endl;
	else{
		g--;
		//stampa tutti i valori del giorno scelto
		for(int i=1;i<MAXR;i++){
			cout<<"Ora "<<i-1<<": "<<app[i][g]<<endl;
		}
	}
}

void stampa_cognome(){
	string cog;
	int ora,giorno;
	bool check=false;
	cout<<"\nInserire cognome da cercare"<<endl;
	cin>>cog;
	//controllo esistenza del cognome all'interno della matrice
	for(int i=1;i<MAXR;i++){
		for(int j=0;j<MAXC;j++){
			if(app[i][j]==cog)
				check=true;
		}
	}
	cout<<endl;
	//stampa dell'appuntamento se il cognome esiste nella matrice
	if(check==true){
		for(int i=1;i<MAXR;i++){
			for(int j=0;j<MAXC;j++){
				if(app[i][j]==cog)
					cout<<"Il paziente "<<cog<<" ha un appuntamento "<<app[0][j]<<" alle ore "<<i-1<<endl;
			}
		}
	}
	else
		cout<<"Il paziente "<<cog<<" non ha appuntamenti"<<endl;
}
