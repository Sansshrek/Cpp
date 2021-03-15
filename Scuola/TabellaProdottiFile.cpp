/* Di un prodotto sono forniti i quantitativi venduti a N clienti e in una tabella sono presenti: nome cliente, quantita venduta. Il programma deve:
a)stampare media vendite superiori a dato fornito in input
b)trovare cliente con quantita massima e stampa del nome
c)dato nome cliente, stampare vendita o errore se non trovato
d)ordinare e stampare clienti in ordine alfabetico
*/
#include <iostream>
#include <string>
#include <math.h>
#include <time.h>
#include <fstream>
using namespace std;

string cognomiRandom[15] = {"Rossi", "Ferrari", "Bianchi", "Romano", "Gallo", "Costa", "Fontana", "Conti", "Esposito", "Bruno", "Rizzo", "Moretti", "Marino", "Barbieri", "Lombardi"};

fstream File;

int nc = 0, vend;
string nome;

void Random(){
    srand(time(0));
    File.open("prodotti.txt", ios::out);
    int cogIndex;
    cout<<"\nInserire massimo studenti"<<endl;
    cin>>nc;
    srand(time(0));
    for(int i=0;i<nc;i++){
        cogIndex = rand()%15;
        nome = cognomiRandom[cogIndex];
        vend = rand()%80;
        File<<nome<<" "<<vend<<"\n";
    }
    cout<<"\n\t--Randomizzazione completata--"<<endl;
    File.close();
}

void Inserimento(){
    int scelta;
    cout << "Vorresti inserire i valori manualmente o random?  (0/1)" << endl;
    cin >> scelta;
    if(scelta == 1)
        Random();
    else{
        File.open("prodotti.txt", ios::out);
        cout<<"\nInserire massimo clienti"<<endl;
        cin>>nc;
        for(int i=0;i<nc;i++){
            cout<<"Inserire nome del cliente "<<i+1<<endl;
            cin>>nome;
            cout<<"Inserire quantita venduta dal cliente "<<i+1<<endl;
            cin>>vend;
            File<<nome<<" "<<vend<<"\n";
        }
        File.close();
    }
}

void InserimentoFile(){
    bool check = false;
    cout<<"\nInserire il file 'prodotti.txt' nella cartella del programma"<<endl;
    File.open("prodotti.txt", ios::in);
    if(File.is_open())  //check esistenza file
        check = true;  //il file esiste
    if(!check)
        cout<<"\nIl file non esiste"<<endl;
    else{  
        nc=0;
        string x;
        File>>x;
        while(!File.eof()){
            nc++;
            cout<<"nice"<<endl;
        }
        cout<<"Numero Clienti= "<<nc<<endl;
    }
    File.close();
}

void SceltaInsert(){
    int scelta;
    cout<<"\nInserire valore per scegliere opzione"<<endl
    <<"\n\tOpzione 1: Inserimento Random"<<endl
    <<"\n\tOpzione 2: Inserimento Manuale"<<endl
    <<"\n\tOpzione 3: Inserimento da File"<<endl;
    cin>>scelta;
    switch(scelta){
        case 1:
            Random();
        break;
        case 2:
            Inserimento();
        break;
        case 3:
            InserimentoFile();
        break;
        default:
            cout<<"\nScelta inesistente"<<endl;
    }
}

void Stampa(){
    if(nc==0)
        cout<<"Non ci sono ancora clienti"<<endl;
    else{
        File.open("prodotti.txt", ios::in);
        for(int i=0;i<nc;i++){
            File>>nome>>vend;
            cout<<"\nCliente "<<i+1<<" "<<nome<<" ha venduto "<<vend<<" prodotti"<<endl;
        }
        File.close();
    }
}

void StampaMedia(){
    int n, som=0, scelta;
    float med=0;
    cout<<"\nSi vuole stampare la media totale (inserire 1) o la media dei valori maggiori dal valore in input (predefinito)?"<<endl;
    cin>>scelta;
    if(scelta==1){
        File.open("prodotti.txt", ios::in);
        for(int i=0;i<nc;i++){
            File>>nome>>vend;
            med+=vend;
        }
        med/=nc;
        cout<<"\nLa media totale e': "<<med<<endl;
        File.close();
    }
    else{
        File.open("prodotti.txt", ios::in);
        cout<<"\nInserire valore per controllare la media maggiore prodotti venduti al valore"<<endl;
        cin>>n;
        for(int i=0;i<nc;i++){
            File>>nome>>vend;
            if(vend>n){
                som++;
                med+=vend;
            }
        }
        med/=som;
        cout<<"\nLa media delle vendite superiore a "<<n<<" e': "<<med<<endl;
        File.close();
    }
}

