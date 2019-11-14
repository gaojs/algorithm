#include<cstdio>
main() {
	int m,n,i,t,s=0;
	scanf("%d %d",&m,&n);
	for(i=m; i<=n; i++) {
		for(t=i; t>0; t=t/10) {
			if(t%10==2)
				s+=1;
		}
	}
	printf("%d",s);
}