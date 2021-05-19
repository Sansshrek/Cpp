#include <iostream>
#include <math.h>
#include <string.h>
#include <time.h>
using namespace std;
int main(){
    srand(time(0));
    string tipi[3]={"sasso","carta","forbice"};
    string mossa;
    float tot=0,vit=0,perd=0,pari=0;
    int mossanum,bot;
    while(mossa!="0"){
        bot = rand()%3;
        do{
            cout<<"\nInserire sasso,carta o forbici (s,c,f)"<<endl;
            cin>>mossa;
            if(mossa!="s" && mossa!="sasso" && mossa!="c" && mossa!="carta" && mossa!="f" && mossa!="forbice")
                cout<<"\nInserire scelta corretta"<<endl;
        }while(mossa!="s" && mossa!="sasso" && mossa!="c" && mossa!="carta" && mossa!="f" && mossa!="forbice");
        if(mossa=="0")
            break;
        else if(mossa=="s" || mossa=="sasso")
            mossanum=0;
        else if(mossa=="c" || mossa=="carta")
            mossanum=1;
        else if(mossa=="f" || mossa=="forbice")
            mossanum=2;
        if(mossanum!=0 && mossanum!=1 && mossanum!=2)
            cout<<"Non conta un cazzo"<<endl;
        else if(mossanum==bot){
            cout<<"\nPari"<<endl;
            pari++;
            tot++;
        }
        else if(mossanum==0 && bot==2 || mossanum==1 && bot==0 || mossanum==2 && bot==1){
            cout<<"\nHai vinto"<<endl;
            cout<<"Il bot ha scelto "<<tipi[bot]<<endl;
            vit++;
            tot++;
        }
        else{
            cout<<"\nHai perso"<<endl;
            cout<<"Il bot ha scelto "<<tipi[bot]<<endl;
            perd++;
            tot++;
        }
    }
    cout<<"Totale partite giocate = "<<tot<<" Totale vittorie = "<<vit<<" Totale perdite = "<<perd<<" Totale parita = "<<pari<<endl;
    tot=(vit*100)/tot;
    cout<<"Hai vinto il "<<tot<<"% delle volte"<<endl;
}