void StampaMaggiore(){
    int max=0;
    string nm;
    File.open("prodotti.txt", ios::in);
    for(int i=0;i<nc;i++){
        File>>nome>>vend;
        if(vend>max){
            max = vend;
            nm = nome;
        }
    }
    File.close();
    cout<<"\nIl cliente con la quantita piu alta di vendite e': "<<nm<<endl;
}

void StampaVendita(){
    bool checkNome = false, checkVend = false;
    string nm;
    int vendite;
    cout<<"\nInserire nome per stampare la vendita"<<endl;
    cin>>nm;
    File.open("prodotti.txt", ios::in);
    for(int i=0;i<nc;i++){
        File>>nome>>vend;
        if(nome == nm){
            checkNome = true;
            vendite = vend;
            if(vend>0)
                checkVend = true;
        }
    }
    File.close();
    if(!checkNome)
        cout<<"\nIl nome inserito non esiste nella lista"<<endl;
    else{
        if(!checkVend)
            cout<<"\n"<<nm<<" non ha venduto prodotti ancora"<<endl;
        else
            cout<<"\n"<<nm<<" ha venduto "<<vendite<<" prodotti"<<endl;
    }
}

void OrdinamentoVend(){
    bool checkScambio;
    int vendite[nc], scelta, tmpInt;
    string nomi[nc], tmpStr;
    File.open("prodotti.txt", ios::in);
    for(int i=0;i<nc;i++){
        File>>nomi[i]>>vendite[i];
    }
    File.close();
    cout << "\nVuoi eseguire l'ordinamento:" << endl
         << "\tOpzione 0: dal piu grande al piu piccolo" << endl
         << "\tOpzione 1: dal piu piccolo al piu grande" << endl;
    cin >> scelta;
    if (scelta == 0 || scelta == 1) {
        for (int i = 0; i < nc; i++) {
            checkScambio = false;
            for (int j = 1; j < (nc - i); j++)
                if (scelta == 0) {
                    if (vendite[j - 1] < vendite[j]) {
                        tmpStr = nomi[j - 1];  //scambio nomi
                        nomi[j - 1] = nomi[j];
                        nomi[j] = tmpStr;
                        tmpInt = vendite[j - 1];  //scambio vendite
                        vendite[j - 1] = vendite[j];
                        vendite[j] = tmpInt;
                        checkScambio = true;
                    }
                } else if (scelta == 1) {
                    if (vendite[j - 1] > vendite[j]) {
                        tmpStr = nomi[j - 1];  //scambio nomi
                        nomi[j - 1] = nomi[j];
                        nomi[j] = tmpStr;
                        tmpInt = vendite[j - 1];  //scambio vendite
                        vendite[j - 1] = vendite[j];
                        vendite[j] = tmpInt;
                        checkScambio = true;
                    }
                }
            if (!checkScambio)
                break;
        }
    } else
        cout << "\nScelta inesistente" << endl;
    File.open("prodotti.txt", ios::out);
    for(int i=0;i<nc;i++){
        File<<nomi[i]<<" "<<vendite[i]<<"\n";
    }
    File.close();
}

void OrdinamentoNome(){
    int vendite[nc], scelta, tmpInt;
    string nomi[nc], tmpStr;
    File.open("prodotti.txt", ios::in);
    for(int i=0;i<nc;i++){
        File>>nomi[i]>>vendite[i];
    }
    File.close();
    for(int i=0;i<nc-1;i++){
        for(int j=i+1;j<nc-1;j++){
            if(nomi[i] > nomi[j]){
                tmpStr = nomi[i];  //scambio nomi
                nomi[i] = nomi[j];
                nomi[j] = tmpStr;
                tmpInt = vendite[i];  //scambio vendite
                vendite[i] = vendite[j];
                vendite[j] = tmpInt;
            }
        }
    }
    for (int i=0; i<nc-1; i++) {
        int index = i;
        for (int j=i+1; j<nc; j++)
            if (nomi[j] < nomi[index]) 
                index = j;
            tmpStr = nomi[index];  //scambio nomi
            nomi[index] = nomi[i];
            nomi[i] = tmpStr;
            tmpInt = vendite[index];  //scambio vendite
            vendite[index] = vendite[i];
            vendite[i] = tmpInt;
   }
    File.open("prodotti.txt", ios::out);
    for(int i=0;i<nc;i++){
        File<<nomi[i]<<" "<<vendite[i]<<"\n";
    }
    File.close();
}

