#include <iostream>
using namespace std;

int a[100000]= {0}; //ÊäÈë

void swap(int & a,int & b) {
	int tmp;
	tmp = a;
	a = b;
	b = tmp;
}

void Qsort( int a[], int s, int e ) {
	if(s >= e)
		return;
	int k = a[s];
	int i = s,j = e;
	while (i < j) {
		while(j > i && a[j] >= k ) j--;
		swap(a[i], a[j]);
		while(i < j && a[i] <= k ) i++;
		swap(a[i], a[j]);
	}
	Qsort( a, s, i-1 );
	Qsort( a, i+1, e );
}

void arrangeRight(int a[],int k,int s,int e) {
	if(s <= e) {
		int kk = a[s];
		int i = s,j = e;
		while (i < j) {
			while ( j > i && a[j] >= kk )j--;
			swap( a[i], a[j]);
			while ( i < j && a[i] <= kk )i++;
			swap( a[i], a[j]);
		}

		if(e - i + 1 == k)  return;
		else if(e - i + 1 > k)  arrangeRight(a,k,i+1,e);
		else arrangeRight(a,k-(e-i+1),s,i-1);
	}
}

int main() {
//	freopen("F:\\aain3.txt","r",stdin);
	int n,k,i,j,m,t;
	cin>>n;
	for(i=0; i<n; i++) {
		cin>>a[i];
	}
	cin>>k;

	arrangeRight(a,k,0,n-1);
	Qsort(a,n-k,n-1);
	for(j=n-1; j>=n-k; j--)
		cout<<a[j]<<endl;
	return 0;
}
