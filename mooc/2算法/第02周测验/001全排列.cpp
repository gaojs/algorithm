#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
const int M=7;

char *pn(char a[], int al, char o[], int ol, char an[], char on[], int i) {
//	cout<<"pn() a="<<a<<",o="<<o<<",i="<<i<<endl;
	for(int t=0; t<al; t++) {
		an[t]=a[t];
	}
	an[al]=o[i];
	for(int t=0; t<i; t++) {
		on[t]=o[t];
	}
	for(int t=i+1; t<ol; t++)	{
		on[t-1]=o[t];
	}
//	cout<<"pn() an="<<an<<",on="<<on<<endl;
}

void p(char a[], char o[]) {
//	cout<<"p() a="<<a<<",o="<<o<<endl;
	int al=strlen(a), ol=strlen(o);
	if(ol==0) {
		cout<<a<<endl;
	} else {
		for(int i=0; i<ol; i++) {
			char *an=(char*)malloc(al+2);
			char *on=(char*)malloc(ol);
			memset(an, 0, al+2);
			memset(on, 0, ol);
			pn(a, al, o, ol, an, on, i);
			p(an, on);
			free(an);
			free(on);
		}
	}
}

int main() {
//	freopen("F:\\aain.txt","r",stdin);
	char o[M], a[M]= {0};
	cin>>o;
//	cout<<o<<endl;
	p(a, o);
	return 0;
}
