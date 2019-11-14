#include<cstdio>
main() {
	int i=2,j=1,a,b,c;
	scanf("%c",&c);
	for(; i>=0; i--,j+=2) {
		for(a=i; a>0; a--)printf(" ");
		for(b=j; b>0; b--)printf("%c",c);
		printf("\n");
	}
	for(i+=2,j-=4; j>0; i++,j-=2) {
		for(a=i; a>0; a--)printf(" ");
		for(b=j; b>0; b--)printf("%c",c);
		printf("\n");
	}
}