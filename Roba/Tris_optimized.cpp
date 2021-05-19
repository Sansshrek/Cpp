#include <iostream>
#include <string.h>
#include <time.h>
using namespace std;

string tris[9];
bool checkwin=false;
int cont=0;

void move(string playerlet, int pos){ 
    tris[pos]=playerlet;
    cont++;
}

void moveCopy(string table[], string playerlet, int pos){
    table[pos]=playerlet;
}

bool spaceFree(string table[], int pos){
    if(table[pos]==" ")
        return true;
    else
        return false;
}

bool checkWin(string table[], string let){
    if(table[0]==let && table[1]==let && table[2]==let ||   //check orizzontali
       table[3]==let && table[4]==let && table[5]==let ||
       table[6]==let && table[7]==let && table[8]==let ||
       table[0]==let && table[3]==let && table[6]==let ||   //check verticali
       table[1]==let && table[4]==let && table[7]==let ||
       table[2]==let && table[5]==let && table[8]==let ||
       table[0]==let && table[4]==let && table[8]==let ||   //check obliqui
       table[2]==let && table[4]==let && table[6]==let)
        return true;
    else
        return false;
}

int checkPC(){
    //check pc vince nella prossima mossa
    string trisCopy[9];
    for(int i=0;i<9;i++){
        trisCopy[i]=tris[i];
    }
    for(int i=0;i<9;i++){
        if(spaceFree(trisCopy,i)){
            cout<<"\nSpaceFree O pos "<<i<<endl;
            moveCopy(trisCopy, "O", i);
            if(checkWin(trisCopy, "O"))
                return i;
        }
    }
    
    //check player vince nella prossima mossa
    for(int i=0;i<9;i++){
        trisCopy[i]=tris[i];
    }
    for(int i=0;i<9;i++){
        if(spaceFree(trisCopy,i)){
            cout<<"\nSpaceFree X pos "<<i<<endl;
            moveCopy(trisCopy, "X", i);
            if(checkWin(trisCopy, "X"))
                return i;
        }
    }

    //check spazi liberi alle cornici
    int n = rand()%4;
    cout<<"\nN1="<<n<<endl;
    if(n==0 && tris[0]==" ")  //posizione 1 libera
        return 1;
    else if(n==1 && tris[2]==" ")  //posizione 3 libera
        return 3;
    else if(n==2 && tris[6]==" ")  //posizione 7 libera
        return 7;
    else if(n==3 && tris[8]==" ")  //posizione 9 libera
        return 9;

    //check spazio libero centro
    if(tris[4]==" ")
        return 5;

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

int main(){
    for(int i=0;i<9;i++){
        tris[i]=" ";
    }
    cout<<"Formato gioco:"<<endl;
    cout<<"\t1 | 2 | 3"<<endl;
    cout<<"\t---------"<<endl;
    cout<<"\t4 | 5 | 6"<<endl;
    cout<<"\t---------"<<endl;
    cout<<"\t7 | 8 | 9"<<endl;
    cout<<endl;
    int mossa,countplayer,playerNum;
    string playerlet;
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
        cin>>playerNum;
        if(playerNum!=1 && playerNum!=2)
            cout<<"\nnon esistente"<<endl;
    }
    while(playerNum!=1 && playerNum!=2);
    if(playerNum==1)
        playerlet="X";
    else
        playerlet="O";
    while(!checkwin && cont!=9){
        cout<<endl;
        cout<<"\t"<<tris[0]<<" | "<<tris[1]<<" | "<<tris[2]<<"\t1 | 2 | 3"<<endl;
        cout<<"\t---------\t---------"<<endl;
        cout<<"\t"<<tris[3]<<" | "<<tris[4]<<" | "<<tris[5]<<"\t4 | 5 | 6"<<endl;
        cout<<"\t---------\t---------"<<endl;
        cout<<"\t"<<tris[6]<<" | "<<tris[7]<<" | "<<tris[8]<<"\t7 | 8 | 9"<<endl;
        cout<<endl;
        cout<<"\nTocca al player "<<playerlet<<" Inserire posizione"<<endl;
        if(countplayer==1 || countplayer==2 && playerlet!="O"){
            do{
                checkmove=false;
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
            while(!checkmove);
        }
        if(playerlet=="X"){ //player 1
            move(playerlet, mossa-1);
            checkwin = checkWin(tris,playerlet);
            if(checkwin)
                break;
            playerlet="O";
        }
        else{   //player 2
            if(countplayer==1){  //2 player
                move(playerlet, mossa-1);
                checkwin = checkWin(tris,playerlet);
                if(checkwin)
                    break;
                playerlet="X";
            }
            else{   //vs computer
                mossa=checkPC();
                move(playerlet, mossa);
                checkwin = checkWin(tris,playerlet);
                if(checkwin)
                    break;
                playerlet="X";
            }
        }
        cout<<"pos: "<<mossa-1<<", "<<tris[mossa-1]<<" cont: "<<cont<<endl;
    }
    cout<<endl;
    cout<<"\t"<<tris[0]<<" | "<<tris[1]<<" | "<<tris[2]<<endl;
    cout<<"\t---------"<<endl;
    cout<<"\t"<<tris[3]<<" | "<<tris[4]<<" | "<<tris[5]<<endl;
    cout<<"\t---------"<<endl;
    cout<<"\t"<<tris[6]<<" | "<<tris[7]<<" | "<<tris[8]<<endl;
    cout<<endl;
    if(checkwin)
        cout<<"\n\nComplimenti ha vinto il player "<<playerlet<<endl;
    else
        cout<<"\n\nMi spiace, pareggio"<<endl;
}