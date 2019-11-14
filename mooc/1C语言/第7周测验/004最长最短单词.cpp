#include <iostream>
#include <cstring>
using namespace std;
int main() {
	char a[100],m[100],n[100];
	int l,lm,ln;
	cin>>a;
	strcpy(m,a);
	strcpy(n,a);
	lm=ln=strlen(a);
	while(cin>>a) {
		l=strlen(a);
		if(l<lm) {
			strcpy(m,a);
			lm=l;
		}
		if(l>ln) {
			strcpy(n,a);
			ln=l;
		}
	}
	cout<<n<<endl<<m;
	return 0;
}