#include <iostream>
#include <string>
using namespace std;
int main(){
	string giorno;
	cout<<"inserire nome giorno"<<endl;
	cin>>giorno;
	switch('giorno'){
		case 'lunedi':
			cout<<"1"<<endl;
		break;
		case 'martedi':
			cout<<"2"<<endl;	
		break;
		case 'mercoledi':
			cout<<"3"<<endl;
		break;
		case 'giovedi':
			cout<<"4"<<endl;
		break;
		case 'venerdi':
			cout<<"5"<<endl;
		break;
		case 'sabato':
			cout<<"6"<<endl;
		break;
		case 'domenica':
			cout<<"7"<<endl;
		break;
		default:
			cout<<"giorno inesistente"<<endl;
	}
return 0;
}
