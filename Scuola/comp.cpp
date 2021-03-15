#include <iostream>
using namespace std;
int main() {
  int n1, n2, n3, t1, t2, t3;
  cout << "inserire numeri " << endl;
  cin >> n1;
  cin >> n2;
  cin >> n3;
  if (n1 > n2 && n2 > n3) {
    t1 = n3;
    t2 = n2;
    t1 = n1;
  } else if (n1 > n3 && n3 > n2) {
    t1 = n2;
    t2 = n3;
    t3 = n1;
  } else if (n2 > n1 && n1 > n3) {
    t1 = n3;
    t2 = n1;
    t3 = n2;
  } else if (n2 > n3 && n3 > n1) {
    t1 = n1;
    t2 = n3;
    t3 = n2;
  } else if (n3 > n1 && n1 > n2) {
    t1 = n2;
    t2 = n1;
    t3 = n3;
  } else {
    t1 = n1;
    t2 = n2;
    t3 = n3;
  }
  cout << t1 << " " << t2 << " " << t3;
  return 0;
}
