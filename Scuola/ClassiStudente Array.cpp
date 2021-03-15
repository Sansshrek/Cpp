#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Materia {
    string materia;
    float voto;
};
Materia Interr[100];

int cont = 0;
int nc=0;
bool checkMedia = false;

class Dati {
    string cognome;
    string nome;
    string indirizzo;
    string classe;
    float numInterr;
    float votoMedio;

public:
    Dati()
    {
        numInterr = 0;
        votoMedio = 0;
    }
    void input()
    {
        cout << "\nInserire Nome e Cognome alunno" << endl;
        cin >> nome;
        cin >> cognome;
        cout << "\nInserire Classe alunno" << endl;
        cin >> classe;
        cout << "\nInserire Indirizzo alunno" << endl;
        cin>>indirizzo;
    }
    void Stampa()
    {
        cout << "\n-Studente: "<<cognome << " " << nome <<":"<< endl
             << "\tClasse: " << classe << endl
             << "\tIndirizzo: " << indirizzo << endl
             << "\tVoto Medio: " << votoMedio << endl
             << "\tNumero Interrogazioni: " << numInterr << endl;
             if(cont==0)
                cout<<"\n\tLista Voti:"<<endl;
             for(int i=0;i<cont;i++){
                cout<<"\t-"<<Interr[i].materia<<": "<<Interr[i].voto<<endl;
             }
    }
    void Interrogazione()
    {
        cout << "\nInserire voto alunno" << endl;
        cin >> Interr[cont].voto;
        cout << "\nInserire materia" << endl;
        cin >> Interr[cont].materia;
        if (Interr[cont].voto > 1 && Interr[cont].voto <= 10) {
            if (!checkMedia) {
                votoMedio = Interr[cont].voto;
                checkMedia = true;
            } else {
                votoMedio = (votoMedio + Interr[cont].voto) / 2;
            }
            numInterr++;
            cont++;
        } else
            cout << "\nVoto non valido" << endl;
    }
    void CambioIndirizzo()
    {
        cout << "\nInserire indirizzo" << endl;
        cin >> indirizzo;
    }
    void InterrogazioniFile(){
        fstream File;
        File.open("interrogazione.txt", ios::in);
        while(!File.eof()){
            File>>Interr[cont].materia>>Interr[cont].voto;
            if (!checkMedia) {
                votoMedio = Interr[cont].voto;
                checkMedia = true;
            } else {
                votoMedio = (votoMedio + Interr[cont].voto) / 2;
            }
            numInterr++;
            cont++;
        }
        File.close();   
    }
    string Nome(){

        return nome;
    }
    string Cognome(){
        return cognome;
    }
};

int main()
{
    Dati Stud[100];
    int scelta = 1, sceltaAlunno = 1, userIndex;
    cout << "Inserire numero Alunni" << endl;
    cin >> nc;
    for (int i = 0; i < nc; i++) {
        Stud[i].input();
    }
    while (sceltaAlunno != 0) {
        cout << "\nInserire valore per scegliere opzione" << endl
             << "Opzione 1: Scelta Alunno" << endl
             << "Opzione 2: Stampa lista alunni" << endl
             << "Opzione 3: Aggiungi alunno" << endl
             << "Opzione 4: Elimina alunno" << endl
             << "Opzione 0: Esci dal programma" << endl;
        cin >> sceltaAlunno;
        switch (sceltaAlunno) {
        case 0:
            cout << "\n---Uscendo dal programma---" << endl;
            break;
        case 1:
            cout << "\nInserire Numero Alunno da controllare" << endl;
            cin >> userIndex;
            if (userIndex >= 0 && userIndex < nc) {
                scelta = 1;
                while (scelta != 0) {
                    cout << "\nInserire valore per scegliere opzione" << endl
                         << "Opzione 1: Stampa Dati alunno" << endl
                         << "Opzione 2: Interrogazione" << endl
                         << "Opzione 3: Cambia indirizzo alunno" << endl
                         << "Opzione 4: Inserimento voti da file" << endl
                         << "Opzione 0: Esci dai Dati alunno" << endl;
                    cin >> scelta;
                    switch (scelta) {
                    case 0:
                        cout << "\n---Uscendo dai dati alunno---" << endl;
                        break;
                    case 1:
                        Stud[userIndex].Stampa();
                        break;
                    case 2:
                        Stud[userIndex].Interrogazione();
                        break;
                    case 3:
                        Stud[userIndex].CambioIndirizzo();
                        break;
                    case 4:
                        Stud[userIndex].InterrogazioniFile();
                        break;
                    default:
                        cout << "\nScelta inesistente" << endl;
                    }
                }
            } else
                cout << "\nAlunno non esistente" << endl;
            break;
        case 2:
            cout << endl;
            for (int i = 0; i < nc; i++) {
                string nome = Stud[i].Nome();
                string cognome = Stud[i].Cognome();
                cout << "Alunno " << i << ": " << nome << " " << cognome << endl;
            }
            break;
        break;
        case 3:
            Stud[nc].input();
            nc++;
            break;
        case 4:
            break;
        default:
            cout << "\nScelta inesistente" << endl;
        }
    }
}