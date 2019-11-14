#include<cstdio>
#include<cmath>
main() {
	double a,b,c,x1,x2;
	scanf("%lf %lf %lf",&a,&b,&c);
	x1=(+sqrt(b*b-4*a*c)-b)/(2*a);
	x2=(-b-sqrt(b*b-4*a*c))/(2*a);
	if(b*b==4*a*c)printf("x1=x2=%.5f",x1);
	else if(b*b>4*a*c)printf("x1=%.5f;x2=%.5f",x1!=0?x1:0,x2);
	else {
		x1=b==0?b:-b/(2*a);
		x2=sqrt(4*a*c-b*b)/(2*a);
		printf("x1=%.5f+%.5fi;x2=%.5f-%.5fi",x1,x2,x1,x2);
	}
}