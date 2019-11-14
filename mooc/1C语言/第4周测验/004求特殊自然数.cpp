#include<cstdio>
main() {
	int n,m,a,b,c,x,y,z;
	for(n=9*9+1; n<7*7*7; n++) {
		m=n,c=m%7,m/=7,b=m%7,m/=7,a=m;
		m=n,z=m%9,m/=9,y=m%9,m/=9,x=m;
		if(a==z&&b==y&&c==x) {
			printf("%d\n",n);
			printf("%d%d%d\n",a,b,c);
			printf("%d%d%d\n",x,y,z);
			break;
		}
	}
}