#include <iostream>
using namespace std;
int main()
{
    float gg, mm, aa;
    cout << "inserire la data" << endl;
    cin >> gg;
    cin >> mm;
    cin >> aa;
    if (gg < 0 || mm < 0 || aa < 0)
        cout << "Data sbagliata" << endl;
    else {
        if (gg > 31 || mm > 12)
            cout << "Data sbagliata" << endl;
        else {
            if (mm == 2) {
                if (gg < 28)
                    cout << "Data corretta" << endl;
                else
                    cout << "Data sbagliata" << endl;
            } else {
                if (mm == 4 || mm == 6 || mm == 9 || mm == 11) {
                    if (gg > 30)
                        cout << "Data sbagliata" << endl;
                    else
                        cout << "Data corretta" << endl;
                } else
                    cout << "Data corretta" << endl;
                return 0;
            }
        }
    }
}