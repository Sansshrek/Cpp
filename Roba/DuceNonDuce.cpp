#include<iostream>
#include <string.h>
#include <time.h>
#include <cstdlib>
using namespace std;

/*
int main(){
    string Persone[]={"Mussolini", "Perri", "Giulio", "Borto", "Gino", "Benito"};
    string scelta;
    cout<<"\nBenvenuti al famosissimo gioco Duce non Duce"<<endl;
    int n;
    srand(time(0));
    while(scelta!="0"){
        n = rand()%6;
        cout<<Persone[n];
        cout<<"\nDuce o non Duce?"<<endl;
        getline(cin, scelta);
        if(Persone[n]=="Mussolini"){
            if(scelta=="Duce" or scelta=="duce")
                cout<<"\nOk"<<endl;
            else if(scelta=="Non Duce" or scelta=="non duce" or scelta=="non Duce"){
                cout<<"\nHai sbagliato"<<endl;
                break;
            }
            else
                cout<<"\nScelta inesistente"<<endl;
        }
        else{
            if(scelta=="Duce" or scelta=="duce"){
                cout<<"\nHai sbagliato"<<endl;
                break;
            }
            else if(scelta=="Non Duce" or scelta=="non duce" or scelta=="non Duce")
                cout<<"\nOk"<<endl;
            else
                cout<<"\nScelta inesistente"<<endl;
        }
    }
}
*/
string utente;

