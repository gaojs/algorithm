#include <iostream>
using namespace std;
int main() {
	char s[256];int i,n;
	gets(s);
	for(i=n=0;s[i];i++){
		if(s[i]<='9'&&s[i]>='0') n++; 
	}
	cout<<n;
	return 0;
}