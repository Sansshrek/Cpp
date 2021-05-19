#include <iostream>
#include <string.h>
using namespace std;

int posi,posj,mappa[10][10],cont=0;

void reset(){
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            mappa[i][j]=0;
        }
    }
    posi=0;
    posj=0;
    mappa[posi][posj]=1;
    cont=0;
    //pass:esami2020;
  //  es@mi2020
}

void print(){
    cout<<endl<<" ";
    for(int i=0;i<19;i++){
        cout<<"_";
    }
    cout<<endl;
    for(int i=0;i<10;i++){
        cout<<"|";
        for(int j=0;j<10;j++){
            if(mappa[i][j]==0)
                cout<<"X";
            else if(mappa[i][j]==2)
                cout<<"#";
            else
                cout<<"O";
            if(j<9)
            cout<<" ";
        }
        if(i==5)
            cout<<"|\t("<<posi<<";"<<posj<<")"<<endl;
        else
            cout<<"|"<<endl;
    }
    cout<<" ";
    for(int i=0;i<19;i++){
        cout<<"-";
    }
    cout<<endl;
}


void go_up(){
    if(posi!=0){
        if(mappa[posi][posj]!=2)
            mappa[posi][posj]=0;
            posi-=1;
            mappa[posi][posj]=1;
    }
    else
        cout<<"\nBloccato"<<endl;
}

void go_down(){
    if(posi!=9){
        if(mappa[posi][posj]!=2)
            mappa[posi][posj]=0;
            posi+=1;
            mappa[posi][posj]=1;
    }
    else
        cout<<"\nBloccato"<<endl;
}

void go_left(){
    if(posj!=0){
        if(mappa[posi][posj]!=2)
            mappa[posi][posj]=0;
            posj-=1;
            mappa[posi][posj]=1;
    }
    else
        cout<<"\nBloccato"<<endl;
}

void go_right(){
    if(posj!=9){
        if(mappa[posi][posj]!=2)
            mappa[posi][posj]=0;
            posj+=1;
            mappa[posi][posj]=1;
    }
    else
        cout<<"\nBloccato"<<endl;
}

void set_point(){
    mappa[posi][posj]=2;
    cont++;
}

int main(){
    string move;
    posi=0;posj=0;
    mappa[posi][posj]=1;
    int n;
    do{
        cout<<"\nUse WASD to move, R to reset, Q to set waypoint and E to close the program"<<endl;
        cin>>move;
        if(move=="e")
            cout<<"\nClosing the program"<<endl;
        else{
            if(move=="r")
                reset();
            else if(move=="q")
                set_point();
            else if(move=="w")
                go_up();
            else if(move=="a")
                go_left();
            else if(move=="s")
                go_down();
            else if(move=="d")
                go_right();
            else
                cout<<"\nError"<<endl;
            print();
        }
    }
    while(move!="e");
}