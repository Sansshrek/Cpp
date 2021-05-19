/*
   0 1 2 3 4 5 6 7 8 9
0 |1|1|1|1|9|1|0|0|0|0|
1 |2|9|2|1|1|1|0|1|1|1|
2 |2|9|2|0|1|1|1|1|9|1|
3 |1|1|1|0|1|9|1|1|1|1|
4 |0|1|1|1|1|1|1|0|0|0|
5 |0|1|9|1|0|0|1|1|1|0|
6 |0|1|1|1|0|1|2|9|1|0|
7 |0|0|0|0|0|1|9|2|1|0|
8 |1|1|1|0|0|1|1|1|1|1|
9 |1|9|1|0|0|0|0|0|1|9|
*/
#include <iostream>
#include <string.h>
#include <time.h>
using namespace std;

int Mnum[100][100], maxMosse = 0, mosseNum = 0;
string Mtxt[100][100];
bool checkWin, checkLose;

int checkBox(int posy, int posx){
    int num = 0;
    if(Mnum[posy-1][posx-1] == 9)
        num++;
    if(Mnum[posy-1][posx] == 9)
        num++;
    if(Mnum[posy-1][posx+1] == 9)
        num++;
    if(Mnum[posy][posx-1] == 9)
        num++;
    if(Mnum[posy][posx+1] == 9)
        num++;
    if(Mnum[posy+1][posx-1] == 9)
        num++;
    if(Mnum[posy+1][posx] == 9)
        num++;
    if(Mnum[posy+1][posx+1] == 9)
        num++;
    return num;
}

void resetNum(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(Mnum[i][j] != 9)
                Mnum[i][j] = checkBox(i, j);
        }
    }
}

void reset(int n, int nbombe){
    checkLose = false;
    checkWin = false;
    maxMosse = (n*n)-nbombe;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            Mtxt[i][j] = "■";
            Mnum[i][j] = 0;
        }
    }
    for(int i=0;i<nbombe;i++){
        while(true){
            int posy = rand()%n;
            int posx = rand()%n;
            if(Mnum[posy][posx] != 9){  // 9 determina la posizione di una bomba
                Mnum[posy][posx] = 9;
                break;
            }
        }
    }
    resetNum(n);
}

void Lose(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(Mnum[i][j] == 9)
                Mtxt[i][j] = "X";
        }
    }
    checkLose = true;
}

void checkZeros(int posy, int posx){

}

void checkMossa(int n, int posy, int posx){
    if(Mnum[posy][posx] != 9){
        Mtxt[posy][posx] = to_string(Mnum[posy][posx]);
        checkZeros(posy, posx);
        mosseNum++;
        if(mosseNum == maxMosse)
            checkWin = true;
    }
    else
        Lose(n);
}

void stampa(int n){
    cout<<endl<<" ";
    for(int i=0;i<(n*2)-1;i++){
        cout<<"_";
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<"|";
        for(int j=0;j<n;j++){
            cout<<Mnum[i][j]<<"|";
        }
        cout<<endl;
    }
    cout<<" ";
    for(int i=0;i<(n*2)-1;i++){
        cout<<"‾";
    }
    cout<<endl;
    // stampa matrice testo
    cout<<"   ";
    for(int i=0;i<n;i++){
        cout<<i<<" ";
    }
    cout<<"\n   ";
    for(int i=0;i<(n*2)-1;i++){
        cout<<"_";
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<i<<" |";
        for(int j=0;j<n;j++){
            cout<<Mtxt[i][j]<<"|";
        }
        cout<<endl;
    }
    cout<<"   ";
    for(int i=0;i<(n*2)-1;i++){
        cout<<"‾";
    }
    cout<<endl;
}

int main(){
    int scelta;
    do{
        int n, nbombe;
        do{
            cout<<"\nInserire grandezza campo (min 5)"<<endl;
            cin>>n;
        }while(n<5);
        do{
            cout<<"\nInserire quantita bombe (min "<<n<<")"<<endl;
            cin>>nbombe;
        }while(nbombe>n);
        reset(n, nbombe);
        while(!checkWin && !checkLose){
            stampa(n);
            int posy, posx;
            bool check;
            do{
                cout<<"\nInserire posizione riga da controllare"<<endl;
                cin>>posy;
                cout<<"\nInserire posizione colonna da controllare"<<endl;
                cin>>posx;
                if(Mtxt[posy][posx] == "■")
                    check = true;
                else
                    cout<<"\nPosizione gia inserita in precedenza"<<endl;
            }while(!check);
            checkMossa(n, posy, posx);
        }
        if(checkLose)
            cout<<"\nHai perso"<<endl;
        else
            cout<<"\nHai vinto"<<endl;
        cout<<"\nVuoi continuare? si(1), no(0)"<<endl;
        cin>>scelta;
    }while(scelta!=0);
}