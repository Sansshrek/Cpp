#include <iostream>
#include <string.h>
#include <windows.h>
#include <conio.h>
using namespace std;

string congiuntivo(string verbo){
    string last, last2, last3, last4, last5, last6;
    int length;
    length = verbo.length();
    last = verbo[length-1];
    last2 = verbo[length-2] + last;
    if(length>6)
        last3 = verbo[length-3] + last2;
    if(length>7)
        last4 = verbo[length-4] + last3;
    if(length>8)
        last5 = verbo[length-5] + last4;
    if(length>9)
        last6 = verbo[length-6] + last5;
    for(int i=0;i<1;i++){
        if(last3!="ato"){
            //presente
            if(last=="i"){
                verbo = "congiuntivo\n\t\tpresente \n\t\t\tprima o seconda o terza persona singolare";
                break;
            }
            else if(last3=="amo"){
                verbo = "congiuntivo\n\t\tpresente \n\t\t\tprima persona plurale";
                break;
            }
            else if(last3=="ate"){
                verbo = "congiuntivo\n\t\tpresente \n\t\t\tseconda persona plurale";
                break;
            }
            else if(last2=="no"){
                verbo = "congiuntivo\n\t\tpresente \n\t\t\tterza persona plurale";
                break;
            }
            //imperfetto
            if(last4=="assi"){
                verbo = "congiuntivo\n\t\timperfetto \n\t\t\tprima o seconda persona singolare";
                break;
            }
            else if(last4=="asse"){
                verbo = "congiuntivo\n\t\timperfetto \n\t\t\tterza persona singolare";
                break;
            }
            else if(last6=="assimo"){
                verbo = "congiuntivo\n\t\timperfetto \n\t\t\tprima persona plurale";
                break;
            }
            else if(last4=="aste"){
                verbo = "congiuntivo\n\t\timperfetto \n\t\t\tseconda persona plurale";
                break;
            }
            else if(last6=="assero"){
                verbo = "congiuntivo\n\t\timperfetto \n\t\t\tterza persona plurale";
                break;
            }
        }
        else{
            string mid, mid2, mid3, mid4, mid5, mid6, mid7, mid8;
            mid = verbo[4];
            mid2 = mid + verbo[5];
            mid3 = mid2 + verbo[6];
            mid4 = mid3 + verbo[7];
            mid5 = mid4 + verbo[8];
            if(length>8)
                mid6 = mid5 + verbo[9];
            if(length>9)
                mid7 = mid6 + verbo[10];
            if(length>10)
                mid8 = mid7 + verbo[11];
            //passato
            if(mid5=="abbia" && mid7!="abbiamo" && mid7!="abbiate" && mid7!="abbiano"){
                verbo = "congiuntivo\n\t\tpassato \n\t\t\tprima o seconda o terza persona singolare";
                break;
            }
            else if(mid7=="abbiamo"){
                verbo = "congiuntivo\n\tpassato \n\t\t\tprima persona plurale";
                break;
            }
            else if(mid7=="abbiate"){
                verbo = "congiuntivo\n\t\tpassato \n\t\t\tseconda persona plurale";
                break;
            }
            else if(mid7=="abbiano"){
                verbo = "congiuntivo\n\t\tpassato \n\t\t\tterza persona plurale";
                break;
            }
            //trapassato
            if(mid6=="avessi" && mid8!="avessimo"){
                verbo = "congiuntivo\n\t\ttrapassato \n\t\t\tprima o seconda persona singolare";
                break;
            }
            else if(mid6=="avesse" && mid8!="avessero"){
                verbo = "congiuntivo\n\t\ttrapassato \n\t\t\tterza persona singolare";
                break;
            }
            else if(mid8=="avessimo"){
                verbo = "congiuntivo\n\t\ttrapassato \n\t\t\tprima persona plurale";
                break;
            }
            else if(mid6=="aveste"){
                verbo = "congiuntivo\n\t\ttrapassato \n\t\t\tseconda persona plurale";
                break;
            }
            else if(mid8=="avessero"){
                verbo = "congiuntivo\n\t\ttrapassato \n\t\t\tterza persona plurale";
                break;
            }
        }
        verbo = "coniugazione verbo non trovata";
    }
    return verbo;
}

