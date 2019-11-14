#include <iostream>
using namespace std;
char s[100000];
int main() {
	int i,j,n;
	gets(s);
	for(i=0; s[i]; i++) {
		n=0;
		for(j=i-1; j>=0; j--)
			if(s[i]==s[j]) {
				n=1;
				break;
			}
		if(n)continue;
		for(j=i+1; s[j]; j++)
			if(s[i]==s[j]) {
				n=1;
				break;
			}
		if(n)continue;
		cout<<s[i];
		return 0;
	}
	cout<<"no";
	return 0;
}