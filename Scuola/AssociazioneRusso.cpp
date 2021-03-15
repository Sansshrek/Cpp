/*Sia data una tabella contenente i dati relativi agli iscritti ad un�associazione. 
Per ogni iscritto il record ha 4 campi: cognome, data_acconto, acconto, data_saldo. 
Considerare le date come delle variabili string di 6 caratteri (ad esempio 120320 risulta il 12 marzo del 2020). 
Considerare il saldo pari a 200euro, mentre l�acconto � inferiore a 200.Usando un menu:
a)aggiornare la tabella quando viene effettuato un pagamento
b)stampi l�elenco degli iscritti che devono pagare ancora il saldo, con il relativo acconto*/

#include <iostream>
using namespace std;
int n;
struct iscritto
{
	string cognome;
	string data_acconto;
	float saldo;
	string data_saldo;
};
iscritto Assoc[1000];

void Pagamento()
{
	float soldi;
	string cognome1;
	cou<<"Dammi il nome"<<endl;
	cin>>cognome1;
	cout<<"Quanto paghi"<<endl;
	cin>>soldi;
	cout<<"Dammi data"<<endl;
	cin>>data;
	if(soldi==200)
		for(i=0;i<n;i++)
		{
			if(Assoc[i].cognome==cognome1)
				Assoc[i].saldo=200;
				Assoc[i].data_saldo=data;
		}
	else
		for(i=0;i<n;i++)
		{
			if(Assoc[i].cognome==cognome1)
				Assoc[i].saldo=soldi;
				Assoc[i].data_acconto=data;
		}
}
void Elenco_Morosi()
{
	
	for(int i=0;i<n;i++)
	{
		if(Assoc[i].data_saldo==" ")
			cout<<"Cognome moroso"<<Assoc[i].cognome<<endl;
	}
}
void Nuovo_Iscritto()
{
	cout<<"Dammi il cognome"<<endl;
	cin>>cognome1;
	Assoc[n].cognome=cognome1;
	Assoc[n].data_acconto=" "; 
	Assoc[n].saldo=0; 
	Assoc[n].data_saldo=" ";
	n++;
}

void Cancella_Iscritto()
{
	cout<<"Dammi il cognome"<<endl;
	cin>>cognome1;
	
	for(int i=0;i<n;i++)
	{
		if(Assoc[i].cognome==cognome1)
			for(int j=i;)
				Assoc[j].cognome==Assoc[j+1].cognome;
				Assoc[j].data_acconto=Assoc[j+1].data_acconto; 
				Assoc[j].saldo=Assoc[j+1].saldo; 
				Assoc[j].data_saldo=Assoc[j+1].data_saldo;
	}
}


int main()
{
	cout<<"Dammi Numero iscritti"<<endl;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"dammi i dati dell'iscritto in posizione "<<i<<endl;
		cin>>Assoc[i].cognome;
		Assoc[i].data_acconto=" "; 
		Assoc[i].saldo=0; 
		Assoc[i].data_saldo=" ";	
	}
	
	
}