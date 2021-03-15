#include <iostream>
#include <string>
#include <time.h>
using namespace std;

class giorno{
    int ng, tmin, tmax;
    public:
        void random(int dt){
            int nmin, nmax, segno;
            nmin=rand()%10;
            nmax=rand()%15+5;
            segno=rand()%3;
            if(segno==0)
                tmin=nmin;
            else
                tmin=-nmin;
        }
        void inserisci(int dt){
            ng=dt;
            cout<<"\nInserire la temperatura minima del giorno "<<ng<<endl;
            cin>>tmin;
            cout<<"Inserire la temperatura massima del giorno "<<ng<<endl;
            cin>>tmax;
        }
        int differenza(){
            return(tmax-tmin);
        }
        void stampa(int dt){
            if(tmin>dt)
                cout<<ng<<endl;
        }
        float mediag(){
            return((tmax-tmin)/2);
        }
        int getmin(){
            return(tmin);
        }
        int getng(){
            return(ng);
        }
};

const int NG=31;
int main(){
    int i,sc,min,p;
    float m;
    giorno dic[NG];
    do{
        cout<<"\nInserire opzione"<<endl
        <<"Opzione 1: Stampa dell'escursione termica giornaliera"<<endl
        <<"Opzione 2: Stampa del giorno piu freddo"<<endl
        <<"Opzione 3: Stampa dei giorni in cui la temperatura e' rimasta sopra lo zero"<<endl
        <<"Opzione 4: Stampa media delle temperature medie giornaliere"<<endl
        <<"Opzione 5: Inserimento random"<<endl
        <<"Opzione 6: Inserimento manuale"<<endl
        <<"Opzione 0: Esci dal programma"<<endl;
        cin>>sc;
        switch(sc){
            case 0:
                cout<<"\n---Uscendo dal programma---"<<endl;
            break;
            case 1:
                cout<<endl;
                for(i=0;i<NG;i++){
                    cout<<"escursione termica giorno "<<dic[i].getng()<<" e': "<<dic[i].differenza()<<endl;
                }
            break;
            case 2:
                min = dic[0].getng();
                p=0;
                for(i=1;i<NG;i++){
                    if(dic[i].getmin()<min){
                        min=dic[i].getmin();
                        p=i;
                    }
                }
                cout<<"\nIl giorno piu freddo e' statp il "<<dic[p].getng()<<" con "<<min<<" gradi"<<endl;
            break;
            case 3:
                cout<<"\nGiorni in cui la temperatura e' rimasta sopra lo zero"<<endl;
                for(i=0;i<NG;i++)
                    dic[i].stampa(0);
            break;
            case 4:
                m=0;
                for(i=0;i<NG;i++){
                    m=m+dic[i].mediag();
                }
                m=m/NG;
                cout<<"\nLa temperatura media del mese e' "<<m<<endl;
            break;
            case 5:
                srand(time(0));
                for(i=0;i<NG;i++)
                    dic[i].random(i+1);
            break;
            case 6:
                for(i=0;i<NG;i++)
                    dic[i].inserisci(i+1);
            break;
            default:
                cout<<"\nOpzione inesistente"<<endl;
        }
    }
    while(sc!=0);
}