#include <iostream>
#include <time.h>
#include <string.h>
#include <math.h>
using namespace std;
float V[100];

int Input(){
    float scelta;
    int n;
    srand(time(0));
    cout<<"\nInserire quantità numeri da inserire"<<endl;
    cin>>n;
    do{
        cout<<"\nInserimento valori manuale(1) o random(2)"<<endl;
        cin>>scelta;
        if(scelta!=1 && scelta!=2)
            cout<<"\nScelta inesistente"<<endl;
    }while(scelta!=1 && scelta!=2);
    if(scelta == 1){
        for(int i=0;i<n;i++){
            cout<<"\nInserire valore "<<i+1<<endl;
            cin>>V[i];
        }
    }else{
        for(int i=0;i<n;i++){
            V[i] = (rand()%41)+10;
        }
    }
    return n;
}

float Media(int n){
    float med;
    for(int i=0;i<n;i++){
        med += V[i];
    }
    med/=n;
    return med;
}

void Mediana(int n){
    float N[n];
    for(int i=0;i<n;i++){
        N[i] = V[i];
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(N[j]<N[i]){
                float tmp = N[i];
                N[i] = N[j];
                N[j] = tmp;
            }
        }
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<"["<<N[i]<<"]"<<endl;
    }
    float num;
    if((n%2)==1){
        int med = n/2;
        num = N[med];
    }                     
    else{
        int med = n/2;
        float num1 = N[med];
        float num2 = N[med-1];
        num = (num1+num2)/2;
    }                             
    cout<<"\nLa mediana dei valori e' "<<num<<endl;
}

void Moda(int n){
    float M[n][2] = {0};
    int cont = 0;
    for(int i=0;i<n;i++){
        int pos;
        bool check = false;
        for(int j=0;j<n;j++){
            if(V[i] == M[j][0]){
                pos = j;
                check = true;
                cout<<"\nnum = "<<V[i]<<endl;
                break;
            }
        }
        if(check)
            M[pos][1] += 1;
        else{
            M[cont][0] = V[i];
            cout<<"print"<<i<<endl;
            M[cont][1] = 1;
            cont++;
        }
    }
    int max = M[0][1], pos;
    for(int i=0;i<cont;i++){
        if(M[i][1]>max){
            pos = i;
            max = M[i][1];
        }
        cout<<i<<") ["<<M[i][0]<<"] "<<M[i][1]<<" volte"<<endl;
    }
    cout<<"\n\nIl numero con maggiore frequenza e': "<<M[pos][0]<<endl;
}

void ScartoQuadraticoMedio(int n){
    float val=0, som=0;
    cout<<endl;
    for(int i=0;i<n;i++){
        val = (V[i] - Media(n));
        som += val*val;
        cout<<"";
    }
    float num = som/n;
    float sqr = sqrt(num);
    cout<<"\n\nLo scarto quadratico medio e': "<<sqr<<endl;
}

void Stampa(int n){
    cout<<"\nLista valori"<<endl;
    for(int i=0;i<n;i++){
        cout<<"["<<V[i]<<"]"<<endl;
    }
    cout<<endl;
}

int main(){
    int n, scelta;
    n = Input();
    do{
        cout<<"\nInserire valore per scegliere opzione"<<endl;
        cout<<"Opzione 1: Re-inserimento valori"<<endl;
        cout<<"Opzione 2: Stampa valori"<<endl;
        cout<<"Opzione 3: Media valori"<<endl;
        cout<<"Opzione 4: Mediana valori"<<endl;
        cout<<"Opzione 5: Moda valori"<<endl;
        cout<<"Opzione 6: Scarto Quadratico Medio"<<endl;
        cout<<"Opzione 7: Aggiunta valore"<<endl;
        cout<<"Opzione 8: Elimina ultimo valore"<<endl;
        cout<<"Opzione 0: Esci dal programma"<<endl;
        cin>>scelta;
        switch(scelta){
            case 0:
                cout<<"\n---Uscendo dal programma---"<<endl;
            break;
            case 1:
                n = Input();
            break;
            case 2:
                Stampa(n);
            break;
            case 3:
                cout<<"\nLa media dei valori e' "<<Media(n)<<endl;
            break;
            case 4:
                Mediana(n);
            break;
            case 5:
                Moda(n);
            break;
            case 6: 
                ScartoQuadraticoMedio(n);
            break;
            case 7:{
                int scelta;
                do{
                    cout<<"\nInserimento manuale(1) o random(2)"<<endl;
                    cin>>scelta;
                }while(scelta!=1 && scelta!=2);
                if(scelta==1){
                    cout<<"\nInserire valore da aggiungere"<<endl;
                    cin>>V[n];
                }
                else{
                    V[n] = (rand()%41)+10;
                }
                n++;
                Stampa(n);
                cout<<"\nValore aggiunto correttamente"<<endl;
            }break;
            case 8:{
                string t;
                cout<<"\nVerrà eliminato il numero \""<<V[n]<<"\". Confermi? (s\\n)"<<endl;
                cin>>t;
                if(t == "s"){
                    n--;
                    Stampa(n);
                    cout<<"\nValore eliminato correttamente"<<endl;
                }
            }break;
            default:
                cout<<"\nScelta inesistente"<<endl;
        }
    }while(scelta!=0);
}