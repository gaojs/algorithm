#include <cstdio>
int main() {
	int k,arr[30],a[30] = {0},ans = 0;
	scanf("%d",&k);
	for(int i=0; i<k; i++) {
		scanf("%d",&arr[i]);
		int max=0;
		for(int j=i-1; j>=0; j--) {
			if(arr[i]<=arr[j] && max < a[j]) {
				max = a[j];
			}
		}
		a[i] = max + 1;
		if(ans < a[i]) {
			ans = a[i];
		}
	}
	printf("%d\n",ans);
	return 0;
}