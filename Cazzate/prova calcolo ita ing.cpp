#include <iostream>
#include <stdlib.h>
using namespace std;
int pi=180,lng,mcd();
void radiante(),angolo();

int main() {
	int scelta;
    cout<<"write 0 to view the program in english"<<endl;
    cout<<"digita 1 per visualizzare il programma in italiano"<<endl;
    cout<<"digita 2 per uscire dal programma"<<endl;
    cout<<"type 2 to exit the program"<<endl;
    cin>>lng;
   	do{
		cout<<endl;
		if(lng==0){  //inglese
			cout<<"Insert number to choose an option"<<endl;
			cout<<"Option 1: Calculate Radiant having angle"<<endl;
			cout<<"Option 2: Calculate Angle degree having radiant"<<endl;
			cout<<"Insert 0 to exit the program"<<endl;
		}
		else{
			cout<<"Inserire numero per scegliere opzione"<<endl;
			cout<<"Opzione 1: Calcolo Radiante avendo angolo"<<endl;
			cout<<"Opzione 2: Calcola gradi Angolo avendo radiante"<<endl;
			cout<<"Inserire 0 per uscire dal programma"<<endl;
		}
		cin>>scelta;
		switch(scelta){
			case 1:
				if(lng==0)  //inglese
					lng=0;
				else  //italiano
					lng=1;
				radiante();
			break;
			case 2:
				if(lng==0)  //inglese
					lng=0;
				else  //italiano
					lng=1;
				angolo();
			break;
			default:
				if(scelta==0){
					if(lng==0)  //inglese
						cout<<"\n--- Exiting the program ---"<<endl;
					else //italiano
						cout<<"\n--- Uscendo dal programma ---"<<endl;
				}
				else{
					if(lng==0)  //inglese
						cout<<"Choice non-existent"<<endl;
					else
						cout<<"Scelta insesistente"<<endl;
				}
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
	if(lng==0){
		cout<<"\n Calculate Radiant having angle"<<endl;
		cout<<"\nInsert angle value: ";
	}
	else{
		cout<<"\n Calcolo radiante avendo l'angolo"<<endl;
		cout<<"\nInserire valore angolo: ";
	}
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
	if(lng==0){
		cout<<"The MCD between the two numbers is "<<x<<endl;
		if(check==false)
			cout<<"The radiant between "<<n1<<" and "<<n2<<" is "<<a<<"/"<<b<<endl;
		else
			cout<<"The radiant between "<<n1<<" and "<<n2<<" is -"<<a<<"/"<<b<<endl;
	}
	else{
		cout<<"L'MCD fra i due numeri e' "<<x<<endl;
		if(check==false)
			cout<<"Il radiante tra "<<n1<<" e "<<n2<<" e' "<<a<<"/"<<b<<endl;
		else
			cout<<"Il radiante tra "<<n1<<" e "<<n2<<" e' -"<<a<<"/"<<b<<endl;
	}
}

void angolo(){
	int n1,n2,a,b,r;
	float x;
	bool check;
	if(lng==0) //inglese
		cout<<"\n Calculate Angle degree having radiant"<<endl;
	else  //italiano
		cout<<"\n Calcolo angolo avendo radiante"<<endl;
	do{
		if(lng==0) //inglese
			cout<<"\nChoose if the radiant has 1 or 2 value"<<endl;
		else  //italiano
			cout<<"\nScegliere se il radiante ha 1 o 2 valori"<<endl;
		cin>>n1;
		if(n1!=1 && n1!=2)
			if(lng==0) //inglese
				cout<<"The choosen value is wrong"<<endl;
			else  //italiano
				cout<<"Il valore inserito e' errato"<<endl; 
		}
	while(n1!=1 && n1!=2);
	if(n1==1){
		if(lng==0) //inglese
			cout<<"Insert value"<<endl;
		else  //italiano
			cout<<"Inserire valore"<<endl;
		cin>>n1;
		n2=1;
		check=true;
	}
	else if(n1==2){
		if(lng==0) //inglese
			cout<<"Insert the two value"<<endl;
		else  //italiano
			cout<<"Inserire i due valori"<<endl;
		cin>>n1;
		cin>>n2;
	}
	a=n1*pi;
	b=n2;
	r=a%b;
	if(check==true){
		if(lng==0) //inglese
			cout<<"The radiant's angle "<<n1<<" is "<<a<<"\370"<<endl;
		else  //italiano
			cout<<"L'angolo della radiante "<<n1<<" e' "<<a<<"\370"<<endl;
	}
	else{
		if(r==0){
			a=a/b;
			if(lng==0)  //inglese
				cout<<"The radiant's angle "<<n1<<"/"<<n2<<" is "<<a<<"\370"<<endl;
			else  //italiano
				cout<<"L'angolo della radiante "<<n1<<"/"<<n2<<" e' "<<a<<"\370"<<endl;
		}
		else{
			x=mcd(a,b);
			a=a/x;
			b=b/x;n
			if(lng==0)  //inglese
				cout<<"The MCD of the radiant is "<<x<<endl;
			else  //italiano
				cout<<"L'MCD per la radiante è "<<x<<endl;
			x=a/b;
			if(lng==0)  //inglese
				cout<<"The radiant's angle "<<n1<<"/"<<n2<<" is "<<a<<"/"<<b<<" or "<<x<<"\370"<<endl;
			else  //italiano
				cout<<"L'angolo della radiante "<<n1<<"/"<<n2<<" e' "<<a<<"/"<<b<<" oppure "<<x<<"\370"<<endl;
		}
	}
}
