#include <iostream>
#include <string.h>
#include <windows.h>
using namespace std;

int main(){
    int n;
    bool check=false;
    HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
    do{
        cout<<"\nInserire grandezza matrice (min 5)(dispari)"<<endl;
        cin>>n;
        if(n<5)
            cout<<"\nLa matrice deve essere piu grande di 5"<<endl;
        else{
            int r=n%2;
            if(r!=1)
                cout<<"\nLa grandezza matrice non e' dispari"<<endl;
            else
                break;
        }
    }while(true);
    string M[n][n];
    int meta=(n-1)/2;
    cout<<"Meta: "<<meta<<endl<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            M[i][j]="O";
        }
    }
    for(int i=0;i<n;i++){
        M[meta][i]="#";
    }
    for(int i=0;i<n;i++){
        M[i][meta]="#";
    }

    for(int i=0;i<meta;i++){
        M[0][i]="#";  //alto sinistra
    }
    for(int i=0;i<meta;i++){ 
        M[i][n-1]="#";  //alto destra
    }
    for(int i=meta;i<(n);i++){
        M[n-1][i]="#";  //basso sinistra
    }
    for(int i=meta;i<n;i++){
        M[i][0]="#";  //basso destra
    }

    SetConsoleTextAttribute(hConsole,4);
    for(int i=0;i<n+6;i++){
        cout<<"O ";
    }
    cout<<endl;
    for(int i=0;i<n+6;i++){
        cout<<"O ";
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<"O O O ";
        for(int j=0;j<n;j++){
            if(M[i][j]=="#")
                SetConsoleTextAttribute(hConsole,7);
            else
                SetConsoleTextAttribute(hConsole,4);
            cout<<M[i][j]<<" ";
        }
        SetConsoleTextAttribute(hConsole,4);
        cout<<"O O O"<<endl;
    }
    for(int i=0;i<n+6;i++){
        cout<<"O ";
    }
    cout<<endl;
    for(int i=0;i<n+6;i++){
        cout<<"O ";
    }
}