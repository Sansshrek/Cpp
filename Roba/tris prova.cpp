#include <iostream>
using namespace std;

//disegna Board
void DisegnaBoard(int Board){
    sleep(1);
    cout<<endl;
    cout<<"             "<<Board[1]<<"  |  "<<Board[2]<<"  |  "<<Board[3]<<endl;
    cout<<"             - - - - - - - "<<endl;
    cout<<"             "<<Board[4]<<"  |  "<<Board[5]<<"  |  "<<Board[6]<<endl;
    cout<<"             - - - - - - - "<<endl;
    cout<<"             "<<Board[7]<<"  |  "<<Board[8]<<"  |  "<<Board[9]<<endl;
    cout<<endl;
}

//chiede al player che lettera scegliere
string inputPlayerLettera(){
    string lettera = "";
    while(~(lettera == "X" || lettera == "0")){
        cout<<"Vuoi essere X o 0"<<endl;
        cin>>lettera;
    }
    if(lettera == "X")
        return["X","0"];
    else
        return["0","X"];
}

//scelta primo turno random
string primoTurno(){
    string opponente["computer","player"];
    if (scelta(opponente) == "computer")
        return "computer";
    else
        return "player";
}

//fare la mossa
string faiMossa(string Board,string lettera,int mossa){
    Board[mossa] = lettera;
}

//controlla se qualcuno ha vinto, return True se vinto
bool Vincitore(string Board,string lettera){
    return( (Board[1] == lettera && Board[2] == lettera && Board[3] == lettera) ||   //1° vincita orizzontale
            (Board[4] == lettera && Board[5] == lettera && Board[6] == lettera) ||   //2° vincita orizzontale
            (Board[7] == lettera && Board[8] == lettera && Board[9] == lettera) ||   //3° vincita orizzontale
            (Board[1] == lettera && Board[4] == lettera && Board[7] == lettera) ||   //1° vincita verticale
            (Board[2] == lettera && Board[5] == lettera && Board[8] == lettera) ||   //2° vincita verticale
            (Board[3] == lettera && Board[6] == lettera && Board[9] == lettera) ||   //3° vincita verticale
            (Board[1] == lettera && Board[5] == lettera && Board[9] == lettera) ||   //1° vincita diagonale
            (Board[3] == lettera && Board[5] == lettera && Board[7] == lettera) || ) //2° vincita diagonale
    return value;
}

//copia Board
string CopiaBoard(string Board){
    string copiaBoard = [];
    for(i=1; i<10;i++){
        copiaBoard[i] = Board[i];
    }
    return copiaBoard;
}

//controllo spazio libero
string SpazioLibero(string Board, int mossa){
    return Board[mossa] = " ";
}

//prendere mossa player
int inputPlayerMossa(string Board){
    int mossa = "";
    for(i=1;i<10;i++){
        while(mossa ~(i)){
            cout<<"Inserire la mossa (1 - 9)"<<endl;
            cin>>mossa;
        }
    }
    return mossa;
}

//sceglie mosse random per AI
//continuare

bool BoardPiena(int Board){
    for(i=1;i<10;i++){
        if(SpazioLibero(Board,i));
            return false;
    }
    return true;
}

int main(){
    cout<<"----Benvenuto a tris----"<<endl;
    while(true){
        string Board[10]{" "};
        string sceltaPlayer, sceltaComputer = inputPlayerlettera();
        string turno = primoTurno();
        cout<<"Parte il "<<turno<<endl;
        bool partita=true;
        while(partita){
            if(turno == 'player'){   //turno player
                cout<<"    Turno del "<<turno<<endl;
                int mossa = inputPlayerMossa(Board,sceltaPlayer);
                faiMossa(Board,sceltaPlayer,mossa);
                if (Vincitore(Board,sceltaPlayer)){
                    BoardFinale(Board);
                    cout<<"Hai vinto il gioco"<<endl;
                    partita = ~partita;
                }
                else if(BoardPiena(Board)){
                    BoardFinale(Board);
                    cout<<"Parita finita con parita"<<endl;
                    partita = ~partita;
                }
                else{
                    DisegnaBoard(Board);
                    turno = "computer";
                }
            }
            else{   //turno computer
                cout<<"    Turno del "<<turno<<endl;
                int mossa = inputComputerMossa(Board,sceltaComputer);
                faiMossa(Board,sceltaComputer,mossa);
                if(Vincitore(Board,sceltaComputer)){
                    BoardFinale(Board);
                    cout<<"Hai perso contro il computer"<<endl;
                    partita = ~partita;
                }
                else if(BoardPiena(Board)){
                    BoardFinale(Board);
                    cout<<"Partita finita con partita"<<endl;
                    partita = ~partita;
                }
                else{
                    DisegnaBoard(Board);
                    turno = "player";
                }
            }
        }
    }
}