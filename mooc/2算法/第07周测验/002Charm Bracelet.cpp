#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int N,M;
int w[3500],c[3500];
int f[13500];

int main() {
	cin>>N>>M;
	for(int i=1 ; i<=N ; i++) {
		cin>>c[i]>>w[i];
	}
	memset(f,0,sizeof(f) );
	for(int i=1 ; i<=N ; i++) {
		for(int j=M ; j>=1 ; j--) {
			int a;
			if( j-c[i]>=0 )
				a = f[j-c[i]]+w[i];
			else
				a = 0;
			f[j] = f[j]>a? f[j]:a;
		}
	}
	cout<<f[M]<<endl;
	return 0;
}
