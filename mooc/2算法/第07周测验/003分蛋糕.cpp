#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N=22,INF=1e9;
int f[N][N][N],w,h,m;
void solve() {
	memset(f,0,sizeof(f));
	for(int i=1; i<=w; i++)
		for(int j=1; j<=h; j++) f[i][j][1]=i*j;

	for(int i=1; i<=w; i++)
		for(int j=1; j<=h; j++)
			for(int k=2; k<=min(i*j,m); k++) {
				f[i][j][k]=INF;
				for(int t=1; t<i; t++) {
					//f[i][j][k]=min(f[i][j][k],max(f[t][j][k-1],(i-t)*j));
					for(int p=1; p<k; p++)
						f[i][j][k]=min(f[i][j][k],max(f[t][j][p],f[i-t][j][k-p]));
				}
				for(int t=1; t<j; t++) {
					//f[i][j][k]=min(f[i][j][k],max(f[i][t][k-1],(j-t)*i));
					for(int p=1; p<k; p++)
						f[i][j][k]=min(f[i][j][k],max(f[i][t][p],f[i][j-t][k-p]));
				}
			}

}

int main() {
	while(cin>>w>>h>>m) {
		if(w==0&&h==0&&m==0) break;
		solve();
		cout<<f[w][h][m]<<"\n";
	}
	return 0;
}
