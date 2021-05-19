#include <iostream>
#include <math.h>
using namespace std;
void intToBin(){
    int n;
    cout<<"Inserire numero da inserire: ";
    cin>>n;
    int binaryNum[32];
    int i=0;
    while(n>0){
        binaryNum[i]=n%2;
        n=n/2;
        i++;
    }
    cout<<"il binario e': ";
    for(int j=i-1;j>=0;j--){
        cout<<binaryNum[j];
    }
}

void binToInt(){
    int n;
    string bin;
    cout<<"\nInserire stringa binaria da inserire: ";
    cin>>bin;
    n = stoi(bin, 0, 2);
    cout<<"il decimale e': "<<n<<endl;
}

void calcoloCRC(){
    string num,den;
    cout<<"Inserire numeratore binario"<<endl;
    cin>>num;
    cout<<"Inserire denominatore binario"<<endl;
    cin>>den;
    
}
int main(){
    int scelta;
    do{
        cout<<"\nInserire valore per scegliere opzione"<<endl;
        cout<<"Opzione 1: convertitore decimale a binario"<<endl;
        cout<<"Opzione 2: convertitore binario a decimale"<<endl;
        cout<<"Opzione 3: calcolatore crc"<<endl;
        cout<<"Opzione 0: Uscire dal programma"<<endl;
        cin>>scelta;
        switch(scelta){
            case 0:
                cout<<"Uscendo dal programma"<<endl;
            break;
            case 1:
                intToBin();
            break;
            case 2:
                binToInt();
            break;
            case 3:
                calcoloCRC();
            break;
            default:
                cout<<"\nScelta inesistente riprovare"<<endl;
        }
    }
    while(scelta!=0);
}
