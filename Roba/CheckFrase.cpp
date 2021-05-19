#include <iostream>
#include <string.h>
using namespace std;

bool CheckFrase(string frase){
    int length = frase.length();
    string art;
    bool checkFound;
    for(int i=0;i<length;i++){  //check articoli 2 lettere
        art=frase[i];
        art+=frase[i+1];
        art+=frase[i+2];
        if(art=="il " || art=="lo " || art=="l'" || art=="la " || art=="le " || art=="un"){
            checkFound = true;
            break;
        }
    }
    for(int i=0;i<length;i++){  //check articoli 3 lettere
        art=frase[i];
        art+=frase[i+1];
        art+=frase[i+2];
        art+=frase[i+3];
        if(art=="gli " || art=="uno " || art=="una " || art=="un'" || art=="del " || art=="dei "){
            checkFound = true;
            break;
        }
    }
    for(int i=0;i<length;i++){  //check articoli 5 lettere
        art=frase[i];
        art+=frase[i+1];
        art+=frase[i+2];
        art+=frase[i+3];
        art+=frase[i+4];
        art+=frase[i+5];
        if(art=="dello " || art=="dell'" || art=="degli " || art=="della " || art=="delle "){
            checkFound = true;
            break;
        }
    }
    for(int i=0;i<length;i++){  //check articoli 1 lettere
        art=frase[i];
        art=frase[i+1];
        art=frase[i+2];
        if(art==" i "){
            checkFound = true;
            break;
        }
    }
    if(checkFound==true)
        return true;
    else
        return false;
}

int main(){
    string frase;
    bool check; 
    while(frase != "0"){
        cout<<"Inserire la frase (0 per uscire)"<<endl;
        cin>>frase;
        check = CheckFrase(frase);
        if(check==true){
            cout<<"Ci sta un articolo"<<endl;
        }
        else{
            cout<<"Non ho trovato un articolo"<<endl;
        }
    }
}