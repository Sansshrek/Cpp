#include <iostream>
using namespace std;

int main(){
    int num1,den1,numLength=0,denLength=0,i,temp,j,z,n=0;
    cout<<"Inserire numeratore binario"<<endl;
    cin>>num1;
    numLength = std::to_string(num1).length();
    int num[numLength];
    //inserimento di ogni valore del numero nell'array
    for(i=0;i<numLength;i++){
        num[i]=num1%10;
        num1/=10;
    }
    //inversione dell'array perche non funziona l'inserimento al contrario
    for (i = 0; i < numLength/2; ++i) {
        temp = num[numLength-i-1];
        num[numLength-i-1] = num[i];
        num[i] = temp;
    }
    cout<<"Inserire denominatore binario"<<endl;
    cin>>den1;
    denLength = std::to_string(den1).length();
    int den[denLength],ris[denLength],crc[denLength];
    //inserimento di ogni valore del numero nell'array
    for(i=0;i<denLength;i++){
        den[i]=den1%10;
        den1/=10;
    }
    //inversione dell'array perche non funziona l'inserimento al contrario
    for (i = 0; i < denLength/2; ++i) {
        temp = den[denLength-i-1];
        den[denLength-i-1] = den[i];
        den[i] = temp;
    }
    cout<<"denLength= "<<denLength<<" numLength= "<<numLength<<endl; 
    //inzio stampa
    for(i=0;i<numLength;i++){
        cout<<num[i]<<" ";
    }
    cout<<"| ";
    for(i=0;i<denLength;i++){
        cout<<den[i]<<" ";
    }
    cout<<endl;
    int spa=0;int m=denLength;int cont;int pos;int k=denLength;
    for(z=0;z<numLength;z++){  //for iniziale stampa 
        for(i=0;i<spa;i++){ //spaziatura denominatore
            cout<<"  ";
        }
        for(i=0;i<denLength;i++){   //stampa denominatore
            cout<<den[i]<<" ";
        }
        for(j=n;j<denLength;j++){   //calcolo XOR
            if(num[j]==den[j])
                ris[j]=0;
            else
                ris[j]=1;
        }
        cout<<endl;
        for(i=0;i<spa;i++){ //spaziatura resto
            cout<<"  ";
        }
        for(i=0;i<denLength;i++){    //stampa resto XOR 
            cout<<ris[i]<<" ";
        }
        cont=0;
        for(i=0;i<denLength;i++){  //trova primo 1 del resto
            if(ris[i]==1){
                pos=i;
                i=denLength;
            }
            cont++;   //conta valori da 0 al primo 1 del resto
        }
        for(i=pos;i<denLength+pos;i++){  //stampa numeri portati giu da numeratore
            cout<<num[k]<<" ";
            k++;
        }
        cout<<endl;
        for(i=0;i<denLength-cont;i++){
            ris[i]=ris[pos];
            pos++;
        }
        for(i=cont;i<denLength;i++){
            ris[i]=ris[m];
            m++;
        }
        spa=cont;
        /*
        for(i=0;i<denLength;i++){  //loop check resto
            if(j==numLength-1){   //check resto finale
                z==numLength;
                for(j=0;j<denLength;j++){
                    crc[j]=ris[j];
                }
            }
            else if(ris[i]==0){   //check valore 0 all'inizio del resto (da migliorare)
                ris[j+1]=num[j+1];
                n++;
            }
            else if(ris[i]==1){     //check posizione valore 1 nel resto
                i=denLength;
                n=i;
            }
            else{
                cout<<"Errore nella risposta"<<endl;
            }
        }  */
    }
    /*
    cout<<"Il CRC e': ";
    for(i=0;i<denLength;i++){
        cout<<crc[i]<<" ";
    }
        */
    /*
    for(i=0;i<denLength;i++){
        cout<<den[i]<<" ";
    }
    for(int j=0;j<denLength;j++){
        if(num[j]==den[j])
            ris[j]=0;
        else
            ris[j]=1;
    }
    cout<<"-"<<endl;
    for(i=0;i<denLength;i++){
        cout<<ris[i]<<" ";
    }
    */
}