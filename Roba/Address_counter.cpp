#include <iostream>
#include <math.h>
using namespace std;

void indir(){
    int num;
    cout<<"\nInserire numero reti"<<endl;
    cin>>num;
    int num_ip[num];
    for(int i=0;i<num;i++){
        cout<<"\nInserire numero ip rete "<<i+1<<endl;
        cin>>num_ip[i];
    }
    cout<<"\nINFORMAZIONI:"<<endl;
    for(int i=0;i<num;i++){
        cout<<"Rete "<<i+1<<": "<<num_ip[i]<<" IP"<<endl;
    }
    int cont=0;
    cout<<"\nRete | Primo IP      | Ultimo IP     |"<<endl;
    for(int i=0;i<num;i++){
        cont++;
        //--- Rete
        cout<<i+1;
        if((i+1)<100)  // if number is less than 100 add a space
            cout<<" ";
        if((i+1)<10)   // if number is less than 10 add a space
            cout<<" ";
        //--- Primo IP
        cout<<"  | 192.168.1."<<cont;
        if(cont<100)  // if number is less than 100 add a space
            cout<<" ";
        if(cont<10)   // if number is less than 10 add a space
            cout<<" ";
        cout<<" | ";
        //--- Ultimo IP
        cont += (num_ip[i]-1);
        cout<<"192.168.1."<<cont;
        if(cont<100)  // if number is less than 100 add a space
            cout<<" ";
        if(cont<10)   // if number is less than 10 add a space
            cout<<" ";
        cout<<" |"<<endl;
    }
}

void liberi(){
    int num, num_lib;
    cout<<"\nInserire numero reti"<<endl;
    cin>>num;
    int num_ip[num];
    for(int i=0;i<num;i++){
        cout<<"\nInserire numero ip rete "<<i+1<<endl;
        cin>>num_ip[i];
    }
    cout<<"\nInserire numero ip liberi"<<endl;
    cin>>num_lib;
    cout<<"\nINFORMAZIONI:"<<endl;
    for(int i=0;i<num;i++){
        cout<<"Rete "<<i+1<<": "<<num_ip[i]<<" IP, "<<num_lib<<" IP Liberi"<<endl;
    }
    cout<<"Lista ip:"<<endl;
    int cont=0;
    cout<<"\nRete | Primo IP      | Ultimo IP     | IP Liberi                     |"<<endl;
    for(int i=0;i<num;i++){
        cont++;
        //--- Rete
        cout<<i+1;
        if((i+1)<100)  // if number is less than 100 add a space
            cout<<" ";
        if((i+1)<10)   // if number is less than 10 add a space
            cout<<" ";
        //--- Primo IP
        cout<<"  | 192.168.1."<<cont;
        if(cont<100)  // if number is less than 100 add a space
            cout<<" ";
        if(cont<10)   // if number is less than 10 add a space
            cout<<" ";
        cout<<" | ";
        //--- Ultimo IP
        cont += (num_ip[i]-1);
        cout<<"192.168.1."<<cont;
        if(cont<100)  // if number is less than 100 add a space
            cout<<" ";
        if(cont<10)   // if number is less than 10 add a space
            cout<<" ";
        cout<<" | ";
        //--- IP liberi 1
        cont++;
        cout<<"192.168.1."<<cont;
        if(cont<100)  // if number is less than 100 add a space
            cout<<" ";
        if(cont<10)   // if number is less than 10 add a space
            cout<<" ";
        cout<<" - ";
        //--- IP liberi 2
        cont += num_lib-1;
        cout<<"192.168.1."<<cont;
        if(cont<100)  // if number is less than 100 add a space
            cout<<" ";
        if(cont<10)   // if number is less than 10 add a space
            cout<<" ";
        cout<<" |"<<endl;
    }
}

