#include <iostream>
#include <string>
using namespace std;

float T[3][7];
string g[7]={"lunedi","martedi","mercoledi","giovedi","venerdi","sabato","domenica"};
void mediagiorno(int j);
int main(){
	int i,j,giorno,n,m=0;
	float meds=0,medg=0;
	for(j=0;j<7;j++){
		for(i=0;i<3;i++){
			cout<<"Inserire temperatura "<<i+1<<" giorno "<<g[j]<<endl;
			cin>>T[i][j];
			meds=meds+T[i][j];
		}
	}
	for(j=0;j<7;j++){
		for(i=0;i<3;i++){
			medg=medg+T[i][j];
		}
		medg=medg/3;
		cout<<"Media temperatura giorno "<<g[j]<<" = "<<medg<<endl;
	}
	meds=meds/21;
	cout<<"Media temperatura settimana: "<<meds<<endl;
	do{
		cout<<"\nInserire numero da controllare"<<endl;
		cout<<"inserire 0 per uscire"<<endl;
		cin>>n;
		if(n!=0){
			for(j=0;j<7;j++){
				m=0;
				for(i=0;i<3;i++){
					m++;
					if(T[i][j]>n){
						cout<<"La temperatura "<<T[i][j]<<" n."<<m<<" del giorno "<<g[j]<<" e' piu grande di "<<n<<endl;
					}
				}
			}
		}
	}
	while(n!=0);
}
