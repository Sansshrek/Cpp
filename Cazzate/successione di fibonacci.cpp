#include <iostream>
using namespace std;
int main(){
	int n,prim=1,sec=1,ter,temp=0;
	cout<<prim<<endl;
	cout<<sec<<endl;
	while (temp !=1){	
	n=n+1;
		ter=prim+sec;
		prim=sec;
		sec=ter;
		cout<<ter<<endl;
	}
return 0;
}
