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
    cout<<endl;
    cout<<"         Player\t\t\t         Computer"<<endl;
    cout<<"   A B C D E F G H I J\t\t   A B C D E F G H I J"<<endl;
    cout<<"   ___________________\t\t   ___________________"<<endl;
    for(int i=0;i<10;i++){
        cout<<i<<" ";
        for(int j=0;j<10;j++){
            if(MappaPlayer[i][j]!="/")
                cout<<"|"<<MappaPlayer[i][j];
            else
                cout<<"| ";
        }
        cout<<"|\t\t";
        cout<<i<<" ";
        for(int j=0;j<10;j++){
            cout<<"|"<<MappaComputer[i][j];
        }
        cout<<"|"<<endl;
    }
    cout<<"   -------------------\t\t   -------------------"<<endl;
}

void MovePlayer(int posx, int posy){
    if(MappaComputer[posx][posy]=="B")
        MappaComputer[posx][posy]="X";
    else if(MappaComputer[posx][posy]==" " || MappaComputer[posx][posy]=="/")
        MappaComputer[posx][posy]="O";
}

void MoveComputer(int posx, int posy){
    MappaPlayer[posx][posy]="X";
}

void setBoat(){
    cout<<"\nInserire posizioni barche"<<endl;
    for(int i=0;i<5;i++){
        bool check=false, checkValid=false, checkNear=false;
        int posx1,posy1,posx2,posy2,posx3,posy3,posn;
        do{
            do{
                cout<<"\nInserire posizione 1 x e y barca "<<i+1<<endl;
                cin>>posx1;
                cin>>posy1;
                cout<<"\nInserire posizione 2 x e y barca "<<i+1<<endl;
                cin>>posx2;
                cin>>posy2;
                cout<<"\nInserire posizione 3 x e y barca "<<i+1<<endl;
                cin>>posx3;
                cin>>posy3;
                if(MappaPlayer[posx1][posy1]=="/" || MappaPlayer[posx1][posy1]=="B" ||
                MappaPlayer[posx2][posy2]=="/" || MappaPlayer[posx2][posy2]=="B" ||
                MappaPlayer[posx3][posy3]=="/" || MappaPlayer[posx3][posy3]=="B")
                    cout<<"\nPosizione occupata"<<endl;
                else
                    check=true;
            }while(!check);
            if(posx1==posx2 && posx2==posx3){
                checkValid=true;
                posn=1;  //orizzontale
            }
            else if(posy1==posy2 && posy2==posy3){
                checkValid=true;
                posn=2;  //verticale
            }
            if(checkValid){
                if(posn==1){
                    if((posy1+1)==posy2 && (posy1+2)==posy3 ||
                    (posy1+1)==posy3 && (posy1+2)==posy2 ||
                    (posy1+1)==posy2 && (posy1-1)==posy3 ||
                    (posy1+1)==posy3 && (posy1-1)==posy2 ||
                    (posy1-1)==posy2 && (posy1-2)==posy3 ||
                    (posy1-1)==posy3 && (posy1-2)==posy2)
                        checkNear=true;
                }
                else{
                    if((posx1+1)==posx2 && (posx1+2)==posx3 ||
                    (posx1+1)==posx3 && (posx1+2)==posx2 ||
                    (posx1+1)==posx2 && (posx1-1)==posx3 ||
                    (posx1+1)==posx3 && (posx1-1)==posx2 ||
                    (posx1-1)==posx2 && (posx1-2)==posx3 ||
                    (posx1-1)==posx3 && (posx1-2)==posx2)
                        checkNear=true;
                }
            }
            else
                cout<<"\nPosizioni barca invalide"<<endl;
        }while(!checkValid && !checkNear);
        MappaPlayer[posx1][posy1]="B";
        MappaPlayer[posx2][posy2]="B";
        MappaPlayer[posx3][posy3]="B";
        //inserire if posizioni vicino barca
    }
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
                bool checkExist=false;
                string let_capital[]={"A","B","C","D","E","F","G","H","I","J"};
                string let_lower[]={"a","b","c","d","e","f","g","h","i","j"};
                do{
                    cout<<"\nInserire posizione Lettera da attaccare"<<endl;
                    cin>>mossa1;
                    for(int i=0;i<10;i++){  //capital letter search
                        if(mossa1==let_capital[i]){
                            checkExist=true;
                            pos2=i;
                        }
                    }
                    for(int i=0;i<10;i++){  //lower letter search
                        if(mossa1==let_lower[i]){
                            checkExist=true;
                            pos2=i;
                        }
                    }
                    if(!checkExist)
                        cout<<"\nLettera non valida"<<endl;
                }while(!checkExist);
                checkExist=false;
                do{
                    cout<<"\nInserire posizione Numero da attaccare"<<endl;
                    cin>>mossa2;
                    for(int i=0;i<10;i++){
                        if(mossa2==i)
                            checkExist=true;
                    }
                    if(!checkExist)
                        cout<<"\nInserire Numero"<<endl;
                }while(!checkExist);
                pos1 = mossa2;
                for(int i=0;i<10;i++){
                    for(int i=0;i<10;i++){
                        if(MappaPlayer[pos1][pos2]==" ")
                            checkInput=true;
                    }
                }
                if(!checkInput)
                    cout<<"\nPosizione gia occupata"<<endl;
                cout<<"Pos1 = "<<pos1<<", Pos2 = "<<pos2<<endl;
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