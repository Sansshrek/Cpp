#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

int ng=0;

class giorno{
    int num_giorno=0;
    float t_max,  t_min;
public:
    giorno(int num, float min, float max){
        num_giorno=num;
        t_max = max;
        t_min = min;
    }
    void print(){
        cout<<"\nGiorno "<<num_giorno<<endl
        <<"  temp min= "<<t_min<<" / temp max= "<<t_max<<endl;
    }
    float diff(){ return (t_max-t_min);}
    float min(){ return t_min;}
    int ng(){ return num_giorno;}
    void print_zero(){
        if(t_min>0)
            cout<<"Giorno "<<num_giorno<<endl;
    }
    float media_temp(){ return((t_max+t_min)/2);}
    float mediang(float media){
        float m = media_temp();
        media+=m;
        return media;
    }
};

int main(){
    vector<giorno> day; 
    int scelta;
    cout<<"\nInserire numero giorni"<<endl;
    cin>>ng;
    for(int i=0;i<ng;i++){
        float min, max;
        cout<<"\nInserire temperatura minima giorno "<<i+1<<endl;
        cin>>min;
        do{
            cout<<"\nInserire temperatura massima giorno "<<i+1<<endl;
            cin>>max;
            if(max<min)
                cout<<"\nERRORE: Temperatura massima minore di quella minima"<<endl;
        }
        while(max<min);
        giorno tmp(i+1,min,max);
        day.push_back(tmp);
    }
    do{
        cout<<"\nInserire opzione"<<endl
        <<"Opzione 1: Stampa lista giorni e temperature"<<endl
        <<"Opzione 2: Stampa dell'escursione termica giornaliera"<<endl
        <<"Opzione 3: Stampa del giorno piu freddo"<<endl
        <<"Opzione 4: Stampa dei giorni in cui la temperatura e' rimasta sopra lo zero"<<endl
        <<"Opzione 5: Stampa media delle temperature medie giornaliere"<<endl
        <<"Opzione 6: Aggiunta giorno e temperature"<<endl
        <<"Opzione 7: Re-inserimento giorni"<<endl
        <<"Opzione 0: Esci dal programma"<<endl;
        cin>>scelta;
        switch(scelta){
            case 0:
                cout<<"\n---Uscendo dal programma---"<<endl;
            break;
            case 1:{
                cout<<endl;
                for(int i=0;i<day.size();i++){
                    day[i].print();
                }
            }
            break;
            case 2:{
                cout<<endl;
                for(int i=0;i<day.size();i++){
                    cout<<"escursione giorno "<<i+1<<": "<<day[i].diff()<<endl;
                }
            }
            break;
            case 3:{
                int min=day[0].min(), pos;
                for(int i=0;i<day.size();i++){
                    if(day[i].min()<min){
                        min=day[i].min();
                        pos=i;
                    }
                }
                cout<<"\nIl giorno "<<pos+1<<" ha la temperatura piu bassa con: "<<min<<endl;
            }
            break;
            case 4:{
                cout<<endl;
                for(int i=0;i<day.size();i++){
                    day[i].print_zero();
                }
            }
            break;
            case 5:{
                cout<<endl;
                float media=0;
                for(int i=0;i<day.size();i++){
                    media=day[i].mediang(media);
                }
                cout<<"\nMedia del mese: "<<media/day.size()<<endl;
            }
            break;
            case 6:{
                float min, max;
                cout<<"\nInserire temperatura minima giorno "<<ng+1<<endl;
                cin>>min;
                cout<<"\nInserire temperatura massima giorno "<<ng+1<<endl;
                cin>>max;
                giorno tmp(ng+1,min, max);
                ng++;
                day.push_back(tmp);
            }
            break;
            case 7:{
                cout<<"\nInserire numero giorni"<<endl;
                cin>>ng;
                day.clear();
                for(int i=0;i<ng;i++){
                    float min, max;
                    cout<<"\nInserire temperatura minima giorno "<<i+1<<endl;
                    cin>>min;
                    cout<<"\nInserire temperatura massima giorno "<<i+1<<endl;
                    cin>>max;
                    giorno tmp(i+1,min,max);
                    day.push_back(tmp);
                }
            }
            break;
            default:
                cout<<"\nScelta inesistente"<<endl;
        }
    }
    while(scelta!=0);
}