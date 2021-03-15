#include <iostream>
using namespace std;

float T[3][7];
void mediagiorno(int j);
int main(){
	int i,j,giorno,n;
	float meds=0;
	for(j=0;j<7;j++){
		for(i=0;i<3;i++){
			cout<<"Inserire temperatura "<<i+1<<" giorno "<<j+1<<endl;
			cin>>n;
			T[i][j]=n;
		}
	}
	for(j=0;j<7;j++){
		for(i=0;i<3;i++){
			meds=meds+T[i][j];
		}
	}
	meds=meds/(7*3);
	cout<<" Media settimanale: "<<meds<<endl;
	do{
		cout<<endl;
		cout<<"Inserire numero giorno da visualizzare:"<<endl;
		cout<<"Inserire 0 per uscire dal menu"<<endl;
		cin>>giorno;
		switch(giorno){
			case 1:
				j=0;
				mediagiorno(j);
			break;
			case 2:
				j=1;
				mediagiorno(j);
			break;
			case 3:
				j=2;
				mediagiorno(j);
			break;
			case 4:
				j=3;
				mediagiorno(j);
			break;
			case 5:
				j=4;
				mediagiorno(j);
			break;
			case 6:
				j=5;
				mediagiorno(j);
			break;
			case 7:
				j=6;
				mediagiorno(j);
			break;
			default:
				if(giorno==0)
					cout<<"Uscendo dal programma"<<endl;
				else
				cout<<"Giorno inesistente"<<endl;
		}
	}
	while(giorno!=0);
}

void mediagiorno(int j){
	int i;
	float medg=0;
	for(i=0;i<3;i++){
		medg=medg+T[i][j];
	}
	medg=medg/3;
	cout<<"Media giorno "<<j+1<<" = "<<medg<<endl;
} 
