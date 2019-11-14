#include<cstdio>
main() {
	int a,s[4]={0},n,i;
	scanf("%d",&n);
	for(i=0; i<n; i++) {
		scanf("%d",&a);
		if(a<=18) s[0]++;
		else if(a<=35) s[1]++;
		else if(a<=60) s[2]++;
		else s[3]++;
	}
	for(i=0; i<4; i++) {
		printf("%.2f%\n",s[i]*100.0/n);
	}
}