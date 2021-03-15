#include <iostream>
using namespace std;
namespace Gianni{
	int z;
	int n=6;
}
namespace gesu{
	int z=2;
	int n;
}
int main(){
	Gianni::z=gesu::z;
	cout<<Gianni::z<<endl;
	gesu::n=1+Gianni::n;
	cout<<gesu::n<<endl;
return 0;	
}
