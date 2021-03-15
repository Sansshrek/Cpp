//definire struct studente con cognome e età, leggere in input tre studenti con eta diverse tra loro e stampare il 
//cognome dello studente che non è ne il piu piccolo ne il piu grande
#include <iostream>
#include <string>
#include <cstdlib>
#include <stdlib.h>
using namespace std;

struct studente{
    int eta;
    string cognome;
};

int main(){
    studente stud1, stud2, stud3, medio;
    bool check=false;
    int metodo;
    string scelta;
    do{
        if(check==true){
            cout<<"\nVuoi usare i valori di prima?(si o no)"<<endl;
            cin>>scelta;
        }
        if(scelta=="no" || check==false){
            cout<<"\nInserire cognome e eta primo studente"<<endl;
            cin>>stud1.cognome;
            cin>>stud1.eta;
            cout<<"Inserire cognome e eta secondo studente"<<endl;
            cin>>stud2.cognome;
            cin>>stud2.eta;
            cout<<"Inserire cognome e eta terzo studente"<<endl;
            cin>>stud3.cognome;
            cin>>stud3.eta;
        }
        check=true;
        cout<<"\nScegli metodo"<<endl;
        cout<<"Inserire 0 per uscire"<<endl;
        cin>>metodo;
        switch(metodo){
            //metodo 1
            case 1:{
                if(stud1.eta>stud2.eta && stud1.eta<stud3.eta){
                    medio.eta=stud1.eta;
                    medio.cognome=stud1.cognome;
                }
                else if(stud1.eta>stud3.eta && stud1.eta<stud2.eta){
                    medio.eta=stud1.eta;
                    medio.cognome=stud1.cognome;
                }
                else if(stud2.eta>stud1.eta && stud2.eta<stud3.eta){
                    medio.eta=stud2.eta;
                    medio.cognome=stud2.cognome;
                }
                else if(stud2.eta>stud3.eta && stud2.eta<stud1.eta){
                    medio.eta=stud2.eta;
                    medio.cognome=stud2.cognome;
                }
                else if(stud3.eta>stud1.eta && stud3.eta<stud3.eta){
                    medio.eta=stud3.eta;
                    medio.cognome=stud3.cognome;
                }
                else if(stud3.eta>stud3.eta && stud3.eta<stud1.eta){
                    medio.eta=stud3.eta;
                    medio.cognome=stud3.cognome;
                }
            }
            break;
            //metodo 2 uguale a 1 ma piu corto
            case 2:{
                if(stud1.eta>stud2.eta && stud1.eta<stud3.eta || stud1.eta>stud3.eta && stud1.eta<stud2.eta){
                    medio.eta=stud1.eta;
                    medio.cognome=stud1.cognome;
                }
                else if(stud2.eta>stud1.eta && stud2.eta<stud3.eta || stud2.eta>stud3.eta && stud2.eta<stud1.eta){
                    medio.eta=stud2.eta;
                    medio.cognome=stud2.cognome;
                }
                else if(stud3.eta>stud1.eta && stud3.eta<stud3.eta || stud3.eta>stud1.eta && stud3.eta<stud3.eta){
                    medio.eta=stud3.eta;
                    medio.cognome=stud3.cognome;
                }
            }
            break;
            //metodo 3
            case 3:{
                if(stud1.eta>stud2.eta && stud1.eta<stud3.eta){   //BAC
                    medio.eta=stud1.eta;
                    medio.cognome=stud1.cognome;
                }
                else if(stud1.eta>stud3.eta && stud1.eta<stud2.eta){  //CAB
                    medio.eta=stud1.eta;
                    medio.cognome=stud1.cognome;
                }
                else if(stud1.eta<stud2.eta && stud1.eta<stud3.eta){   //Axx
                    if(stud2.eta>stud3.eta){  //ACB
                        medio.eta=stud3.eta;
                        medio.cognome=stud3.cognome;
                    }
                    else{    //ABC
                        medio.eta=stud2.eta;
                        medio.cognome=stud2.cognome;
                    }
                }
                else if(stud1.eta>stud2.eta && stud1.eta>stud3.eta){   //xxA
                    if(stud2.eta>stud3.eta){  //BCA
                        medio.eta=stud3.eta;
                        medio.cognome=stud3.cognome;
                    }
                    else{    //CBA
                        medio.eta=stud2.eta;
                        medio.cognome=stud2.cognome;
                    }
                }
            }
            break;
            //metodo 4
            case 4:{
                float med=stud1.eta+stud2.eta+stud3.eta;  //es. 4 2 9 = 15
                med/=3;  //med=5
                float n1,n2,n3;
                n1=med-stud1.eta;  //5-4=1
                n2=med-stud2.eta;  //5-2=3
                n3=med-stud3.eta;  //5-9=-4
                n1=abs(n1);  //toglie il meno se c'è
                n2=abs(n2);
                n3=abs(n3);
                //controlla la distanza di numeri fra n e med e il minore e lo studente medio
                if(n1<n2 && n1<n3){  
                    medio.eta=stud1.eta;
                    medio.cognome=stud1.cognome;
                }
                else if(n2<n1 && n2<n3){
                    medio.eta=stud2.eta;
                    medio.cognome=stud2.cognome;
                }
                else if(n3<n1 && n3<n2){
                    medio.eta=stud3.eta;
                    medio.cognome=stud3.cognome;
                }
            }
            break;
            //metodo 5
            case 5:{   //es 9 16 3
                int n1,n2,n3;
                n1=stud1.eta-stud2.eta;  // 9-16=-7
                n2=stud2.eta-stud3.eta;  // 16-3=13
                n3=stud1.eta-stud3.eta;  // 9-3=6
                n1=abs(n1);  //toglie il meno se c'è
                n2=abs(n2);
                n3=abs(n3);
                //controlla i due numeri minori e determina il medio
                if(n1<n2 && n3<n2){  //A<B & C<B  7<13  6<13
                    medio.eta=stud1.eta;
                    medio.cognome=stud1.cognome;
                }
                if(n2<n1 && n3<n1){  //B<A & C<A  13<7  6<7
                    medio.eta=stud3.eta;
                    medio.cognome=stud3.cognome;
                }
                if(n1<n3 && n2<n3){  //A<C & B<C  7<6  13<6
                    medio.eta=stud2.eta;
                    medio.cognome=stud2.cognome;
                }
            }
            break;
            default:
                if(metodo!=0)
                    cout<<"scegliere un numero tra 1 e 5"<<endl;
        }
        if(metodo>0 && metodo<=5)
            cout<<"\nLo studente che non è ne piu grande ne piu piccolo è "<<medio.cognome<<" eta: "<<medio.eta<<endl;
    }
    while(metodo!=0);
    cout<<"\n---Uscendo dal programma---";
}