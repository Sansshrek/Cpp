#include <iostream>
#include <math.h>
#include <string.h>
#include <time.h>
using namespace std;

string generatore(){
    string articolo1[4]={"il","la","i","le"};  //articoli1  4
    string articolo2[4]={"il","la","i","le"};  //articoli2  4
    string oggetto[9]={"gatt","pupazz","ragazz","signor","mar","rumor","fior","vent","fuoc"}; //0-8 oggetti(9)
    string aggettivo[7]={"buon","spaventos","rumoros","tenebros","pericolos","cup","vecchi"}; // 0-6 aggettivi(7)
    string verbo[10]={"ha","è","spaventa","diventa","cancella","suona","canta","gioca","da'","fa"};  //verbi (10)
    string somiglianza[6]={"simili","uguali","diversi","completamente uguali","completamente diversi","molto simili"};  //simiglianze  (6)
    string OggVoc1,OggVoc2,AggVoc1,AggVoc2,testo;
    int articoloLength=sizeof(articolo1)/sizeof(articolo1[0]);
    int oggettoLength=sizeof(oggetto)/sizeof(oggetto[0]);
    int aggettivoLength=sizeof(aggettivo)/sizeof(aggettivo[0]);
    int verboLength=sizeof(verbo)/sizeof(verbo[0]);
    int somiglianzaLength=sizeof(somiglianza)/sizeof(somiglianza[0]);
    srand(time(0));
    string con1="";  //con reset
    string VerboPlur=""; //plurale verbo reset
    int indexart2,indexogg1,indexogg2;
    int indexverbo=rand()%verboLength;  //index verbo
    int indexagg1=rand()%aggettivoLength;  //index primo aggettivo
    int indexagg2=rand()%aggettivoLength;  //index secondo aggettivo
    int indexsomig=rand()%somiglianzaLength;  //index somiglianza
    int indexart1=rand()%articoloLength;  //index primo articolo
    if(verbo[indexverbo]=="gioca" || verbo[indexverbo]=="suona" || verbo[indexverbo]=="canta")
        con1="con ";
    switch(indexart1){
        case 0: //articolo il singolare maschile
            AggVoc1="o";  //maschile singolare
            indexart2=rand()%2; //index secondo articolo sing il o la
            indexogg1=rand()%oggettoLength;
            if(oggetto[indexogg1]=="gatt" || 
            oggetto[indexogg1]=="pupazz" || 
            oggetto[indexogg1]=="ragazz" || 
            oggetto[indexogg1]=="vent" || 
            oggetto[indexogg1]=="fuoc"){
                OggVoc1="o";
            }
            else if(oggetto[indexogg1]=="signor" ||
            oggetto[indexogg1]=="mar" ||
            oggetto[indexogg1]=="rumor" ||
            oggetto[indexogg1]=="fior"){
                OggVoc1="e";
            }
        break;
        case 1:  //articolo la singolare femminile
            AggVoc1="a";
            indexart2=rand()%2;
            indexogg1=rand()%4;  //gatta, pupazza, ragazza, signora
            OggVoc1="a";
        break;
        case 2:  //articolo i plurale maschile
            AggVoc1="i";
            VerboPlur="no";
            OggVoc1="i";
            indexart2=(rand()%2)+2;
            indexogg1=rand()%oggettoLength;
            if(verbo[indexverbo]=="ha")
                verbo[indexverbo]="han";
            if(verbo[indexverbo]=="è")
                verbo[indexverbo]="so";
            if(verbo[indexverbo]=="da'")
                verbo[indexverbo]="dan";
            if(verbo[indexverbo]=="fa")
                verbo[indexverbo]="fan";
            if(oggetto[indexogg1]=="fuoc")
                OggVoc1="hi";
            if(aggettivo[indexagg1]=="vecchi")
                AggVoc1="";
        break;
        case 3:  //articolo le plurale femminile
            AggVoc1="e";
            VerboPlur="no";
            indexart2=(rand()%2)+2;
            indexogg1=rand()%4;  //gatta, pupazza, ragazza, signora
            OggVoc1="e";
            if(verbo[indexverbo]=="ha")
                verbo[indexverbo]="han";
            if(verbo[indexverbo]=="è")
                verbo[indexverbo]="so";
            if(verbo[indexverbo]=="da'")
                verbo[indexverbo]="dan";
            if(verbo[indexverbo]=="fa")
                verbo[indexverbo]="fan";
        break;
        default:
            testo="impossibile indexart1";
    }
    switch(indexart2){
        case 0:  //articolo il singolare maschile
            AggVoc2="o";
            indexogg2=rand()%oggettoLength;
            if(oggetto[indexogg1]=="gatt" || 
            oggetto[indexogg1]=="pupazz" || 
            oggetto[indexogg1]=="ragazz" || 
            oggetto[indexogg1]=="vent" || 
            oggetto[indexogg1]=="fuoc"){
                OggVoc2="o";
            }
            else if(oggetto[indexogg1]=="signor" ||
            oggetto[indexogg1]=="mar" ||
            oggetto[indexogg1]=="rumor" ||
            oggetto[indexogg1]=="fior"){
                OggVoc2="e";
            }
        break;
        case 1:  //articolo la singolare femminile
            AggVoc2="a";
            indexogg2=rand()%4;
            OggVoc2="a";
        break;
        case 2:  //articolo i plurale maschile
            AggVoc2="i";
            OggVoc2="i";
            indexogg2=rand()%oggettoLength;
            if(oggetto[indexogg2]=="fuoc")
                OggVoc2="hi";
            if(aggettivo[indexagg2]=="vecchi")
                AggVoc2="";
        break;
        case 3:  //articolo le plurale femminile
            AggVoc2="e";
            OggVoc2="e";
            indexogg2=rand()%4;
        break;
        default:
            testo="impossibile indexart2";
    }
    int text=rand()%7;
    switch(text){
        case 0:
            testo=articolo1[indexart1] + " " + oggetto[indexogg1] + OggVoc1 + " " + aggettivo[indexagg1] + AggVoc1 + " " + verbo[indexverbo] + VerboPlur + " " + con1 + articolo2[indexart2] + " " + oggetto[indexogg2] + OggVoc2 + " " + aggettivo[indexagg2] +AggVoc2;
        break;
        case 1:
            if(indexagg1==0 && indexart1==0){
                AggVoc1="";
            }
            else if(indexagg1==0 && indexart1==2){
                AggVoc1="";
            }
            if(indexagg1==1 && indexart1==0){
                articolo1[indexart1]="lo";
            }
            else if(indexagg1==1 && indexart1==2){
                articolo1[indexart1]="gli";
            }
            testo=articolo1[indexart1] + " " + aggettivo[indexagg1] + AggVoc1 + " " + oggetto[indexogg1] + OggVoc1 + " " + verbo[indexverbo] + VerboPlur + " " + con1 + articolo2[indexart2] + " " + oggetto[indexogg2] + OggVoc2 + " " + aggettivo[indexagg2] +AggVoc2;
        break;
        case 2:
            if(indexagg2==0 && indexart2==0){
               AggVoc2="";
            }
            else if(indexagg2==0 && indexart2==2){
               AggVoc2="";
            }
            if(indexagg2==1 && indexart2==0){
                articolo2[indexart2]="lo";
            }
            else if(indexagg2==1 && indexart2==2){
                articolo2[indexart2]="gli";
            }
            testo=articolo1[indexart1] + " " + oggetto[indexogg1] + OggVoc1 + " " + aggettivo[indexagg1] + AggVoc1 + " " + verbo[indexverbo] + VerboPlur + " " + con1 + articolo2[indexart2] + " " + aggettivo[indexagg2] +AggVoc2 + " " + oggetto[indexogg2] + OggVoc2;
        break;
        case 3:
            if(indexagg1==0 && indexart1==0){
                AggVoc1="";
            }
            else if(indexagg1==0 && indexart1==2){
                AggVoc1="";
            }
            if(indexagg2==0 && indexart2==0){
               AggVoc2="";
            }
            else if(indexagg2==0 && indexart2==2){
               AggVoc2="";
            }
            if(indexagg1==1 && indexart1==0){
                articolo1[indexart1]="lo";
            }
            else if(indexagg1==1 && indexart1==2){
                articolo1[indexart1]="gli";
            }
            if(indexagg2==1 && indexart2==0){
                articolo2[indexart2]="lo";
            }
            else if(indexagg2==1 && indexart2==2){
                articolo2[indexart2]="gli";
            }
            testo=articolo1[indexart1] + " " + aggettivo[indexagg1] + AggVoc1 + " " + oggetto[indexogg1] + OggVoc1 + " " + verbo[indexverbo] + VerboPlur + " " + con1 + articolo2[indexart2] + " " + aggettivo[indexagg2] +AggVoc2 + " " + oggetto[indexogg2] + OggVoc2;
        break;
        case 4: 
            if(indexart1==0 || indexart1==1)  //singolare
                testo=verbo[indexverbo] + VerboPlur + " " + con1 + articolo1[indexart1] + " " + oggetto[indexogg1] + OggVoc1 + " " + aggettivo[indexagg1] + AggVoc1 + " colui che " + verbo[indexverbo] + VerboPlur + " " + articolo2[indexart2] + " " + oggetto[indexogg2] + OggVoc2 + " " + aggettivo[indexagg2] +AggVoc2;
            else //plurale
                testo=verbo[indexverbo] + VerboPlur + " " + con1 + articolo1[indexart1] + " " + oggetto[indexogg1] + OggVoc1 + " " + aggettivo[indexagg1] + AggVoc1 + " coloro che " + verbo[indexverbo] + VerboPlur + " " + articolo2[indexart2] + " " + oggetto[indexogg2] + OggVoc2 + " " + aggettivo[indexagg2] +AggVoc2;
        break;
        case 5:  //somiglianza
			testo=articolo1[indexart1] + " " + oggetto[indexogg1] + OggVoc1 + " " + aggettivo[indexagg1] + AggVoc1 + " e " + articolo2[indexart2] + " " + oggetto[indexogg2] + OggVoc2 + " " + aggettivo[indexagg2] +AggVoc2 + " sono " + somiglianza[indexsomig];
        break;
        case 6:  //somiglianza
			testo=articolo1[indexart1] + " " + oggetto[indexogg1] + OggVoc1 + " " + aggettivo[indexagg1] + AggVoc1 + " e " + articolo2[indexart2] + " " + oggetto[indexogg2] + OggVoc2 + " " + aggettivo[indexagg2] +AggVoc2 + " sono " + somiglianza[indexsomig];
        break;
        default:
            testo="Impossibile";
    }
    return testo;
}

int main(){
    string scelta,haiku;
    while(scelta!="0"){
        cout<<"\nInserire carattere per genererare haiku (0 per uscire)"<<endl;
        cin>>scelta;
        if(scelta!="0"){
            haiku=generatore();
            cout<<"\n\t -";
            int length=haiku.length();
            for(int i=0;i<length;i++){
                cout<<"-";
            }
            cout<<"-";
            cout<<"\n\t| ";
            for(int i=0;i<length;i++){
                cout<<" ";
            }
            cout<<" |";
            cout<<"\n\t| "<<haiku<<" |";
            cout<<"\n\t| ";
            for(int i=0;i<length;i++){
                cout<<" ";
            }
            cout<<" |";
            cout<<"\n\t -";
            for(int i=0;i<length;i++){
                cout<<"-";
            }
            cout<<"-"<<endl<<endl;
        }
    }
    cout<<"\n\t---Uscendo dal programma---"<<endl<<endl;
}