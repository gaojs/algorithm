#include <iostream>
using namespace std;
int main() {
	int n;
	char a[20],b[20];
	cin>>n;
	for(; n>0; n--) {
		cin>>a>>b;
		if(a[0]==b[0]) cout<<"Tie"<<endl;
		else if((a[0]=='R'&&b[0]=='S')||(a[0]=='S'&&b[0]=='P')||(a[0]=='P'&&b[0]=='R'))		cout<<"Player1"<<endl;
		else cout<<"Player2"<<endl;
	}
	return 0;
}