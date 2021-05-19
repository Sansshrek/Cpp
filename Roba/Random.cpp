#include <iostream>
#include <time.h>
using namespace std;

int main(){
    int scelta, n1, n2;
    do{
        cout<<"\nStampa random(1) o inverso(2) o esci(0)"<<endl;
        cin>>scelta;
        if(scelta==1){
            cout<<"\nInserire numero random"<<endl;
            cin>>n1;
            cout<<"\nInserire numero da sommare"<<endl;
            cin>>n2;
            cout<<"\nrand()%"<<n1<<"+"<<n2<<endl;
            cout<<"\nminimo risultato= "<<0+n2<<endl;
            cout<<"massimo risultato= "<<(n1-1)+n2<<endl;
        }
        else if(scelta==2){
            cout<<"\nInserire minimo risultato"<<endl;
            cin>>n1;
            cout<<"\nInserire massimo risultato"<<endl;
            cin>>n2;
            cout<<"\nrand()%"<<(n2+1)-n1<<"+ "<<n1<<endl;
        }
        else break;
    }
    while(scelta!=1 or scelta!=2);
}