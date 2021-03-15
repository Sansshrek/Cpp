#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
using namespace std;
void setColor(short Color){
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hCon,Color);
}
int main(){
    setColor(2);
    bool i;
    int n;
    srand(time(0));
    while(!i){
        n=(rand()%30);
        if(n==18)
            cout<<"SCIMIA";
        else if(n==28)
            cout<<"BANANA";
        else if(n==10)
            cout<<"GOLIRA";
        else
            cout<<n;
    }
}