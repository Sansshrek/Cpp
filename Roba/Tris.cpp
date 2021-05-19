#include <iostream>
#include <string.h>
#include <time.h>
using namespace std;

string tris[9];
bool checkwin;
int cont;

void reset(){
    for(int i=0;i<9;i++){
        tris[i]=" ";
    }
    checkwin=false;
    cont=0;
}

void moveX(int pos){ 
    tris[pos]="X";
    cont++;
}

void moveO(int pos){
    tris[pos]="O";
    cont++;
}

void checkWin(int player){
    string let;
    if(player==1)
        let="X";
    else
        let="O";
    if(tris[0]==let && tris[1]==let && tris[2]==let ||   //check orizzontali
       tris[3]==let && tris[4]==let && tris[5]==let ||
       tris[6]==let && tris[7]==let && tris[8]==let ||
       tris[0]==let && tris[3]==let && tris[6]==let ||   //check verticali
       tris[1]==let && tris[4]==let && tris[7]==let ||
       tris[2]==let && tris[5]==let && tris[8]==let ||
       tris[0]==let && tris[4]==let && tris[8]==let ||   //check obliqui
       tris[2]==let && tris[4]==let && tris[6]==let)
        checkwin=true;
}

int checkPC(){
    //check pc vince nella prossima mossa
    if(tris[0]=="O" && tris[1]=="O" && tris[2]==" ")    
        return 3;
    else if(tris[0]=="O" && tris[3]=="O" && tris[6]==" ")
        return 7;
    else if(tris[0]=="O" && tris[4]=="O" && tris[8]==" ")
        return 9;
    else if(tris[6]=="O" && tris[3]=="O" && tris[0]==" ")
        return 1;
    else if(tris[6]=="O" && tris[7]=="O" && tris[8]==" ")
        return 9;
    else if(tris[6]=="O" && tris[4]=="O" && tris[2]==" ")
        return 3;
    else if(tris[8]=="O" && tris[7]=="O" && tris[6]==" ")
        return 7;
    else if(tris[8]=="O" && tris[5]=="O" && tris[2]==" ")
        return 3;
    else if(tris[8]=="O" && tris[4]=="O" && tris[0]==" ")
        return 1;
    else if(tris[2]=="O" && tris[5]=="O" && tris[8]==" ")
        return 9;
    else if(tris[2]=="O" && tris[1]=="O" && tris[0]==" ")
        return 1;
    else if(tris[2]=="O" && tris[4]=="O" && tris[6]==" ")
        return 7;
    else if(tris[0]=="O" && tris[8]=="O" && tris[4]==" ")
        return 5;
    else if(tris[0]=="O" && tris[6]=="O" && tris[3]==" ")
        return 4;
    else if(tris[6]=="O" && tris[8]=="O" && tris[7]==" ")
        return 8;
    else if(tris[2]=="O" && tris[8]=="O" && tris[5]==" ")
        return 6;
    else if(tris[0]=="O" && tris[2]=="O" && tris[1]==" ")
        return 2;
    else if(tris[2]=="O" && tris[6]=="O" && tris[4]==" ")
        return 5;
    
    //check player vince nella prossima mossa
    if(tris[0]=="X" && tris[1]=="X" && tris[2]==" ")    
        return 3;
    else if(tris[0]=="X" && tris[3]=="X" && tris[6]==" ")
        return 7;
    else if(tris[0]=="X" && tris[4]=="X" && tris[8]==" ")
        return 9;
    else if(tris[6]=="X" && tris[3]=="X" && tris[0]==" ")
        return 1;
    else if(tris[6]=="X" && tris[7]=="X" && tris[8]==" ")
        return 9;
    else if(tris[6]=="X" && tris[4]=="X" && tris[2]==" ")
        return 3;
    else if(tris[8]=="X" && tris[7]=="X" && tris[6]==" ")
        return 7;
    else if(tris[8]=="X" && tris[5]=="X" && tris[2]==" ")
        return 3;
    else if(tris[8]=="X" && tris[4]=="X" && tris[0]==" ")
        return 1;
    else if(tris[2]=="X" && tris[5]=="X" && tris[8]==" ")
        return 9;
    else if(tris[2]=="X" && tris[1]=="X" && tris[0]==" ")
        return 1;
    else if(tris[2]=="X" && tris[4]=="X" && tris[6]==" ")
        return 7;
    else if(tris[0]=="X" && tris[8]=="X" && tris[4]==" ")
        return 5;
    else if(tris[0]=="X" && tris[6]=="X" && tris[3]==" ")
        return 4;
    else if(tris[6]=="X" && tris[8]=="X" && tris[7]==" ")
        return 8;
    else if(tris[2]=="X" && tris[8]=="X" && tris[5]==" ")
        return 6;
    else if(tris[0]=="X" && tris[2]=="X" && tris[1]==" ")
        return 2;
    else if(tris[2]=="X" && tris[6]=="X" && tris[4]==" ")
        return 5;

    int n;
    //check spazi liberi alle cornici
    if(tris[0]==" " || tris[2]==" " || tris[6]==" " || tris[8]==" ")
        n = rand()%4;
        cout<<"\nN2="<<n<<endl;
        if(n==0 && tris[0]==" ")  //posizione 1 libera
            return 1;
        else if(n==1 && tris[2]==" ")  //posizione 3 libera
            return 3;
        else if(n==2 && tris[6]==" ")  //posizione 7 libera
            return 7;
        else if(n==3 && tris[8]==" ")  //posizione 9 libera
            return 9;
    else if(tris[4]==" "){
        //check spazio libero centro
        if(tris[4]==" ")
            return 5;
    }
    else{
        //check spazi liberi lati
        n = rand()%4;
        cout<<"\nN2="<<n<<endl;
        if(n==0 && tris[1]==" ")  //pos 2 libera
            return 2;
        else if(n==1 && tris[3]==" ")  //pos 4 libera
            return 4;
        else if(n==2 && tris[5]==" ")  //pos 6 libera
            return 6;
        else if(n==3 && tris[7]==" ")  //pos 8 libera
            return 8;
    }
}

