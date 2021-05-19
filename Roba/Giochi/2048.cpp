/*
 ___________________     ___________________
|    |    |    |    |   |2048|1024|    | 16 |
|2048|1024|    | 16 |   |----|----|----|----|
|    |    |    |    |   |512 | 32 | 4  | 2  |
|----|----|----|----|   |----|----|----|----|
*/
#include <iostream>
#include <time.h>
#include <string.h>
using namespace std;
int M[4][4];
bool checkwin, checklose;

int random[] = {2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048};

void Reset(){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            int n = rand()%22;
            if(n<10)
                M[i][j] = random[n];
            else 
                M[i][j] = 0;
        }
    }
}

string print(int n){
    if(n > 1000)      return to_string(n);
    else if(n > 100)  return to_string(n) + " ";
    else if(n >10)    return " " + to_string(n) + " ";
    else if(n > 0)    return " " + to_string(n) + "  ";
    else              return "    ";
}

void Stampa(){
    cout<<" ";
    for(int i=0;i<19;i++){ cout<<"_";}
    cout<<endl;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cout<<"|"<<print(M[i][j]);
        }
        cout<<"|"<<endl;
        for(int j=0;j<4;j++){
            if(i!=3)
                cout<<"|----";
        }
        if(i!=3)
            cout<<"|"<<endl;
    }
    cout<<" ";
    for(int i=0;i<19;i++){ cout<<"‾";}
}

void checkWin(){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(M[i][j] == 2048)
                checkwin = true;
        }
    }
}

bool checkSame(int posy, int posx){
    int n = M[posy][posx];
    bool check = true;
    if(n != M[posy][posx+1] && n != M[posy+1][posx] && n != M[posy][posx-1] && n != M[posy-1][posx])
        check = false;
    return check;
}

void checkLose(){
    bool check = true;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(M[i][j] == 0)
                check = false;
        }
    }
    if(check){
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                check = checkSame(i, j);
            }
        }
        if(!check)
            checklose = true;
    }
}

void Add(){
    int y,x;
    do{
        y = rand()%4;
        x = rand()%4;
        if(M[y][x] == 0)
            M[y][x] = 2;
    }while(M[y][x]!=0);
}

void moveLeft(){
    cout<<"Left"<<endl;
}

void moveRight(){
    cout<<"Right"<<endl;
}

void moveUp(){
    cout<<"Up"<<endl;
}

void moveDown(){
    cout<<"Down"<<endl;
}

void move(){
    string scelta;
    do{
        cout<<"\nMuoversi con WASD"<<endl;
        cin>>scelta;
        if(scelta!="w" && scelta!="W" && scelta!="a" && scelta!="A" && scelta!="s" && scelta!="S" && scelta!="d" && scelta!="D")
            cout<<"\nInserire mossa corretta"<<endl;
    }while(scelta!="w" && scelta!="W" && scelta!="a" && scelta!="A" && scelta!="s" && scelta!="S" && scelta!="d" && scelta!="D");
    if (scelta == "w" || scelta == "W")
        moveUp();
    else if (scelta == "a" || scelta == "A")
        moveLeft();
    else if (scelta == "s" || scelta == "S")
        moveDown();
    else
        moveRight();
    checkWin();
    Add();
    if(!checkwin)
        checkLose();
    if(!checkwin && !checklose)
}

int main(){
    srand(time(0));
    string scelta;
    do{
        Reset();
        do{
            Stampa();
            move();
        }while(!checkwin && !checklose);
        cout<<"\nVuoi continuare? (s/n)"<<endl;
        cin>>scelta;
    }while(scelta!="n" && scelta!="N");
}