void sottoreti(){
    int num;
    cout<<"\nInserire numero reti"<<endl;
    cin>>num;
    int num_ip[num];
    for(int i=0;i<num;i++){
        cout<<"\nInserire numero ip rete "<<i+1<<endl;
        cin>>num_ip[i];
    }
    cout<<"\nINFORMAZIONI:"<<endl;
    for(int i=0;i<num;i++){
        cout<<"Rete "<<i+1<<": "<<num_ip[i]<<" IP"<<endl;
    }
    int cont=0;
    cout<<"\nRete | Primo IP    | Ultimo IP     |"<<endl;
    for(int i=0;i<num;i++){
        //--- Rete
        cout<<i+1;
        if((i+1)<100)  // if number is less than 100 add a space
            cout<<" ";
        if((i+1)<10)   // if number is less than 10 add a space
            cout<<" ";
        //--- Primo IP
        cout<<"  | 172.16."<<i+1<<".100";
        cout<<" | ";
        //--- Ultimo IP
        cout<<"172.16."<<i+1<<"."<<num_ip[i]+99;
        if(cont<100)  // if number is less than 100 add a space
            cout<<" ";
        if(cont<10)   // if number is less than 10 add a space
            cout<<" ";
        cout<<" |"<<endl;
    }
}

void binario(){
    int num;
    cout<<"\nInserire numero reti"<<endl;
    cin>>num;
    int num_ip[num], exp[num];
    for(int i=0;i<num;i++){
        cout<<"\nInserire numero ip rete "<<i+1<<endl;
        cin>>num_ip[i];
        int e=0;
        while(true){
            int n = pow(2, e);
            if(num_ip[i] < n){
                exp[i] = n;
                break;
            }
            e++;
        }
    }
    cout<<"\nINFORMAZIONI:"<<endl;
    for(int i=0;i<num;i++){
        cout<<"Rete "<<i+1<<": "<<num_ip[i]<<" IP, bin = 2^"<<log2(exp[i])<<" = "<<exp[i]<<endl;
    }
    int cont=0;
    cout<<"\nRete | Primo IP      | Ultimo IP     | IP Liberi                     |"<<endl;
    for(int i=0;i<num;i++){
        cont++;
        //--- Rete
        cout<<i+1;
        if((i+1)<100)  // if number is less than 100 add a space
            cout<<" ";
        if((i+1)<10)   // if number is less than 10 add a space
            cout<<" ";
        //--- Primo IP
        cout<<"  | 192.168.1."<<cont;
        if(cont<100)  // if number is less than 100 add a space
            cout<<" ";
        if(cont<10)   // if number is less than 10 add a space
            cout<<" ";
        cout<<" | ";
        //--- Ultimo IP
        cont += (num_ip[i]-1);
        cout<<"192.168.1."<<cont;
        if(cont<100)  // if number is less than 100 add a space
            cout<<" ";
        if(cont<10)   // if number is less than 10 add a space
            cout<<" ";
        cout<<" | ";
        //--- IP liberi 1
        cont++;
        cout<<"192.168.1."<<cont;
        if(cont<100)  // if number is less than 100 add a space
            cout<<" ";
        if(cont<10)   // if number is less than 10 add a space
            cout<<" ";
        cout<<" - ";
        //--- IP liberi 2
        int left = exp[i] - num_ip[i];
        cont += left-1;
        cout<<"192.168.1."<<cont;
        if(cont<100)  // if number is less than 100 add a space
            cout<<" ";
        if(cont<10)   // if number is less than 10 add a space
            cout<<" ";
        cout<<" |"<<endl;
    }
}

int main(){
    int scelta;
    do{
        cout<<"\nInserire valore per scegliere opzione"<<endl;
        cout<<"Opzione 1: Indirizzamento ordinario"<<endl;
        cout<<"Opzione 2: Indirizzamento con ip liberi"<<endl;
        cout<<"Opzione 3: Indirizzamento con sottoreti"<<endl;
        cout<<"Opzione 4: Indirizzamento binario"<<endl;
        cout<<"Opzione 0: Esci dal programma"<<endl;
        cin>>scelta;
        switch(scelta){
            case 0:
                cout<<"\n---Uscendo dal programma---"<<endl;
            break;
            case 1:
                indir();
            break;
            case 2:
                liberi();
            break;
            case 3:
                sottoreti();
            break;
            case 4:
                binario();
            break;                
            default:
                cout<<"\nScelta inesistente"<<endl;
        }
    }while(scelta!=0);
}