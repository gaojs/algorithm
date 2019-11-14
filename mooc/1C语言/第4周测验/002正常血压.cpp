#include<cstdio>
main() {
	int n,x,y,m=0,l=0;
	scanf("%d",&n);
	for(; n>0; n--) {
		scanf("%d %d",&x,&y);
		if(x<=140&&x>=90&&y<=90&&y>=60) {
			l++;
			if(m<l)m=l;
		} else {
			l=0;
		}
	}
	printf("%d",m);
}