int main(){
    int sceltaReset;
    cout<<"Formato gioco:"<<endl;
    cout<<"\t1 | 2 | 3"<<endl;
    cout<<"\t---------"<<endl;
    cout<<"\t4 | 5 | 6"<<endl;
    cout<<"\t---------"<<endl;
    cout<<"\t7 | 8 | 9"<<endl;
    cout<<endl;
    do{
        reset();
        srand(time(0));
        int mossa,player,countplayer;
        bool checkmove=false;
        do{
            cout<<"\n1)2 player"<<endl
            <<"2)vs computer"<<endl;
            cin>>countplayer;
            if(countplayer!=1 && countplayer!=2)
                cout<<"\nScelta inesistente"<<endl;
        }
        while(countplayer!=1 && countplayer!=2);
        do{
            cout<<"Inizia player 1(X) o 2(O)?"<<endl;
            cin>>player;
            if(player!=1 && player!=2)
                cout<<"\nnon esistente"<<endl;
        }
        while(player!=1 && player!=2);
        while(!checkwin && cont!=9){
            cout<<endl;
            cout<<"\t"<<tris[0]<<" | "<<tris[1]<<" | "<<tris[2]<<"\t1 | 2 | 3"<<endl;
            cout<<"\t---------\t---------"<<endl;
            cout<<"\t"<<tris[3]<<" | "<<tris[4]<<" | "<<tris[5]<<"\t4 | 5 | 6"<<endl;
            cout<<"\t---------\t---------"<<endl;
            cout<<"\t"<<tris[6]<<" | "<<tris[7]<<" | "<<tris[8]<<"\t7 | 8 | 9"<<endl;
            cout<<endl;
            cout<<"\nTocca al player "<<player<<" Inserire posizione"<<endl;
            if(countplayer==1 || countplayer==2 && player!=2){
                do{
                    checkmove=false;
                    if(countplayer==1 || countplayer==2 && player!=2){
                        cin>>mossa;
                        if(mossa!=1 && mossa!=2 && mossa!=3 && mossa!=4 && mossa!=5 && mossa!=6 && mossa!=7 && mossa!=8 && mossa!=9)
                            cout<<"\nPosizione inesistente"<<endl;
                        else if(tris[mossa-1]=="X")
                            cout<<"\nPosizione gia occupata"<<endl;
                        else if(tris[mossa-1]=="O")
                            cout<<"\nPosizione gia occupata"<<endl;
                        else
                            checkmove=true;
                    }
                }
                while(!checkmove);
            }
            if(player==1){ //player 1
                moveX(mossa-1);
                checkWin(player);
                if(checkwin)
                    break;
                player=2;
            }
            else{   //player 2
                if(countplayer==1){  //2 player
                    moveO(mossa-1);
                    checkWin(player);
                    if(checkwin)
                        break;
                    player=1;
                }
                else{   //vs computer
                    mossa=(checkPC()-1);
                    moveO(mossa);
                    checkWin(player);
                    if(checkwin)
                        break;
                    player=1;
                }
            }
            cout<<"pos: "<<mossa<<", "<<tris[mossa]<<" cont: "<<cont<<endl;
        }
        cout<<endl;
        cout<<"\t"<<tris[0]<<" | "<<tris[1]<<" | "<<tris[2]<<endl;
        cout<<"\t---------"<<endl;
        cout<<"\t"<<tris[3]<<" | "<<tris[4]<<" | "<<tris[5]<<endl;
        cout<<"\t---------"<<endl;
        cout<<"\t"<<tris[6]<<" | "<<tris[7]<<" | "<<tris[8]<<endl;
        cout<<endl;
        if(checkwin)
            cout<<"\n\nComplimenti ha vinto il player "<<player<<endl;
        else
            cout<<"\n\nMi spiace, pareggio"<<endl; 
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