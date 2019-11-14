#include <iostream>
using namespace std;
int main() {
	char a[80],i;
	gets(a);
	for(i=0;a[i];i++)
	if(a[i]=='z')a[i]='a';
	else if(a[i]=='Z')a[i]='A';
	else if(a[i]<'Z'&&a[i]>='A'||a[i]<'z'&&a[i]>='a')a[i]+=1;
	puts(a);
	return 0;
}