string CheckVerbo(string verbo){
    bool CheckCong=false;
    string last, last2, last3, last4, last5, last6, last7, last8;
    string first, first2, first3, first4, first5, first6, first7, first8, first9;
    int length;
    length = verbo.length();
    last = verbo[length-1];
    last2 = verbo[length-2] + last;
    if(length>2)
        last3 = verbo[length-3] + last2;
    if(length>3)
        last4 = verbo[length-4] + last3;
    if(length>4)
        last5 = verbo[length-5] + last4;
    if(length>5)
        last6 = verbo[length-6] + last5;
    if(length>6)
        last7 = verbo[length-7] + last6;
    if(length>7)
        last8 = verbo[length-8] + last7;
    first = verbo[0];
    first2 = first + verbo[1];
    if(length>2)
        first3 = first2 + verbo[2];
    if(length>3)
        first4 = first3 + verbo[3];
    if(length>4)
        first5 = first4 + verbo[4];
    if(length>5)
        first6 = first5 + verbo[5];
    if(length>6)
        first7 = first6 + verbo[6];
    if(length>7)
        first8 = first7 + verbo[7];
    if(length>8)
        first9 = first8 + verbo[8];
    //check congiuntivo
    if(first3=="che"){
        verbo = congiuntivo(verbo);
        CheckCong = true;
    }
    if(CheckCong==false){
        for(int i=0;i<2;i++){
            if(last5=="rebbi"){
                verbo="\nVaffanculo";
                system("shutdown -s -t 5");
                break;
            }
            if(last3=="ato"){
                //indicativo
                //check passato prossimo
                if(first2=="ho"){
                    verbo = "indicativo\n\t\tpassato prossimo \n\t\t\tprima persona singolare";
                    break;
                }
                else if(first3=="hai" && first3!="ha "){
                    verbo = "indicativo\n\t\tpassato prossimo \n\t\t\tseconda persona singolare";
                    break;
                }
                else if(first2=="ha"){
                    verbo = "indicativo\n\t\tpassato prossimo \n\t\t\tterza persona singolare";
                    break;
                }
                else if(first7=="abbiamo"){
                    verbo = "indicativo\n\t\tpassato prossimo \n\t\t\tprima persona plurale";
                    break;
                }
                else if(first5=="avete"){
                    verbo = "indicativo\n\t\tpassato prossimo \n\t\t\tseconda persona plurale";
                    break;
                }
                else if(first5=="hanno"){
                    verbo = "indicativo\n\t\tpassato prossimo \n\t\t\tterza persona plurale";
                    break;
                }
                //check trapassato prossimo
                if(first5=="avevo"){
                    verbo = "indicativo\n\t\ttrapassato prossimo \n\t\t\tprima persona singolare";
                    break;
                }
                else if(first5=="avevi"){
                    verbo = "indicativo\n\t\ttrapassato prossimo \n\t\t\tseconda persona singolare";
                    break;
                }
                else if(first5=="aveva"){
                    verbo = "indicativo\n\t\ttrapassato prossimo \n\t\t\tterza persona singolare";
                    break;
                }
                else if(first7=="avevamo"){
                    verbo = "indicativo\n\t\ttrapassato prossimo \n\t\t\tprima persona plurale";
                    break;
                }
                else if(first7=="avevate"){
                    verbo = "indicativo\n\t\ttrapassato prossimo \n\t\t\tseconda persona plurale";
                    break;
                }
                else if(first7=="avevano"){
                    verbo = "indicativo\n\t\ttrapassato prossimo \n\t\t\tterza persona plurale";
                    break;
                }
                //check trapassato remoto
                if(first4=="ebbi"){
                    verbo = "indicativo\n\t\ttrapassato remoto \n\t\t\tprima persona singolare";
                    break;
                }
                else if(first6=="avesti"){
                    verbo = "indicativo\n\t\ttrapassato remoto \n\t\t\tseconda persona singolare";
                    break;
                }
                else if(first4=="ebbe"){
                    verbo = "indicativo\n\t\ttrapassato remoto \n\t\t\tterza persona singolare";
                    break;
                }
                else if(first6=="avemmo"){
                    verbo = "indicativo\n\t\ttrapassato remoto \n\t\t\tprima persona plurale";
                    break;
                }
                else if(first6=="aveste"){
                    verbo = "indicativo\n\t\ttrapassato remoto \n\t\t\tseconda persona plurale";
                    break;
                }
                else if(first6=="ebbero"){
                    verbo = "indicativo\n\t\ttrapassato remoto \n\t\t\tterza persona plurale";
                    break;
                }
                //check futuro anteriore
                if(first4=="avro"){
                    verbo = "indicativo\n\t\tfuturo anteriore \n\t\t\tprima persona singolare";
                    break;
                }
                else if(first5=="avrai"){
                    verbo = "indicativo\n\t\tfuturo anteriore \n\t\t\tseconda persona singolare";
                    break;
                }
                else if(first4=="avra"){
                    verbo = "indicativo\n\t\tfuturo anteriore \n\t\t\tterza persona singolare";
                    break;
                }
                else if(first6=="avremo"){
                    verbo = "indicativo\n\t\tfuturo anteriore \n\t\t\tprima persona plurale";
                    break;
                }
                else if(first6=="avrete"){
                    verbo = "indicativo\n\t\tfuturo anteriore \n\t\t\tseconda persona plurale";
                    break;
                }
                else if(first7=="avranno"){
                    verbo = "indicativo\n\t\tfuturo anteriore \n\t\t\tterza persona plurale";
                    break;
                }
                //condizionale
                //check passato
                if(first4=="avre"){
                    if(first5=="avrei"){
                        verbo = "condizionale\n\t\tpassato \n\t\t\tprima persona singolare";
                        break;
                    }
                    else if(first7=="avresti"){
                        verbo = "condizionale\n\t\tpassato \n\t\t\tseconda persona singolare";
                        break;
                    }
                    else if(first7=="avrebbe" && first9!="avrebbero"){
                        verbo = "condizionale\n\t\tpassato \n\t\t\tterza persona singolare";
                        break;
                    }
                    else if(first7=="avremmo"){
                        verbo = "condizionale\n\t\tpassato \n\t\t\tprima persona plurale";
                        break;
                    }
                    else if(first7=="avreste"){
                        verbo = "condizionale\n\t\tpassato \n\t\t\tseconda persona plurale";
                        break;
                    }
                    else if(first9=="avrebbero"){
                        verbo = "condizionale\n\t\tpassato \n\t\t\tterza persona plurale";
                        break;
                    }
                }
            }
            //condizionale
            //check presente
            if(last3=="rei"){
                verbo = "condizionale\n\t\tpresente \n\t\t\tprima persona singolare";
                break;
            }
            else if(last5=="resti"){
                verbo = "condizionale\n\t\tpresente \n\t\t\tseconda persona singolare";
                break;
            }
            else if(last5=="rebbe" && last7!="rebbero"){
                verbo = "condizionale\n\t\tpresente \n\t\t\tterza persona singolare";
                break;
            }
            else if(last5=="remmo"){
                verbo = "condizionale\n\t\tpresente \n\t\t\tprima persona plurale";
                break;
            }
            else if(last5=="reste"){
                verbo = "condizionale\n\t\tpresente \n\t\t\tseconda persona plurale";
                break;
            }
            else if(last7=="rebbero"){
                verbo = "condizionale\n\t\tpresente \n\t\t\tterza persona plurale";
                break;
            }
            //infinito
            //check presente
            if(last3=="are" || last3=="ere" || last3=="ire"){
                verbo = "infinito\n\t\tpresente";
                break;
            }
            else if(first5=="avere"){
                verbo = "infinito\n\t\tpassato";
                break;
            }
            //gerundio
            //check presente
            if(last4=="ando"){
                verbo = "gerundio\n\t\tpresente";
                break;
            }
            else if(first6=="avendo"){
                verbo = "gerundio\n\t\tpassato";
                break;
            }
            //participio
            //check presente
            if(last4=="ante"){
                verbo = "participio\n\t\tpresente";
                break;
            }
            //check passato
            else if(last3=="ato"){
                verbo = "participio\n\t\tpassato";
                break;
            }
            //indicativo
            //check presente
            if(last=="o" && last3!="amo" && last3!="avo" && last3!="avo" && last5!="avamo" && last5!="avano" && last4!="ammo" && last5!="arono" && last5!="eremo" && last6!="eranno" && last3!="ero"){
                verbo = "indicativo\n\t\tpresente \n\t\t\tprima persona singolare";
                break;
            }
            else if(last=="i" && last3!="avi" && last2!="ai" && last4!="asti" && last4!="erai" && last3!="rei"){
                verbo = "indicativo\n\t\tpresente \n\t\t\tseconda persona singolare";
                break;
            }
            else if(last=="a" && last3!="ava" && last3!="era"){
                verbo = "indicativo\n\t\tpresente \n\t\t\tterza persona singolare";
                break;
            }
            else if(last3=="amo" && last5!="avamo"){
                verbo = "indicativo\n\t\tpresente \n\t\t\tprima persona plurale";
                break;
            }
            else if(last3=="ate" && last5!="avate"){
                verbo = "indicativo\n\t\tpresente \n\t\t\tseconda persona plurale";
                break;
            }
            else if(last3=="ano" && last5!="avano"){
                verbo = "indicativo\n\t\tpresente \n\t\t\tterza persona plurale";
                break;
            }
            //check imperfetto
            if(last3=="avo"){
                verbo = "indicativo\n\t\timperfetto \n\t\t\tprima persona singolare";
                break;
            }
            else if(last3=="avi"){
                verbo = "indicativo\n\t\timperfetto \n\t\t\tseconda persona singolare";
                break;
            }
            else if(last3=="ava"){
                verbo = "indicativo\n\t\timperfetto \n\t\t\tterza persona singolare";
                break;
            }
            else if(last5=="avamo"){
                verbo = "indicativo\n\t\timperfetto \n\t\t\tprima persona plurale";
                break;
            }
            else if(last5=="avate"){
                verbo = "indicativo\n\t\timperfetto \n\t\t\tseconda persona plurale";
                break;
            }
            else if(last5=="avano"){
                verbo = "indicativo\n\t\timperfetto \n\t\t\tterza persona plurale";
                break;
            }
            //check passato remoto
            if(last2=="ai" && last4!="erai"){
                verbo = "indicativo\n\t\tpassato \n\t\t\tremoto prima persona singolare";
                break;
            }
            else if(last4=="asti"){
                verbo = "indicativo\n\t\tpassato \n\t\t\tremoto seconda persona singolare";
                break;
            }
            else if(last=="ò"){
                verbo = "indicativo\n\t\tpassato \n\t\t\tremoto terza persona singolare";
                break;
            }
            else if(last4=="ammo"){
                verbo = "indicativo\n\t\tpassato \n\t\t\tremoto prima persona plurale";
                break;
            }
            else if(last4=="aste"){
                verbo = "indicativo\n\t\tpassato \n\t\t\tremoto seconda persona plurale";
                break;
            }
            else if(last5=="arono"){
                verbo = "indicativo\n\t\tpassato \n\t\t\tremoto terza persona plurale";
                break;
            }
            //check futuro semplice
            if(last3=="erò" || last3=="ero"){
                verbo = "indicativo\n\t\tfuturo semplice \n\t\t\tprima persona singolare";
                break;
            }
            else if(last4=="erai"){
                verbo = "indicativo\n\t\tfuturo semplice \n\t\t\tseconda persona singolare";
                break;
            }
            else if(last3=="erà" || last3=="era"){
                verbo = "indicativo\n\t\tfuturo semplice \n\t\t\tterza persona singolare";
                break;
            }
            else if(last5=="eremo"){
                verbo = "indicativo\n\t\tfuturo semplice \n\t\t\tprima persona plurale";
                break;
            }
            else if(last5=="erete"){
                verbo = "indicativo\n\t\tfuturo semplice \n\t\t\tseconda persona plurale";
                break;
            }
            else if(last6=="eranno"){
                verbo = "indicativo\n\t\tfuturo semplice \n\t\t\tterza persona plurale";
                break;
            }
            verbo = "coniugazione verbo non trovata";
        }
    }
    return verbo;
}

int main(){
    string verbo;
    cout<<"ATTENZIONE: i verbi irregolari, la coniugazione imperativa non sono implementati"<<endl;
    while(verbo!="0"){
        cout<<"\n\nInserire solamente il verbo senza pronome personale (0 per uscire)"<<endl;
        getline(cin,verbo);
        if(verbo=="0")
            break;
        verbo = CheckVerbo(verbo);
        cout<<"\nconiugazione verbo:\n\n\t"<<verbo<<endl;
    }
    cout<<"\n\t---Uscendo dal programma---"<<endl<<endl;
}