#include <iostream>
#include <string.h>
#include <time.h>
#include <cstdlib>
using namespace std;

bool checkwin=false;
string MappaPlayer[10][10];
string MappaComputer[10][10];

void Reset(){
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            MappaPlayer[i][j]=" ";
            MappaComputer[i][j]=" ";
        }
    }
    checkwin=false;
}

void Stampa(){
    cout<<"         Player"<<endl;
    cout<<"\n   A B C D E F G H I J"<<endl;
    cout<<"   ___________________"<<endl;
    for(int i=0;i<10;i++){
        cout<<i<<" ";
        for(int j=0;j<10;j++){
            cout<<"|"<<MappaPlayer[i][j];
        }
        cout<<"|"<<endl;
    }
    cout<<"   -------------------"<<endl;
    
    cout<<"         Computer"<<endl;
    cout<<"\n   A B C D E F G H I J"<<endl;
    cout<<"   ___________________"<<endl;
    for(int i=0;i<10;i++){
        cout<<i<<" ";
        for(int j=0;j<10;j++){
            cout<<"|"<<MappaComputer[i][j];
        }
        cout<<"|"<<endl;
    }
    cout<<"  -------------------"<<endl;
}

void MovePlayer(int posx, int posy){
    MappaPlayer[posx][posy]="O";
}

void MoveComputer(int posx, int posy){
    MappaComputer[posx][posy]="O";
}

int main(){
    int sceltaReset;
    string mossa;
    do{
        Reset();
        cout<<"\nFormato gioco:"<<endl;
        cout<<"   A B C D E F G H I J"<<endl;
        cout<<"   ___________________"<<endl;
        for(int i=0;i<10;i++){
            cout<<i<<" | | | | | | | | | | |"<<endl;
        }
        cout<<"   -------------------"<<endl;
        bool checkInput;
        int pos1,pos2;
        do{
            //turno player
            do{
                checkInput=false;
                string mossa1;
                int mossa2;
                do{
                    cout<<"\nInserire posizione Lettera da attaccare"<<endl;
                    cin>>mossa1;
                    if(mossa1.length()!=1)
                        cout<<"\nInserire Lettera"<<endl;
                }while(mossa1.length()!=1);
                bool check=false;
                do{
                    cout<<"\nInserire posizione Numero da attaccare"<<endl;
                    cin>>mossa2;
                    for(int i=0;i<10;i++){
                        if(mossa2==i)
                            check=true;
                    }
                    if(!check)
                        cout<<"\nInserire Numero"<<endl;
                }while(!check);
                bool checkSearch=false;
                string let_capital[]={"A","B","C","D","E","F","G","H","I","J"};
                string let_lower[]={"a","b","c","d","e","f","g","h","i","j"};
                for(int i=0;i<10;i++){  //capital letter search
                    if(mossa1==let_capital[i]){
                        pos2=i;
                        checkSearch=true;
                        checkInput=true;
                    }
                }
                if(!checkSearch){
                    for(int i=0;i<10;i++){  //lower letter search
                        if(mossa1==let_lower[i]){
                            pos2=i;
                            checkInput=true;
                        }
                    }
                }
                if(!checkInput)
                    cout<<"\nMossa inesistente"<<endl;
                cout<<"Pos1 = "<<pos1<<", Pos2 = "<<pos2<<endl;
                /*
                if(mossa.length()==2){
                    bool checkSearch=false;
                    char let_capital[]={'A','B','C','D','E','F','G','H','I','J'};
                    char let_lower[]={'a','b','c','d','e','f','g','h','i','j'};
                    char let = mossa[0];
                    for(int i=0;i<10;i++){  //capital letter search
                        if(let==let_capital[i]){
                            pos2=i;
                            checkSearch=true;
                            checkInput=true;
                        }
                    }
                    if(!checkSearch){
                        for(int i=0;i<10;i++){  //lower letter search
                            if(let==let_lower[i]){
                                pos2=i;
                                checkInput=true;
                            }
                        }
                    }
                    if(!checkInput)
                        cout<<"\nMossa inesistente"<<endl;
                    cout<<"Pos1 = "<<pos1<<", Pos2 = "<<pos2<<endl;
                    pos1 = stoi(mossa[0]);  
                    cout<<"Pos1 = "<<pos1<<", Pos2 = "<<pos2<<endl;
                } */
            }
            while(!checkInput);
            MovePlayer(pos1, pos2);
            Stampa();
            //mossa pc
            pos1 = rand()%10;
            pos2 = rand()%10;
            MoveComputer(pos1, pos2);
            Stampa();
        }
        while(!checkwin);
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