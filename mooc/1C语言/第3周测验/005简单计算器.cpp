#include<cstdio>
main() {
	int a,b,r;
	char c;
	scanf("%d %d %c",&a,&b,&c);
	switch(c) {
		case '+':
			r=a+b;
			break;
		case '-':
			r=a-b;
			break;
		case '*':
			r=a*b;
			break;
		case '/':
			if(b==0) {
				printf("Divided by zero!");
				return 0;
			} else r=a/b;
			break;
		default: {
			printf("Invalid operator!");
			return 0;
		}
	}
	printf("%d",r);
}