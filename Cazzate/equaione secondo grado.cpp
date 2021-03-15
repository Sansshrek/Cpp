#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	float a, b, c, sol, del, x1, x2;
	cout << "inserire dati" << endl;
	cin >> a;
	cin >> b;
	cin >> c;
	del = b * b - 4 * a * c;
	if (del == 0)
	{
		sol = (-b) / (2 * a);
		cout << "unica soluzione = " << sol;
	}
	else if (del > 0)
	{
		x1 = (-b + sqrt(del)) / (2 * a);
		x2 = (-b - sqrt(del)) / (2 * a);
		cout << "soluzione con + = " << x1;
		cout << "soluzione con - = " << x2;
	}
	else
		cout << "calcolo impossibile" << endl;
	return 0;
}
