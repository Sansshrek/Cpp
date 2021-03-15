#include <iostream>
using namespace std;

int main(){
    int som, T, N, R, M, j, w;
    //cout<<"\nQuante volte vuoi provare"<<endl;
    cin>>T;
    for(int cont=0;cont<T;cont++){
        som=1;
        //cout<<"\nInserire R"<<endl;
        cin>>R;
        //cout<<"\nInserire grandezza scacchiera"<<endl;
        cin>>N;
        //cout<<"\nInserire grandezza sacco"<<endl;
        cin>>M;
        int g=R;
        som+=R;
        for(int i=0;i<(N*N)-2;i++){
            g*=R;
            som+=g;
        }
        j=som/M;
        j*=M;
        w=som-j;
        cout<<"Case #"<<cont+1<<": "<<w<<endl; 
    }
}