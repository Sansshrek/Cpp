#include <iostream>
using namespace std;
int main(){
	int n,g,r,c,f,i,e,m,a[] = {};
	for (i=101;i<=200;i++){
		e=i-1;
		for(n=2;n<i;n++){
			r=i%n;
			if(r!=0)
				m++;
		}
		c++;
		if(e==m){
			for(f=0;f<c;f++){
				a[f]=i;
			}
		}
	}
	for(g=0;g<c;g++){
		cout<<a[g]<<endl;
	}
}