void Tombola(){
        cout<<"\n             Hai scelto di giocare a Tombola";   
} 
void TestaCroce(){
	string scelta;
        cout<<"\n             Hai scelto di lanciare una moneta\n";

    do{
        cout<<"\n                  Scegli testa o croce? ";
        cin>>scelta;
        if(scelta!="testa" and scelta!="croce")
        cout<<"\n                        Riprova\n";
    }
    while(scelta!="testa" and scelta!="croce");
    int scelta2;
    if (scelta=="testa")
        scelta2=0;
    else
    	scelta2=1;
    int lancio=rand()%2;
    
	if(lancio==0)
        cout<<"\n                    E' uscito testa\n";
    else
        cout<<"\n                    E' uscito croce\n";
    if(lancio==scelta2)
        cout<<"\n                 Complimenti hai vinto\n";
    else
        cout<<"\n          Mi spiace, ma Tognoli è troppo forte\n";
  		    
}    
void CartaForbiceSasso(){
	int mossa,n;
	
	cout<<"\n\n       Hai iniziato a giocare a Carta Forbice Sasso";
	cout<<"\n\n                      [1] Carta";
	cout<<"\n                      [2] Forbice";
	cout<<"\n                      [3] Sasso";
	cout<<"\n\n                Scegli che mossa vuoi fare \n         per battere Tognoli digitando un numero ";
	
	do{
	cout<<"\n\n                   "<<utente<<" sceglie ";
	cin>>mossa;          
	if(mossa!=1 and mossa!=2 and mossa!=3)	
	cout<<"\n\n       Inserire un numero tra quelli selezionati";
	}	
	while(mossa!=1 and mossa!=2 and mossa!=3);

	n=rand()%3+1;
	cout<<"\n                   Tognoli ha scelto "<<n<<"  \n";

	if (n==mossa){
	cout<<"\n\n                       Pareggio ";
	}
    else
        
    if (n==2 and mossa==1 or n==3 and mossa==2 or n==1 and mossa==3)
    {
	cout<<"\n          Mi spiace, ma Tognoli è troppo forte";
	}
	else
	    
	if (mossa==2 and n==1 or mossa==3 and n==2 or mossa==1 and n==3)
    {
	cout<<"\n                   "<<utente<<" ha vinto ";
	}
	
       	
}
void Dadi(){
	int x,lancio1,lancio2,lancio3,lancio4,somma1,somma2;;
	
	cout<<"\n\n              Hai iniziato a giocare a Dadi\n\n";
    cout<<"\n      Lancio dei dadi in corso da parte di "<<utente<<"";
    lancio1=rand()%6+1;
    lancio2=rand()%6+1;
    somma1=lancio1+lancio2;
    cout<<"\n                      E' uscito "<<somma1<<"\n";
    cout<<"\n       Lancio dei dadi in corso da parte di Tognoli";
    lancio3=rand()%6+1;
    lancio4=rand()%6+1;
    somma2=lancio3+lancio4;
    cout<<"\n                      E' uscito "<<somma2<<"\n";
    
    if(somma1>somma2)
        cout<<"\n                 Complimenti hai vinto!";
    else 
	
	if(somma1==somma2)
        cout<<"\n                    E' un pareggio\n";
    else
        cout<<"\n                  Mi spiace, hai perso\n";
		
}
void DND(){	
	string Persone[]={"Mussolini", "Benito", "Hitler", "Stalin", "Iervese"};
    string risposta = "prova";
	cout<<"\n                 DVCE O NON DVCE";
	
    int n;
    while(risposta!="0"){
        n = rand()%5;
        cout<<"\n\n\t\t      ";
		cout<<Persone[n];
        cout<<"\nDuce o non Duce?"<<endl;
        cin>>risposta;
        if(Persone[n]=="Mussolini" or Persone[n]=="Benito"){
            if(risposta=="Si" or risposta=="si" or risposta=="s")
                cout<<"\nOk\n";
            else 
			if(risposta=="No" or risposta=="no" or risposta=="n"){
                cout<<"\nNon va bene, devi studiare la storia!";
                break;
            }
            else
                cout<<"\nScelta inesistente\n";
        }
        else{
            if(risposta=="Si" or risposta=="si" or risposta=="s"){
                cout<<"\nNon va bene, devi studiare la storia!";
                break;
            }
            else 
			if(risposta=="No" or risposta=="no" or risposta=="n")
                cout<<"\nOk\n";
            else
                cout<<"\nScelta inesistente\n";
        }
    }
}
/*
void DND(){	
	string Persone[]={"Mussolini", "Benito", "Hitler", "Stalin", "Iervese"};
    string risposta = "prova";
	cout<<"\n                 DVCE O NON DVCE";
	
    int n;
    while(risposta!="0"){
        n = rand()%5;
        cout<<"\n\n\t\t      ";
		cout<<Persone[n];
        cout<<"\nDuce o non Duce?"<<endl;
        getline(cin, risposta);
        if(Persone[n]=="Mussolini" or Persone[n]=="Benito"){
            if(risposta=="Duce" or risposta=="duce")
                cout<<"\nOk\n";
            else 
			if(risposta=="Non Duce" or risposta=="non duce" or risposta=="non Duce"){
                cout<<"Non va bene, devi studiare la storia!";
                break;
            }
            else
                cout<<"\nScelta inesistente\n";
        }
        else{
            if(risposta=="Duce" or risposta=="duce"){
                cout<<"Non va bene, devi studiare la storia!";
                break;
            }
            else 
			if(risposta=="Non Duce" or risposta=="non duce" or risposta=="non Duce")
                cout<<"\nOk\n";
            else
                cout<<"\nScelta inesistente\n";
        }
    }
	if (risposta=="si"){
		cout<<"Complimenti, hai riconosciuto il dvce!";
	}
	else
	if (risposta=="no"){
		cout<<"Non va bene, devi studiare la storia!";
	}
} */

    int main(){
	setlocale(LC_ALL, "italian");
    int scelta=1,n,i,carta,sasso,forbice,mossa,c,x,r;
    srand(time(NULL));
    
	cout<<"                  Multigioco/Tognoli Bot\n          (un gioco ideato da Valentino Tognoli)\n\n";
    
    cout<<"             Inserisci il tuo nome utente: ";
    cin>>utente;
    cout<<"\n";
    
	while(scelta!=0){

	cout<<"                   [1] Tombola";
	cout<<"\n                   [2] Testa o Croce";
	cout<<"\n                   [3] Carta Forbice Sasso";
	cout<<"\n                   [4] Dadi";
	cout<<"\n\n     Scegli un gioco digitando il numero corrispondente";
	cout<<"\n            (Se vuoi uscire dal gioco digita 0)";
	cout<<"\n\n                     "<<utente<<" sceglie ";
    cin>>scelta;
    
    if (scelta==0 or scelta==1 or scelta==2 or scelta==3 or scelta==4 or scelta==5){
    
    switch (scelta) {
    	
    	case (0):
    		cout<<"\n\nUscita dal programma...\n\n";
    	break;	
        case (1):
        	Tombola();
        break;
        case (2):
            TestaCroce();
		break;  
        case (3):
        	CartaForbiceSasso();
		break;
        case (4):
            Dadi();
		break;
	    case (5):
            DND();
		break;
    
    	}
    	cout<<"\n";
	}
		else
		cout<<"\n                        [ERRORE]\n    Inserire un numero riportato nella tabella adiacente";
		
		cout<<"\n\n";
 	
}
}