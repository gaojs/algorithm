#include<iostream>
#include<cstring>
using namespace std;
const int M=4;

void op(int t, int a[3][3],int n) {
	switch(t) {
		case 1:
			a[0][0]=(a[0][0]+n)%M;
			a[0][1]=(a[0][1]+n)%M;
			a[1][0]=(a[1][0]+n)%M;
			a[1][1]=(a[1][1]+n)%M;
			break;
		case 2:
			a[0][0]=(a[0][0]+n)%M;
			a[0][1]=(a[0][1]+n)%M;
			a[0][2]=(a[0][2]+n)%M;
			break;
		case 3:
			a[0][1]=(a[0][1]+n)%M;
			a[0][2]=(a[0][2]+n)%M;
			a[1][1]=(a[1][1]+n)%M;
			a[1][2]=(a[1][2]+n)%M;
			break;
		case 4:
			a[0][0]=(a[0][0]+n)%M;
			a[1][0]=(a[1][0]+n)%M;
			a[2][0]=(a[2][0]+n)%M;
			break;
		case 5:
			a[0][1]=(a[0][1]+n)%M;
			a[1][0]=(a[1][0]+n)%M;
			a[1][1]=(a[1][1]+n)%M;
			a[1][2]=(a[1][2]+n)%M;
			a[2][1]=(a[2][1]+n)%M;
			break;
		case 6:
			a[0][2]=(a[0][2]+n)%M;
			a[1][2]=(a[1][2]+n)%M;
			a[2][2]=(a[2][2]+n)%M;
			break;
		case 7:
			a[1][0]=(a[1][0]+n)%M;
			a[1][1]=(a[1][1]+n)%M;
			a[2][0]=(a[2][0]+n)%M;
			a[2][1]=(a[2][1]+n)%M;
			break;
		case 8:
			a[2][0]=(a[2][0]+n)%M;
			a[2][1]=(a[2][1]+n)%M;
			a[2][2]=(a[2][2]+n)%M;
			break;
		case 9:
			a[1][1]=(a[1][1]+n)%M;
			a[1][2]=(a[1][2]+n)%M;
			a[2][1]=(a[2][1]+n)%M;
			a[2][2]=(a[2][2]+n)%M;
			break;
	}
}

int ok(int a[3][3]) {
	for(int i=0; i<3; i++)
		for(int j=0; j<3; j++)
			if(a[i][j])
				return false;
	return true;
}

int main() {
//	freopen("F:\\aain.txt","r",stdin);
	int o[3][3],a[3][3],n[10],m[10],min=4*9,mt;
	for(int i=0; i<3; i++)
		for(int j=0; j<3; j++)
			cin>>o[i][j];
	for(n[1]=0; n[1]<M; n[1]++) {
		for(n[2]=0; n[2]<M; n[2]++) {
			for(n[3]=0; n[3]<M; n[3]++) {
				for(n[4]=0; n[4]<M; n[4]++) {
					for(n[5]=0; n[5]<M; n[5]++) {
						for(n[6]=0; n[6]<M; n[6]++) {
							for(n[7]=0; n[7]<M; n[7]++) {
								for(n[8]=0; n[8]<M; n[8]++) {
									for(n[9]=0; n[9]<M; n[9]++) {
										memcpy(a,o,sizeof(o));
										for(int i=1; i<10; i++) {//操作
											op(i,a,n[i]);
										}
										if(ok(a)) {
											mt=0;
											for(int i=1; i<10; i++) {
												mt+=n[i];
											}
											if(min>mt) {
												min=mt; //找最小的
												memcpy(m,n,sizeof(n));
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	for(int i=1; i<10; i++)
		for(int j=m[i]; j>0; j--)
			cout<<i<<" ";
	return 0;
}
