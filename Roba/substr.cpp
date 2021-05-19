#include <iostream>
#include <string.h>
using namespace std;

int main(){
    int scelta;
    do{
        string text;
        cout<<"\nInserire testo"<<endl;
        cin>>text;
        int n1, n2;
        cout<<"\nInserire posizione 1:"<<endl;
        cin>>n1;
        cout<<"\nInserire posizione 2 (inserire -1 per non metterla)"<<endl;
        cin>>n2;
        if(n2==-1){
            cout<<"\n"<<text<<".substr("<<n1<<")"<<endl;
            cout<<"\n-- "<<text.substr(n1)<<" --"<<endl;
        }else{
            cout<<"\n"<<text<<".substr("<<n1<<", "<<n2<<")"<<endl;
            cout<<"\n-- "<<text.substr(n1, n2)<<" --"<<endl;
        }
        cout<<"\nInserire 0 per uscire, o altro per continuare"<<endl;
        cin>>scelta;
    }while(scelta!=0);
}