#include <iostream>
#include <stdlib.h>
using namespace std;

int pi=180;
void radiante(),angolo();
int mcd();
main() {
	int scelta;
	do{
		cout<<endl;
		cout<<"Inserire numero per scegliere opzione"<<endl;
		cout<<"Opzione 1: Calcolo Radiante avendo angolo"<<endl;
		cout<<"Opzione 2: Calcola gradi Angolo avendo radiante"<<endl;
		cout<<"Inserire 0 per uscire dal programma"<<endl;
		cin>>scelta;
		switch(scelta){
			case 1:
				radiante();
			break;
			case 2:
				angolo();
			break;
			default:
				if(scelta==0)
					cout<<"\n--- Uscendo dal programma ---"<<endl;
				else
					cout<<"Scelta inesistente"<<endl;
		}
	}
	while(scelta!=0);
}

int mcd(int x, int y){
	while (y > 0) {
    	int r = x % y;
    	x = y;
    	y = r;
	}
	return x;
}

void radiante(){
	int a,b=pi,x,y=pi,n1,n2=pi,val;
	bool check;
	cout<<"\n Calcolo radiante avendo l'angolo"<<endl;
	cout<<"\nInserire valore angolo: ";
	cin>>a;
	if(a<0){
		a=abs(a);
		check=true;
	}
	n1=a;
	x=a;
	x=mcd(x,y);
	a=a/x;
	b=b/x;
	cout<<"L'MCD fra i due numeri e' "<<x<<endl;
	if(check==false)
		cout<<"Il radiante tra "<<n1<<" e "<<n2<<" e' "<<a<<"/"<<b<<endl;
	else
		cout<<"Il radiante tra "<<n1<<" e "<<n2<<" e' -"<<a<<"/"<<b<<endl;
}

void angolo(){
	int n1,n2,a,b,r;
	float x;
	bool check;
	cout<<"\n Calcolo angolo avendo radiante"<<endl;
	do{
	cout<<"\nScegliere se il radiante ha 1 o 2 valori"<<endl;
	cin>>n1;
	if(n1!=1 && n1!=2)
		cout<<"Il valore inserito e' errato"<<endl; 
	}
	while(n1!=1 && n1!=2);
	if(n1==1){
		cout<<"Inserire valore"<<endl;
		cin>>n1;
		n2=1;
		check=true;
	}
	else if(n1==2){
		cout<<"Inserire i due valori"<<endl;
		cin>>n1;
		cin>>n2;
	}
	a=n1*pi;
	b=n2;
	r=a%b;
	if(check==true){
		cout<<"L'angolo della radiante "<<n1<<" e' "<<a<<"\370"<<endl;
	}
	else{
		if(r==0){
			a=a/b;
			cout<<"L'angolo della radiante "<<n1<<"/"<<n2<<" e' "<<a<<"\370"<<endl;
		}
		else{
			x=mcd(a,b);
			a=a/x;
			b=b/x;
			cout<<"L'MCD per la radiante è "<<x<<endl;
			x=a/b;
			cout<<"L'angolo della radiante "<<n1<<"/"<<n2<<" e' "<<a<<"/"<<b<<" oppure "<<x<<"\370"<<endl;
		}
	}
}
