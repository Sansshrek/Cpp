#include <iostream>
#include <string.h>
#include <time.h>
#include <cstdlib>
using namespace std;

int main(){
    int sceltaReset;
    string mossa;
    do{
        cout<<"\nFormato gioco:"<<endl;
        cout<<"  A B C D E F G H I J"<<endl;
        cout<<"  ___________________"<<endl;
        for(int i=0;i<10;i++){
            cout<<i<<"| | | | | | | | | | |"<<endl;
        }
        cout<<"  -------------------"<<endl;
        do{
            bool checkInput=false;
            cout<<"\nInserire posizione da attaccare"<<endl;
            cin>>mossa;
            if(mossa.length()==2){
                string 
            }
        }
        while(!checkInput);
        do{
            cout<<"\nVuoi rigiocare? si(1) no(0)"<<endl;
            cin>>sceltaReset;
            if(sceltaReset!=1 && sceltaReset!=0)
                cout<<"\nScelta inesistente"<<endl;
        }
        while(sceltaReset!=1 && sceltaReset!=0);
    }
    while(sceltaReset!=0);
}