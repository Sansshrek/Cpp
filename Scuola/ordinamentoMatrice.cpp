#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;
int A[100][100];

void random(int n,int m){
    int i,j;
    srand(time(0));
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            A[i][j]=(rand()%10)+1;
        }
    }
}

void inserimento(int n,int m){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cout<<"Inserire numero in pos "<<i<<" = ";
            cin>>A[i][j];
        }
    }
}
void stampa(int n,int m){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cout<<A[i][j]<<"  ";
        }
        cout<<endl;
    }
}

void scambio(int z,int x,int y){
    int tmp;
    tmp=A[z][x];
    A[z][x]=A[z][y];
    A[z][y]=tmp;
}

void ordinamento(int n,int m){
    int i,j,index,z;
    cout<<"-----"<<endl;
    for(z=0;z<n;z++){
        for(i=0;i<m-1;i++){
            index=i;
            for(j=i+1;j<m;j++){
                if(A[z][j]>A[z][index]){
                    index=j;
                }
                scambio(z,j,index);
            }
        }
    }
}

int main(){
    int i,j,n,m,tmp;
    cout<<"Inserire grandezza righe"<<endl;
    cin>>n;
    cout<<"Inserire grandezza colonne"<<endl;
    cin>>m;
    random(n,m);
    stampa(n,m);
    ordinamento(n,m);
    stampa(n,m);
}