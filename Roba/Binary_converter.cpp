#include <iostream>
#include <cmath>
#include <string.h>
using namespace std;

int Bin_to_Dec(int bin){
    int dec=0,i=0;
    while(bin>0){
		if(bin%10!=0) {
			dec=dec+pow(2,i);
		}
		bin=bin/10;
		i++;			
	}
    return dec;
}

int Dec_to_Bin(int dec){
    string b = "";
    while (dec>0) {
		if (dec%2==0)
			b='0'+b;
		else
			b='1'+b;
		dec=dec/2;
	}
    int bin = stoi(b);
    return bin;
}

bool checkBin(string bin){
    bool check = true;
    for(int i=0;i<bin.length();i++){
        if(bin[i] != '0' and bin[i] != '1'){
            check = false;
        }
    }
    if(!check){
        cout<<"\nInserire valori binari corretti"<<endl;
    }
    return check;
}

int main(){
    int scelta;
    do{
        cout<<"\nInserire valore per scegliere opzione"<<endl;
        cout<<"Opzione 1: Convertire da Binario a Decimale"<<endl;
        cout<<"Opzione 2: Convertire da Decimale a Binario"<<endl;
        cout<<"Opzione 0: Esci dal programma"<<endl;
        cin>>scelta;
        switch(scelta){
            case 0:
                cout<<"\n---Uscendo dal programma---"<<endl;
            break;
            case 1:{
                string b;
                do{
                    cout<<"\nInserire stringa binaria"<<endl;
                    cin>>b;
                }while(!checkBin(b));
                int bin = stoi(b);
                cout<<"\nIl valore "<<b<<" in decimale diventa: "<<Bin_to_Dec(bin)<<endl;
            }break;
            case 2:{
                int dec;
                cout<<"\nInserire valore decimale"<<endl;
                cin>>dec;
                cout<<"\nIl valore "<<dec<<" in binario diventa: "<<Dec_to_Bin(dec)<<endl;
            }
            break;
            default:
                cout<<"\nScelta inesistente"<<endl;
        }
    }while(scelta!=0);
}