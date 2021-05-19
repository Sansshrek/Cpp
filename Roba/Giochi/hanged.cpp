#include <iostream>
#include <time.h>
#include <string.h>
#include <cstdlib>
using namespace std;

int maxx=6,maxy=8,cont=0, indexword;
bool checkwin=false,checklose=false;
string parola, parola_check[30];
string M[8][6];

string Words[] = {"banana","gatto","telefono","bottiglia","cavallo","pallone","libro","pecora","matita","scatola","vulcano","argento","lampada","fiore","computer","pasta","carbonara","moneta"};
string Help[] = {"frutto lungo","animale da compagnia","lo usi spesso nella giornata","trasporta liquidi","animale veloce","giocattolo/maradona","lo e' la bibbia","la ragazza dei sardi","usato a scuola","la usa solid snake","ce n'è uno a napoli","metallo prezioso ma non troppo","fa luce dai","profumato","lo stai usando al momento","famosa degli italiani","piatto tipico romano","valuta/denaro"};
string letters[26];
string letters_start[] = {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};

void Restart(){
    for(int i=0;i<maxy;i++){
        for(int j=0;j<maxx;j++){
            M[i][j]=" ";
        }
    }
    for(int i=1;i<maxx-1;i++){
        M[0][i]="-";
    }
    for(int i=0;i<3;i++){
        M[maxy-1][i]="-";
    }
    for(int i=1;i<maxy-1;i++){
        M[i][1]="|";
    } 
    M[1][4]="|";
    checkwin = false;
    checklose = false;
    int word_length = (sizeof(Words)/sizeof(*Words));
    indexword = rand()%word_length;
    parola = Words[indexword];
    for(int i=0;i<26;i++){
        letters[i] = letters_start[i];  //resetta le lettere da stampare
    }
    for(int i=0;i<parola.length();i++){
        parola_check[i]="-";
    }
}

void Stampa(){
    for(int i=0;i<maxy;i++){
        for(int j=0;j<maxx;j++){
            cout<<M[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<endl;
    for(int i=0;i<parola.length();i++){
        cout<<parola_check[i]<<" ";
    }
    cout<<endl<<endl;
    for(int i=0;i<26;i++){
        cout<<letters[i]<<" ";
        if(i==12)
            cout<<endl;
    }
    cout<<endl;
}

bool CheckMove(string mossa){
    for(int i=0;i<26;i++){
        if(mossa==letters[i])
            letters[i] = " ";  //elimina la lettera inserita dalle lettere disponibili
    }
    bool check=false;
    for(int i=0;i<parola.length();i++){
        char s = parola[i];
        string l(1, s);
        if(mossa == l){
            check = true;  //ha trovato una lettera corrispondente nella parola
        }
    }
    return check;
}

void Corretto(string mossa){
    for(int i=0;i<parola.length();i++){
        char s = parola[i];
        string l(1, s);
        if(mossa == l){
            parola_check[i] = mossa;
        }
    }
    cout<<"\nLettera corretta"<<endl;
    bool check=true;
    for(int i=0;i<parola.length();i++){
        if(parola_check[i] == "-")
            check = false;
    }
    if(check)
        checkwin = true;
}

void Errore(){
    if(cont==0)
        M[2][4]="O";
    else if(cont==1){
        M[3][4]="|";
        M[4][4]="|";
    }
    else if(cont==2)
        M[3][3]="-";
    else if(cont==3)
        M[3][5]="-";
    else if(cont==4)
        M[5][3]="/";
    else
        M[5][5]="\\";
    cout<<"\nLettera sbagliata"<<endl;
    if(cont>=5){
        checklose=true;
        Stampa();
    }
    cont++;
}

int main(){
    string mossa;
    srand(time(0));
    bool exit=false;
    while(!exit){
        Restart();
        while(!checkwin and !checklose){
            bool check=false;
            Stampa();
            do{
                cout<<"\nInserire lettera da controllare (0 per uscire, 1 per indizio) INSERIRE SOLO MINUSCOLE"<<endl;
                cin>>mossa;
                if(mossa.length()>=2)
                    cout<<"\nInserire solo una lettera"<<endl;
            }while(mossa.length()>=2);
            if(mossa!="0"){
                if(mossa!="1"){
                    check = CheckMove(mossa);
                    if(!check)
                        Errore();
                    else
                        Corretto(mossa);
                }
                else
                    cout<<"\n\nINDIZIO: "<<Help[indexword]<<endl<<endl;
            }
            else{
                exit=true;
                break;
            }
        }
        if(checkwin)
            cout<<"\nComplimenti hai vinto, la parola era "<<parola<<endl;
        if(checklose)
            cout<<"\nMi spiace hai perso, la parola nuova era "<<parola<<endl;
        if(checkwin or checklose){
            cout<<"Vuoi riprovare? s/n"<<endl;
            cin>>mossa;
            if(mossa=="n" or mossa=="no" or mossa=="0")
                exit = true;
        }
    }
}