void Ordinamento()
{
    int scelta;
    bool check = true;
    cout << "\nIn che modo vuoi ordinare la tabella" << endl
         << "\tOpzione 1: Ordinamento in base alle vendite" << endl
         << "\tOpzione 2: Ordinamento in base al nome" << endl;
    cin >> scelta;
    switch (scelta) {
    case 1:
        OrdinamentoVend();
        break;
    case 2:
        OrdinamentoNome();
        break;
    default:
        cout << "\nScelta inesistente" << endl;
        check = false;
    }
    if(check)
        cout << "\n\t-Ordinamento Completato-" << endl;
        Stampa();
}

void Aggiunta(){
    int n=-1, vendite[nc];
    string  nomi[nc];
    while(n<0){
        cout<<"\nQuanti studenti vuoi aggiungere?"<<endl;
        cin>>n;
        if(n<0)
            cout<<"\nValore impossibile. reinserire"<<endl;
    }
    File.open("prodotti.txt", ios::in);  //apri il file per prendere dati
    for(int i=0;i<nc;i++){
        File>>nomi[i]>>vendite[i];  //salva i valori nello struct studente 
    }
    File.close();
    File.open("prodotti.txt", ios::out);  //apri il file per inserire dati
    for(int i=0;i<nc+n;i++){
        if(i>=nc){
            cout<<"\nInserire cognome e eta' studente "<<i+1<<endl;
            cin>>nome;
            cin>>vend;
            File<<nome<<" "<<vend<<"\n";
        }
        else{
            File<<nomi[i]<<" "<<vendite[i];
        }
    }
    File.close();
    cout<<"\nAggiunta completata"<<endl;
    nc+=n;
}

void Elimina(){
    int scelta, pos, vendite[nc];
    string cog, nomi[nc];
    cout<<"\nVuoi stampare i cognomi degli studenti con le posizioni? (si=1/no=0)"<<endl;
    cin>>scelta;
    if(scelta==1){
        File.open("prodotti.txt", ios::in);
        for(int i=0;i<nc;i++){
            File>>nome>>vend;
            cout<<"\nStudente "<<i+1<<": "<<nome<<endl;
        }
        File.close();
    }
    cout<<"\nInserisci cognome da eliminare"<<endl;
    cin>>cog;
    bool check = false;
    File.open("prodotti.txt", ios::in);
    for(int i=0;i<nc;i++){
        File>>nomi[i]>>vendite[i];  //salva i valori nello struct studente 
        if(nomi[i]==cog){
            pos=i;
            check = true;
        }
    }
    File.close();
    if(check==false)
        cout<<"\nCognome inesistente"<<endl;
    else{
        for(int i=pos;i<nc;i++){
            nomi[i] = nomi[i+1];  //elimina il cognome inserito
            vendite[i] = vendite[i+1];
        }
        File.open("prodotti.txt", ios::out);
        for(int i=0;i<nc;i++){
            File<<nomi[i]<<" "<<vendite[i]<<"\n"; //reinserisce i dati con il cognome eliminato nel file
        }
        File.close();
        cout << "Studente eliminato correttamente." << endl;
        nc--;
    }
}

int main(){
    int scelta=1;
    SceltaInsert();
    while(scelta!=0){
        cout<<"\nInserire valore per scegliere opzione"<<endl
        <<"Opzione 1: Inserire o randomizzare nuovi clienti"<<endl
        <<"Opzione 2: Stampare lista clienti"<<endl
        <<"Opzione 3: Stampa media vendite maggiori a valore in input"<<endl
        <<"Opzione 4: Stampa cliente con maggiore vendita"<<endl
        <<"Opzione 5: Stampa vendita cliente dato"<<endl
        <<"Opzione 6: Ordinamento lista clienti"<<endl
        <<"Opzione 0: Esci dal programma"<<endl;
        cin>>scelta;
        switch(scelta){
            case 0:     
                cout<<"\n---Chiusura e del programma---"<<endl;
            break;
            case 1:
                SceltaInsert();
            break;
            case 2: 
                Stampa();
            break;
            case 3:
                StampaMedia();
            break;
            case 4:
                StampaMaggiore();
            break;
            case 5:
                StampaVendita();
            break;
            case 6:
                Ordinamento();
            break;
            default:
                cout<<"\nScelta inesistente"<<endl;
        }
    }
}