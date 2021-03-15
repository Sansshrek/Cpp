/*Creare una classe studente con le seguenti caratteristiche:
1) Attributi privati: Cognome, Nome, Classe, numInterr, Indirizzo, votoMedio
2) Costruttore: Cognome, Nome, Indirizzo, NumInterr = 0, votoMedio = 0
3) Metodi Pubblici: Interrogazioni(float votocorrente) -> votoMedio=(votoMedio/numInterr+votoInterr)/(numInterr+1)
4) Metodo Stampa
5) Metodo cambio indirizzo */
#include <iostream>
#include <string.h>
using namespace std;
bool checkMedia = false;

struct Alunno{
    string cognome;
    string nome;
    string indirizzo;
    string classe;
    float numInterr=0;
    float votoMedio=0;
};
Alunno Stud[100];
int cont=0;

struct Materia{
    string materia;
    float voto;
};
Materia Interr[100]; 

class Dati{
    public:
    void Stampa(int user){
        cout<<"\n"<<Stud[user].cognome<<" "<<Stud[user].nome<<endl
        <<"\tClasse: "<<Stud[user].classe<<endl
        <<"\tIndirizzo: "<<Stud[user].indirizzo<<endl
        <<"\tVoto Medio: "<<Stud[user].votoMedio<<endl
        <<"\tNumero Interrogazioni: "<<Stud[user].numInterr<<endl;
    }
    void Interrogazione(int user){
        cout<<"\nInserire voto alunno"<<endl;
        cin>>Interr[user].voto;
        cout<<"\nInserire materia"<<endl;
        cin>>Interr[user].materia;
        if(Interr[user].voto>1 && Interr[user].voto<=10){
            if(!checkMedia){
                Stud[user].votoMedio = Interr[user].voto;
                checkMedia = true;
            }
            else{
                Stud[user].votoMedio = (Stud[user].votoMedio + Interr[user].voto)/2;
            }
            Stud[user].numInterr++;
        }
        else
            cout<<"\nVoto non valido"<<endl;
    }
    void CambioIndirizzo(int user){
        cout<<"\nInserire indirizzo"<<endl;
        cin>>Stud[user].indirizzo;
    }
};

void StampaAlunni(){
    for(int i=0;i<cont;i++){
        cout<<"\nAlunno "<<i+1<<endl
        <<"\tNome: "<<Stud[i].nome<<" "<<Stud[i].cognome<<endl;
    }
}

void Menu(int user);

int main(){
    int scelta, userindex;
    cout<<"\nInserire numero studenti"<<endl;
    cin>>cont;
    for(int i=0;i<cont;i++){
        cout<<"\nInserire Nome e Cognome alunno"<<endl;
        cin>>Stud[i].nome;
        cin>>Stud[i].cognome;
        cout<<"\nInserire Classe alunno"<<endl;
        cin>>Stud[i].classe;
        cout<<"\nInserire Indirizzo alunno"<<endl;
        getline(cin, Stud[i].indirizzo);
    }
    do{
        cout<<"\nInserire valore per scegliere opzione"<<endl
        <<"Opzione 1: Stampa Lista Alunni"<<endl
        <<"Opzione 2: Scelta Alunno"<<endl
        <<"Opzione 0: Esci"<<endl;
        cin >> scelta;
        switch(scelta){
            case 0:
                cout<<"\n---Uscendo dal programma---"<<endl;
            break;
            case 1:
                StampaAlunni();
            break;
            case 2:{
                cout<<"\nInserire Numero Alunno da controllare"<<endl;
                cin>>userindex;
                userindex--;
                if(userindex>=0 && userindex<cont)
                    Menu(userindex);
                else
                    cout<<"\nNumero Alunno non esistente"<<endl;
            }
            break;
            default:
                cout<<"\nScelta inesistente"<<endl;
        }
    }
    while(scelta!=0);
}

void Menu(int user){
    int scelta;
    Dati Studente();
    do{
        cout<<"\nInserire valore per scegliere opzione"<<endl
        <<"Opzione 1: Stampa Dati alunno"<<endl
        <<"Opzione 2: Interrogazione"<<endl
        <<"Opzione 3: Cambia indirizzo alunno"<<endl
        <<"Opzione 0: Esci"<<endl;
        cin >> scelta;
        switch(scelta){
            case 0:
                cout<<"\n---Uscendo dal programma---"<<endl;
            break;
            case 1:
                Studente.Stampa(user);
            break;
            case 2:
                Studente.Interrogazione(user);
            break;
            case 3:
                Studente.CambioIndirizzo(user);
            break;
            default:
                cout<<"\nScelta inesistente"<<endl;
        }
    }
    while(scelta!=0);
}